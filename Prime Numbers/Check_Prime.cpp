#include <iostream>
using namespace std;
bool IsPrime(int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)//(5,7,11,13,17,19,23,25)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    if (IsPrime(n))
    {
        cout << endl
             << n << " is a prime number.";
    }
    else
    {
        cout << endl
             << n << " is not a prime number.";
    }
}


