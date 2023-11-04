#include <iostream>
using namespace std;

int ks(int n, int W, int p[], int w[])
{
    // Create a 2D array 'arr' to store intermediate results
    int arr[n + 1][W + 1];

    // Create an array 'x' to track selected items (0 or 1)
    int x[20] = {0};

    // Initialize the dynamic programming table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                arr[i][j] = 0; // Base case: no items or no capacity
            }
            else if (w[i - 1] <= j)
            {
                // Calculate the maximum value considering the current item
                arr[i][j] = max(arr[i - 1][j - w[i - 1]] + p[i - 1], arr[i - 1][j]);
            }
            else
            {
                // If the item's weight is greater than the current capacity, skip it
                arr[i][j] = arr[i - 1][j];
            }
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Backtrack to find the selected items
    int i = n;
    int j = W;
    while (i > 0 && j > 0)
    {
        if (arr[i][j] != arr[i - 1][j])
        {
            x[i - 1] = 1;     // Mark item 'i-1' as selected
            j = j - w[i - 1]; // Subtract the weight of the selected item
        }
        i--;
    }

    // Print the selected items
    cout << "Selected items: ";
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << "\nmax Profit:: ";

    // Return the maximum profit obtained
    return arr[n][W];
}

int main()
{
    int n;
    cout << "Enter number of items: \n";
    cin >> n;
    int W;
    cout << "Enter Capacity: \n";
    cin >> W;

    int p[n];
    int w[n];

    // Input the profit and weight values for each item
    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and weight values for item " << i << endl;
        cin >> p[i] >> w[i];
    }

    // Call the knapsack function and print the maximum profit
    cout << ks(n, W, p, w);

    return 0;
}

/*
        OUTPUT
----------------------------------
Enter number of items:
4
Enter Capacity:
7
Enter profit and weight values: 0
1 1
Enter profit and weight values: 1
4 3
Enter profit and weight values: 2
5 4
Enter profit and weight values: 3
7 5

0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1
0 1 1 4 5 5 5 5
0 1 1 4 5 6 6 9
0 1 1 4 5 7 8 9

Selected items: 0 1 1 0
max Profit:: 9

*/
/*
#include <iostream>
using namespace std;

int kp(int n,int W,int p[],int w[]){
    int mat[n+1][W+1];
    for (int i = 0; i <= n; i++)
    {
            for (int j = 0; j <= W; j++)
            {
                if (i==0 || j==0)
                {
                    mat[i][j]=0;
                }

                else if (w[i-1] <= j)
                {
                    mat[i][j] = max( mat[i-1][j-w[i-1]]+p[i-1], mat[i-1][j]);
                }

                else{
                    mat[i][j] = mat[i-1][j];
                }
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
    }
    int i= n;
    int j= W;
    while (i>0 && j>0){
        if (mat[i][j]==mat[i-1][j-1])
        {
            cout<<"0"<<" "<<i--;
        }
        else
        {
            cout<<"1"<<" "<<i--<<j=j-w[i];
        }
    }

    return mat[n][W];
}

int main(){
    int n;
    cout<<"Enter number of items:\n";
    cin>>n;

    int W;
    cout<<"Enter Capacity:\n";
    cin>>W;

    int p[n],w[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter profit and weight value:: \n";
        cin>>p[i]>>w[i];
    }
    cout<<"Max Profit::\n"<<kp(n,W,p,w);
    return 0;
}
*/
