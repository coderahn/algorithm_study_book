#include <stdio.h>
#include <string.h>
#include "Calculator.h"

int main(void) {
	char InfixExpresion[100];
	char PostfixExpression[100];

	double Result = 0.0;

	//memset: 특정메모리 블럭을 지정된 값으로 채우는 함수. 아래는 ??Expression배열에 0으로 채운다.
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