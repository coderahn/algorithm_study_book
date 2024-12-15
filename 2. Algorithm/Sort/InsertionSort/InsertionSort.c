#include <stdio.h>
#include <string.h>

void InsertionSort(int DataSet[], int Length) {
    //먼저 타겟을 비교대상(앞)과 비교했을때 타겟이 더 크면 굳이 옮길 필요 없음

    int i=0;
    int j=0;
    int value = 0;

    for (i=1; i<Length; i++) {
        if (DataSet[i-1] <= DataSet[i]) {
            continue;
        }
        value = DataSet[i]; //타겟값

        for (j=0; j<i; j++) {
            if (DataSet[j] > value) {
                //출발지(두번째 변수)에서 목적지(첫번째 변수)로 사이즈만큼 값 복사(이후 j인덱스 위치에 value를 삽입)
                memmove(&DataSet[j+1], &DataSet[j], sizeof(DataSet[0])*(i-j));
                DataSet[j] = value;
                break;
            }
        }
    }
}

int main(void) {
    int DataSet[] = {6,4,2,3,1,5};
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i =0;

    InsertionSort(DataSet, Length);

    for (i=0; i<Length; i++) {
        printf("%d ", DataSet[i]);
    }

    printf("\n");

    return 0;
}