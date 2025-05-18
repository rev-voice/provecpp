pipeline {
    agent {
        docker {
            image 'gcc:latest'
            args "-v ${pwd()}:/workspace -w /workspace"
        }
    }

    environment {
        WORKSPACE_UNIX = '/workspace'
    }

    stages {
        stage('Checkout') {
            steps {
                git branch: 'experimental', url: 'https://github.com/rev-voice/provecpp.git '
            }
        }

        stage('Build') {
            steps {
                script {
                    sh '''
                        echo "Compilazione del progetto..."
                        g++ -std=c++20 -o main main.cpp || exit 1
                        echo "Compilazione completata."
                    '''
                }
            }
        }

        stage('Run') {
            steps {
                script {
                    sh '''
                        echo "Esecuzione del programma..."
                        if [ -f main ]; then
                            ./main
                        else
                            echo "Errore: file main non trovato."
                            exit 1
                        fi
                    '''
                }
            }
        }
    }

    post {
        success {
            archiveArtifacts artifacts: '**/main.cpp, **/main', fingerprint: true
        }
        failure {
            echo 'Errore durante l\'esecuzione della pipeline.'
        }
    }
}
