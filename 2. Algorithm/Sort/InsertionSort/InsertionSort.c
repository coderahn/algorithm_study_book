#include <stdio.h>
#include <string.h>

void InsertionSort(int DataSet[], int Length) {
    int i=0; 
    int j=0;
    int value = 0;

    //삽입정렬
    //i -> n-1만큼 처리하는 것은 맞음
    //j -> max까지 횟수가 매번 1씩 늘어남
    //i가 0일때 j는 2회(0,1) for 필요
    //i가 1일때 j는 3회(0,1,2) for 필요
    //i+1만큼 j가 돌아야함 

    //처음 i for문에서 비교해서 같거나 오른쪽이 더 크면 다음으로 넘어감

    //그게 아니면 변경 필요

    for (i=1; i<Length; i++) {
        if (DataSet[i-1] <= DataSet[i]) {
            continue;
        }

        value = DataSet[i];

        for (j=0; j<i; j++) {
            if (DataSet[j] > value) { //비교대상 끝보다 큰 경우가 있을 경우
                memmove(&DataSet[j+1], &DataSet[j], sizeof(DataSet[0]) * (i-j));
                // 배열의 각 요소를 하나씩 출력
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