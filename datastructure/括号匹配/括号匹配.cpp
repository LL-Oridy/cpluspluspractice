#include<iostream>
using namespace std;
#define MAXSIZE 10

int isMatched(char left, char right);
int bracketCheck(char ch[]);

int isMatched(char left, char right) {
	if (left == '(' && right == ')')
		return 1;
	else if (left == '[' && right == ']')
		return 1;
	else if (left == '{' && right == '}')
		return 1;
	else
		return 0;
}

int bracketCheck(char ch[]) {
	//˳��ջ��С
	char s[MAXSIZE];
	//˳��ջͷָ��
	int top = -1;
	//һֱ�������һ��Ԫ��
	for (int i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] == '(' || ch[i] == '{' || ch[i] == '[') 
		{
			s[++top] = ch[i];
		}
		if (ch[i] == ')' || ch[i] == '}' || ch[i] == ']') {
			//���ջ�գ����ܳ�ջ
			if (top == -1) {
				cout << "ջ��ƥ��ʧ��" << endl;
				return 0;
			}
			//�õ�ջ��ջ��Ԫ�غ����Ԫ��ƥ��
			char left = s[top--];
			if (isMatched(left, ch[i]) == 0) {
				cout << "�������Ų�ƥ��ʧ��" << endl;
				return 0;
			}
		}
	}
	//�����ƥ������ջ�ﻹ��Ԫ�أ�ƥ��ʧ��
	if (top > -1) {
		cout << "ջ�ڻ���Ԫ�أ�ƥ��ʧ��" << endl;
		return 0;
	}
	cout << "ƥ��ɹ�" << endl;
	return 1;

}

//void test() {
//	char ch1[] = "{";
//	bracketCheck(ch1);
//}
//int main() {
//	test();
//	return 0;
//}