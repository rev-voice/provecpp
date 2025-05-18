pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                git branch: 'experimental', url: 'https://github.com/rev-voice/provecpp.git '
            }
        }

        stage('Build and Run with Docker') {
            steps {
                script {
                    // Pulisci eventuali container precedenti
                    bat '''
                        docker rm -f my-build-container || true
                    '''

                    // Esegui il container Docker con il comando desiderato
                    bat '''
                        docker run --name my-build-container ^
                            -v /c/ProgramData/Jenkins/.jenkins/workspace/rovacpp-multibranch_experimental:/workspace ^
                            -w /workspace ^
                            gcc:latest sh -c "g++ -std=c++20 -o main main.cpp && ./main"
                    '''
                }
            }
        }
    }

    post {
        success {
            echo 'Pipeline completata con successo!'
        }
        failure {
            echo 'Errore durante l\'esecuzione della pipeline.'
        }
    }
}
