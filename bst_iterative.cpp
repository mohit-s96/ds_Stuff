#include <iostream>
#define LOG(x) std::cout <<x;

struct _Tree
{
    _Tree* left;
    int data;
    _Tree* right;
};

class Tree
{
private:
    _Tree* ROOT = nullptr;
    _Tree* new_node(int data)
    {
        _Tree* node = new _Tree();
        node->data = data;
        node->left = nullptr;
        node->right = nullptr;

        return node;
    }
    void recursive_print(_Tree* current) // inorder
    {
        if(!current->left && !current->right)
        {
            LOG(current->data);
            LOG("\n");
            return;
        }

        if(current->left)
        {
            recursive_print(current->left);
        }
        if(current->right)
        {
            recursive_print(current->right);
            LOG(current->data);
            LOG("\n");        
        }

    }
public:
    void insert(int value)
    {
        if(!ROOT)
        {
            ROOT = new_node(value);
        }
        else
        {
            _Tree* current = ROOT;
            while(true)
            {

                if(current->data >= value)
                {
                    if(!current->left)
                    {
                        current->left = new_node(value);
                        break;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                else
                {
                    if(!current->right)
                    {
                        current->right = new_node(value);
                        break;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
                
            }    
        }
    }

    int search(int value)
    {
        if(!ROOT)
        {
            return -9999;
        }
        else
        {
            _Tree* current = ROOT;
            while(true)
            {
                if(!current) return -9999;

                if(current->data == value)
                    return current->data;
                else if(value <= current->data)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }

    void print()
    {
        if(!ROOT) return;

        recursive_print(ROOT);
    }
};

int main()
{
    Tree T;
    T.insert(4);
    T.insert(2);    
    T.insert(5);    
    T.insert(1);    
    T.insert(3);    
    // T.insert(5);    
    // T.insert(19);

    T.print();  

    // LOG(T.search(84));
    // LOG("\n");

    return 0; 
}