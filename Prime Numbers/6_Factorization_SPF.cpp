#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
//Used: 265 ms, 41764 KB 10^6
int spf[MAXN];
vector<int> factor[MAXN];
inline vector<int> getFactorization(int x)
{
	vector<int> ret;
	while (x != 1)
	{
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	return ret;
}
void sievefactor()
{
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)
	{
		spf[i] = i;
	}
	for (int i = 4; i < MAXN; i += 2)
	{
		spf[i] = 2;
	}
	for (int i = 3; i * i < MAXN; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j < MAXN; j += i)
				if (spf[j] == j)
				{
					spf[j] = i;
				}
		}
	}
	for (int i = 1; i <= MAXN; i++)
	{
		factor[i] = getFactorization(i);
	}
}



int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sievefactor();
	return 0;
}

