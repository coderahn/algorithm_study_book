#include <stdio.h>
#include <string.h>

void InsertionSort(int DataSet[], int Length) {
    int i=0; 
    int j=0;
    int value = 0;

    //��������
    //i -> n-1��ŭ ó���ϴ� ���� ����
    //j -> max���� Ƚ���� �Ź� 1�� �þ
    //i�� 0�϶� j�� 2ȸ(0,1) for �ʿ�
    //i�� 1�϶� j�� 3ȸ(0,1,2) for �ʿ�
    //i+1��ŭ j�� ���ƾ��� 

    //ó�� i for������ ���ؼ� ���ų� �������� �� ũ�� �������� �Ѿ

    //�װ� �ƴϸ� ���� �ʿ�

    for (i=1; i<Length; i++) {
        if (DataSet[i-1] <= DataSet[i]) {
            continue;
        }

        value = DataSet[i];

        for (j=0; j<i; j++) {
            if (DataSet[j] > value) { //�񱳴�� ������ ū ��찡 ���� ���
                memmove(&DataSet[j+1], &DataSet[j], sizeof(DataSet[0]) * (i-j));
                // �迭�� �� ��Ҹ� �ϳ��� ���
                printf("i=%d, j=%d:", i, j);
                printf("DataSet: ");
                for (int k = 0; k < Length; k++) {
                    printf("%d ", DataSet[k]);
                }
                printf("\n");
                DataSet[j] = value;
                break;
            }
        }
    }
}


int main(void) {
    int DataSet[] = {6, 4, 2, 3, 1, 5};

    int Length = sizeof DataSet / sizeof DataSet[0];
    int i=0;

    InsertionSort(DataSet, Length);

    for (i=0; i<Length; i++) {
        printf("%d ", DataSet[i]);
    }

    printf("\n");

    return 0;
}