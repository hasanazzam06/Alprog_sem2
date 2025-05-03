#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <string>
#include <winsock2.h>
#include <bits/stdc++.h>

using namespace std;

#define PORT 8888

class Host {
    public:
        string nameserver;
        string ip_address;
};

class DNSStorage {
    private:
        string FILENAME = "bind.txt";

    public:
        static vector<Host> GetData() {
            DNSStorage storage;
            ifstream file_data;
            vector<Host> data = {};

            file_data.open(storage.FILENAME);
            
            if(file_data.fail()){
                cout << "Failed to open file." << endl ;

                return {};
            }

            string line;
            while (!file_data.eof()) {
                getline(file_data, line);
                
                stringstream ss(line);
                string temp;
                Host tempData;

                getline(ss, temp, '@');
                tempData.nameserver = temp;
                
                getline(ss, temp);
                tempData.ip_address = temp;

                data.push_back(tempData);
            }
            file_data.close();

            return data;
        }
};


string processRequest(vector<Host>& storage, string request){
    string format, arg,message;
    
    stringstream ss(request);
    
    getline(ss,format,' ');
    getline(ss,arg,' ');
    
    if(format != "nslookup"){
    	if(format == "SHUTDOWN"){
    		return "program telah selesai, menutup server.....";
		}
    	return "Command "+format+ " tidak ada...";
	}
	
	for(const auto& str:storage){
		if(str.nameserver == arg){
			message = "Domain ["+str.nameserver+"] found!! Ip Address: "+str.ip_address;
			return message;
		}else if(str.ip_address == arg){
			message = "Host ["+str.ip_address+"] found!! Name Server: "+str.nameserver;
			return message;
		}	
	}
	message = "["+arg+"] is not found...";
	return message;
}


int main() {
    vector<Host> storage = DNSStorage::GetData();
    
    //Kerjakan program anda disini
    
    WSADATA wsa;
    SOCKET listen_socket, client_socket;
    struct sockaddr_in server, client;
    int c, recv_size;
    char messageRecv[100];
    string messageSend;
    
    cout << "Memulai Winsock...\n";
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        cerr << "WSAStartup gagal. Error code: " << WSAGetLastError() <<endl;
        return 1;
    }
    cout << "Winsock terisntall.\n";

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == INVALID_SOCKET) {
        cerr <<"gagal membuat socket. Error code: " << WSAGetLastError() <<endl;
        WSACleanup();
        return 1;
    }
    cout << "Socket berhasil dibuat."<<endl;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        cerr << "Bind gagal. Error code: " << WSAGetLastError() <<endl;
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    cout << "Bind berhasil."<<endl;

    listen(listen_socket, 3);
    cout << "menunggu koneksi..."<<endl;

    c = sizeof(struct sockaddr_in);
    
    client_socket = accept(listen_socket, (struct sockaddr*)&client, &c);
    
    if (client_socket == INVALID_SOCKET) {
        cerr << "Accept gagal. Error code: " << WSAGetLastError() <<endl;
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    cout << "koneksi terhubung.\n\n";
    
    while(1){
    	recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
    
    	if(recv_size == SOCKET_ERROR){
        	cout << "gagal menerima pesan error code" <<  WSAGetLastError()<<endl;
    	}else {
        	messageRecv[recv_size] = '\0';
    	}
    
    	cout << "Pesan dari server: " << messageRecv <<endl;
    
    	string message = processRequest(storage,messageRecv);
    
    	send(client_socket, message.c_str(), message.length(), 0);
    	
    	if(message == "program telah selesai, menutup server....."){
    		break;
		}
	}
    
    closesocket(client_socket);
    closesocket(listen_socket);
    WSACleanup();

    return 0;
}
