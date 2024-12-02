#include <stdio.h>
#include <string.h>
#include "Calculator.h"

int main(void) {
	char InfixExpresion[100];
	char PostfixExpression[100];

	double Result = 0.0;

	//memset: Ư���޸� ���� ������ ������ ä��� �Լ�. �Ʒ��� ??Expression�迭�� 0���� ä���.
	memset(InfixExpression, 0, sizeof(InfixExpresion));
	memset(PostfixExpression, 0, sizeof(PostfixExpression));

	printf("Enter Infix Expression:");
	scanf("%s", InfixExpresion);

	GetPostfix(InfixExpression, PostfixExpression);

	printf("Infix:%s\nPostfix:%s\n", InfixExpresion, PostfixExpression);

	Result = Calculate(PostfixExpression);

	printf("Calculation Result : %f\n", Result);

	return 0;

}