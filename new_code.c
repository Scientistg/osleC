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


 
int main(int argc, char *argv[]){
    

    // export GPIO
    int i;
    fd = open(path0, O_WRONLY);
    for(i = 0; i < 5; i++){
        strcat(strcpy(buffer, ports[i]), "\n");
        write(fd, buffer, 3);
    }
    close(fd);


    // Configure as input
    for(i = 0; i < 3; i++){
        strcat(strcpy(buffer, path1), ports[i]);
        strcat(strcpy(buffer, buffer), path2);    
        fd = open(buffer, O_WRONLY);
        write(fd, "in", 3);
        close(fd);
    }

    // Configure as output
    for(i = 3; i < 5; i++){
        strcat(strcpy(buffer, path1), ports[i]);
        strcat(strcpy(buffer, buffer), path2);    
        fd = open(buffer, O_WRONLY);
        write(fd, "out", 3);
        close(fd);
    }



    resetGame();
    while(true){
        printf("\t\t%d\t%d\t\t\n", !jogoTerminou, readPort(ports[0]));
        usleep(1000);
        if(readPort(ports[0]) && !jogoTerminou){
            escritaLed(1, "0");
            printf("Game Ganhou 1");
            jogoTerminou = true;
        } else if(readPort(ports[1]) && !jogoTerminou){
            escritaLed(2, "0");
            printf("Game Ganhou 2");
            jogoTerminou = true;
        }
        
        if(readPort(ports[2])){
            resetGame();
            printf("Game resetado");
        }
    }
 
    return EXIT_SUCCESS;
}