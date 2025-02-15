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
  //���� ��忡 �߰��ϴ� ��
  //Head�� ����ִ� ���� �� ����ִ� ��� ������

  if ((*Head) == NULL) {
    (*Head) = NewNode;
    (*Head)->NextNode = NULL;
  } else {
    //����� NextNode�� ���������� whileó�� �� �ֱ�
    Node* CurrentNode = (*Head);

    while(CurrentNode->NextNode != NULL) {
        CurrentNode = CurrentNode->NextNode;
    }

    CurrentNode->NextNode = NewNode;
  }
}

//��� ����
void SLL_InsertAfter(Node* Current, Node* NewNode) {
    //Current�� nextNode�� newNode�� �ٲ���� ��.
    //newNode�� ������ Current->nextNode
    
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

//��� ����
void SLL_InsertNewHead(Node** Head, Node* NewHead) {
   //Head�� ���� ���� Newhead�� ��尡 ��.
   //Head�� ���� ���� Head �տ� �־�� ��

    if ((*Head) == NULL) {
        (*Head) = NewHead;
    } else {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
} 

//��� ����
void SLL_RemoveNode(Node** Head, Node* Remove) {
    //Remove�Ұ� Head��� Head������ Head�� ����� ��
    //Remove�� Head���� ��ȯ�ؼ� ã�� �� ���������

    if ((*Head) == Remove) {
        (*Head) = (*Head)->NextNode;
    } else {
        Node* CurrentNode = (*Head);

        while(CurrentNode->NextNode != NULL) {
            if (CurrentNode->NextNode == Remove) {
                CurrentNode->NextNode = Remove->NextNode;
                free(Remove);
                break;
            } else {
                CurrentNode = CurrentNode->NextNode;
            }
        }
    }
}

//��� Ž��
Node* SLL_GetNodeAt(Node* Head, int Location) { //Location�� 0���� ����
    //Ư�� ��ġ�� ��� ��ȯ
    //Head�� ��ȯ�ϴµ� Location��ŭ ����
    Node* CurrentNode = Head;

    for(int i=0; i<Location; i++) {
        CurrentNode = CurrentNode->NextNode;
    }

    return CurrentNode;
}

//��� �� ����
int SLL_GetNodeCount(Node* Head) {
    //NextNode�� NULL�϶����� Count
    int Count = 0;
    Node* CurrentNode = Head;
    
    while(CurrentNode != NULL) {
        //CurrentNode�� 1����� NextNode�� ����. �̰� �ѹ����� �������� �ȵ��⿡ Count�� 1�� ��.
        CurrentNode = CurrentNode->NextNode;
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