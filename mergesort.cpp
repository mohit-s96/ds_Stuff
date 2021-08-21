#include <iostream>
#define LOG(x) std::cout << x;

class Array
{
private:
    int length;
    int* array = nullptr;

    void divideArray(int* arr, int n)
    {
        if(n < 2) return;
        int leftLength = 0, rightLength = 0;
        leftLength = n/2;
        rightLength = n - leftLength;

        int* leftSubArray = new int[leftLength];
        int* rightSubArray = new int[rightLength];

        int i = 0;
        while(i < leftLength)
        {
            leftSubArray[i] = arr[i];
            i++;
        }
        i = 0;
        int j = leftLength;
        while(j < n)
        {
            rightSubArray[i++] = arr[j++];
        }

        divideArray(leftSubArray, leftLength);
        divideArray(rightSubArray, rightLength);
        _merge(leftSubArray, rightSubArray, arr, leftLength, rightLength, n);

        delete[] leftSubArray;
        delete[] rightSubArray;
    }

    void _merge(int* a, int* b, int* x, int k, int l, int m)
    {
        int p = 0, q = 0, r = 0;
        while(p < k && q < l)
        {
            if(a[p] < b[q])
            {
                x[r] = a[p];
                p++;
            }
            else
            {
                x[r] = b[q];
                q++;
            }
            r++;
        }
        while(p < k)
        {
            x[r++] = a[p++];
        }
        while(q < l)
        {
            x[r++] = b[q++];
        }
    }
public:
    Array(int x, int* arr):
    length(x){
        array = new int[x];
        int i = 0;
        while(i < x)
        {
            array[i] = arr[i];
            i++;
        }
    }

    int getLength() {return this->length;}

    void print()
    {
        int n = this->length, i = 0;
        while(i < n)
        {
            LOG(this->array[i++]);
            LOG(" ");
        }
    }


    void mergeSort()
    {
        divideArray(array, length);
    }

};

int main()
{
    int length = 10;
    int arr[10] = {14, 6, 78, 25, 3, 36, 9, 2, 69, 102};
    Array a = Array(length, arr);
    a.mergeSort();
    a.print();
    LOG("\n");
    return 0;
}