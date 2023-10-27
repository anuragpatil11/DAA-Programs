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
            tp = tp + ((u / w[i]) * p[i]);
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
                float temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                // profit
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
                // weight
                temp = w[j];
                w[j] = w[i];
                w[i] = temp;
            }
        }
    }

    knapsack(n, W, p, w);

    return 0;
}

/*
OUTPUT

Enter number of Objects: 3
Enter Capacity: 50

Enter weight for object 1: 20
Enter profit for object 1: 100
Enter weight for object 2: 10
Enter profit for object 2: 60
Enter weight for object 3: 30
Enter profit for object 3: 120

Result vector is:  1 1 0.666667
Total profit is 240

#include <iostream>
using namespace std;
class Item
{
public:
    int weight;
    int value;
    double vw;
};

void BubbleSort(Item obj[], int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (obj[j].vw < obj[j + 1].vw)
            {
                swap(obj[j + 1], obj[j]);
            }
        }
    }
}
double fractionKnapsack(Item obj[], int capacity, int num)
{
    BubbleSort(obj, num);
    double profit = 0.0;
    for (int i = 0; i < num; i++)
    {
        if (obj[i].weight <= capacity)
        {
            profit = profit + obj[i].value;
            capacity = capacity - obj[i].weight;
        }
        else
        {
            profit = profit + (double(obj[i].value) * (double(capacity) / obj[i].weight));
            break;
        }
    }
    return profit;
}

int main()
{
    int numOfItem;
    cout << "Enter Number fo Item :- ";
    cin >> numOfItem;
    int capacity;
    cout << "Enter Capacity Of Bag :- ";
    cin >> capacity;
    Item obj[numOfItem];
    // obj[0].weight = 10;
    // cout<<obj[0].weight;
    for (int i = 0; i < numOfItem; i++)
    {
        cout << "Entet Weight Of Item :- ";
        cin >> obj[i].weight;
        cout << "Enter Value Of Item :- ";
        cin >> obj[i].value;
        obj[i].vw = obj[i].value / double(obj[i].weight);
    }
    cout << "\n";
    for (int i = 0; i < numOfItem; i++)
    {
        cout << "Weight Of Item :- " << obj[i].weight << "\n";
        cout << "Value Of Item :- " << obj[i].value << "\n";
        cout << "ratio of value and weight :- " << obj[i].vw << "\n";
    }
    cout << "\n";
    BubbleSort(obj, numOfItem);
    for (int i = 0; i < numOfItem; i++)
    {
        cout << "Weight Of Item :- " << obj[i].weight << "\n";
        cout << "Value Of Item :- " << obj[i].value << "\n";
        cout << "ratio of value and weight :- " << obj[i].vw << "\n";
    }
    cout << "\n"
         << fractionKnapsack(obj, capacity, numOfItem);
    return 0;
}
*/
