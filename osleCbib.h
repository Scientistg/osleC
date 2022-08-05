// +---------------------------------------------+
// |    Creation Date:  2022-08-05T15:33         |
// |                                             |
// |    Authors: Gabriel Araujo                  |
// |             Estevao Calera                  |
// |                                             |
// +---------------------------------------------+

#ifndef OSLECBIB_H
#define OSLECBIB_H

extern bool jogoTerminou;
extern int fd;
extern char path0[];
extern char path1[];
extern char path2[];
extern char path3[];
extern char buffer[];
extern char ports[][];

void writePort(char *port, char *value);
bool readPort(char *port);
void escritaLed(int ledNum, char *value);
void resetGame();

#endif
