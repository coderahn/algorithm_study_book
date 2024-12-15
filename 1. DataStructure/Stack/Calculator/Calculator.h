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
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE); //토큰읽기
int IsPrior(char Operator1, char Operator2); //연산자 우선순위 판별
void GetPostfix(char* InfixExpression, char* PostfixExpression); //중위표기법->후위표기법 변환
double Calculate(char* PostfixExpression); //후위표기법 계산

#endif