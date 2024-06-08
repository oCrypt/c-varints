#ifndef VARINT_H
#define VARINT_H

#define FALSE 0
#define TRUE 1

char* valloc(int i);
int decode(char* varintPointer);

#endif
