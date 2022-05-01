/*
Problem:
Author:QiZhao
Data:2018-07-
Description:
Copyright  2018 QiZhao. All rights reserved.
*/
#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int read()
{
    int x;
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x;
}
bool IsOperator(char ch);
char Precede(char opr1, char opr2);
double Operate(double opnd1, char op, double opnd2);
int ConvertToIndex(char opr);
/**
  这个是用来判断一个字符是不是
  操作符的
*/
bool IsOperator(char ch)
{
    if (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' ||
            ch == '(' || ch == ')' || ch == '=' || ch == 'd')
        return true;
    else
        return false;

}

//运算符的优先关系
//'+', '-', '*', '/', '(', ')', '#',  'd'
char OprRelation[8][8] =
{
    {'>', '>', '<', '<', '<', '>', '>', '<'}, //'+'
    {'>', '>', '<', '<', '<', '>', '>', '<'}, //'-'
    {'>', '>', '>', '>', '<', '>', '>', '<'}, //'*'
    {'>', '>', '>', '>', '<', '>', '>', '<'}, //'/'
    {'<', '<', '<', '<', '<', '=', ' ', '<'}, //'('
    {'>', '>', '>', '>', ' ', '>', '>', '>'}, //')'
    {'<', '<', '<', '<', '<', ' ', '=', '<'}, //'#'
    {'>', '>', '>', '>', '<', '>', '>', '>',}
};//'d'
/**
   这个是用来获取每一个操作符的优先级
*/
int ConvertToIndex(char opr)
{
    int index;

    switch (opr)
    {
    case '+':
        index = 0;
        break;
    case '-':
        index = 1;
        break;
    case '*':
        index = 2;
        break;
    case '/':
        index = 3;
        break;
    case '(':
        index = 4;
        break;
    case ')':
        index = 5;
        break;
    case '=':
        index = 6;
        break;
    case 'd':
        index = 7;
        break;
    }

    return index;
}
/**
   这个是用来获取连个字符的优先级
*/
char Precede(char opr1, char opr2)
{
    int index1 = ConvertToIndex(opr1);
    int index2 = ConvertToIndex(opr2);

    return OprRelation[index1][index2];
}
/**
    这个是用来对两个数进行求值
*/
ll Operate(ll opnd1, char op, ll opnd2, char op2, int flagg)
{
    double ret;

    switch(op)
    {
    case '+':
        ret = opnd1 + opnd2;
        break;
    case '-':
        ret = opnd1 - opnd2;
        break;
    case '*':
        ret = opnd1 * opnd2;
        break;
    case '/':
        ret = opnd1 / opnd2;
        break;
    case 'd'://算最小值
        {
            if(flagg == 0)
            {
                if(op2 == '-')
                {
                    ret = opnd1*opnd2;
                }
                else
                {
                    ret = opnd1;
                }
            }
            else
            {
                if(op2 == '-')
                {
                    ret = opnd1;
                }
                else
                {
                    ret = opnd1 * opnd2;
                }
            }
        }
        break;
    }

    return ret;
}

//算符优先算法
ll CaculateExpression(string exp, int flaggg)
{
    stack<char> optr; //只处理+ - # / ()运算
    stack<ll> opnd;  //只处理0-9的整数运算
    char ch;
    int i = 0;
    optr.push('=');
    ch = exp[i++];
    bool flag = true;
    //如果##配对，表达式求值完成
    while (flag && (ch != '=' || optr.top() != '='))
    {
        if (!IsOperator(ch))
        {
            string f, g;
            f = exp[i - 1];
            g.append(f);
            while(!IsOperator(exp[i]))
            {
                f = exp[i];
                g.append(f);
                ++i;
            }
            double value = atof(g.c_str());
            //操作数入栈
            opnd.push(value);
            ch = exp[i++];
        }
        else
        {
            //比较栈顶操作符和新取得的操作符的优先关系
            switch (Precede(optr.top(), ch))
            {
            case '<'://栈顶优先权低
                optr.push(ch);
                ch = exp[i++];
                break;
            case '='://括号配对，栈顶括号弹出
                optr.pop();
                if(exp.length() == i)
                {
                    flag = false;
                }
                else
                {
                    ch = exp[i++];
                }
                break;
            case '>'://栈顶优先权高，先弹出，计算，结果操作数入栈
                char op = optr.top();
                optr.pop();
                ll num2 = opnd.top();//第二个操作数在前
                opnd.pop();
                ll num1 = opnd.top();
                opnd.pop();

                ll ret = Operate(num1, op, num2, optr.top(), flaggg);

                opnd.push(ret);
                break;
            }
        }
    }//end of while

    //操作数栈的唯一元素即为计算结果
    return opnd.top();
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    char str[1000];
    string s;
    while(cin >> s)
    {
        s += "=";
        ll a=CaculateExpression(s, 0);
        ll b=CaculateExpression(s,1);
        cout << min(a,b) << " " << max(a,b) << endl;;
    }
    return 0;
}
