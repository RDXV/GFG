#include <iostream>
#include "algorithm"
using namespace std;

int main()
{
  int a[] = {4, 2, 1, 6, 9};
  int n = sizeof(a) / sizeof(a[0]);
  sort(a, a + n);
  int i, j;
  for (i = 0, j = n - 1; i < j; i++, j--)
  {
    cout << a[i] << " " << a[j] << " ";
  }
  // for odd total numbers 2 times repeated, end will be the middle element
  if (n % 2 != 0)
  {
    cout << a[i];
  }
  return 0;
}