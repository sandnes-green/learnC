/**
*   判断本机是大端还是小端
**/
#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for(i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;
    show_bytes((byte_pointer)&val, sizeof(int));
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main()
{
    int val = 0x87654321;
    test_show_bytes(val);
    const char s[] = "abcdef";
    show_bytes((byte_pointer)&s,strlen(s));
    short x = 12345;
    show_bytes((byte_pointer) &x, sizeof(short));
    short mx = -x;
    show_bytes((byte_pointer) &mx, sizeof(short));
    return 0;
}
