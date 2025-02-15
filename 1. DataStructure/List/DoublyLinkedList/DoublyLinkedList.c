#include "DoublyLinkedList.h"

//��� ����
Node* DLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

//��� �Ҹ�
void DLL_DestroyNode(Node* Node){
    free(Node);
}

//��� �߰�
void DLL_AppendNode(Node** Head, Node* NewNode){
    //Head�� ������� �� Head�� �߰�
    //Head�� ������� ���� �� while�� ��ȯ �� �ֱ�
    if ((*Head) == NULL) {
        (*Head) = NewNode;
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
    //���� Current ��ȯ ��, NewNode���̱�
    //Current�� NULL�ϼ��� ����. �̶��� NewNode�� Current��
    if (Current == NULL) {
        Current = NewNode;
    } else {
        NewNode->NextNode = Current->NextNode;

        if (Current->NextNode != NULL){
            Current->NextNode->PrevNode = NewNode;
        }
        
        NewNode->PrevNode = Current;
        Current->NextNode = NewNode;
    }
}

//��� ����
void DLL_RemoveNode(Node** Head, Node* Remove) {
    if ((*Head) == Remove) {
        (*Head) = Remove->NextNode;

        if ((*Head) != NULL) {
            (*Head)->PrevNode = NULL;
        }

        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    } else {
        Node* Current = (*Head);

        while(Current->NextNode != NULL) {
            if (Current->NextNode == Remove) {
                Current->NextNode = Remove->NextNode;

                if (Remove->NextNode != NULL) {
                    Remove->NextNode->PrevNode = Current;
                }
                
                break;
            } 
            
            Current = Current->NextNode;
        }

        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }
}

//��� Ž��
Node* DLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;

    while(Current != NULL && --Location >= 0) {
        Current = Current->NextNode;
    }

    return Current;
}

//��� �� ����
int DLL_GetNodeCount(Node* Head) {
    int Count = 0;

    while(Head != NULL) {
        Head = Head->NextNode;
        Count++;
    }    

    return Count;
}

void PrintNode(Node* _Node) {
    if (_Node->PrevNode == NULL) {
        printf("Prev: NULL");
    } else {
        printf("Prev: %d", _Node->PrevNode->Data);
    }

    printf(" Current: %d", _Node->Data);

    if (_Node->NextNode == NULL) {
        printf("Next: NULL\n");
    } else {
        printf("Next: %d\n", _Node->NextNode->Data);
    }
}