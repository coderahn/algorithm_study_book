#include <stdio.h>

void BubbleSort(int DataSet[], int Length){ // 5
    int i=0; 
    int j=0; 
    int temp =0;
    int passCount = 0;

    for (i=0; i<Length-1; i++) { 
        passCount=0;

        for(j=0; j<Length-(i+1); j++) {
            if (DataSet[j] > DataSet[j+1]) {
                printf("%d\n", i);
                temp = DataSet[j+1];
                DataSet[j+1] = DataSet[j];
                DataSet[j] = temp;
            } else {
                passCount++;
            }
        }

        if (passCount == (Length-(i+1))) {
            break;
        }
    }
}

int main(void) {
    int DataSet[] = {2,1,3,4,5,6};
    int Length = sizeof DataSet/ sizeof DataSet[0];
    int i=0;


    //�迭�� �����ͷ� �ȳѰܵ� �Ű������� �迭�� ù��° ��Ҹ� �����ͷ� ó��
    BubbleSort(DataSet, Length);

    for(i=0; i<Length; i++) {
        printf("%d ", DataSet[i]); //���� �� ������ ���� ���
    }

    printf("\n");

    return 0;
}