#include "ArrayStack.h"

int main(void) {
    int i = 0;
    ArrayStack* Stack = NULL;

    AS_CreateStack(&Stack, 10);

    AS_Push(Stack, 3);
    AS_Push(Stack, 37);
    AS_Push(Stack, 11);
    AS_Push(Stack, 12);
    
    //Capacity: 10, Size: 4, Top: 12
    printf("Capacity: %d, Size: %d, Top: %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

    for(i=0; i<4; i++) {
        if(AS_IsEmpty(Stack)) {
            break;
        }

        //하나 pop으로 뺀걸 출력하고, 아직 스택 노드가 있으면 최상위 스택(AS_Top)을 출력
        printf("Popped: %d, ", AS_Pop(Stack));

        if (!AS_IsEmpty(Stack)) {
            printf("Current Top: %d\n", AS_Top(Stack));
        } else {
            printf("Stack Is Empty.\n");
        }
    }

    AS_DestroyStack(Stack);

    return 0;
}