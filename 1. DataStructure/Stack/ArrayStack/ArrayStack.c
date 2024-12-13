#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity){
    //스택 자유저장소 할당
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

    //노드 자유저장소 할당(Capacity만큼)
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);

    //Capacity, Top 초기화
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
}

void AS_DestroyStack(ArrayStack* Stack) {
    free(Stack->Nodes);
    free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data) {
    int Position = Stack->Top;

    Stack->Nodes[Position].Data = Data;
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

int AS_IsFull(ArrayStack* Stack) {
    //capacity 3이면 3개만 들어갈 수 있음. Top이 3이면 1,2,3 이면 3개 들어간 것. 여기서 풀
    return Stack->Capacity == Stack->Top;
}