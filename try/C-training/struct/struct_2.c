#include <stdio.h>

//共用体（联合体） -- 共享同一片存储区

union register{
    struct{
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    }bytes;
    unsigned int number
};