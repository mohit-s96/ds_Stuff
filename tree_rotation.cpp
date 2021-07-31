#include "tree.h"

int main()
{
    Tree T;

    T.insert(7);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(3);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(12);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(1);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(6);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(0);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(2);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(4);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(5);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(9);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(13);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(8);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(11);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(15);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(10);
    T.print_tree_normal();
    T.delay(15000);

    T.insert(14);
    T.print_tree_normal();

    // T.rotate_r(12);

    T.rotate_l(9);

    T.print_tree_normal();

    LOG("Press return to exit\n");

    std::cin.get();
    return 0;
}