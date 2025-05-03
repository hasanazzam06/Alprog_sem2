#include <iostream>
#include <string>
#include <winsock2.h>
#include <bits/stdc++.h>

using namespace std;

#define PORT 8888
#define PASSWORD "eeee" //Boleh diganti

string decrypt(string text, int n){
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        result += char((int(text[i] - 97 + n)  % 26) + 97);
    }
    
    return result;
}

void parseMessage(const string& messageRecv, string& pass, int& key) {
    stringstream ss(messageRecv);
    string temp;

    getline(ss, temp, ' ');
    pass = "";
    for (int x = 0; x < temp.length(); x++) {
        pass += char(tolower(temp[x]));
    }

    getline(ss, temp, ' ');
    key = atoi(temp.c_str());
}

int main() {
    WSADATA wsa;
    SOCKET listen_socket, client_socket;
    struct sockaddr_in server, client;
    int c, recv_size;
    char messageRecv[100];
    string messageSend;

    string pass;
    int key;

    // Kerjakan program kalian disini
    
    cout << "Initialising Winsock...\n";
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        cerr << "WSAStartup failed. Error code: " << WSAGetLastError() <<endl;
        return 1;
    }
    cout << "Winsock initialised.\n";

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == INVALID_SOCKET) {
        cerr << "Could not create socket. Error code: " << WSAGetLastError() <<endl;
        WSACleanup();
        return 1;
    }
    cout << "Socket created."<<endl;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        cerr << "Bind failed. Error code: " << WSAGetLastError() <<endl;
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    cout << "Bind done."<<endl;

    listen(listen_socket, 3);
    cout << "Waiting for incoming connections..."<<endl;

    c = sizeof(struct sockaddr_in);
    
    client_socket = accept(listen_socket, (struct sockaddr*)&client, &c);
    
    if (client_socket == INVALID_SOCKET) {
        cerr << "Accept failed. Error code: " << WSAGetLastError() <<endl;
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    cout << "Connection accepted.\n\n";
    
    recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
    if(recv_size == SOCKET_ERROR){
        cout << "recv failed with error code" <<  WSAGetLastError()<<endl;
    }
    else {
        messageRecv[recv_size] = '\0';
    }
    cout << "Pesan dari client: " << messageRecv <<endl;
    
    parseMessage(messageRecv, pass, key);
    
    string code = decrypt(pass,key);
    cout<<"Hasil Cipher: "<<code<<"(key = "<<key<<")"<<endl;
    
    string message;
    
    if(code == PASSWORD){
    	message = "success, code terbuka";

	}else{
		message = "failed, code tidak terbuka";
	}
	
    cout<<message<<endl;
    
   	send(client_socket, message.c_str(), message.length(), 0);


	cout<<endl<<"--------------------------------"<<endl;
	cout<<"Process exited after 12.63 seconds with return value 0"<<endl;
	system("pause");
    return 0;
}
