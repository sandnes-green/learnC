#include <stdio.h>

float sum_elements(float a[], unsigned length)
{
    int i;
    float result = 0;
    if(length != 0){
    for(i = 0; i <= length-1; i++)
    {
        printf("%f\n", a[i]);
        result += a[i];

    }
    }
    return result;
}

int main(void)
{
    float x[] = {1,2,3};
    printf("%d\n", (int)x[0]);
    float y = sum_elements(x, 1);
    printf("%f", y);


    return 0;
}
