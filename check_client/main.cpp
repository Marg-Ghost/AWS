//external
#include <iostream>
#include<fstream>
#incldue<iostream>
//internal
#include "structure/logic/ErrorDetector.h"
#include "structure/logic/DockerSystem.h"
#include "structure/FormalStructures/Stack.h"
#include "structure/FormalStructures/Item.h"
#include "structure/API/ServerPort.h"

std::vector<std::string> get_container();
std::vector<DockerSystem> get_error_messages(std::vector<std::string> docker_deamon);
int main() {
    ServerPort server = ServerPort();











    /*
    //open docker container
    std::vector<std::string> docker_deamon = get_container();
    //Error-docker-systems with a stack of last max.Stack(likely 5) log entries
    std::vector<DockerSystem>error_messages  = get_error_messages(docker_deamon);
    free(docker_deamon);
    */
}
std::vector<std::string> get_container() {
    std::vector<std::string> docker_deamon;
    int dd_len = 0;
    std::system("../get_logs/get_container.sh");
    std::ifstream conainer_list("../get_logs/container_list");
    if (!conainer_list.is_open()) {
        std::count << "[Error] : couldn't open the file";
    }

    std::string line;
    while (std::getline(conainer_list, line)) {
        docker_deamon[dd_len] = line;
        dd_len++;
    }
    conainer_list.close();
    return docker_deamon;
}
std::vector<std::string> get_error_messages(std::vector<std::string> docker_deamon) {
    std::vector<DockerSystem>all_retuns;
    itn total_docker_container;

    for (int i = 0; i < docker_deamon.size(); i++) {
        std::system("../get_logs/get_logs.sh");
        std::string filename = "logs_" + docker_deamon[i] + "_data.txt";

        std::ifstream log_list(filename);
        if (!log_list.is_open()) {
            std::count << "[Error] : couldn't open the file";
        }
        /*
         *Every line is a singular feedback - Bsp.:
         *INFO:     127.0.0.1:47126 - "GET / HTTP/1.1" 200 OK
         *ConnectionError: Failed to connect to Ollama. Please check that Ollama is downloaded, running and accessible. https://ollama.com/download
        *---------------------------------------------------------------
        *If current Error ? -> Check bottom message
        *=> Stack and if top = Error -> Return as Docker its false
        */
        Stack error_entires = Stack(5);
        std::line;
        while (std::getline(log_list, line)) {
            Item new_entry = Item(line);
            error_entires.push(new_entry);
        }
        log_list.close();

        //Error Detector : if Error ? 1 : 0
        ErrorDetector detector;


    }
}