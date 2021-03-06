# cpp-exercises

In this repository I host some implementations of C++ exercises.

Each file in `/src` corresponds to an exercise.
A task description is given in each file.
There are unit tests in `/test` which verify a correct implementation.
They are based on [GoogleTest](<https://github.com/google/googletest>).
The testing process is automated in CI fashion by Jenkins.

## Requirements

Developed and tested on the following setup:

- Debian 11.2
- Docker 20.10
- Jenkins 2.341
- cmake 3.21.4

## Build

Run following commands on your host to compile the project:

```text
mkdir build
cd build
cmake ..
make
```

Or build the project in a container:

```text
docker build -t cpp-exercises .
```

## Test

Run the unit tests from your build environment:

```text
cd build
ctest
```

Or run the container:

```text
docker run --rm cpp-exercises cpp-exercises-test
```

## Continuous Testing

The following instructions explain how to set up a containerized Jenkins environment.

Create a bridge network for Docker containers:

```text
docker network create jenkins
```

Create a container which runs a Docker daemon:

```text
docker run \
  --name jenkins-docker --detach \
  --privileged --network jenkins --network-alias docker \
  --env DOCKER_TLS_CERTDIR=/certs \
  --volume jenkins-certs:/certs/client \
  --volume jenkins-data:/var/jenkins_home \
  --publish 2376:2376 \
  docker:dind --storage-driver overlay2
```

Create a container which runs a Jenkins server:

```text
docker run \
  --name jenkins-server --detach \
  --network jenkins --env DOCKER_HOST=tcp://docker:2376 \
  --env DOCKER_CERT_PATH=/certs/client --env DOCKER_TLS_VERIFY=1 \
  --publish 8000:8080 --publish 50000:50000 \
  --volume jenkins-data:/var/jenkins_home \
  --volume jenkins-certs:/certs/client:ro \
  jenkins/jenkins:latest
```

Retrieve the password to authenticate with the Jenkins server in the last step:

```text
docker logs jenkins-server
```

Start a shell inside the Jenkins server:

```text
docker exec -it -u root jenkins-server bash
```

Run following instructions to complete the setup of the Jenkins server:

```text
curl -fsSLo /usr/share/keyrings/docker-keyring.asc https://download.docker.com/linux/debian/gpg
echo "deb [arch=amd64 \
  signed-by=/usr/share/keyrings/docker-keyring.asc] \
  https://download.docker.com/linux/debian \
  bullseye stable" > /etc/apt/sources.list.d/docker.list
apt-get update
apt-get upgrade
apt-get install -y docker-ce-cli nano cmake gcc g++ cppcheck
jenkins-plugin-cli --plugins docker-plugin:1.2.6
jenkins-plugin-cli --plugins docker-workflow:1.28
jenkins-plugin-cli --plugins docker-commons:1.19
jenkins-plugin-cli --plugins docker-java-api:3.1.5.2
jenkins-plugin-cli --plugins cmakebuilder:4.1.1
jenkins-plugin-cli --plugins xunit:3.0.6
jenkins-plugin-cli --plugins cppcheck:1.25
echo "alias c='clear'" > /var/jenkins_home/.bashrc && source /var/jenkins_home/.bashrc
exit
```

Open `http://localhost:8000`, enter the authentication password and finish the setup.

### Create Pipeline

After the setup for the Jenkins server is done, you need to create a Jenkins pipeline.

Select `Pipeline script from SCM` in the options, so Jenkins will use the [Jenkinsfile](https://github.com/cfanatic/cpp-exercises/blob/master/Jenkinsfile) provided in this repository.

### Activate Webhook

Jenkins shall trigger a pipeline run, whenever a new commit is pushed to the repository.

Use `ngrok` on your host to expose the Jenkins server to the Internet:

```text
ngrok http 8000
```

Take note of the resulting address, and add a webhook with a push-event in the settings section of your repository:

```text
https://<subdomain>.ngrok.io/github-webhook/
```

Activate the checkbox for `GitHub hook trigger for GITScm polling` in the options of your Jenkins pipeline.

### Known Issues

The Jenkins plugin [cppcheck 1.25](https://plugins.jenkins.io/cppcheck) is incompatible with JDK11.
When you perform a pipeline run, you may encounter following error in the *Console Output*:

> [Cppcheck] Parsing throws exceptions. javax.xml.bind.JAXBException:
Implementation of JAXB-API has not been found on module path or classpath.

You can resolve this issue by implementing the [pull request #56](https://github.com/jenkinsci/cppcheck-plugin/pull/56).

Follow these steps to build the plugin including patch:

```text
git clone -b jdk11 https://github.com/xnYi9wRezm/cppcheck-plugin.git
cd cppcheck-plugin
mvn verify
mvn hpi:hpi
cp target/cppcheck.hpi /var/jenkins_home/plugins
```

Install the plugin by restarting the Jenkins server.
