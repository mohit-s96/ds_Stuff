#pragma once
#include <iostream>
#define LOG(x) std::cout << x;
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}
void clrscr(void)
{
    system("clear");
}
template <typename T>
void print_fn(T *current, int x, int y, T* ROOT)
{
    if (!current)
        return;

    gotoxy(x, y);
    LOG(current->data);
    if (current == ROOT)
        gotoxy(x, y + 2);
    else
        gotoxy(x, y + 1);

    int b = 0;

    if (current->left && current->left->right && current->right && current->right->left)
    {
        b = 8;
    }
    int a = x;

    if (current->left || current->right)
        LOG("|");

    if (current->left)
    {
        int i = b == 0 ? 3 : b - 4, j;

        for (j = 1; j != i; j++)
        {
            gotoxy(a - (1 + j), y + (1 + j));
            LOG("/");
        }
    }

    if (current->right)
    {
        int i = b == 0 ? 3 : b - 4, j;

        for (j = 1; j != i; j++)
        {
            gotoxy(a + (1 + j), y + (1 + j));
            LOG("\\");
        }
    }

    print_fn(current->left, x - 3 - b, y + 4, ROOT);
    print_fn(current->right, x + 3 + b, y + 4, ROOT);
}

template <typename S>
void call_print(S* ROOT_, int a, int b)
{   
    print_fn<S>(ROOT_, a, b, ROOT_);
}