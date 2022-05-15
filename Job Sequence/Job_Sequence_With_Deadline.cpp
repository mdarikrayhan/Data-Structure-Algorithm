#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, profit = 0, deadline = 0, name = 0, max = 0;
    // cout << "Enter the number of activity : ";
    cin >> n;
    vector<int> input[n];
    for (int i = 0; i < n; i++)
    {
        // cout << "Enter the End time of Activiy " << i + 1 << " : ";
        cin >> deadline;
        if (max < deadline)
        {
            max = deadline;
        }
        // cout << "Enter the Profit of Activiy " << i + 1 << " : ";
        cin >> profit;
        name = i+1;
        input[i].push_back(deadline);
        input[i].push_back(profit);
        input[i].push_back(name);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (input[j][1] < input[j + 1][1])
            {
                vector<int> temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }

    int result[max]={0};
    for (int i = 0; i < n; i++)
    {
        for (int j = input[i][0] - 1; j >= 0; j--)
        {
            if (result[j] == 0)
            {
                result[j] = input[i][2];         
                break;
            }
        }
    }
    for (int i = 0; i < max; i++)
    {
        if (result[i]!=0)
        {
            cout << result[i] << " ";
        }
    }
    return 0;
}
