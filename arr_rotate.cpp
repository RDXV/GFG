#include <iostream>
using namespace std;
// rotate arr[] of size n by d elements

// n=6, arr[]=1 3 5 7 8 9, d=3
// Method 1 - using temp array

void rotate_temp(int arr[], int n, int d)
{
  int temp[100];
  int c = 0;
  for (int i = n - d; i < n; i++)
  {
    temp[c++] = arr[i];
    // cout << arr[i] << " ";
  }
  for (int i = 0; i < n - d; i++)
  {
    temp[c++] = arr[i];
  }

  int size_temp = c;
  for (int i = 0; i < size_temp; i++)
  {
    cout << temp[i] << " ";
  }
}

void leftrotate(int a[], int n)
{
  int temp = a[0], i;
  for (i = 0; i < n - 1; i++)
  {
    a[i] = a[i + 1];
  }
  a[n - 1] = temp;
}

void rotate_by_one(int a[], int n, int d)
{
  for (int i = 0; i < d; i++)
  {
    leftrotate(a, n);
  }
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
}

int main()
{
  int a[100], n, d;
  cout << "enter size of array and elements to be shifted from - ";
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> d;
  d = d % n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  // rotate_temp(a, n, d);
  rotate_by_one(a, n, d);
  return 0;
}
