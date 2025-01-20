#include "LinkedList.h"

//노드 생성
Node* SLL_CreateNode(ElementType NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}

//노드 소멸
void SLL_DestroyNode(Node* Node) {
    free(Node);
}

//노드 추가
void SLL_AppendNode(Node** Head, Node* NewNode) {
    if ((*Head) == NULL) {
        (*Head) = NewNode;
    } else {
        Node* Tail = (*Head);

        while (Tail->NextNode != NULL) {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
    }
}

//노드 삽입
void SLL_InsertAfter(Node* Current, Node* NewNode) {
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

//헤드 삽입
void SLL_InsertNewHead(Node** Head, Node* NewHead) {
    if (Head == NULL) {
        (*Head) = NewHead;
    } else {        
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
} 

//노드 제거
void SLL_RemoveNode(Node** Head, Node* Remove) {
    if ((*Head) == Remove) {
        (*Head) = Remove->NextNode;
    } else {
        Node* Current = (*Head);

        while (Current != NULL && Current->NextNode != Remove) {
            Current = Current->NextNode;
        } 

        if (Current != NULL) {
            Current->NextNode = Remove->NextNode;
        }
    }
}

//노드 탐색
Node* SLL_GetNodeAt(Node* Head, int Location) { //Location은 0부터 시작
    Node* Current = Head;

    while (Current != NULL && --Location >= 0){
        Current = Current->NextNode;
    }

    return Current;
}

//노드 수 세기
int SLL_GetNodeCount(Node* Head) {
    int Count = 0;
    Node* Current = Head;

    while (Current != NULL) {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

//알고리즘(순차탐색-전진이동법)
Node* SLL_MoveToFront(Node** Head, int Target) {
    Node* Current = (*Head);
    Node* Previous = NULL;
    Node* Match = NULL;

    while(Current != NULL) {
        if (Current->Data == Target) {
            Match = Current;

            if (Previous != NULL) {
                //이전노드와 현재노드의 다음노드 연결
                Previous->NextNode = Current->NextNode;

                //현재노드를 맨 앞으로(전진이동)
                Current->NextNode = (*Head);
                (*Head) = Current;
            }
            break;
        } else {
            Previous = Current;
            Current = Current->NextNode;
        }
    } 

    return Match;
}

//알고리즘(순차탐색-전위법)
Node* SLL_Transpose(Node** Head, int Target) {
    Node* Current = (*Head);
    Node* PPrevious = NULL;
    Node* Previous = NULL;
    Node* Match = NULL;

    while (Current != NULL) {
        if (Current->Data == Target) {
            Match = Current;
            if (Previous != NULL) {
                if (PPrevious != NULL) {
                    PPrevious->NextNode = Current;
                } else {
                    (*Head) = Current;
                }

                Previous->NextNode = Current->NextNode;
                Current->NextNode = Previous;
            }
            break;
        }
        else {
            //현재값, 이전값, 이전의 이전값을 들고다녀야 교환시 연결 가능
            if (Previous != NULL) {
                PPrevious = Previous;
            }
            
            Previous = Current;
            Current = Current->NextNode;
        }
    }
    return Match;
}