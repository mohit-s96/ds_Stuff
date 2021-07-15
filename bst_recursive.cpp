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

    bool recursive_search(_Tree* current, int value)
    {
        if(!current) return false;
        if(current->data == value) return true;
        if(value <= current->data) return recursive_search(current->left, value);
        else return recursive_search(current->right, value);
    }

    int recursive_max(_Tree* current)
    {
        if(!current->right) return current->data;

        else return recursive_max(current->right);
    }

    int recursive_min(_Tree* current)
    {
        if(!current->left) return current->data;

        else return recursive_min(current->left);
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int recursive_height(_Tree* current)
    {
        if(!current) return -1;
        
        return max(recursive_height(current->left), recursive_height(current->right)) + 1;
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

    bool search(int value)
    {
        return recursive_search(ROOT, value);
    }

    int max_node()
    {
        return recursive_max(ROOT);
    }

    int min_node()
    {
        return recursive_min(ROOT);
    }

    int tree_height()
    {
        return recursive_height(ROOT);
    }
};

int main()
{
    Tree T;
    T.insert(5);
    T.insert(4);
    T.insert(8);
    T.insert(3);
    T.insert(9);
    T.insert(7);
    T.insert(14);
    // T.insert(11);


    // T.print();

    // LOG(T.search(3));
    // LOG("\n");
    // LOG(T.search(59));

    LOG(T.tree_height());
    LOG("\n");
    return 0;
}