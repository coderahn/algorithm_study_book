#include "ArrayStack.h"

int main(void) {
    int i = 0;
    ArrayStack* Stack = NULL;

    AS_CreateStack(&Stack, 4);

    AS_Push(Stack, 3);
    AS_Push(Stack, 37);
    AS_Push(Stack, 11);
    
    //����á���� ���� üũ
    if (AS_IsFull(Stack)) {
        printf("full: %d\n", 1);
    } else {
        printf("not full: %d\n", 0);
    }

    //�⺻ üũ
    printf("Capacity: %d, Size: %d, Top: %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

    //Pop�ϸ� ���
    for (i=0; i<4; i++) {
        if (AS_IsEmpty(Stack)) {
            break;
        } else {
            printf("Popped %d, ", AS_Pop(Stack));

            if(!AS_IsEmpty(Stack)) {
                printf("Current Top: %d\n", AS_Top(Stack));
            } else {
                printf("Stack Is Empty.\n");
            }
        }
    }

    //�޸𸮿��� ����(Stack, Stack->Nodes)
    AS_DestroyStack(Stack);

    return 0;
}

