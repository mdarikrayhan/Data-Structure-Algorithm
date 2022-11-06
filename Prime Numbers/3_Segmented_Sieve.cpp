/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int count_primes(int n)
{
    const int S = 10000;

    vector<int> primes; // sqrt(n) পর্যন্ত যত প্রাইম আছে এইখানে থাকবে
    int nsqrt = sqrt(n);

    // সিভ দিয়ে sqrt পর্যন্ত প্রাইম নাম্বার বের করে তা vector primes এ রাখা হবে এখানে 
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;//যতগুলো প্রাইম আছে তা গননা করার জন্য 

    vector<char> block(S);
    for (int k = 0; k * S <= n; k++)
    {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes)
        {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }

        if (k == 0)//প্রথম ব্লকটিতে ০,১ আছে যা প্রাইম না তাই এখানে false করা হয়েছে
            block[0] = block[1] = false;


        for (int i = 0; i < S && start + i <= n; i++)
        {
            if (block[i])
                result++;
        }
    }

    return result;
}

int main()
{
    cout << count_primes(100) << nl;
    return 0;
}
// can count prime numbers upto 10^8 in 1200ms