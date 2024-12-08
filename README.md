# algorithm_study_book

This repository contains my learnings from the book '뇌를 자극하는 알고리즘'. All content in this repository is for educational purposes only. The book is copyrighted, and all rights to the original content are reserved by the author and publisher.

## 1부.자료구조
### 1)링크드 리스트(Linked List)
  - 노드가 다음 노드의 주소를 갖고 있음
  - 배열에 비해 삽입, 삭제가 빠름
  - 특정 위치에 있는 노드를 찾는 연산은 느림

### 2)더블 링크드 리스트(Doubly Linked List)
  - 링크드 리스트와 비슷한 구조지만 이전 노드 주소를 갖고 있음
  - 양방향 탐색이 가능해서 좀 더 검색속도가 향상됨
  - 추가적인 메모리가 필요(prev, next 두 개의 포인터)

### 3)환형 링크드 리스트
  - 더블 링크드 리스트와 비슷하지만 Head와 Tail이 연결된 구조
  - 꼬리를 무는 용을 생각(Head->PrevNode == Tail, Tail->NextNode == Head)

### 4)스택
  - LIFO구조
  - 배열로 만드는 스택, 링크드리스트로 만드는 스택이 있음
  - 자동메모리도 스택 구현(변수 선언 후 자동 해제해주는 알고리즘)

  - (1)배열 스택
    - 스택 구조체에 Capacity(용량) 필요
    - 크기를 자동으로 늘려주지 못하며 용량 선언한 만큼의 스택 사용

  - (2)링크드리스트 스택
    - 크기를 자유롭게 늘릴 수 있음(Capacity 불필요)
    - 스택 구조체에 List(헤드), Top(테일)만 필요
      - cf)Tail이 없어도 List->NextNode로 찾아갈 수 있으나 성능 이슈로 Top이 있어야 함

### 5)큐
  - FIFO구조
  - 선입선출
  - push->enqueue, pop->dequeue
  - 배열로 처리하는 순환큐
    - 시작과 끝을 연결하는 큐
    - 전단(Front), 후단(Rear) 포인터가 필요함
    - 후단과 전단이 같으면 비어있는 것을 의미
    - 후단이 전단보다 1 작으면 FULL 상태 의미
    - 그래서 후단은 실제 후단보다 1큼
  - 링크드 리스트를 이용하는 링크드 큐
    - 순환큐보다 직관적이고 쉬움
    - 성능적으로는 순환큐가 더 좋다고 함(링크드큐는 노드 생성, 삭제시 malloc호출
      - cf)Queue->Rear->NextNode = NewNode; //내부적으로 malloc등 호출하여 동적 메모리 할당

### 6)트리
  - 나무를 닮은 자료구조
  - 운영체제의 파일 시스템, 데이터 베이스 트리 자료구조(B*Tree 등) 
  - 뿌리(Root), 가지(Branch), 잎(Left) 3가지 요소로 이루어짐
  - 차수(Degree): 트리 내 노드들 가운데 자식 노드가 가장 많은 노드의 차수
  - 트리표현: 중첩된 괄호, 중첩된 집합, 들여쓰기(윈도우 탐색기) 
  - 노드 표현하기
    - N-링크 표현법: 노드의 차수가 N이면 N개 링크를 가지고 있어서 이 링크들이 각각 자식 노드를 가리키도록 구성하는 방법
    - 왼쪽 자식-오른쪽 형제(LCRS) 표현법: 왼쪽에는 자식, 오른쪽에는 형제 포인터 갖는 노드 구조
      - cf)부모의 모든 자식은 한 줄로 연결된 형제 관계 유지. 부모는 항상 첫번째 자식(LeftChild)만 알고 있으며 나머지 자식들은 첫번째 자식의 오른쪽형제(RightSibling) 체인을 통해 연결.

  - 이진트리(Binary Tree)
    - 하나의 노드가 최대 2개의 자식 노드를 가짐
    - 탐색방식에 따라 전위순회, 중위순회, 후위순회
    - 검색엔진,인덱스 등 다양하게 활용
    - 재귀함수로 구현

  - 수식트리(Expression Tree)
    - 연산자, 피연산자로 만든 트리
    - 연산자는 루트 노트 또는 가지 노드이다.
    - 후위표기식을 기반으로 만드는 트리
      - 후위표기식 뒤에서부터 토큰을 읽어나가면서 계산

## 2부.알고리즘

---

## 기타정리(TIL)

### 241208(일)
* memset: 메모리 블록을 특정 값으로 초기화

```c
// C 언어 코드 예시
#include <stdio.h>

int main() {
    //트리구조체 선언되어있다고 가정(Tree->Data = 2)
    
    char Temp[2];

    memset(Temp, 0, sizeof(Temp)); //Temp에 0으로 값 초기화
    Temp[0] = Tree->Data; //Temp[0]에 값 세팅, Temp[1]은 '\0'으로 문자열 종료 문자
}
```

* visual studio code(vscode) pull 오류

- 저번에 다른 컴퓨터로 readme를 github에서 수정
- vscode에서 pull 받으려는데 오류
    - 로컬,리모트 서로 다른 커밋을 갖고 있기 때문
- ```shell git config pull.rebase false  # 병합 방식 사용 ```
- 다시 pull하면 처리 완료
- 충돌난 부분 수정 해야함
    - Accept Incomming Change, Accept Current Change있는데 전자 누르면 원격꺼 덮어쓸 수 있음