#include <stdio.h>

unsigned long pack_to_ulong(unsigned char a, unsigned char b, unsigned short c, unsigned int d)
{
    return ((unsigned long)a << 7*8) + ((unsigned long)b << 6*8) + ((unsigned long)c << 4*8) + d;
}

void unpack_ulong(unsigned long l, unsigned char *a, unsigned char *b, unsigned short *c, unsigned int *d)
{
    *d = l & 0xFFFFFFFF; // (unsigned int)l;
    *c = (l >> 4*8) & 0xFFFF;
    *b = (l >> 6*8) & 0xFF;
    *a = (l >> 7*8) & 0xFF;
}

int main()
{
    unsigned char a, b;
    unsigned short c;
    unsigned int d;
    unsigned long l;

    l = pack_to_ulong(12, 156, 47123, 123456);
    printf("ul = %lu\n", l);
    unpack_ulong(l, &a, &b, &c, &d);
    printf("a = %hhu, b = %hhu, c = %hu, d = %u\n", a, b, c, d);
}
