

#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    int arr[] = {-3, 3, 1, 6};

    int x = findZeroSubArray(arr);

    if (x == 0)
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}
