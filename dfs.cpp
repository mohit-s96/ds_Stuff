#include <iostream>
#define LOG(x) std::cout << x;

class Tree
{
public:
    struct _Tree
    {
        _Tree* left;
        int data;
        _Tree* right;
    };
private:
    _Tree* ROOT = nullptr;
    _Tree* new_node(int value) const
    {
        _Tree* node = new _Tree();
        node->data = value;
        node->left = nullptr;
        node->right = nullptr;

        return node;
    }

    _Tree* insert_recursive(_Tree** current, int value)
    {
        if(!*current)
        {
            *current = new_node(value);
        }
        else if (value <= (*current)->data)
        {
            (*current)->left = insert_recursive(&(*current)->left, value);
        }
        else
        {
            (*current)->right = insert_recursive(&(*current)->right, value);
        }
        return (*current);
    }

    void print_recursive(_Tree* current)
    {
        if(!current) return;

        LOG(current->data);
        LOG("\n");
        print_recursive(current->left);
        print_recursive(current->right);
    }

    void preorder_recursive(_Tree* current)
    {
        if(!current) return;
        LOG(current->data);
        LOG("\n");
        preorder_recursive(current->left);
        preorder_recursive(current->right);
    }

    void inorder_recursive(_Tree* current)
    {
        if(!current) return;
        inorder_recursive(current->left);
        LOG(current->data);
        LOG("\n");
        inorder_recursive(current->right);
    }

    void postorder_recursive(_Tree* current)
    {
        if(!current) return;
        postorder_recursive(current->left);
        postorder_recursive(current->right);
        LOG(current->data);
        LOG("\n");
    }

public:
    void insert(int value)
    {
        insert_recursive(&ROOT, value);
    }

    void print()
    {
        if(ROOT)
        {
            print_recursive(ROOT);
        }
        else{
            LOG("No root found\n");
        }
    }

    void inorder()
    {
        inorder_recursive(ROOT);
    }

    void preorder()
    {
        preorder_recursive(ROOT);
    }

    void postorder()
    {
        postorder_recursive(ROOT);
    }
};

int main()
{
    Tree T;

    T.insert(4);
    T.insert(2);
    T.insert(5);
    T.insert(3);
    T.insert(1);

    LOG("PRE--------------------\n");
    T.preorder();
    LOG("IN--------------------\n");
    T.inorder();
    LOG("POST--------------------\n");
    T.postorder();
    return 0;
}