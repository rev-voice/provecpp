pipeline {
    agent {
        docker {
            image 'gcc:latest' // Usa un'immagine Docker con GCC
        }
    }

    stages {
        stage('Parallel Tests') {
            failFast true // Add FailFast here
            parallel {
                stage('Test A') {
                    steps {
                        bat 'echo testA'
                        bat 'dir'
                    }
                }
                stage('Test B') {
                    steps {
                        bat 'echo testB'
                        sleep time: 2, unit: 'SECONDS'
                        // Simulate an error
                        //bat 'sh ciao errore'
                    }
                }
                stage('Test C') {
                    steps {
                        bat 'echo testC'
                        sleep time: 5, unit: 'SECONDS'
                    }
                }
            }
        }

        stage('Build') {
            steps {
                script {
                    bat 'g++ -std=c++20 -o main.exe main.cpp'
                }
            }
        }

        stage('Run') {
            steps {
                script {
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
