#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

const int pmxsz = 100000000;
int status[(pmxsz / 32) + 2];
int prime[5761455 + 5], noofprime = 0;
inline bool Bit_Check(int N, int pos) { return (bool)(N & (1 << pos)); }
inline int Bit_Set(int N, int pos) { return N = N | (1 << pos); }
inline bool PrimeCheck(int i) { return 1 ^ (bool)(Bit_Check(status[i >> 5], i & 31)); }
inline void PrimeSet(int i) { status[i >> 5] = Bit_Set(status[i >> 5], i & 31); }
inline void Mark(int i, int N)
{
    for (int j = i * i; j <= N; j += (i << 1))
    {
        PrimeSet(j);
    }
}

void sieve(int N)
{
    int i, j, sqrtN;
    sqrtN = int(sqrt(N));
    for (i = 5; i <= sqrtN; i += 6)
    {
        if (PrimeCheck(i))
        {
            Mark(i, N);
        }
        if (PrimeCheck(i + 2))
        {
            Mark(i + 2, N);
        }
    }
    prime[noofprime++] = 2;
    prime[noofprime++] = 3;

    for (i = 5; i <= N; i += 6)
    {
        if (PrimeCheck(i))
        {
            prime[noofprime++] = i;
        }
        if (PrimeCheck(i + 2))
        {
            prime[noofprime++] = i + 2;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve(100000000);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << prime[prime[i] - 1] << " ";
    }
    return 0;
}