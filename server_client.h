#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <iostream>
#include <arpa/inet.h>

class server
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *message;
    int port;

public:
    int createServer(int prt)
    {
        port = prt;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(prt);

        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }

        // Forcefully attaching socket to the port 8080
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                       &opt, sizeof(opt)))
        {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
        // Forcefully attaching socket to the port 8080
        if (bind(server_fd, (struct sockaddr *)&address,
                 sizeof(address)) < 0)
        {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
        if (listen(server_fd, 3) < 0)
        {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        std::cout << "\nServer listening\n";
        return 1;
    }
    std::string receiveString()
    {
        valread = read(new_socket, buffer, 1024);
        return buffer;
    }
    void sendString(char *message)
    {
        send(new_socket, message, strlen(message), 0);
    }
};

class client
{
    int port;
    char *ip_addr;
    char *message;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

public:
    void setIPAddress(int prt, char *ip_address)
    {
        port = prt;
        ip_addr = ip_address;
        // strcpy(ip_addr, ip_address.c_str());
    }
    bool connect_server()
    {
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            printf("\n Socket creation error \n");
            return false;
        }
        if (inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr) <= 0)
        {
            printf("\nInvalid address/ Address not supported \n");
            return false;
        }
        // cout << serv_addr.sin_port;
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            printf("\nConnection Failed \n");
            return false;
        }
        return true;
    }
    void sendString(char *msg)
    {
        // strcpy(message, msg.c_str());
        send(sock, msg, strlen(msg), 0);
    }
    std::string receiveString()
    {
        valread = read(sock, buffer, 1024);
        return buffer;
    }
};
