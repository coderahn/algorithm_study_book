#include <stdio.h>

//퀵소트 2번째 복습
void Swap(int* A, int* B) {
    int Temp = *A;
    *A = *B;
    *B = Temp;
}

int Partition(int DataSet[], int Left, int Right) {
    int First = Left;
    int Pivot = DataSet[First];

    Left++;

    while (Left < Right) {
        while(DataSet[Left] <= Pivot) {
            Left++;
        }

        while(DataSet[Right] > Pivot) {
            Right--;
        }

        if (Left < Right) {
            Swap(&DataSet[Left], &DataSet[Right]);
        }else {
            break;
        }
    }

    //Right가 Left보다 작아지는 시점. Right와 Pivot 위치 변경
    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}

void QuickSort(int DataSet[], int Left, int Right) {
    if (Left < Right) {
        int Index = Partition(DataSet, Left, Right);

        QuickSort(DataSet, Left, Index-1);
        QuickSort(DataSet, Index+1, Right);       
    }
}

int main(void) {
    int DataSet[] = {6,4,2,3,1,5};
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    QuickSort(DataSet, 0, Length-1);

    for(i = 0 ; i<Length; i++) {
        printf("%d ", DataSet[i]);
    }

    printf("\n");

    return 0;
}