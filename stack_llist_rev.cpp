#include <iostream>
#include <stack>
#define LOG(x) std::cout << x << std::endl

class List
{
private:

    struct _List
    {
        int data;
        _List* next;
    };

    _List* HEAD = nullptr;
    
public:
    ~List()
     {
         _List* current = HEAD;
         while(current)
         {
             _List* temp = current->next;
             delete current;
             current = temp;
         }
     }
    _List* insert_head(int val)
    {
        if(HEAD == nullptr)
        {
            HEAD = new _List();
            HEAD->data = val;
            HEAD->next = 0;
        }
        else{
            _List* temp = new _List();
            temp->data = val;
            temp->next = HEAD;
            HEAD = temp;
        }
        return HEAD;
    }
    void print()
    {
        _List* current = HEAD;
        while(current)
        {
            LOG(current->data);
            current = current->next;
        }
    }
    void reverse_list_stack()
    {
        std::stack<_List*> S;
        _List* current = HEAD;
        _List* temp = nullptr;
        while(current)
        {
            S.push(current);
            current = current->next;
        }
        temp = S.top();
        HEAD = temp;
        S.pop();
        while(!S.empty())
        {
            temp->next = S.top();
            S.pop();
            temp = temp->next;
        }
        temp->next = 0;
    }
};


int main()
{
    List* L = new List();
    L->insert_head(5);
    L->insert_head(6);
    L->insert_head(7);
    L->insert_head(8);
    L->insert_head(9);

    L->reverse_list_stack();

    L->print();

    delete L;   
    return 0;
}