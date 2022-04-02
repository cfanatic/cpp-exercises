# cpp-exercises

In this repository I host some implementations of C++ exercises.

Each file in `/src` corresponds to an exercise. A task description is given in each file. There are unit tests in `/test` which verify a correct implementation. They are based on [GoogleTest](<https://github.com/google/googletest>).

## Requirements

Developed and tested on the following setup:

- Debian 11.2
- Docker 20.10
- macOS 12.2.1
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
docker run --rm cpp-exercises cpp-exercises-debug
docker run --rm cpp-exercises cpp-exercises-test
```

## Test

The binary which runs the unit tests is stored in the `build` folder:

```text
./cpp-exercises-test
```

Or simply call `ctest` to execute the unit tests conveniently.

## Continuous Testing

The following instructions explain how to set up a containerized Jenkins environment.
Whenever a new commit is pushed, a new pipeline run shall be triggered to automate the testing process.

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

Start a shell inside the Jenkins server container:

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
apt-get install -y docker-ce-cli nano sudo
jenkins-plugin-cli --plugins docker-plugin:1.2.6
jenkins-plugin-cli --plugins docker-workflow:1.28
jenkins-plugin-cli --plugins docker-commons:1.19
jenkins-plugin-cli --plugins docker-java-api:3.1.5.2
echo "alias c='clear'" > /var/jenkins_home/.bashrc && source /var/jenkins_home/.bashrc
exit
```

Open `http://localhost:8000`, enter the authentication password and finish the setup.
