#ifndef SERVEUR_H
#define SERVEUR_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>

class connexion
{
public:
    connexionS(int port,char* tab);
};

#endif // CONNEXION_H
