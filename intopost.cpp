#include <iostream>
#include <stack>
#define LOG(x) std::cout << x <<std::endl;


bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int priorityEval(char x)
{
    switch (x)
    {
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -2;
    }
}

std::stack<char> convert(char* str)
{
    std::stack<char> S;
    std::stack<char> S1;
    for(int i = 0 ; str[i] != '\0' ; i++)
    {
        if(isOperator(str[i]))
        {
            S1.push(str[i]);
        }
        else
        {
            if(S1.empty())
            {
                S.push(str[i]);
            }else{
                S.push(str[i]);
                if(str[i + 1] != '\0')
                {
                    int j = 1;
                    while(j <= S1.size())
                    {
                        j++;
                        int res;
                        int c1 = priorityEval(S1.top());
                        int c2 = priorityEval(str[i + 1]);
                        res = c1 - c2;
                        if(res >= 0 && str[i + 1] != S1.top()){
                            S.push(S1.top());
                            S1.pop();
                            --j;
                        }
                    }
                }
            }
        }
    }
    while(!S1.empty())
    {
        S.push(S1.top());
        S1.pop();
    }

    return S;
}

int main()
{
    char exp[51];
    LOG("Enter the expression");

    std::cin.getline(exp, 50, '\n');
    // LOG(exp);
    std::stack<char> res = convert(exp);
    char str[20];
    int i = 0;
    while(!res.empty())
    {
        str[i++] = res.top();
        res.pop();
    }
    str[i] = '\0';
    for(int j = i - 1 ; j >= 0 ; j--)
    {
        std::cout << str[j] << " " ;
    }
    return 0;
}