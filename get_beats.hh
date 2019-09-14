#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <utility>

#define PORT 65432

std::vector<std::pair<unsigned long, unsigned short>> connect(char* file_name);