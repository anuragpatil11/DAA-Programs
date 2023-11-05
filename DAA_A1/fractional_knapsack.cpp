#include <iostream>

using namespace std;
class Item
{
public:
    float p, w, pw, x, element;
};

void kp(int n, int W, Item obj[])
{

    float tp = 0;
    for (int i = 0; i < n; i++)
    {
        obj[i].x = 0.0;
    }

    for (int i = 0; i < n; i++)
    {
        if (W > obj[i].w)
        {
            obj[i].x = 1.0;
            tp = tp + obj[i].p;
            W = W - obj[i].w;
        }

        else
        {
            obj[i].x = double(W) / obj[i].w;
            tp = tp + ((double(W) / obj[i].w) * double(obj[i].p));
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (obj[j].element < obj[j + 1].element)
            {
                swap(obj[j], obj[j + 1]);
            }
        }
    }
    cout << "\n\nelement"
         << " "
         << " track\n";
    for (int i = 0; i < n; i++)
    {
        cout << obj[i].element << " " << obj[i].x << endl;
    }

    cout << "\nTotal Profit::\n"
         << tp;
}
int main()
{
    int n;
    cout << "Enter number of items::\n";
    cin >> n;
    int W;
    cout << "Enter Capacity::\n";
    cin >> W;
    Item obj[n];
    int j = 1;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Profit and Weight " << i + 1 << " ::\n";
        cin >> obj[i].p >> obj[i].w;
        obj[i].element = j;
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        obj[i].pw = obj[i].p / obj[i].w;
    }
    cout << "\nElement:: ";
    for (int i = 0; i < n; i++)
    {
        cout << obj[i].element << " ";
    }
    cout << "\nProfit:: ";
    for (int i = 0; i < n; i++)
    {
        cout << obj[i].p << " ";
    }
    cout << "\nWeight:: ";
    for (int i = 0; i < n; i++)
    {
        cout << obj[i].w << " ";
    }
    cout << "\nProfit Weight Ratio:: ";
    for (int i = 0; i < n; i++)
    {
        cout << obj[i].pw << " ";
    }

    cout << "\n\nAfter sorting::\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obj[j].pw < obj[j + 1].pw)
            {
                swap(obj[j], obj[j + 1]);
            }
        }
    }
    cout << "\nProfit:: ";
    for (int i = 0; i < n; i++)
    {
        cout << obj[i].p << " ";
    }
    cout << "\nWeight:: ";
    for (int i = 0; i < n; i++)
    {
        cout << obj[i].w << " ";
    }
    cout << "\nProfit Weight Ratio:: ";
    for (int i = 0; i < n; i++)
    {
        cout << obj[i].pw << " ";
    }

    kp(n, W, obj);

    return 0;
}
/*
OUTPUT
Enter number of items::
4
Enter Profit and Weight 1 ::
1 1
Enter Profit and Weight 2 ::
4 3
Enter Profit and Weight 3 ::
5 4
Enter Profit and Weight 4 ::
7 5

Element:: 1 2 3 4
Profit:: 1 4 5 7
Weight:: 1 3 4 5
Profit Weight Ratio:: 1 1.33333 1.25 1.4

After sorting::

Profit:: 7 4 5 1
Weight:: 5 3 4 1
Profit Weight Ratio:: 1.4 1.33333 1.25 1

element  track
4 1
3 0
2 0.666667
1 0

Total Profit::
9.66667

*/
/*
#include <iostream>
#include <algorithm>

using namespace std;

void knapsack(int n, float W, float p[], float w[])
{
    float x[20], tp = 0;
    float u = W; // Change 'int u' to 'float u'

    for (int i = 0; i < n; i++)
    {
        x[i] = 0.0;

        if (u > w[i])
        {
            x[i] = 1.0;
            u = u - w[i];
            tp = tp + p[i];
        }
        else
        {
            x[i] = u / w[i]; // Use fractional part of the item
            tp = tp + (x[i] * p[i]);
            break; // Add a 'break' to exit the loop when knapsack is full
        }
    }

    cout << "Result vector is: ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << x[i];
    }
    cout << "\nTotal profit is " << tp;
}

int main()
{
    int n;

    cout << "Enter number of Objects: ";
    cin >> n;

    float p[n], w[n], W;

    // Initialize arrays with appropriate sizes after knowing 'n'

    cout << "Enter Capacity: ";
    cin >> W;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight for object " << i + 1 << ": ";
        cin >> w[i];
        cout << "Enter profit for object " << i + 1 << ": ";
        cin >> p[i];
    }

    float ratio[n];
    for (int i = 0; i < n; i++)
    {
        ratio[i] = p[i] / w[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                swap(ratio[i], ratio[j]);
                swap(p[i], p[j]);
                swap(w[i], w[j]);
            }
        }
    }

    knapsack(n, W, p, w);

    return 0;
}
*/
