#include <stdio.h>

void Swap(int* A, int* B){
    int Temp = *A;
    *A = *B;
    *B = Temp;
}

int Partition(int DataSet[], int Left, int Right) {
    int First = Left;
    int Pivot = DataSet[First];

    Left++;

    while (Left < Right) {
        while(Pivot >= DataSet[Left]) {
            Left++;
        }

        while(Pivot < DataSet[Right]) {
            Right--;
        }

        if (Left < Right) {
            Swap(&DataSet[Left], &DataSet[Right]);
        } else {
            break;
        }
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}

void QuickSort(int DataSet[], int Left, int Right) {
    if(Left < Right) {
        int index = Partition(DataSet, Left, Right);

        QuickSort(DataSet, Left, index-1);
        QuickSort(DataSet, index+1, Right);
    }
}

int main(void) {
    int DataSet[] = {6,4,2,3,1,5};
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    QuickSort(DataSet, 0, Length-1);

    for (i=0; i < Length; i++) {
        printf("%d ", DataSet[i]);
    }

    printf("\n");

    return 0;
}