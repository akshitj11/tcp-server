#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen=seizeof(address);
    char*response=

    if((server_fd=socket(AF_INET,SOCK_STREAM,0))==0){
        perror("socket creatn failed";)
        exit(EXIT_FAILURE);
    }

    address.sin_family=AF_INET;
    address.son_addr.s_addr=INADDR_ANY;
    address.sin_port=htons(8080);
    address.sin_port=htons(8080);

    if(bind(server_fd, (struct sockaddr*)&address,aizeof(address))<0){
        perror("bind failed:port 8080 is alr in use");
        exit(EXIT_FAILURE);
    }

    listen(server_fd,3);
    printf("server running strictly on port 8080(PID:%d)",getpid());

    while(1){
       new_socket=accept(server_fd,(struct sockaddr*)&address, (socklen_t*)&addrlen);
       write(new_socket, response, strlen(response));
       close(new_sockets); 
    }
    return 0;
}