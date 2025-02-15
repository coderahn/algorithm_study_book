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
  //다음 노드에 추가하는 것
  //Head가 비어있는 경우와 안 비어있는 경우 있을듯

  if ((*Head) == NULL) {
    (*Head) = NewNode;
    (*Head)->NextNode = NULL;
  } else {
    //헤드의 NextNode가 없을때까지 while처리 후 넣기
    Node* CurrentNode = (*Head);

    while(CurrentNode->NextNode != NULL) {
        CurrentNode = CurrentNode->NextNode;
    }

    CurrentNode->NextNode = NewNode;
  }
}

//노드 삽입
void SLL_InsertAfter(Node* Current, Node* NewNode) {
    //Current의 nextNode를 newNode로 바꿔줘야 함.
    //newNode의 다음은 Current->nextNode
    
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

//헤드 삽입
void SLL_InsertNewHead(Node** Head, Node* NewHead) {
   //Head가 없을 경우는 Newhead가 헤드가 됨.
   //Head가 있을 경우는 Head 앞에 넣어야 함

    if ((*Head) == NULL) {
        (*Head) = NewHead;
    } else {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
} 

//노드 제거
void SLL_RemoveNode(Node** Head, Node* Remove) {
    //Remove할게 Head라면 Head다음을 Head로 만들면 끝
    //Remove를 Head에서 순환해서 찾은 후 제거해줘야

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

//노드 탐색
Node* SLL_GetNodeAt(Node* Head, int Location) { //Location은 0부터 시작
    //특정 위치의 노드 반환
    //Head를 순환하는데 Location만큼 돌기
    Node* CurrentNode = Head;

    for(int i=0; i<Location; i++) {
        CurrentNode = CurrentNode->NextNode;
    }

    return CurrentNode;
}

//노드 수 세기
int SLL_GetNodeCount(Node* Head) {
    //NextNode가 NULL일때까지 Count
    int Count = 0;
    Node* CurrentNode = Head;
    
    while(CurrentNode != NULL) {
        //CurrentNode가 1개라면 NextNode가 없음. 이걸 한번돌면 다음에는 안돌기에 Count는 1로 끝.
        CurrentNode = CurrentNode->NextNode;
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