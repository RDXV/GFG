// Given an array A[] of size n. The task is to find the largest element in it.
#include <iostream>
#include <climits>
using namespace std;

int largest(int a[], int n)
{
  int big = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (big < a[i])
    {
      big = a[i];
    }
  }
  return big;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    /* code */
    cin >> a[i];
  }
  cout << largest(a, n);
}
