#include <iostream>
#include <queue>
#define LOG(x) std::cout << x;

class Tree
{
public:
    std::queue<int> Q;
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
            (*current)->right = insert_recursive(&(*current)->right, value);
        }
        else
        {
            (*current)->left = insert_recursive(&(*current)->left, value);
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

    void inorder_recursive(_Tree* current)
    {
        if(!current) return;
        inorder_recursive(current->left);
        LOG(current->data);
        Q.push(current->data);
        LOG("\n");
        inorder_recursive(current->right);
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

    bool isBST()
    {
        inorder_recursive(ROOT);
        int previous = Q.front();
        Q.pop();
        while(!Q.empty())
        {
            if(previous > Q.front()) return false;
            previous = Q.front();
            Q.pop();
        }
        return true;
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

    LOG(T.isBST());
    LOG("\n");
    return 0;
}