#include <iostream>
#define LOG(x) std::cout << x << std::endl;

struct _Dll
{
    int value;
    _Dll* next;
    _Dll* prev;
    _Dll(int x)
        : value(x)
    {} 
};

class Doubly
{
private:
   int length = 0;
   _Dll* HEAD = nullptr;
   _Dll* TAIL = nullptr;
public:
    ~Doubly()
    {
        std::cout << "De-allocating" << std::endl;
        if(HEAD != nullptr)
        {
            _Dll* temp = HEAD;
            while(temp != 0)
            {
                _Dll* x = temp->next;
                std::cout << "Deleted " << temp->value << std::endl;
                delete temp;
                temp = x;
            }

        }        
    }
    int get_length()
    {
        return length;
    }
    _Dll* insert(int index, int v)
    {
        if(index < length && index >= 0)
        {
            length++;
            if(index == 0)
            {
                _Dll* temp = new _Dll(v);
                temp->next = HEAD;
                temp->prev = 0;
                HEAD = temp;
                return temp;
            }
            else
            {
                _Dll* current = HEAD;
                for(int i = 0 ; i < index-1 ; i++)
                {
                    current = current->next;
                }
                _Dll* temp1 = new _Dll(v);
                temp1->prev = current;
                _Dll* temp2 = current->next;
                temp2->prev = temp1;
                current->next = temp1;
                temp1->next = temp2;
                return temp1;
            }
        }else{
            LOG("Invalid index to function Doubly::insert\n");
            return nullptr;
        }
    }
    void print_list()
    {
        _Dll* current = HEAD;
        for(int i = 0 ; current ; i++)
        {
            std::cout << "Element at position " << i << "->" << current->value << std::endl;
            current = current->next;
        }
    }
    void print_reverse()
    {
        _Dll* current = TAIL;
        for(int i = length - 1 ; current ; i--)
        {
            std::cout << "Element at position " << i << "->" << current->value << std::endl;
            current = current->prev;
        }
    }
    _Dll* push(int v)
    {
        length++;
        if(HEAD == nullptr)
        {
            _Dll* temp = new _Dll(v);
            temp->prev = 0;
            temp->next = 0;
            HEAD = TAIL = temp;
            return temp;
        }
        else
        {
            _Dll* temp = new _Dll(v);

            TAIL->next = temp;
            temp->prev = TAIL;
            TAIL = temp;
            TAIL->next = 0;
        
           return temp;
        }
    }
    void remove(int index)
    {
        if(index < length && index > -1)
        {
            if(index == 0)
            {
                _Dll* temp = HEAD->next;
                temp->prev = 0;
                delete HEAD;
                HEAD = temp;
            }else{
                _Dll* current = HEAD;
                for(int i = 0 ; i < index - 1 ; i++)
                {
                    current = current->next;
                }
                _Dll* temp = current->next;
                current->next = current->next->next;
                current->next->prev = current;
                delete temp;
            }
            length--;
        }else{
            LOG("Invalid index value");
        }
    }
};




int main()
{
    Doubly* dlist = new Doubly();

    dlist->push(5);
    dlist->push(6);
    dlist->push(7);
    dlist->push(8);
    dlist->push(9);


    dlist->print_list();

    LOG("---------------------------------------");

    dlist->insert(2, 420);

    dlist->remove(3);
    dlist->print_list();
    LOG("---------------------------------------");

    dlist->print_reverse();


    LOG(dlist->get_length());

    delete dlist;
    return 0;
}