#include <stdio.h>
#include <stdlib.h>
#include "winsock2.h"
//#define _WIN32_WINNT 0x0501
int main()
{
	// int a = SOCKET_ERROR;
	// printf("SOCKET_ERROR = %d", a);
	WSADATA wsadata;
	int result = WSAStartup(MAKEWORD (2,2), & wsadata);
	if(result != NO_ERROR)
	{
		printf("ERROR");
	}
	SOCKET m_socket;
	m_socket = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);
	if(m_socket == INVALID_SOCKET)
	{
		printf("error");
		// // printf(WSAGETLASTERROR());
		// WSACleanUp();
	}
	struct sockaddr_in sa;
	sa.sin_family =AF_INET;
	sa.sin_port = htons(6789);
	sa.sin_addr.s_addr = htonl(INADDR_ANY);

		//struct sockaddr ....macro define gareko SOCKADDR
	//capital vaneko MACRO define gareko
	if(bind(m_socket, (SOCKADDR*) &sa, sizeof(sa))==SOCKET_ERROR)
	{
		printf("error");
		// printf(WSAGETLASTERROR());
	
		return 1;
		
	}
	if(listen(m_socket,10) == SOCKET_ERROR)
	{
		printf("ERROR");
		return 1;

	}

	SOCKET client_fd;

	client_fd = accept(m_socket, NULL, NULL);

	if (client_fd == INVALID_SOCKET){
		perror("accept error");
		WSACleanUp();
		return 1;
	}

}

