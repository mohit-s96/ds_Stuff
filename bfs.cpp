#include <iostream>
#include <queue>
#define LOG(x) std::cout << x;

template <typename T>
class Tree
{
public:
    struct _Tree
    {
        _Tree* left;
        T data;
        _Tree* right;
    };
private:
    std::queue<_Tree*> Q;
    _Tree* ROOT = nullptr;
    _Tree* new_node(T value) const
    {
        _Tree* node = new _Tree();
        node->data = value;
        node->left = nullptr;
        node->right = nullptr;

        return node;
    }

    _Tree* insert_recursive(_Tree** current, T value)
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

    void level_recurse(_Tree* current)
    {
        if(Q.empty() && current != ROOT) return;

        if(current == ROOT) Q.push(current);

        if(Q.front()->left) Q.push(Q.front()->left);
        if(Q.front()->right) Q.push(Q.front()->right);

        LOG(Q.front()->data);
        LOG(" ");
        Q.pop();

        level_recurse(Q.front());
    }

public:
    void insert(T value)
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

    void level_traverse()
    {
        level_recurse(ROOT);
        while(!Q.empty())
        {
            LOG(Q.front()->data);
            LOG("\t");
            Q.pop();
        }
        LOG("\n");
    }

};

int main()
{
    Tree<char> T;
    // Tree<char>::_Tree* x;
    T.insert('F');
    T.insert('D');
    T.insert('J');
    T.insert('B');
    T.insert('E');
    T.insert('G');
    T.insert('K');
    T.insert('A');
    T.insert('C');
    T.insert('I');
    T.insert('H');

    T.level_traverse();

    // T.print();
    return 0;
}