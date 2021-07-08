#include <iostream>
#include <stack>
#define LOG(x) std::cout << x << std::endl

bool isBracketIsh(char ch)
{
    return (ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == '(' || ch == ')');
}
bool isPair(char ch, char top)
{
    switch (ch)
    {

    case ')':
        return top == '(';

    case ']':
        return top == '[';

    case '}':
        return top == '{';
    default:
        return false;
        break;
    }
}
bool eval(char* str)
{
    std::stack<char> S;
    for(int i = 0 ; str[i] != '\0' ; i++)
    {
        if(isBracketIsh(str[i]))
        {
            if(!S.empty())
            {
                char top = S.top();
                if(isPair(str[i], top))
                {
                    S.pop();
                }else{
                    S.push(str[i]);
                }
            }else{
                S.push(str[i]);
            }
        }
    }
    return S.empty();
}



int main()
{
    char expression[51];
    LOG("Enter your expression");
    std::cin.getline(expression, 50, '\n');
    // LOG(expression);
    bool valid = eval(expression);
    if(valid)
        LOG("Valid");
    else
        LOG("Invalid");
    
    return 0;
}