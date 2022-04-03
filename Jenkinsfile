pipeline {

    agent {
        dockerfile {
            filename 'Dockerfile'
            args '-e PATH=/src/cpp-exercises/build:$PATH'
        }
    }

    options {
        timeout(time: 1, unit: 'HOURS')
    }

    stages {
        stage('Build') {
            steps {
                checkout([
                    $class: 'GitSCM',
                    branches: [[name: 'feature/jenkins']],
                    extensions: [],
                    userRemoteConfigs: [[url: 'https://github.com/cfanatic/cpp-exercises']],
                ])
                cmakeBuild buildType: 'Debug',
                    buildDir: 'build',
                    cleanBuild: true,
                    installation: 'InSearchPath',
                    steps: [[withCmake: true]]
            }
        }
        stage('Test') {
            steps {
                sh './build/cpp-exercises-test --gtest_output=xml:gtest-results.xml'
                sh 'cppcheck . --enable=all --language=c++ --std=c++14 -ibuild/ --xml 2> cppcheck-result.xml'
            }
        }
        stage('Deploy') {
            steps {
                echo 'n/a'
            }
        }
    }

    post {
        success {
            xunit (
                thresholds: [ skipped(failureThreshold: '0'), failed(failureThreshold: '0') ],
                tools: [ GoogleTest(pattern: 'gtest-results.xml') ]
            )
            publishCppcheck ignoreBlankFiles: true, pattern: '**/cppcheck-result.xml'
        }
    }

}
