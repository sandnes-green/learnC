#include <stdio.h>
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX-1)
int add_ok(int x, int y)
{
    int sum = x + y;
    printf("%d\n", y < 0);
    printf("%d\n", x < 0);
    printf("sum=%d\n", sum);

    int neg_over = x < 0 && y < 0 && sum >= 0;//��������Ϊ����������ȴΪ������˵�������
    int pos_over = x >= 0 && y >= 0 && sum < 0;//��������Ϊ����������ȴΪ������˵�������
    printf("neg_over=%d\n", neg_over);
    printf("pos_over=%d\n", pos_over);
    return !neg_over && !pos_over;//��һ��ȡ����Ϊ0���ͻ᷵��0
}

int t_sub(int x, int y){
    return add_ok(x,-y);
}
int main()
{
    int x = -1;
    int y = INT_MIN;
  //  int y = 2;
    int z = t_sub(x,y);
    printf("y=%d\n", y);
    printf("-y=%d\n", -y);
    printf("-1-y=%d\n", -1-y);
    printf("-1+y=%d\n", -1+y);
    printf("1+y=%d\n", 1+y);
    printf("%d\n", z);
    return 0;
}
