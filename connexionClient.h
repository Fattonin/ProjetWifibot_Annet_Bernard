#ifndef CONNEXIONCLIENT_H
#define CONNEXIONCLIENT_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>

class connexionClient
{
public:
    connexionClient(int port,int IPserveur);
};

#endif // CONNEXIONCLIENT_H
