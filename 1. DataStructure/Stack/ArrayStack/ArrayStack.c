#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity){
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
}

void AS_DestroyStack(ArrayStack* Stack) {
    free(Stack->Nodes);
    free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data) {
    Stack->Nodes[Stack->Top].Data = Data;
    Stack->Top++;
}

ElementType AS_Pop(ArrayStack* Stack) {
    return Stack->Nodes[--Stack->Top].Data;
}

ElementType AS_Top(ArrayStack* Stack) {
    return Stack->Nodes[(Stack->Top)-1].Data;
}

int AS_GetSize(ArrayStack* Stack) {
    return Stack->Top;
}

int AS_IsEmpty(ArrayStack* Stack) {
    return Stack->Top == 0;
}

int AS_IsFull(ArrayStack* Stack) {
    return Stack->Top == Stack->Capacity;
}