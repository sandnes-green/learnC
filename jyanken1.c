#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int human;
    int comp;
    int judge;
    int retry;

    srand(time(NULL));
    printf("��ȭ��Ϸ��ʼ��\n");
    do{
        comp = rand() % 3;
        printf("\n\aʯͷ������...(0)ʯͷ (1)���� (2)��");
        scanf("%d", &human);
        printf("�ҳ�");
        switch(human) {
            case 0: printf("ʯͷ");break;
            case 1: printf("����");break;
            case 2: printf("��");break;
        }
        printf(".\n");
        judge = (human - comp + 3) % 3;
        switch(judge) {
            case 0: printf("ƽ��.");break;
            case 1: printf("������.");break;
            case 2: printf("��Ӯ��.");break;
        }
        printf("����һ����...(0)��(1)��\n");
        scanf("%d", &retry);
    }while(retry == 1);
    return 0;
}
