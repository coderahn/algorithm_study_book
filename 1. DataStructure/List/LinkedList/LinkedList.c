#include "LinkedList.h"

//��� ����
Node* SLL_CreateNode(ElementType NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}

//��� �Ҹ�
void SLL_DestroyNode(Node* Node) {
    free(Node);
}

//��� �߰�
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

//��� ����
void SLL_InsertAfter(Node* Current, Node* NewNode) {
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

//��� ����
void SLL_InsertNewHead(Node** Head, Node* NewHead) {
    if (Head == NULL) {
        (*Head) = NewHead;
    } else {        
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
} 

//��� ����
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

//��� Ž��
Node* SLL_GetNodeAt(Node* Head, int Location) { //Location�� 0���� ����
    Node* Current = Head;

    while (Current != NULL && --Location >= 0){
        Current = Current->NextNode;
    }

    return Current;
}

//��� �� ����
int SLL_GetNodeCount(Node* Head) {
    int Count = 0;
    Node* Current = Head;

    while (Current != NULL) {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

//�˰���(����Ž��-�����̵���)
Node* SLL_MoveToFront(Node** Head, int Target) {
    Node* Current = (*Head);
    Node* Previous = NULL;
    Node* Match = NULL;

    while(Current != NULL) {
        if (Current->Data == Target) {
            Match = Current;

            if (Previous != NULL) {
                //�������� �������� ������� ����
                Previous->NextNode = Current->NextNode;

                //�����带 �� ������(�����̵�)
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

//�˰���(����Ž��-������)
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
            //���簪, ������, ������ �������� ���ٳ�� ��ȯ�� ���� ����
            if (Previous != NULL) {
                PPrevious = Previous;
            }
            
            Previous = Current;
            Current = Current->NextNode;
        }
    }
    return Match;
}