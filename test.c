#include <stdio.h>
#include <string.h>


#define MAX 100


int main(int argc, char *argv[]){
    int fd;
    char ports[5][3] = {"73","75","77","88","89"};
    char path1[] = "/sys/class/gpio/gpio";
    char path2[] = "/direction";
    char buffer[MAX];

    int i;
    for(i = 0; i < 5; i++){
        strcat(strcpy(buffer, path1), ports[i]);
        strcat(strcpy(buffer, buffer), path2);
        printf("%s\n", buffer);
    }

}

