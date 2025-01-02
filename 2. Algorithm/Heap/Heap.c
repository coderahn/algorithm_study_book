#include "Heap.h"

Heap* HEAP_Create(int InitialSize) {
    Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
    NewHeap->Capacity = InitialSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode) * NewHeap->Capacity);

    printf("size : %d\n", sizeof(HeapNode));

    return NewHeap;
}

void HEAP_Destroy(Heap* H) {
    free(H->Nodes);
    free(H);
}

//����
void HEAP_Insert(Heap* H, ElementType NewData) {
      int CurrentPosition = H->UsedSize; //�迭�� ���� �� ��
      int ParentPosition = HEAP_GetParent(CurrentPosition); //(CurrentPosition-1) / 2
      
      if (H->UsedSize == H->Capacity) {
        H->Capacity *= 2;
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
      }

      H->Nodes[CurrentPosition].Data = NewData;

      //�ļ�ó��
      while (CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data) {
            HEAP_SwapNodes(H, CurrentPosition, ParentPosition);

            CurrentPosition = ParentPosition;
            ParentPosition = HEAP_GetParent(CurrentPosition);
      }

      H->UsedSize++;
}

void HEAP_SwapNodes(Heap* H, int Index1, int Index2) {
    int CopySize = sizeof(HeapNode);
    HeapNode* Temp = (HeapNode*)malloc(CopySize);

    memcpy(Temp, &H->Nodes[Index1], CopySize);
    memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize);
    memcpy(&H->Nodes[Index2], Temp, CopySize);
    
    free(Temp);
}

void HEAP_DeleteMin(Heap* H, HeapNode* Root){
    //TODO..
}