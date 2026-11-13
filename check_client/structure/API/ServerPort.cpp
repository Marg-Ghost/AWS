//
// Created by Admin on 09.11.2026.
//

//external
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
//internal
#include "ServerPort.h"
#include "../ServerPort.h"

ServerPort::ServerPort(int port) {
    /*
    * Dear Reader pls excuse the many explainations in this code but this is my first time
    * dealing with raw sockets in C++, so I'm kinda still figuring it out...
    * btw thx Beej's Guide to Network Programming couldn't have done it without you
    */
    this->port = port;
    int status;
    struct addrinfo hints; // hints als Settings -> Übertragen dann auch servinfo
    struct addrinfo *servinfo; // quasi Briefkasten | verkettete Liste mit möglichen Adressen
    memset(&hints, 0, sizeof(hints)); // certifiyes structure is empty
    hints.ai_family = AF_UNSPEC; // don't care IPv4 or IPv6 hints.
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets hints.
    hints.ai_flags = AI_PASSIVE; // Ich bin ein Server, nimm meine eigene Adresse. -> NULL

    /*Whats: getaddrinfo? :
     * | takes | a human-readable address (like "[www.example.com](https://www.example.com)" && Port
     *======================================================================================================
     * status = getaddrinfo(NULL, "3490", &hints, &servinfo);
     * //  ^                                          ^
     * //  Rückgabewert (return)              Out-Parameter
     * | 1.returns (via. Out-Parameter) | a linked list of structured address data : {IP4, IP6}
     *               Out-Parameter (ein Zeiger auf einen Zeiger, struct addrinfo **res). Hier schreibt getaddrinfo das eigentliche Ergebnis rein.
     * | 2.returns | int a status Code zum Testen nach init error
     */

     /*1.Parameter:
     *  1. NULL || DNS-Adresse
     *  2. Port
     *  3. Settings_data
     *  4. Aufzufüllender Kasten
     */
    status = getaddrinfo(NULL, this->port.aschar() , &hints, &servinfo);
    if (status != 0) {
        fprintf (stderr, "getaddrinfo error: %s\n", gai_strerror(status) ) ;
        exit(1);
    }

    this->socket_fd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    // all return vals fpr socket_fd are diff. types exept "-1" is an Error
    if (socket_fd == -1) {
        perror("Error | socket");
        exit(1);
    }

    if (bind(socket_fd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        perror("Error | bind");
        exit(1);
    }
    freeaddrinfo(servinfo);
}

ServerPort::~ServerPort() {
    close(this->socket_fd);
}
