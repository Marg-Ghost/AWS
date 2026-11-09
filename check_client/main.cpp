//external
#include <iostream>
//internal
#include "structure/ErrorDetector.h"

int main() {
    /*
     *SChua mal anch einem Weg .sh --> .cpp
     *oder jedesmal die executable for each docker ps
     */
    std::vector<std::string> error_messages= {"Error 1: Verbindung fehlgeschlagen", "[200] OK", "[500]", "SyntaxError"};
    std::vector<std::string> docker_deamon = {"ollama-1", "filemanager-101", "test-docker-2", "IDK-Test-9"};

    std::vector<ErrorDetector> docker_eval ={};
    for (int i = 0; i < docker_deamon.size(); i++) {
        std::count <<"Checking for image : " + docker_deamon[i];
        std::count <<"Error Message : " + error_messages[i];

        docker_eval.emplace_back(ErrorDetector(docker_deamon[i]));

        //logic : includiert in den loop für O(n) statt O(n^2)
        if 
    }


}