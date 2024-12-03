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