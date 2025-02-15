#include "DoublyLinkedList.h"

//노드 생성
Node* DLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

//노드 소멸
void DLL_DestroyNode(Node* Node){
    free(Node);
}

//노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode){
    //Head가 비어있을 때 Head에 추가
    //Head가 비어있지 않을 때 while로 순환 후 넣기
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

//노드 삽입(한번 더 해보기)
void DLL_InsertAfter(Node* Current, Node* NewNode) {
    //현재 Current 순환 후, NewNode붙이기
    //Current가 NULL일수도 있음. 이때는 NewNode를 Current로
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

//노드 제거
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

//노드 탐색
Node* DLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;

    while(Current != NULL && --Location >= 0) {
        Current = Current->NextNode;
    }

    return Current;
}

//노드 수 세기
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