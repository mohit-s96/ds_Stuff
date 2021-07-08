#include <iostream>
#define LOG(x) std::cout << x <<std::endl

struct _List
{
    int value;
    _List* node;
    _List(int x)
        : value(x) {}
        
};

class List
{
private:
    _List* HEAD = nullptr;
    _List* TAIL = nullptr;
public:
    int length = 0;
    _List* push(int value)
    {
        if(HEAD == nullptr)
        {
            HEAD = TAIL = new _List(value);
            TAIL->node = 0;
        }
        else{
            _List* temp = new _List(value);
            TAIL->node = temp;
            TAIL = temp;
            TAIL->node = 0;
        }
        length++;
        return TAIL;
    }

    _List* insert(int index, int value)
    {
        _List* retVal = nullptr;
        if(index < length && index >= 0)
        {
            if(index == 0)
            {
                _List* temp = new _List(value);
                temp->node = HEAD;
                HEAD = temp;
                retVal = temp;
            }else{
                _List* buffer = HEAD;
                for(int i = 0 ; i <= index ; i++)
                {
                    if(i == index - 1)
                    {
                        _List* temp = buffer->node;
                        _List* temp1 = new _List(value);
                        temp1->node = temp;
                        buffer->node = temp1;
                        retVal = temp1;
                    }
                    buffer = buffer->node;
                }
            }
            length++;
            return retVal;
        }
        else
        {
            std::cout << "Invalid index provided to insert method" << std::endl;
            return nullptr;
        }
    }

    void print_list()
    {
        _List* temp = HEAD;
        for(int i = 0 ; temp != 0 ; i++)
        {
            std::cout << "Element at position " << i << " -> " << temp->value << std::endl;
            temp = temp->node;
        }
    }
    void recursive_print(_List* block)
    {
        if(block){
            LOG(block->value); // move this below the recursive call to print in reverse
            recursive_print(block->node);
        }
        
    }
    void remove(int index)
    {
        if((index < 0) || (index >= length))
        {
            LOG("Invalid index");
        }else{
            if(index == 0)
            {
                _List* temp = HEAD->node;
                delete HEAD;
                HEAD = temp;
            }
            else
            {
                _List* prev = nullptr;
                _List* buffer = HEAD;
                for(int i = 0 ; i <= index ; i++)
                {
                    if(i == index - 1)
                    {
                        prev = buffer;
                    }
                    if(i == index)
                    {
                        _List* temp = buffer->node;
                        delete buffer;
                        prev->node = temp;
                    }
                    buffer = buffer->node;
                }
            }
            length--;
        }
    }
    void reverse_list()
    {
        _List* currentNode = HEAD;
        _List* last_node = nullptr;
        for(int i = 0 ; currentNode ; i++)
        {
            _List* temp = currentNode->node;
            currentNode->node = last_node;
            last_node = currentNode;
            currentNode = temp;
        }
        _List* temp = HEAD;
        HEAD = TAIL;
        TAIL = temp;
        TAIL->node = 0;  
    }
    void reverse_recursive(_List* block)
    {
        if(!block->node)
        {
            HEAD = block;
            return;
        }
        reverse_recursive(block->node);
        block->node->node = block;
        block->node = 0;
    }
    ~List()
    {
        std::cout << "De-allocating" << std::endl;
        if(HEAD != nullptr)
        {
            _List* temp = HEAD;
            while(temp != 0)
            {
                _List* x = temp->node;
                std::cout << "Deleted " << temp->value << std::endl;
                delete temp;
                temp = x;
            }

        }        
    }
};





int main()
{
    List* llist = new List();

    // int x = 0;

    // std::cout << "Enter your elements" << std::endl;

    // while(std::cin >> x)
    // {
    //     if(x == -1)
    //         break;
    //     llist->push(x);
    // }
    llist->push(0);
    llist->push(1);
    llist->push(2);
    llist->push(3);
    llist->push(4);
    llist->push(5);

    // llist->recursive_print(head);

    // llist->print_list();

    // LOG("-------------------------------------");

    llist->insert(3, 99);

    // llist->print_list();

    _List* head = llist->insert(0, 420);

    llist->print_list();

    LOG("-------------------------------------");

    llist->reverse_recursive(head);

    llist->print_list();

    // LOG("-------------------------------------");

    // llist->reverse_list();

    // llist->print_list();
    // // llist->insert(10, 45);

    // llist->remove(3);

    // LOG("-------------------------------------");
    
    // llist->print_list();

    delete llist;

    return 0;
}