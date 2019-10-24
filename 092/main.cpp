#include <iostream>
#include <vector>
#include <cstring>
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
    char k0[30] = "76481-640-8834005-23362";
    // char k0[] = "94940361391";
    printf("Please input your ProductID:\n");
    scanf("%s", k0);
    char k1[] = "ChinaCrackingGroup";
    char k2[] = "CrackingForFun";
    auto cipher = Blowfish(vector<char>(k0, k0 + strlen(k0)));
    unsigned char plaintext[] = "fishblow";
    cipher.EncryptBlock((uint32_t *)(plaintext + 4), (uint32_t *)(plaintext));

    printBlock(plaintext);

    cipher = Blowfish(vector<char>(k1, k1 + strlen(k1)));
    cipher.EncryptBlock((uint32_t *)(plaintext + 4), (uint32_t *)(plaintext));

    printBlock(plaintext);

    cipher = Blowfish(vector<char>(k2, k2 + strlen(k2)));
    cipher.EncryptBlock((uint32_t *)(plaintext + 4), (uint32_t *)(plaintext));

    printBlock(plaintext);

    printf("%#0x %#0x", *(uint32_t *)(plaintext + 4), *(uint32_t *)(plaintext));
    printf("\n");

    return 0;
}
