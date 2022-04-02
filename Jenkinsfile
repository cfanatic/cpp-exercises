pipeline {

    agent {
        dockerfile {
            filename 'Dockerfile'
            args '-e PATH=/src/cpp-exercises/build:$PATH'
        }
    }

    stages {
        stage('Build') {
            steps {
                sh 'cat test/linked_list_test.cpp'
            }
        }
        stage('Test') {
            steps {
                sh 'cpp-exercises-test --gtest_output=xml:results.xml'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying...'
            }
        }
    }
    post {
        always {
            xunit (
                thresholds: [ skipped(failureThreshold: '0'), failed(failureThreshold: '0') ],
                tools: [ GoogleTest(pattern: 'results.xml') ]
            )
        }
    }
}