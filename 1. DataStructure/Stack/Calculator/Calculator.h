#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdlib.h>
#include "LinkedListStack.h"

typedef enum {
    LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
    PLUS = '+', MINUS = '-',
    MULTIPLY = '*', DIVIDE = '/',
    SPACE = ' ', OPERAND
} SYMBOL;

int IsNumber(char Cipher);
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE); //��ū�б�
int IsPrior(char Operator1, char Operator2); //������ �켱���� �Ǻ�
void GetPostfix(char* InfixExpression, char* PostfixExpression); //����ǥ���->����ǥ��� ��ȯ
double Calculate(char* PostfixExpression); //����ǥ��� ���

#endif