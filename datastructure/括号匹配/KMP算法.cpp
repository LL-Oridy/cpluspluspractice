#include<iostream>
#include<cstring>
using namespace std;


//nextÊý×é
void setNext(string T, int next[])
{
	int tlen = T.length();
	next[0] = -1;
	int j = 0, k = -1;
	while (j < tlen)
	{
		if (k == -1 || T[k] == T[j])
		{
			k++;
			j++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int getLocate(string S, string T, int next[])
{
	setNext(T, next);
	int slen = S.length();
	int tlen = T.length();
	int i = 0, j = 0;
	while (i < slen && j < tlen)
	{
		if (j == 0 || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == tlen)
	{
		return i - tlen + 1;
	}
	return -1;
}
int main()
{
	int next[20];
	string s, t;
	cin >> s;
	cin >> t;
	cout << getLocate(s, t, next);
	return 0;
}

