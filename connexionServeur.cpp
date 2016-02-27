#include "connexionServeur.h"

connexionServeur::connexionS(int port,char* data)
{

int sockPrim = socket(AF_INET,SOCK_STREAM,0);

struct sockaddr_in servAddr, cliAddr;
int addrLength=sizeof(struct sockaddr_in);
int sockWork;

servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
servAddr.sin_family= AF_INET;
servAddr.sin_port= htons(port);

bind (sockPrim, (struct sockaddr *) & servAddr, addrLength);

listen(sockPrim,10);
data=new char[10];
char[0]="a";

while (1) {
sockWork = accept(sockPrim, (struct sockaddr *)& cliAddr,&addrLength);
send(sockWork, *data, data.length, 0);
close(sockWork);
printf("data envoyé");
}

}
