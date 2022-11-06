/*Rearranges the elements in the range [first,last) in
  to the next lexicographically lower permutation.  */
#include <iostream>
#include <algorithm>
using namespace std;
void print(int a[], int n);
int main()
{
  int myints[] = {1, 4, 3}, n = 3;

  sort(myints, myints + n, greater<int>());
  /*sort to see all the combinations of higher to lower
  dont sort if you want to see only the next lower permutation*/

  cout << "The n! possible permutations with 3 elements:\n";
  /*first it will print the original array then
    it will print the next lower permutation  */
  do
  {
    print(myints, n);
  } while (prev_permutation(myints, myints + n));

  cout << "After loop: ";
  print(myints, n); // sorted array descending order

  return 0;
}

void print(int a[], int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}