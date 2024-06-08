#include<stdio.h>
#include<stdlib.h>
#include "varint.h"

char* valloc(int i) {
    int size;
    int shifted = (unsigned int) i;
    while ((shifted = shifted >> 7) != 0) {
        size += 1;
    }

    char* varintPointer = malloc(size);
    
    int index = 0;
    while (TRUE) {
        char c = i & 0x7F;

        if ((i = i >> 7) == 0) {
            varintPointer[index] = c;
            break;
        }

        varintPointer[index] = c | ~0x7F;
        index++;
    }

    return varintPointer;
}

int decode(char* varintPointer) {
    int index = 0;
    int value = 0;
    while (TRUE) {
        char c = varintPointer[index];

        if ((c & ~0x7F) == 0) {
            value |= c << (index * 7);
            break;
        }

        value |= (c & 0x7F) << (index * 7);
        index++;
    }

    return value;
}
