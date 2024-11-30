#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity) {
    //Stack을 자유저장소에 생성
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack)); 

    //입력된 Capacity만큼 노드를 자유저장소에 생성(Nodes는 자유저장소에 생성한 배열의 첫번째 요소를 가리킴)
    (*Stack)->Nodes = (Node*)malloc(sizeof(sizeof(Node)*Capacity));

    //Capacity 및 Top 초기화
    (*Stack)->Top = 0;
    (*Stack)->Capacity = Capacity;
}

void AS_DestroyStack(ArrayStack* Stack) {
    free(Stack->Nodes);
    free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data) {
    int Position = Stack->Top;
    (Stack->Nodes[Position]).Data = Data;

    Stack->Top++;
}

ElementType AS_Pop(ArrayStack* Stack) {
    int Position = --(Stack->Top);

    return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack) {
    int Position = Stack->Top - 1;

    return Stack->Nodes[Position].Data;
}

int AS_GetSize(ArrayStack* Stack) {
    return Stack->Top;
}

int AS_IsEmpty(ArrayStack* Stack) {
    return (Stack->Top == 0);
}

//스택 생성시 정한 용량이 가득차있는지 체크
int AS_IsFull(ArrayStack* Stack) {
    //Stack->Top-1 > Capacity면?? 가득차다
    return Stack->Top >= Stack->Capacity;
}

