#include <iostream>
#include "tree.h"


Tree::RBT* Tree::new_rbt_node(int value)
{
    RBT* node = new RBT();
    node->color = true;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    return node;
}

void Tree::color_flip(Tree::RBT* node)
{
    node->left->color = !node->left->color;
    node->right->color = !node->right->color;
}

Tree::RBT *Tree::left_left_case(Tree::RBT *node)
{
    return rbt_rotate_right(node);
}

Tree::RBT *Tree::left_right_case(Tree::RBT *node)
{
    node->left = rbt_rotate_left(node->left);
    return left_left_case(node);
}

Tree::RBT *Tree::right_right_case(Tree::RBT *node)
{
    return rbt_rotate_left(node);
}

Tree::RBT *Tree::right_left_case(Tree::RBT *node)
{
    node->right = rbt_rotate_right(node->right);
    return right_right_case(node);
}

Tree::RBT* Tree::perform_rotations(Tree::RBT* node)
{
    RBT* granny = node->parent->parent;
    if((node == node->parent->left) && (node->parent == granny->left))
    {
        //left-left case
        return left_left_case(granny);
    }
    else if((node == node->parent->left) && (node->parent == granny->right))
    {
        //right-left case
        return right_left_case(granny);
    }
    else if((node == node->parent->right) && (node->parent == granny->left))
    {
        //left-right case
        return left_right_case(granny);
    }
    else
    {
        // right-right case
        return right_right_case(granny);
    }
    
}

Tree::RBT* Tree::balance_node(Tree::RBT* node)
{
    if(RB_ROOT && RB_ROOT->color)
    {
        RB_ROOT->color = 0;
    }
    if(!RB_ROOT)
    {
        node->color = 0;
        return node;
    }
    if(node->parent && node->parent->parent)
    {
        if(node->color && node->parent->color)
        {
            RBT* aunt = nullptr;
            if(node->parent == node->parent->parent->left)
            {
                RBT* aunt = node->parent->parent->right;
            }
            else
            {
                RBT* aunt = node->parent->parent->left;
            }
            if(aunt && aunt->color)
            {
                color_flip(node->parent->parent);
                return node;
            }
            if(!aunt || !aunt->color)
            {
                return perform_rotations(node);
            }
        }
    }

    return node->parent;
}

Tree::RBT* Tree::_rbt_insert(Tree::RBT* current, int value)
{
    if(!current)
    {
        return new_rbt_node(value);
    }
    if(value < current->data)
    {
        current->left = _rbt_insert(current->left, value);
        if(current->left->parent == nullptr) current->left->parent = current;
        return balance_node(current->left);
    }
    else
    {
        current->right = _rbt_insert(current->right, value);
        if(current->right->parent == nullptr) current->right->parent = current;
        return balance_node(current->right);
    }

}

void Tree::rbt_insert(int val)
{
    RB_ROOT = _rbt_insert(RB_ROOT, val);
}

int main()
{
    Tree T;

    T.rbt_insert(1);
    // T.delay(15000);
    // T.print_tree_rbt();

    T.rbt_insert(2);
    // T.delay(15000);
    // T.print_tree_rbt();

    T.rbt_insert(3);
    // T.delay(15000);
    // T.print_tree_rbt();

    T.rbt_insert(4);
    // T.delay(15000);
    // T.print_tree_rbt();

    T.rbt_insert(5);
    // T.delay(15000);
    // T.print_tree_rbt();

    T.rbt_insert(6);
    // T.delay(15000);
    // T.print_tree_rbt();

    T.rbt_insert(7);
    // T.delay(15000);
    // T.print_tree_rbt();

    T.rbt_insert(8);
    // T.delay(15000);
    // T.print_tree_rbt();

    T.rbt_insert(9);
    // T.delay(15000);
    // T.print_tree_rbt();

    T.rbt_insert(10);
    // T.delay(15000);
    T.print_tree_rbt();
    std::cin.get();
    return 0;
}