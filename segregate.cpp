// segregate 0's and 1's by traversing only once in an array
// 0's on left and 1's on right
#include <iostream>
using namespace std;

// One way to do it is count the 0's and 1's and then allocate them in the array
void count_method(int a[], int n)
{
  int c = 0;

  for (int i = 0; i < n; i++)
  {
    if (a[i] == 0)
      c++;
  }
  for (int i = 0; i < c; i++)
  {
    a[i] = 0;
  }
  for (int i = c; i < n; i++)
  {
    a[i] = 1;
  }
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
}

// Another method which is purely based on single traversal is on the way that we maintain two pointers first and last where moving from left(first)
// if we find a[first]=1, swap(a[first], a[last]) and then last-- bcos we have found 1 '1' at the last, otherwise in else we do first++(outside the if condition)

void single_traverse(int a[], int n)
{
  int first = 0, last = n - 1;
  while (first < last)
  {
    if (a[first] != 0)
    {
      swap(a[first], a[last]);
      // now the last element has 1 for sure
      last--;
    }
    else
    {
      first++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
}

int main()
{
  int a[] = {1, 0, 1, 1, 0, 1, 0};
  int n = sizeof(a) / sizeof(a[0]);
  // count_method(a, n);
  single_traverse(a, n);
  return 0;
}
