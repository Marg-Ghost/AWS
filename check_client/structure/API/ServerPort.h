//
// Created by Admin on 09.11.2026.
//

#ifndef AWS_HACKATHAN_SERVERPORT_H
#define AWS_HACKATHAN_SERVERPORT_H

/*
 * We use this Socket to communicate with the main server.py
 * Why not a simple Library- c++ as py subprocess?
 *-> We will send a lot of requests to refresh the website server status and catch every error right away
 */

class ServerPort {
private:
    // status val
    int socket_fd;
    //custom val
    int port;
    std::string buffer;   // sammelt angekommene Bytes

public:
    ServerPort(int port);
    ~ServerPort();

    std::optional<std::string> poll_json(int timeout_ms = 0); // json trenner '\n'
    void send_request();
};



#endif //AWS_HACKATHAN_SERVERPORT_H
