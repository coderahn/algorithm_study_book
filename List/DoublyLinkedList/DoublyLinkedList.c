#include "DoublyLinkedList.h"

//��� ����
Node* DLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

//��� �Ҹ�
void DLL_DestroyNode(Node* Node){
    free(Node);
}

//��� �߰�
void DLL_AppendNode(Node** Head, Node* NewNode){
    if ((*Head) == NULL) {
        *Head = NewNode;
    } else {
        Node* Tail = (*Head);

        while(Tail->NextNode != NULL) {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}

//��� ����(�ѹ� �� �غ���)
void DLL_InsertAfter(Node* Current, Node* NewNode) {
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if (Current->NextNode != NULL) {
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}

//��� ����