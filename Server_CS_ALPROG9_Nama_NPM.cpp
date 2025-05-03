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

class File {
    public:
        string name;
        string type;

        File(string file_name){
            stringstream ss (file_name);
            string temp;

            getline(ss, temp, '.');
            name = temp;
            
            getline(ss, temp);
            type = temp;
        }
};


class DirectoryReader {
    private:
        string DIRECTORY = "system";

        void _create_file(string file_name){
            ofstream file;
        
            file.open("./" + DIRECTORY + "/"+ file_name);
            file.close();
        }

        void _create_directory(){
            mkdir(DIRECTORY.c_str());
            string tmpFile = "output.txt";
            string path = "./" + DIRECTORY;

            _create_file("A.txt");
            _create_file("B.txt");
            _create_file("k.cpp");
            _create_file("b.cpp");

            string command = "dir " + path + " > " + tmpFile;
            
            cout << "Perintah system: " << command << endl; // Debug output
            
            command = "dir /b \"" + path + "\" > " + tmpFile;

   	 		cout << "Perintah system: " << command << endl; // Debug output
    
            system(command.c_str());
        }

    public:
        static vector<File> GetData() {
            DirectoryReader reader;
            reader._create_directory();

            vector<File> data = {};

            string tmpFile = "output.txt";
            ifstream file_data;

            file_data.open(tmpFile);

            string line, result;
            while (!file_data.eof()) {
                getline(file_data, line);
                
                File newFile(line);
                data.push_back(newFile);
            }
            file_data.close();

            remove(tmpFile.c_str()); 

            return data;
        }
};

void cekRequest(string message, string* request, string* type){
        stringstream ss (message);
        string temp;
        
        getline(ss, temp, ' ');
        *request = temp;
            
        getline(ss, temp);
        *type = temp;
    }

string processRequest(vector<File>& file_list, string request){
    string message,temp = "[";
    for(const auto& ls : file_list){
    	if(ls.type == request){
    		if(temp != "["){
    			temp+= ", ";
			}
    		temp+=(ls.name+"."+ls.type);
		}
	}
	temp+="]";
	if(temp == "[]"){
		message = "file with '" + request + "' extension does not exist";
	}else{
		message = "file with '" + request + "' extension are "+temp; 
	}
	return message;
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
    
    //DirectoryReader drc;
    
    vector<File> data = DirectoryReader::GetData();
    if(data.empty()){
    	cerr<<"data ksoosng"<<endl;
	}else{
		cerr<<"ada datanya"<<endl;
		for (const auto& file : data) {
   			cout << "File: " << file.name << endl;  // Mengakses langsung 'name' jika public
		}		
	}

//	vector<File> data ={};
//	
//	
//	File newFile("tes.txt");
//    data.push_back(newFile);
//    
//    vector<File> file_list = DirectoryReader::GetData();
//
//	for (const auto& file : file_list) {
//   	 	cout << "Name: " << file.name << ", Type: " << file.type << endl;
//	}
	

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
    
    string request, type, message ="kosongan";
    
    cekRequest(messageRecv, &request, &type);
    
    cout<<request<<endl<<type;
    
    if(request == "LIST"){
    	message = processRequest(data, type);
	}else{
		//message = "Command tidak terdeteksi";
		message = type;
	}
    
    send(client_socket, message.c_str(), message.length(), 0);
    
	cout<<endl<<"--------------------------------"<<endl;
	cout<<"Process exited after 12.63 seconds with return value 0"<<endl;
	system("pause");
    return 0;
}
