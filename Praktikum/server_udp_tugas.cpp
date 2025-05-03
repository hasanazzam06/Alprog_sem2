#include <iostream>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET server_socket;
    sockaddr_in server, client;
    
    WSAStartup(MAKEWORD(2,2), &wsa);

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (sockaddr*)&server, sizeof(server));
    
	std::cout << "----------Server Smart Home----------\n";
    std::cout << "Gateway listening...\n";

	int slen = sizeof(client);
    char buffer[1024];
    
    while (true) {
        int recv_len = recvfrom(server_socket, buffer, sizeof(buffer) - 1, 0, (sockaddr*)&client, &slen);
        buffer[recv_len] = '\0';

        std::cout << "Received: " << buffer << " from " << inet_ntoa(client.sin_addr) << "\n";
        
        std::string message = (std::string)buffer;

        //if (strcmp(buffer, "DISCOVER_REQUEST") == 0) {
        if(message == "DISCOVER_REQUEST"){
            const char* reply = "DISCOVER_RESPONSE";
            sendto(server_socket, reply, strlen(reply), 0, (sockaddr*)&client, slen);
        }
    }

    closesocket(server_socket);
    WSACleanup();
    return 0;
}
