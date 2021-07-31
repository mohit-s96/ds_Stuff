#include "tree.h"

#ifndef LOG
#define LOG(x) std::cout << x;
#endif

Tree::AVL *Tree::new_avl_node(int value)
{
    AVL *node = new AVL();

    node->data = value;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}
//add 2 numbers
void Tree::update_node(Tree::AVL *node)
{
    int lh = -1;
    int rh = -1;

    if (node->left != nullptr)
        lh = node->left->height;
    if (node->right != nullptr)
        rh = node->right->height;

    node->height = 1 + max(lh, rh);

    node->b_Factor = rh - lh;
}

Tree::AVL *Tree::left_left_case(Tree::AVL *node)
{
    return avl_rotate_right(node);
}

Tree::AVL *Tree::left_right_case(Tree::AVL *node)
{
    node->left = avl_rotate_left(node->left);
    return left_left_case(node);
}

Tree::AVL *Tree::right_right_case(Tree::AVL *node)
{
    return avl_rotate_left(node);
}

Tree::AVL *Tree::right_left_case(Tree::AVL *node)
{
    node->right = avl_rotate_right(node->right);
    return right_right_case(node);
}

Tree::AVL *Tree::balance_node(Tree::AVL *node)
{
    if (node->b_Factor == -2)
    {
        if (node->left->b_Factor <= 0)
            return left_left_case(node);
        else
            return left_right_case(node);
    }
    if (node->b_Factor == +2)
    {
        if (node->right->b_Factor >= 0)
            return right_right_case(node);
        else
            return right_left_case(node);
    }
    return node;
}

Tree::AVL *Tree::_avl_insert(Tree::AVL *current, int value)
{
    if (!current)
    {
        current = new_avl_node(value);
        return current;
    }
    if (value < current->data)
        current->left = _avl_insert(current->left, value);

    else
        current->right = _avl_insert(current->right, value);

    update_node(current);

    return balance_node(current);
}

void Tree::avl_insert(int value)
{
    A_ROOT = _avl_insert(A_ROOT, value);
}

int main()
{
    Tree T;

    T.avl_insert(1);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(2);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(3);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(4);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(5);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(6);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(7);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(8);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(9);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(10);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(11);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(12);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(13);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(14);
    T.delay(15000);
    T.print_tree_avl();
    
    T.avl_insert(15);
    T.delay(15000);
    T.print_tree_avl();
    
    T.avl_insert(16);
    T.delay(15000);
    T.print_tree_avl();
    
    T.avl_insert(17);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(18);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(19);
    T.delay(15000);
    T.print_tree_avl();

    T.avl_insert(20);
    T.delay(15000);
    T.print_tree_avl();

    LOG("Press return to exit\n");

    std::cin.get();
    return 0;
}