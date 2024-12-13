#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue** Queue) {
    (*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Count = 0;
}

void LQ_DestroyQueue(LinkedQueue* Queue) {
    while(!LQ_IsEmpty(Queue)) {
        Node* Popped = LQ_Dequeue(Queue);
        LQ_DestroyNode(Popped);
    }

    free(Queue);
}

Node* LQ_CreateNode(char* NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));

    //C언어에서 문자열은 배열이기 때문에 아래(주석)처럼 하면 단순 문자복사가 되어 참조가 공유되어 문제 발생
    //NewNode->Data = NewData;

    NewNode->Data = (char*)malloc(strlen(NewData) + 1);

    //데이터 저장
    strcpy(NewNode->Data, NewData); 

    NewNode->NextNode = NULL;

    return NewNode;
}

void LQ_DestroyNode(Node* _Node) {
    free(_Node->Data);
    free(_Node);
}

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode) {
    if (Queue->Front == NULL){
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    } else {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
}

Node* LQ_Dequeue(LinkedQueue* Queue){
    //LQ_Dequeue() 함수가 반환할 최상위 노드
    Node* Front = Queue->Front;

    if (Queue->Front->NextNode == NULL){
        Queue->Front = NULL;
        Queue->Rear = NULL;
    } else {
        Queue->Front = Queue->Front->NextNode;
    }

    Queue->Count--;

    return Front;
}

int LQ_IsEmpty(LinkedQueue* Queue) {
    return (Queue->Front == NULL);
}