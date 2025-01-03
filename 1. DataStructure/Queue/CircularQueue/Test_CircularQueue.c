#include "CircularQueue.h"

int main(void) {
    int i = 100;
    CircularQueue* Queue;

    CQ_CreateQueue(&Queue, 10);

    CQ_Enqueue(Queue, 1);
    CQ_Enqueue(Queue, 2);
    CQ_Enqueue(Queue, 3);
    CQ_Enqueue(Queue, 4);
    
    printf("Queue state1: ");
    for (int i = 0; i < Queue->Capacity+1; i++) {
        printf("[%d] ", Queue->Nodes[i].Data);
    }
    printf("\n");

    printf("Dequeue: %d, Front:%d, Rear:%d\n", CQ_Dequeue(Queue), Queue->Front, Queue->Rear);
    printf("Dequeue: %d, Front:%d, Rear:%d\n", CQ_Dequeue(Queue), Queue->Front, Queue->Rear);
    printf("Dequeue: %d, Front:%d, Rear:%d\n", CQ_Dequeue(Queue), Queue->Front, Queue->Rear);
    
    printf("Queue state2: ");
    for (int i = 0; i < Queue->Capacity+1; i++) {
        printf("[%d] ", Queue->Nodes[i].Data);
    }
    printf("\n");

    while(CQ_IsFull(Queue) == 0) {
        CQ_Enqueue(Queue, i++);
    }

    printf("Queue state3: ");
    for (int i = 0; i < Queue->Capacity+1; i++) {
        printf("[%d] ", Queue->Nodes[i].Data);
    }
    printf("\n");

    printf(" Capacity: %d, Size: %d\n\n", Queue->Capacity, CQ_GetSize(Queue));

    while(CQ_IsEmpty(Queue) == 0) {
        printf("Dequeue: %d, Front:%d, Rear:%d\n", CQ_Dequeue(Queue), Queue->Front, Queue->Rear);
    }
    CQ_DestroyQueue(Queue);

    return 0;
}