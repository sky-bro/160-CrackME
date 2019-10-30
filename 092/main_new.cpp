#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint> // 包含这个, 使用uint64_t, uint32_t的更好
#include "blowfish.h"

using namespace std;

void printBlock(unsigned char *plaintext)
{
    for (int i = 0; i < 8; ++i)
    {
        printf("%02X ", *(plaintext + i));
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    unsigned char plaintext[] = "fishblow";
    printf("Please input your Computer ID:\n");
    *(uint64_t*)(plaintext) = 0x173B565A8A0E6E53;
    // 这里用lX可能会出错，表示unsigned long，linux 64位下，long为64bit，windows下32bit
    // scanf("%08lX%08lX", (unsigned long *)(plaintext+4), (unsigned long*)(plaintext));

    // 64bit (g++ -m64) 下可以这样
    // scanf("%016lX", (unsigned long *)(plaintext));

    // 更好的方式是
    // scanf("%08X%08X", (unsigned int*)(plaintext+4), (unsigned int*)(plaintext));
    scanf("%016llX", (uint64_t*)(plaintext));

    char k1[] = "ChinaCrackingGroup";
    char k2[] = "CrackingForFun";

    printBlock(plaintext);

    auto cipher = Blowfish(vector<char>(k1, k1 + strlen(k1)));
    cipher.EncryptBlock((uint32_t *)(plaintext + 4), (uint32_t *)(plaintext));

    printBlock(plaintext);

    cipher = Blowfish(vector<char>(k2, k2 + strlen(k2)));
    cipher.EncryptBlock((uint32_t *)(plaintext + 4), (uint32_t *)(plaintext));

    printBlock(plaintext);

    printf("%016llX", *(uint64_t *)(plaintext));
    printf("\n");

    return 0;
}
