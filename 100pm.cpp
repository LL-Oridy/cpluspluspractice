#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;
void func1()
{
    int num1 = 100,num2 = -1,input = -1;
    srand(time(NULL));
    bool not_exit = true;
    int cnt = 0,cost = 0,i = 0,cnt2 = 0;
    time_t start,end;
    time(&start);
    vector<string> vec;
    while (not_exit){
        num2 = rand()%100;
        if (num2 == 0)
            num2 = num2+1;
        //num2 [1,99]
        cout<<num1<<"-"<<num2<<"=";
        cin >> input;
        int fac = num1-num2;
        if (input == fac)   ++cnt;
        else
        {
            ++cnt2;
            string s = to_string(num1)+"-"+to_string(num2)+"="+to_string(fac)+" ("+to_string(input)+")";
            vec.push_back(s);
        }
        ++i;
        if (i == 10)
        {
            not_exit = false;
            time(&end);
        }
    }
    cost = difftime(end,start);
    cout<<"用时"<<cost<<"秒"<<"做对"<<cnt<<"题"<<endl;

    if (vec.size()>0){
        cout<<"错题如下:"<<endl;
        for (string s:vec)
        {
            cout<<s<<endl;
        }
    }
}

void func2()
{
    int num1 = -1,num2 = -1,input = -1;
    srand(time(NULL));
    bool not_exit = true;
    int cnt = 0,cost = 0,i = 0,cnt2 = 0,l = 0;
    time_t start,end;
    time(&start);
    vector<string> vec;
    while (not_exit){
        // 1000是RANDOM_MAX 范围是0~RANDOM_MAX-1
        int fact = -1;
        int n1 = rand()%(999-100+1)+100;
        int n2 = rand()%(999-100+1)+100;
        // num1 [100,999] > num2
        num1 = n1 > n2 ? n1 : n2;
        // num2 [100,999] < num1
        num2 = n1 < n2 ? n1 : n2;
        l = rand()%2;
        if (l == 0)
        {
            // plus
            cout<<num1<<"+"<<num2<<"=";
            fact = num1+num2;
        }
        else
        {
            // minus
            cout<<num1<<"-"<<num2<<"=";
            fact = num1-num2;
        }
        cin >> input;
        if (input == fact)   ++cnt;
        else
        {
            ++cnt2;
            string s = "";
            if (l == 0)
                s = to_string(num1)+"+"+to_string(num2)+"="+to_string(fact)+" ("+to_string(input)+")";
            else
                s = to_string(num1)+"-"+to_string(num2)+"="+to_string(fact)+" ("+to_string(input)+")";
            vec.push_back(s);
        }
        ++i;
        if (i == 10)
        {
            not_exit = false;
            time(&end);
        }
    }
    cost = difftime(end,start);
    cout<<"用时"<<cost<<"秒"<<"做对"<<cnt<<"题"<<endl;

    if (vec.size()>0){
        cout<<"错题如下:"<<endl;
        for (string s:vec)
        {
            cout<<s<<endl;
        }
    }
}

void func3()
{
    int num1 = -1,num2 = -1,input = -1;
    srand(time(NULL));
    bool not_exit = true;
    int cnt = 0,cost = 0,i = 0,cnt2 = 0,l = 0;
    time_t start,end;
    time(&start);
    vector<string> vec;
    while (not_exit){
        // 1000是RANDOM_MAX 范围是0~RANDOM_MAX-1
        int fact = -1;
        int n1 = rand()%100;
        int n2 = rand()%100;
        // num1 [100,999] > num2
        num1 = n1 > n2 ? n1 : n2;
        // num2 [100,999] < num1
        num2 = n1 < n2 ? n1 : n2;
        if (num2 == 0){
            num2 = num2+1;
        }
        l = rand()%2;
        if (l == 0)
        {
            // plus
            cout<<num1<<"+"<<num2<<"=";
            fact = num1+num2;
        }
        else
        {
            // minus
            cout<<num1<<"-"<<num2<<"=";
            fact = num1-num2;
        }
        cin >> input;
        if (input == fact)   ++cnt;
        else
        {
            ++cnt2;
            string s = "";
            if (l == 0)
                s = to_string(num1)+"+"+to_string(num2)+"="+to_string(fact)+" ("+to_string(input)+")";
            else
                s = to_string(num1)+"-"+to_string(num2)+"="+to_string(fact)+" ("+to_string(input)+")";
            vec.push_back(s);
        }
        ++i;
        if (i == 10)
        {
            not_exit = false;
            time(&end);
        }
    }
    cost = difftime(end,start);
    cout<<"用时"<<cost<<"秒"<<"做对"<<cnt<<"题"<<endl;

    if (vec.size()>0){
        cout<<"错题如下:"<<endl;
        for (string s:vec)
        {
            cout<<s<<endl;
        }
    }
}

int main(void)
{
    bool exit = false;
    while (!exit)
    {
        cout<<"请选择=====1===>100=====2===>1000=====3===>100"<<endl;
        int choose = -1;
        cin>>choose;
        switch (choose)
        {
        case 1:
            func1();
            break;
        case 2:
            func2();
            break;
        case 3:
            func3();
            break;
        default:
            exit = true;
            break;
        }
    }
    return 0;
    
}