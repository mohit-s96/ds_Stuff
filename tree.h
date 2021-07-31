#pragma once
#include <iostream>
#include "print.h"
#define LOG(x) std::cout << x;

class Tree
{
public:
    struct _Tree
    {
        _Tree *left;
        int data;
        _Tree *right;
    };
    struct AVL
    {
        AVL *left;
        int data;
        AVL *right;
        int height;
        int b_Factor;
    };
    struct RBT
    {
        RBT* left;
        RBT* right;
        RBT* parent;
        int data;
        bool color;
    };

private:
    _Tree *ROOT = nullptr;
    AVL *A_ROOT = nullptr;
    RBT* RB_ROOT = nullptr;

    _Tree *new_node(int value) const
    {
        _Tree *node = new _Tree();
        node->data = value;
        node->left = nullptr;
        node->right = nullptr;

        return node;
    }

    void update_node(AVL *);

    AVL *balance_node(AVL *);

    AVL *left_left_case(AVL *);

    AVL *left_right_case(AVL *);

    AVL *right_right_case(AVL *);

    AVL *right_left_case(AVL *);

    AVL *new_avl_node(int value);

    AVL *_avl_insert(AVL *, int);


    RBT* new_rbt_node(int);

    RBT* _rbt_insert(RBT*, int);

    RBT* balance_node(RBT*);

    void color_flip(RBT*);

    RBT* perform_rotations(RBT*);

    RBT *left_left_case(RBT *);

    RBT *left_right_case(RBT *);

    RBT *right_right_case(RBT *);

    RBT *right_left_case(RBT *);

    _Tree *insert_recursive(_Tree **current, int value)
    {
        if (!*current)
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

    void print_recursive(AVL *current)
    {
        if (!current)
            return;

        LOG(current->data);
        LOG("\n");
        print_recursive(current->left);
        print_recursive(current->right);
    }

    _Tree *recursive_search(_Tree *current, int value)
    {
        if (!current)
            return nullptr;
        if (current->data == value)
            return current;
        if (value <= current->data)
            return recursive_search(current->left, value);
        else
            return recursive_search(current->right, value);
    }

    int recursive_max(_Tree *current)
    {
        if (!current->right)
            return current->data;

        else
            return recursive_max(current->right);
    }

    int recursive_min(_Tree *current)
    {
        if (!current->left)
            return current->data;

        else
            return recursive_min(current->left);
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int recursive_height(_Tree *current)
    {
        if (!current)
            return -1;

        return max(recursive_height(current->left), recursive_height(current->right)) + 1;
    }

    void recurse_print(_Tree *, int, int);
    // void recurse_print(AVL *, int, int);

    _Tree *get_parent(_Tree *current, _Tree *node)
    {
        if (!current->left && !current->right)
            return nullptr;

        if (current->left == node || current->right == node)
            return current;

        if (node->data < current->data)
            return get_parent(current->left, node);
        else
            return get_parent(current->right, node);
    }

    AVL *get_parent(AVL *current, AVL *node)
    {
        if (!current->left && !current->right)
            return nullptr;

        if (current->left == node || current->right == node)
            return current;

        if (node->data < current->data)
            return get_parent(current->left, node);
        else
            return get_parent(current->right, node);
    }

    void rotate_right(_Tree *node)
    {
        _Tree *parent = get_parent(ROOT, node);
        _Tree *left = node->left;
        if (parent && parent->left == node)
            parent->left = left;
        if (parent && parent->right == node)
            parent->right = left;
        node->left = left->right;
        left->right = node;
    }

    void rotate_left(_Tree *node)
    {
        _Tree *parent = get_parent(ROOT, node);
        _Tree *right = node->right;
        if (parent && parent->left == node)
            parent->left = right;
        if (parent && parent->right == node)
            parent->right = right;
        node->right = right->left;
        right->left = node;
    }

    AVL *avl_rotate_right(AVL *node)
    {
        AVL *left = node->left;
        node->left = left->right;
        left->right = node;

        update_node(node);
        update_node(left);

        return left;
    }

    AVL *avl_rotate_left(AVL *node)
    {
        AVL *right = node->right;
        node->right = right->left;
        right->left = node;

        update_node(node);
        update_node(right);

        return right;
    }

    RBT *rbt_rotate_right(RBT *node)
    {
        RBT *left = node->left;
        RBT* parent = node->parent;
        node->left = left->right;
        left->right = node;
        node->parent = left;
        left->parent = parent;
        return left;
    }

    RBT *rbt_rotate_left(RBT *node)
    {
        RBT *right = node->right;
        RBT* parent = node->parent;
        node->right = right->left;
        right->left = node;
        node->parent = right;
        right->parent = parent;
        return right;
    }

public:
    void rbt_insert(int value);
    void avl_insert(int value);
    void insert(int value)
    {
        insert_recursive(&ROOT, value);
    }

    void print()
    {
        if (A_ROOT)
        {
            print_recursive(A_ROOT);
        }
        else
        {
            LOG("No root found\n");
        }
    }

    _Tree *search(int value)
    {
        return recursive_search(ROOT, value);
    }

    void gotoxy(int x, int y)
    {
        printf("%c[%d;%df", 0x1B, y, x);
    }
    void clrscr(void)
    {
        system("clear");
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

    void print_tree_normal();
    void print_tree_avl();
    void print_tree_rbt();

    void delay(int x)
    {
        for (int i = x; i > 0; i--)
            for (int j = x; j > 0; j--)
            {
            }
    }

    void rotate_r(int value)
    {
        _Tree *node = search(value);
        rotate_right(node);
    }

    void rotate_l(int value)
    {
        _Tree *node = search(value);
        rotate_left(node);
    }
};

void Tree::print_tree_normal()
{
    clrscr();
    call_print(ROOT, 60, 0);
    LOG("\n\n");
}

void Tree::print_tree_avl()
{
    clrscr();
    call_print(A_ROOT, 60, 0);
    LOG("\n\n");
}

void Tree::print_tree_rbt()
{
    clrscr();
    call_print(RB_ROOT, 60, 0);
    LOG("\n\n");
}

// void Tree::recurse_print(Tree::_Tree *current, int x, int y)
// {
//     if (!current)
//         return;

//     gotoxy(x, y);
//     LOG(current->data);
//     if (current == ROOT)
//         gotoxy(x, y + 2);
//     else
//         gotoxy(x, y + 1);

//     int b = 0;

//     if (current->left && current->left->right && current->right && current->right->left)
//     {
//         b = 8;
//     }
//     int a = x;

//     if (current->left || current->right)
//         LOG("|");

//     if (current->left)
//     {
//         int i = b == 0 ? 3 : b - 4, j;

//         for (j = 1; j != i; j++)
//         {
//             gotoxy(a - (1 + j), y + (1 + j));
//             LOG("/");
//         }
//     }

//     if (current->right)
//     {
//         int i = b == 0 ? 3 : b - 4, j;

//         for (j = 1; j != i; j++)
//         {
//             gotoxy(a + (1 + j), y + (1 + j));
//             LOG("\\");
//         }
//     }

//     recurse_print(current->left, x - 3 - b, y + 4);
//     recurse_print(current->right, x + 3 + b, y + 4);
// }
// void Tree::recurse_print(Tree::AVL *current, int x, int y)
// {
//     if (!current)
//         return;

//     gotoxy(x, y);
//     LOG(current->data);
//     if (current == A_ROOT)
//         gotoxy(x, y + 2);
//     else
//         gotoxy(x, y + 1);

//     int b = 0;

//     if (current->left && current->left->right && current->right && current->right->left)
//     {
//         b = 8;
//     }
//     int a = x;

//     if (current->left || current->right)
//         LOG("|");

//     if (current->left)
//     {
//         int i = b == 0 ? 3 : b - 4, j;

//         for (j = 1; j != i; j++)
//         {
//             gotoxy(a - (1 + j), y + (1 + j));
//             LOG("/");
//         }
//     }

//     if (current->right)
//     {
//         int i = b == 0 ? 3 : b - 4, j;

//         for (j = 1; j != i; j++)
//         {
//             gotoxy(a + (1 + j), y + (1 + j));
//             LOG("\\");
//         }
//     }

//     recurse_print(current->left, x - 3 - b, y + 4);
//     recurse_print(current->right, x + 3 + b, y + 4);
// }