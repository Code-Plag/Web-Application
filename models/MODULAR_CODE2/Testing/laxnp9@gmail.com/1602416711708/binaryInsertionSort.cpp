#include <iostream>
#include <cmath>
using namespace std;
//4 2 3 5 7 1
//2 4 3 5 7 1
//2 3 4 5 7 1
//2 3 4 5 7 1
//2 3 4 5 7 1

//2 3 4 5 7 7
//2 3 4 5 5 7
//2 3 4 4 5 7
//2 3 3 4 5 7
//2 2 3 4 5 7
//1 2 3 4 5 7

int binarysearch(int A[], int start, int end, int key)
{
    if (start == end && key < A[start])
    {

        return start;
    }
    else if (start == end && key >= A[start])
    {
        return start + 1;
    }
    int mid = (start + end) / 2;

    if (key > A[mid])
    {
        return binarysearch(A, mid + 1, end, key);
    }
    else
    {
        return binarysearch(A, start, mid, key);
    }
}
void insertionSort(int A[], int size)
{
    for (int j = 1; j < size; j++)
    {

        int key = A[j];
        int i = j - 1;
        if (key > A[i])
            continue;
        int pos = binarysearch(A, 0, i, key);
        cout << " Correct postion of " << key << " is : " << pos << endl;
        for (int k = i; k >= pos; k--)
        {
            A[k + 1] = A[k];
        }
        A[pos] = key;

        cout << "After " << j << "th"
             << " pass" << endl;
        for (int i = 0; i < size; i++)
        {

            cout << A[i] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "before Sorting " << endl;
    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }

    cout << endl;

    insertionSort(arr, size);
    cout << "After  Sorting " << endl;

    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }

    return 0;
}