// Some use cases of stack data structure in c++

#include <iostream>
#define LOG(x) std::cout << x <<std::endl
#define MAX_LENGTH 101

class Stack
{
private:
    char stack[MAX_LENGTH];
    int top = -1;
public:
    int push(int value)
    {
        if(top == 100)
        {
            LOG("Stack overflow");
            return top;
        }
        else
        {
            stack[++top] = value;
            return top;
        }
    }
    char pop()
    {
        if(top == -1)
        {
            LOG("No elements left");
            return '\0';
        }
        else
        {
            return stack[top--];
        }
    }
    void print()
    {
        for(int i = top ; i > -1 ; i--)
        {
            LOG(stack[i]);
        }
    }
    int get_top()
    {
        return top;
    }
    int is_empty()
    {
        return top == -1;
    }
};


int main()
{
    Stack S;
    char str[16] = "Data Structures";


    for(int i = 0 ; str[i] != '\0' ; i++)
    {
        S.push(str[i]);
    }
    for(int i = 0 ; str[i] != '\0' ; i++)
    {
        str[i] = S.pop();
    }
    
    LOG(str);

    return 0;
}