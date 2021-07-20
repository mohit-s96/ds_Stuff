// Draws a binary tree representation on the console / terminal
#include <iostream>
#define LOG(x) std::cout << x;


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

    void recurse_print(_Tree*,int, int);

public:
    void insert(int value)
    {
        insert_recursive(&ROOT, value);
    }

    void gotoxy(int x,int y)    
    {
        printf("%c[%d;%df",0x1B,y,x);
    }

    void clrscr(void)
    {
        system("clear");
    }

    void print_tree();


    //delay slows the execution allowing us to see the insertion of nodes at each step
    void delay(int x)
    {
        for(int i=x;i>0;i--)
            for(int j=x;j>0;j--)
        {

        }
    }
};

void Tree::print_tree()
{
    clrscr();
    recurse_print(ROOT, 60, 0);
    LOG("\n\n");
}

void Tree::recurse_print(Tree::_Tree* current, int x, int y)
{
    if(!current)
        return;

    gotoxy(x, y);
    LOG(current->data);
    
    if(current == ROOT) gotoxy(x, y + 2);
    else gotoxy(x, y + 1);

    int b  = 0;

    if(current->left && current->left->right && current->right && current->right->left)
    {
        b = 8;
    } 
    int a = x;
    
    if(current->left || current->right) LOG("|");

    if(current->left)
    {
        int i = b == 0 ? 3 : b - 4, j;

        for(j = 1; j != i ; j++)
        {
            gotoxy(a - (1 + j), y + (1 + j));
            LOG("/");
        }
    }

    if(current->right)
    {
        int i = b == 0 ? 3 : b - 4, j;

        for(j = 1; j != i ; j++)
        {
            gotoxy(a + (1 + j), y + (1 + j));
            LOG("\\");
        }
    }

    recurse_print(current->left, x - 3 - b, y + 4);
    recurse_print(current->right, x + 3 + b, y + 4);
    
}

int main()
{
    Tree T;

    T.insert(7);
    T.print_tree();
    T.delay(15000);

    T.insert(3);
    T.print_tree();
    T.delay(15000);

    T.insert(12);
    T.print_tree();
    T.delay(15000);

    T.insert(1);
    T.print_tree();
    T.delay(15000);

    T.insert(6);
    T.print_tree();
    T.delay(15000);

    T.insert(0);
    T.print_tree();
    T.delay(15000);

    T.insert(2);
    T.print_tree();
    T.delay(15000);

    T.insert(4);
    T.print_tree();
    T.delay(15000);

    T.insert(5);
    T.print_tree();
    T.delay(15000);

    T.insert(9);
    T.print_tree();
    T.delay(15000);

    T.insert(13);
    T.print_tree();
    T.delay(15000);

    T.insert(8);
    T.print_tree();
    T.delay(15000);

    T.insert(11);
    T.print_tree();
    T.delay(15000);

    T.insert(15);
    T.print_tree();
    T.delay(15000);

    T.insert(10);
    T.print_tree();
    T.delay(15000);

    T.insert(14);
    T.print_tree();

    LOG("Press return to exit\n");

    std::cin.get();
    return 0;
}