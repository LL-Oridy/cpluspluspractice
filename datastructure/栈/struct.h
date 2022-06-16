#pragma once
#include<iostream>
using namespace std;
#include<string>

typedef struct Stack {
	int data;
	struct Stack* pNext;
}Stack_t,*pStack_t;


bool Initlist(pStack_t& top);
bool push(pStack_t& top);
bool pop(pStack_t& top);
void print(pStack_t top);