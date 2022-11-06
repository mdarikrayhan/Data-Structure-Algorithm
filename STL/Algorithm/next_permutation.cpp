/*Rearranges the elements in the range [first,last) in
  to the next lexicographically greater permutation.  */
#include <iostream>
#include <algorithm>
using namespace std;
void print(int a[], int n);
int main()
{
  int myints[] = {1, 4, 3}, n = 3;

  sort(myints, myints + n);
  /*sort to see all the combinations of lower to higher
  dont sort if you want to see only the next higher permutation*/

  cout << "The n! possible permutations with 3 elements:\n";
  /*first it will print the original array then
    it will print the next higher permutation  */
  do
  {
    print(myints, n);
  } while (next_permutation(myints, myints + n));

  cout << "After loop: ";
  print(myints, n); // sorted array asending order

  return 0;
}

void print(int a[], int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}