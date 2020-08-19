#include <stdio.h>
int strlonger(char *s, char *t) {
    return strlen(s) > strlen(t);
}

int main(void)
{
    char s[] = "";
    char t[] = "abcdsdfsdfdsfd";
    printf("%d\n",strlen(s));
    printf("%d\n",strlen(t));
    int x = strlonger(s, t);
    printf("%d\n",x);
}
