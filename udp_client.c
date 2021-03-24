#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFSIZE 30

void error_handling(char *message);

int main(int argc, char *argv[])
{	
	int clint_sock;
	char message[BUFSIZE];
	int str_len, addr_size, i;
	char msg1[]="good";
	char msg2[]="afternoon!";
	char msg3[]="everybody";
	struct sockaddr_in serv_addr;
	struct sockaddr_in from_addr;
	int clnt_addr_size;

	clint_sock = socket(PF_INET, SOCK_DGRAM, 0);

	if(clint_sock == -1)
	{
		error_handling("socket() error");
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));
	
	///////////여기부터 계속
	sendto(clint_sock,msg1,strlen(msg1),0,
	

	if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
	{
		error_handling("bind() error");
	}
	sleep(1);
	while(1)
	{
		clnt_addr_size = sizeof(clnt_addr);
		sleep(1);
		str_len = recvfrom(serv_sock, message, BUFSIZE, 0, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
		printf("수신번호 : %d\n",num++);
		sendto(serv_sock, message, str_len, 0, (struct sockaddr *) &clnt_addr, sizeof(clnt_addr));
	}
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
