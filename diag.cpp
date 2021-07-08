#include <iostream>
#define LOG(x) std::cout << x;

void printDiag(int x[4][4] )
{
    int n = 4;
    LOG("Principal\t");
    LOG("Secondary\n");
    for(int i = 0 ; i < n ; i++)
    {
        LOG(x[i][i]);
        LOG("\t\t\t");
        LOG(x[i][n - i - 1]);
        LOG("\n");
    }
}

int main()
{
    int x[4][4] = {
        {1, 2, 3, 10},
        {4, 5, 6, 11}, 
        {7, 8, 9, 12},
        {45, 46, 47, 13}
    };
    printDiag(x);
}