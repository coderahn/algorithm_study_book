#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack) {
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack) {
    while(Stack->List != NULL) {
        Node* Pop = LLS_Pop(Stack);
        LLS_DestroyNode(Pop);
    }

    free(Stack);
}

Node* LLS_CreateNode(char* NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    
    //문자열 복사
    NewNode->Data = (char*)malloc(strlen(NewData) + 1);
    strcpy(NewNode->Data, NewData);

    //NextNode 초기화
    NewNode->NextNode = NULL;

    return NewNode;
}

void LLS_DestroyNode(Node* _Node) {
    free(_Node->Data);
    free(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode) {
    if (Stack->List == NULL) {
        Stack->List = NewNode;
    } else {
        Node* OldTop = Stack->List;

        while(OldTop->NextNode != NULL) {
            OldTop = OldTop->NextNode;
        }

        OldTop->NextNode = NewNode;
    }

    Stack->Top= NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack) {
    Node* TopNode = Stack->Top;

    if (Stack->List == Stack->Top) {
        Stack->List = NULL;
        Stack->Top = NULL;
    } else {
        Node* CurrentTop = Stack->List;

        while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top) {
            CurrentTop = CurrentTop->NextNode;
        }
        CurrentTop->NextNode = NULL;
        Stack->Top = CurrentTop;
    }
    return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack) {
    return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack) {
    int Count = 0;
    Node* Current = Stack->List;

    while(Current != NULL) {
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}

int LLS_IsEmpty(LinkedListStack* Stack) {
    return Stack->List == NULL;
}