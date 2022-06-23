#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define MAX 100



 
int main(int argc, char *argv[]){
    int fd;
    char path1[] = "/sys/class/gpio/gpio";
    char path2[] = "/direction";
    char buffer[MAX];
    int ports[5][3] = {"73","75","77","88","89"};

    // export GPIO
    int i;
    fd = open("/sys/class/gpio/export", O_WRONLY);
    for(i = 0; i < 5; i++){
        write(fd, ports[i], 3);
    }
    close(fd);


    // Configure as output
    for(i = 0; i < 5; i++){
        strcat(strcpy(buffer, path1), ports[i]);
        strcat(strcpy(buffer, buffer), path2);    
        fd = open(buffer, O_WRONLY);
        write(fd, "out", 3);
        close(fd);
    }

    // Read port
    while(true){
        fd = open("/sys/class/gpio/gpio89/value", O_RDONLY);
        read(fd, "0", 1);
        usleep(1000000);
        write(fd, "1", 1);
        close(fd);
 
    }

    // // Blink GPIO once
    // fd = open("/sys/class/gpio/gpio89/value", O_WRONLY | O_SYNC);
    // write(fd, "0", 1);
    // usleep(1000000);
    // write(fd, "1", 1);
    // close(fd);
 
    return EXIT_SUCCESS;
}