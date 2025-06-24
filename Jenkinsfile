pipeline {
    agent any

    stages {
        stage('Parallel Tests') {
            failFast true // Add failFast here
            parallel {
                stage('Test A') {
                    steps {
                        bat 'echo testA'
                        bat 'echo: running tests in branch %env.BRANCH_NAME%'
                        bat 'dir'
                        bat 'set'
                    }
                }
                stage('Test B') {
                    steps {
                        bat 'echo testB'
                        bat 'echo: running tests in branch %env.BRANCH_NAME%'
                        sleep time: 2, unit: 'SECONDS'
                        // Simulate an error
                        //bat 'sh ciao errore'
                    }
                }
                stage('Test C') {
                    steps {
                        bat 'echo testC'
                        bat 'echo: running tests in branch %env.BRANCH_NAME%'
                        sleep time: 5, unit: 'SECONDS'
                    }
                }
            }
        }

        stage('Build') {
            steps {
                script {
                    bat 'echo: running tests in branch %env.BRANCH_NAME%'
                    bat 'g++ -std=c++20 -o main.exe main.cpp'
                }
            }
        }

        stage('Run') {
            steps {
                script {
                    bat 'echo: running tests in branch %env.BRANCH_NAME%'
                    bat '.\\main.exe'
                }
            }
        }
    }

    post {
        success {
            archiveArtifacts artifacts: '**/main.cpp, **/main.exe', fingerprint: true
        }
    }
}
