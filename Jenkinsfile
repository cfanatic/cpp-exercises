pipeline {

    agent {
        dockerfile {
            filename 'Dockerfile'
            args '-e PATH=/src/cpp-exercises/build:$PATH'
        }
    }

    stages {
        stage('Test') {
            steps {
                sh 'cpp-exercises-test'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying...'
            }
        }
    }

}