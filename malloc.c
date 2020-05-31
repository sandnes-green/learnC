#include <stdio.h>
#include <malloc.h>
int main() {
	int a[5] = { 4,10,2,8,6 };
	int len;
	printf("请输入你需要分配的数组长度:len=");
	scanf("%d",&len);
	int* pArr = (int *)malloc(sizeof(int) * len);
	printf("%p\n", a);
	printf("%p\n", pArr);
	for(int i = 0; i<len; ++i) {
     scanf("%d", &pArr[i]);
	}

	for(int i = 0; i<len; ++i) {
        printf("%d\n", *(pArr+i));
	}
	free(pArr);
	printf("%d\n", *a);
	return 0;
}
