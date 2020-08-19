#include <stdio.h>
#include <ctype.h>
#include <limits.h>
void strdump(const char *s)
{
    while(* s) {
        int i;
        unsigned char x = (unsigned char)* s;
        printf("%c ", isprint(x) ? x : ' ');
        printf("%0*X ", (CHAR_BIT + 3) / 4, x);
        for(i = CHAR_BIT - 1; i >= 0; i--){
            putchar(((x >> i) & 1U) ? '1' : '0');
        }
        putchar('\n');
        s++;
    }
}

int main(void) {
    puts("����");            strdump("����");            putchar('\n');
    puts("12�й���AB");      strdump("12�й���AB");      putchar('\n');
    return 0;
}