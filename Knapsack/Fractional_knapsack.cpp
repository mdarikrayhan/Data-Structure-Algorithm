#include <bits/stdc++.h>
using namespace std;
int main()
{
    double tweight = 0, tprofit = 0, profit = 0, weight = 0, ratio = 0;
    int nobj = 0;
    //cout << "Enter the wieght of knapsack : ";
    cin >> tweight;
    //cout << "Enter the number of objects : ";
    cin >> nobj;
    vector<double> input[nobj];

    for (int i = 0; i < nobj; i++)
    {
        //cout << "Enter the profit of Obj " << i + 1 << " : ";
        cin >> profit;
        //cout << "Enter the weight of Obj " << i + 1 << " : ";
        cin >> weight;
        ratio = profit / weight;
        input[i].push_back(profit); // push profit to index i
        input[i].push_back(weight); // push weight to index i
        input[i].push_back(ratio);  // push  ratio to index i
    }

    // sorting the vector in decending order(Bubble sort) to get large values at frist
    for (int i = 0; i < nobj - 1; i++)
    {
        for (int j = 0; j < nobj - i - 1; j++)
        {
            if (input[j][2] < input[j + 1][2]) // comparism using ratio
            {
                vector<double> temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < nobj; i++)
    {
        if (tweight == 0) // to check if the knapsack is full
        {
            break;
        }
        else if (tweight >= input[i][1])
        {
            tweight = tweight - input[i][1]; // reduces the knapsack capacity
            tprofit = tprofit + input[i][0]; // increases the total profit
        }
        else if (tweight < input[i][1]) // if we need the fraction of the last object
        {
            tprofit = tprofit + (tweight * (input[i][0] / input[i][1]));
            tweight = 0;
        }
    }
    cout << "The maximum profit is : " << tprofit;
}