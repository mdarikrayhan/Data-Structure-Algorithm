/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
//Same as sieving till root but half the operation and memory by half 
//but same time is required to find the prime number
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 1000;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    is_prime[2] = true;
    for (int j = 2 * 2; j <= n; j += 2)
    {
        is_prime[j] = false;
    }

    for (int i = 3; i * i <= n; i = i + 2)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {

                is_prime[j] = false;
            }
        }
    }
    
    // শুধু প্রিন্ট জন্য 
    for(int i=0;i<=n;i++)
    {
        if(is_prime[i])
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
/*
Number of data              Time(ms)
1                             0.001
10                            0.003
100                           0.007
1000                          0.075
10000                         0.650
100000                        6.791
1000000                      57.975
10000000                    497.786
100000000                  5204.380
1000000000                64579.900
*/ 