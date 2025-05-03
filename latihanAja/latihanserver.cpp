#include <iostream>
#include <string>
#include <winsock2.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
WSADATA wsa;
    
    if(WSAStartup(MAKEWORD(2,2), &wsa) != 0){
    	cerr<<"error start wsa"<<endl;
    	return 1;
	}
	
	SOCKET listen_sck = socket(AF_INET,SOCK_STREAM,0);
	if(listen_sck == INVALID_SOCKET){
		cerr<<"eror membuat socket"<<endl;
		WSACleanup();
		return 1;
	}
	
	struct sockaddr_in srv;
	
	srv.sin_family=IF_NET;
	srv.sin_port=htons(PORT);
	srv.sin_addr.s_addr=INADDRY_ANY;
	
	if(bind(listen_sck,(sockaddr*)&srv,sizeof(srv)) == SOCKET_ERROR){
		cerr<<"error bind socket"<<endl;
		closesocket(listen_sck);
		WSACleanup();
		return 1;
	}
	
	struct sockaddr_in client
	
	listen(listen_sck,5);
	int c = sizeof(struct sockaddr*);
	SOCKET client_sck = accept(listen_sck,(struct sockaddr*)&client, &c);
	
	return 0;
}