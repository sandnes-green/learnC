#include <stdio.h>
void make4digits(int x[])
{
    int i,j,val;
    for(i=0;i<4;i++) {
        do{
            val = rand()%10;
            for(j=0;j<i;j++) {
                if(val == x[j]){
                    break;
                }
            }
        }while(j<i);
        x[i] = val;
    }
}

int main(void) {
    int x[4];
    int i;
    make4digits(x);
    for(i = 0; i<4; i++) {
        printf("%d\n",x[i]);
    }
    return 0;
}
