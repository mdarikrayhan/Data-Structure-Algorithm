#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b)
{
	return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int> > K(n + 1, vector<int>(W + 1));
	
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
			{
				K[i][w] = 0;
			}
			else if (wt[i - 1] <= w)
			{
				K[i][w] = max(val[i - 1] +K[i - 1][w - wt[i - 1]],K[i - 1][w]);
			}
			else
			{
				K[i][w] = K[i - 1][w];
			}
		}
	}
	return K[n][W];
}
int main()
{
	int num, W;
	// cout<<"Enter number of items : ";
	cin >> num;
	int val[num], wt[num];
	for (int i = 0; i < num; i++)
	{
		cin >> val[i];
		cin >> wt[i];
	}
	// cout<<"Enter the weight : ";
	cin >> W;
	int n = sizeof(val) / sizeof(val[0]);

	cout << knapSack(W, wt, val, n) << endl;

	return 0;
}
