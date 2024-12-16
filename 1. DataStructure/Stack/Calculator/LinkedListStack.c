#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack) {
    //스택을 자유저장소에 생성
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL; 
}

void LLS_DestroyStack(LinkedListStack* Stack) {
    while(!LLS_IsEmpty(Stack)) {
        Node* Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }

    free(Stack);
}

Node* LLS_CreateNode(char* NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    //NewNode->Data = NewData; //NewData가 복사되어, NewData값 변경시 NewNode->Data가 변경될 가능성?
    NewNode->Data = (char*)malloc(strlen(NewData)); //strlen: NULL문자(\0)까지 문자열 개수

    strcpy(NewNode->Data, NewData); //NewData를 NewNode->Data에 저장
    
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
        //최상위 노드를 찾아 NewNode를 연결(쌓기)
        Node* OldTop = Stack->List;
        while(OldTop->NextNode != NULL) {
            OldTop = OldTop->NextNode;
        }

        OldTop->NextNode = NewNode;
    }

    Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack) {
    //LLS_Pop() 함수가 반환할 최상위 노드
    Node* TopNode = Stack->Top;

    if (Stack->List == Stack->Top) {
        Stack->List = NULL;
        Stack->Top = NULL;
    } else {
        //Pop할 노드 이전 노드를 찾아서 Top 연결!
        Node* CurrentTop = Stack->List;

        while(CurrentTop != NULL && CurrentTop->NextNode != Stack->Top) {
            CurrentTop = CurrentTop->NextNode;
        }

        Stack->Top = CurrentTop;
        CurrentTop->NextNode = NULL;
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
    return (Stack->List == NULL);
}