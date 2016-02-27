#include "connexionClient.h"

connexionClient::connexionClient(int port,int IPserveur)
{
    int sockComm = socket(AF_INET,SOCK_STREAM,0); // socket en mode connecté TCP
    struct sockaddr_in servAddr;
    int addrLength=sizeof(struct sockaddr_in);
    char buffer[10];


    servAddr.sin_addr.s_addr = htonl("IPserveur");
    servAddr.sin_family= AF_INET;
    servAddr.sin_port= htons(port);

    connect(sockComm, (struct sockaddr *)& servAddr, addrLength);
    recv(sockComm, buffer, 10, 0);

    close(sockComm);

    exit(0);

}
