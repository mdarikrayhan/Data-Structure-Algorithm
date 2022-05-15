#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0, start = 0, end = 0, name = 0, findex = 0, sindex = 0;
    //cout << "Enter the number of activity : ";
    cin >> n;
    vector<int> input[n];
    for (int i = 0; i < n; i++)
    {
        //cout << "Enter the Start time of Activiy " << i + 1 << " : ";
        cin >> start;
        //cout << "Enter the End time of Activiy " << i + 1 << " : ";
        cin >> end;
        char name;
        cin>>name;
        input[i].push_back(start);
        input[i].push_back(end);
        input[i].push_back(name);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (input[j][1] > input[j + 1][1])
            {
                vector<int> temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        char c =input[i][2];
        cout<<c<<" "<<input[i][0]<<" "<<input[i][1]<<endl;
    }
    cout << "Following activities are selected :";
    findex = 0;
    char c=input[findex][2];
    cout << " " <<c;
    for (sindex = 1; sindex < n; sindex++)
    {
        if (input[sindex][0] >= input[findex][1])
        {
            char c =input[sindex][2];
            cout << " " << c;
            findex = sindex;
        }
    }
    return 0;
}
