#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    vector<int> unsized;
    unsized.push_back(1);
    unsized.push_back(2);
    unsized.push_back(3);
    // initialize vector with 5 elements
    vector<int> sized(5);
    // initialize vector with 1
    vector<int> sized2(5, 1);
    // initialize vector with values
    vector<int> sized3 = {1, 1, 2, 3, 4, 5};

    // copy vector to another vector
    vector<int> sized4 = sized3;
    vector<int> sized5(sized3);
    vector<int> sized6(sized3.begin(), sized3.end());
    vector<int> sized7(sized3.begin(), sized3.begin() + 3); // copy first 3 elements

    int mini = *min_element(sized3.begin(), sized3.end());
    int maxi = *max_element(sized3.begin(), sized3.end());
    int sum = accumulate(sized3.begin(), sized3.end(), 0);
    // count number of 1 in vector
    int cnt = count(sized3.begin(), sized3.end(), 1);
    // count number of even numbers in vector
    int cnt2 = count_if(sized3.begin(), sized3.end(), [](int x)
                        { return x % 2 == 0; });
    // find index of 3 in vector
    auto it = find(sized3.begin(), sized3.end(), 3);
    int index = it - sized3.begin();

    sort(sized3.begin(), sized3.end());
    reverse(sized3.begin(), sized3.end());
    // remove all 1 from vector
    sized3.erase(remove(sized3.begin(), sized3.end(), 1), sized3.end());
    // remove all even numbers from vector
    sized3.erase(remove_if(sized3.begin(), sized3.end(), [](int x)
                           { return x % 2 == 0; }),
                 sized3.end());
    // remove all elements from vector
    sized3.clear();

    // print vector
    for (int i : sized3)
        cout << i << " ";
    cout << nl;

    for (auto it = sized3.rbegin(); it != sized3.rend(); it++)
        cout << *it << " ";
    cout << nl;
    for (auto it = sized3.begin(); it != sized3.end(); it++)
        cout << it - sized3.begin() << " ";
    cout << nl;

    return 0;
}