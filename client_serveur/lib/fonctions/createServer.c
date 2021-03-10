/*
** ETNA PROJECT, 05/07/2020 by vignan_q
** CreateServer
** File description:
**      createServer
*/

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "../../include/server.h"

int serverInit (char *portNb) {
    if (validatePort(portNb) == -1)
        return -1;

    int socketSrv;
    int client;
    socklen_t client_addr_len;
    struct sockaddr_in server;

    socketSrv = socket(AF_INET , SOCK_STREAM , 0);
    if (socketSrv < 0)
        return -1;

    server.sin_port = htons( (int) portNb);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("0.0.0.0"); 

    if (bind(socketSrv , (struct sockaddr *)&server , sizeof(server)) < 0)
        return -1;
    if (listen(socketSrv , 5) < 0)
        return -1;

    client = accept(socketSrv , (struct sockaddr *)&server , &client_addr_len);
    if (client < 0)
        return -1;

    send(client , "Hello\n" , 6 , 0); 
    
    while(1){}
    return 1;
}