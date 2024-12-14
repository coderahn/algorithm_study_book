#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack) {
    //스택을 자유저장소에 저장
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack) {
    while (!LLS_IsEmpty(Stack)) {
        Node* Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }

    free(Stack);
}

Node* LLS_CreateNode(char* NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = (char*)malloc(strlen(NewData) + 1); //문자열 끝을 나타내기 위해 항상 \0저장하기 때문에 +1
    
    //Data가 포인터기 때문에 그냥 =로 넣으면 같은 메모리 참조로 NewData값 변경시 Data도 변경 위험
    strcpy(NewNode->Data, NewData);

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

        //헤드부터 올라가서 Top까지 찾아가며, 다음 노드가 Top이면, 멈춘다.(Top의 이전 노드까지만)
        while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top) {
            CurrentTop = CurrentTop->NextNode;
        }

        Stack->Top = CurrentTop;
        CurrentTop->NextNode = NULL; //Pop한 Top의 주소를 제거하기 위함
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