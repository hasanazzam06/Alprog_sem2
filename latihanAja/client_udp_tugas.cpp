#include <iostream>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

#define BROADCASR_SERVER "255.255.255.255"

int main() {
    WSADATA wsa;
    SOCKET client_socket;
    sockaddr_in server, from;
    
    WSAStartup(MAKEWORD(2,2), &wsa);

    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    BOOL broadcast = TRUE;
    setsockopt(client_socket, SOL_SOCKET, SO_BROADCAST, (char*)&broadcast, sizeof(broadcast));

    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    server.sin_addr.s_addr = inet_addr(BROADCASR_SERVER);

    std::string message = "DISCOVER_REQUEST";

    sendto(client_socket, message.c_str(), strlen(message.c_str()), 0, (sockaddr*)&server, sizeof(server));
    std::cout << "----------Modul Smart Lamp----------\n";
    std::cout << "DISCOVER_REQUEST dikirim...\n";

	int slen = sizeof(from);
	char buffer[1024];
	
    int recv_len = recvfrom(client_socket, buffer, sizeof(buffer) - 1, 0, (sockaddr*)&from, &slen);
    buffer[recv_len] = '\0';

    std::cout << "Response dari gateway: " << buffer << "\n";
    std::cout << "Alamat gateway: " << inet_ntoa(from.sin_addr) << "\n";

    closesocket(client_socket);
    WSACleanup();
    return 0;
}
