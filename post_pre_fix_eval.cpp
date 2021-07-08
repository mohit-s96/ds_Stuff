#include <iostream>
#include <stack>
#define LOG(x) std::cout << x << std::endl

int stringToInt(char* x)
{
    int l = 0;
    bool neg = false;
    for(int i = 0 ; x[i] != '\0' ; i++)
    {
        l++;
    }
    if(x[0] == '-')
    {
        neg = true;
        for(int i = 0 ; x[i] != '\0' ; i++)
        {
            x[i] = x[i + 1];
        }
        l--;
    }
    int mul = 1;
    for (int i = 1; i < l; i++)
    {
        mul = mul*10;
    }
    int sum = 0;
    for(int i = 0 ; x[i] != '\0' ; i++)
    {
        int p = x[i] - '0';
        if(mul){
            p = p * mul;
            mul/=10;
        }
        sum += p;
    }

    if(neg){
        sum = sum * -1;
    }
    return sum;
}

bool isOperator(char c)
{
    return (c == '+' || c == '*' || c == '-' || c == '/');
}

void evalCharStack(std::stack<int>& S, std::stack<char>& charS)
{
    char str[18];
    int size = charS.size();
    int i = size - 1;
    while(!charS.empty())
    {
        str[i--] = charS.top();
        charS.pop();
    }
    str[size] = '\0';
    int n = stringToInt(str);
    S.push(n);
}

int performOeration(int first, int second, char ch)
{
    switch (ch)
    {
    case '+':
        return first + second;
    case '-':
        return first - second;
    case '*':
        return first * second;
    case '/':
        return first / second;
    default:
        return 0;
    }
}

int evalPostfix(char* expression)
{
    std::stack<int> S;
    std::stack<char> charS;
    for(int i = 0 ; expression[i] != '\0' ; i++)
    {
        if(isOperator(expression[i]))
        {
            //todo - perform operation on last 2 entries in the main stack
            if(!charS.empty())
            {
                evalCharStack(S, charS);
            }

            int second = S.top();
            S.pop();
            int first = S.top();
            S.pop();

            int result = performOeration(first, second, expression[i]);

            S.push(result);
            
        }else if(expression[i] == ' '){
            // todo -concat chars from char stack and push them to main stack as integers
            evalCharStack(S, charS);
            
        }else{
            charS.push(expression[i]);
        }
    }
    if(S.size() != 1)
    {
        return -99999;
    }else{
        int x = S.top();
        S.pop();
        return x;
    }
}

int main()
{
    char expression[51];
    LOG("Enter the postfix expression");
    std::cin.getline(expression, 51, '\n');
    int result = evalPostfix(expression);
    LOG(result);
    return 0;
}