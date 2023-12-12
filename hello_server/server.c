#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // ソケットの作成
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // ソケットの設定
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // ソケットを指定のアドレス・ポートにバインド
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // 接続待機
    listen(server_socket, 5);

    printf("Server waiting for connections...\n");

    // クライアントからの接続を受け付け
    int client_socket = accept(server_socket, NULL, NULL);

    // データの受信
    char data[1024];
    recv(client_socket, data, sizeof(data), 0);
    printf("Received from client: %s\n", data);

    // データの送信
    send(client_socket, "Hello from server!", sizeof("Hello from server!"), 0);

    // ソケットのクローズ
    close(server_socket);

    return 0;
}

