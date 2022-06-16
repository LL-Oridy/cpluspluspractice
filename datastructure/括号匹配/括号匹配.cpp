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
	//顺序栈大小
	char s[MAXSIZE];
	//顺序栈头指针
	int top = -1;
	//一直读到最后一个元素
	for (int i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] == '(' || ch[i] == '{' || ch[i] == '[') 
		{
			s[++top] = ch[i];
		}
		if (ch[i] == ')' || ch[i] == '}' || ch[i] == ']') {
			//如果栈空，不能出栈
			if (top == -1) {
				cout << "栈空匹配失败" << endl;
				return 0;
			}
			//用弹栈的栈顶元素和这个元素匹配
			char left = s[top--];
			if (isMatched(left, ch[i]) == 0) {
				cout << "左右括号不匹配失败" << endl;
				return 0;
			}
		}
	}
	//如果都匹配完了栈里还有元素，匹配失败
	if (top > -1) {
		cout << "栈内还有元素，匹配失败" << endl;
		return 0;
	}
	cout << "匹配成功" << endl;
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