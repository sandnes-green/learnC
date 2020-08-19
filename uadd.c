#include <stdio.h>
#include <stdbool.h>
int uadd_ok(unsigned x, unsigned y)
{
    unsigned z = x + y;
    printf("%u\n",z);
    return z >= x;
}

int main()
{
    unsigned x = 4294967295;
    unsigned y = 1000;
    int z = uadd_ok(x,y);
    printf("%d\n", z);
    return 0;
}
