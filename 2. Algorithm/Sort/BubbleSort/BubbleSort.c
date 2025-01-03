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


    //배열은 포인터로 안넘겨도 매개변수가 배열의 첫번째 요소를 포인터로 처리
    BubbleSort(DataSet, Length);

    for(i=0; i<Length; i++) {
        printf("%d ", DataSet[i]); //정렬 후 데이터 집합 출력
    }

    printf("\n");

    return 0;
}