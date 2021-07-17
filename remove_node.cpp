#include <iostream>
#define LOG(x) std::cout << x

class Tree
{
private:
    struct _Tree
    {
        _Tree* left;
        int data;
        _Tree* right;
    };

    _Tree* ROOT = nullptr;

    _Tree* new_node(int val);

    _Tree* recursive_insert(_Tree*& current, int value); 

    void inorder_recursive(_Tree* current);

    _Tree* get_node(int);

    _Tree* recursive_search(_Tree*, int);

    _Tree* get_smallest(_Tree*);

    void check_deletion_cases(_Tree*, _Tree*&);

public:

    void insert(int value)
    {
        recursive_insert(ROOT, value);
    }

    void inorder()
    {
        inorder_recursive(ROOT);
    }

    _Tree* recurse_delete(_Tree*, _Tree*);

    void delete_node(int value)
    {
        _Tree* target = get_node(value);
        if(target)
        {
            recurse_delete(ROOT, target);
        }
        else LOG("not found\n");
    }
};

Tree::_Tree* Tree::new_node(int val)
{
    Tree::_Tree* node = new Tree::_Tree();

    node->data = val;
    node->right = nullptr;
    node->left = nullptr;

    return node;
}

Tree::_Tree* Tree::recursive_insert(Tree::_Tree*& current, int value)
{
    if(!current)
    {
        current = new_node(value);
    }

    else if(value <= current->data)
    {
        current->left = recursive_insert(current->left, value);
    } 

    else
    {
        current->right = recursive_insert(current->right, value);
    }   

    return current;
}

void Tree::inorder_recursive(Tree::_Tree* current)
{
    if(!current) return;

    inorder_recursive(current->left);

    LOG(current->data);
    LOG("\n");

    inorder_recursive(current->right);

}

Tree::_Tree* Tree::get_node(int value)
{
    return recursive_search(ROOT, value);
}

Tree::_Tree* Tree::recursive_search(Tree::_Tree* current, int value)
{
    if(!current) return nullptr;

    if(current->data == value)
    {
        return current;
    }

    if(value <= current->data) return recursive_search(current->left, value);
    else return recursive_search(current->right, value);
    
}

Tree::_Tree* Tree::recurse_delete(Tree::_Tree* current, Tree::_Tree* target)
{
    if(!current) return nullptr;

    if(target == ROOT)
    {
        check_deletion_cases(target, current);
        return nullptr;
    }
    if(target->data <= current->data)
    {
        _Tree* node = recurse_delete(current->left, target);
        if(node == target)
        {
            check_deletion_cases(target, current->left);
        }
    }
    else
    {
        _Tree* node = recurse_delete(current->right, target);
        if(node == target)
        {
            check_deletion_cases(target, current->right);
        }
    }

    return current;
}

Tree::_Tree* Tree::get_smallest(Tree::_Tree* current)
{
    if(!current->left) return current;
    else return get_smallest(current->left);
}

void Tree::check_deletion_cases(Tree::_Tree* node, Tree::_Tree*& current)
{
    if(!node->left && !node->right)
    {
        delete node;
        current = nullptr;
    }

    // case 2 -> when node to be deleted has only 1 child
    if((node->left && !node->right) || (!node->left && node->right))
    {
        _Tree* temp = node->left ? node->left : node->right;
        delete node;
        current = temp;
    }

    // case 3 -> when node to be deleted has 2 children
    if(node->left && node->right)
    {
        _Tree* least = get_smallest(node->right);
        int temp = least->data;
        recurse_delete(node, least);
        node->data = temp;
    }
}

int main()
{
    Tree T;

    T.insert(4);
    T.insert(2);
    T.insert(9);
    T.insert(6);
    T.insert(10);
    T.insert(5);
    T.insert(7);
    T.insert(12);
    T.insert(3);
    T.insert(1);

    

    T.delete_node(41);
    T.inorder();


    return 0;
}