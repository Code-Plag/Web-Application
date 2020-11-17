// C++ program to print diamond shape
// with 2n rows
#include <bits/stdc++.h>
using namespace std;

// Prints diamond pattern with 2n rows
void printDiamond(int n)
{
	int space = n - 1;

	// run loop (parent loop)
	// till number of rows
	int i = 0;
	while ( i < n )
	{
		// loop for initially space,
		// before star printing
		int j = 0;
		while (j < space )
        {
            cout << " ";
            j++;
        }

		// Print i+1 stars
		j = 0;
		while (j <= i )
			{
                cout << "* ";
                j++;
			}
		cout << endl;
		space--;
		i++;
	}

	// Repeat again in reverse order
	space = 0;

	// run loop (parent loop)
	// till number of rows
	i = n;
	while (  i > 0)
	{
		// loop for initially space,
		// before star printing
		int j = 0;
		while ( j < space)
        {
            cout << " ";
            j++;
        }

		// Print i stars
		j = 0;
		while (j < i)
			{
                cout << "* ";
                j++;
			}
		cout << endl;
		space++;
		 i--;
	}

	space = n - 1;

	i = 0;
	while ( i < n )
	{
		// loop for initially space,
		// before star printing
		int j = 0;
		while (j < space )
        {
            cout << " ";
            j++;
        }

		// Print i+1 stars
		j = 0;
		while (j <= i )
			{
                cout << "* ";
                j++;
			}
		cout << endl;
		space--;
		i++;
	}

	// Repeat again in reverse order
	space = 0;

	// run loop (parent loop)
	// till number of rows
	i = n;
	while (  i > 0)
	{
		// loop for initially space,
		// before star printing
		int j = 0;
		while ( j < space)
        {
            cout << " ";
            j++;
        }

		// Print i stars
		j = 0;
		while (j < i)
			{
                cout << "* ";
                j++;
			}
		cout << endl;
		space++;
		 i--;
	}
}

// Driver code
int main()
{
	printDiamond(5);
	return 0;
}

// This is code is contributed
// by rathbhupendra


