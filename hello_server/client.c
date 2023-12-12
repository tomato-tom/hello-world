#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // ソケットの作成
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // ソケットの設定
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // サーバのIPアドレス

    // サーバに接続
    connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // データの送信
    char data[] = "Hello from client!";
    send(client_socket, data, sizeof(data), 0);

    // データの受信
    char response[1024];
    recv(client_socket, response, sizeof(response), 0);
    printf("Received from server: %s\n", response);

    // ソケットのクローズ
    close(client_socket);

    return 0;
}

