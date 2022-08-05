// +---------------------------------------------+
// |    Creation Date:  2022-08-05T15:34         |
// |                                             |
// |    Authors: Gabriel Araujo                  |
// |             Estevao Calera                  |
// |                                             |
// +---------------------------------------------+


#include "osleCbib.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

#define MAX 100

bool jogoTerminou = false;

int fd;
char path0[] = "/sys/class/gpio/export";
char path1[] = "/sys/class/gpio/gpio";
char path2[] = "/direction";
char path3[] = "/value";
char buffer[MAX];
char ports[5][3] = {"46","47","48","88","89"};

void writePort(char *port, char *value){
    strcat(strcpy(buffer, path1), port);
    strcat(strcpy(buffer, buffer), path3);
    fd = open(buffer, O_WRONLY);
    write(fd, value, 1);
    close(fd);
}

bool readPort(char *port){
    char lido[3];
    strcat(strcpy(buffer, path1), port);
    strcat(strcpy(buffer, buffer), path3);    
    fd = open(buffer, O_RDONLY);
    int a = read(fd, lido, 2);
    close(fd);
    if(lido[0] == 48) return true;
    else return false;
}


void escritaLed(int ledNum, char *value){
    char gpio[3];
    switch (ledNum){
    case 1:
        writePort(ports[3],value);
        break;
    
    case 2:
        writePort(ports[4],value); 
        break;

    default:
        writePort(ports[3],"0");
        writePort(ports[4],"0");
        break;
    }
}

void resetGame(){
    escritaLed(1,"1");
    escritaLed(2,"1");
    jogoTerminou = false;
}
