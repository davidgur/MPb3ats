#include "get_beats.hh"

#include <sstream>
#include <string>
#include <vector>
#include <utility>

std::vector<std::pair<unsigned long, unsigned short>> connect(char* file_path) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[7938000] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Connection error! \n");
        exit;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\n Invalid address \n");
        exit;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
        printf("\nConnection Failed \n"); 
        exit; 
    } 
    send(sock , file_path , strlen(file_path) , 0 ); 
    printf("Hello message sent\n"); 
    valread = read( sock , buffer, 7938000); 
    std::stringstream s(buffer);

    unsigned long data_point = 0;
    unsigned short type = 0;
    std::vector<std::pair<unsigned long, unsigned short>> data_points; 
    while (s >> data_point >> type) {
        std::pair <unsigned long, unsigned short> point = std::make_pair(data_point, type);
        data_points.push_back(point);
    }
    
    return data_points;
} 
