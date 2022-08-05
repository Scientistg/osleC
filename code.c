// +---------------------------------------------+
// |    Creation Date:  2022-07-04T12:28         |
// |                                             |
// |    Authors: Gabriel Araujo                  |
// |             Estevao Calera                  |
// |                                             |
// +---------------------------------------------+

#include "osleCbib.c"

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
