/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    const int N = 100000000;
    vector<int> lp(N + 1);
    vector<int> pr;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
        {
            lp[i * pr[j]] = pr[j];
        }
    }
    return 0;
}
//Used: 873 ms, 440684 KB 10^8
