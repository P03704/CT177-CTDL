#include <stdio.h>
#include "AListLib.c"

typedef List Stack;

void makenullStack(Stack *s){
	makenullList(s);
}

int emptyStack(Stack s){
	return emptyList(s);
}

int FullStack(Stack s){
	return fullList(s);
}

ElementType Top(Stack s){
	return retrieve(first(s), s);
}

void Push(ElementType x, Stack *s){
	insertList(x, first(*s), s);
}

void Pop(Stack *s){
	deleteList(first(*s), s);
}
