#pragma once
#include<iostream>
using namespace std;

typedef struct Queue {
	int num;
	struct Queue* pNext;
}Queue;

typedef struct QueueLink {
	Queue* front;
	Queue* rear;
}Qlink;

void Initlist(Qlink* L);
bool Insertlist(Qlink* L);
bool Deletelist(Qlink* L);
