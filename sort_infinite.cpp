// https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
// Given infinite numbers(meaning no end or size of array, find an element in the array)
#include <iostream>
using namespace std;

int bs(int a[], int high, int low, int key)
{
  int f = low, s = high;
  int mid;
  while (f <= s)
  {
    mid = (f + s) / 2;
    cout << a[mid] << " ";
    if (key == a[mid])
    {
      return key;
    }
    else if (key < a[mid]) // a[mid] greater than key
    {
      s = mid - 1;
    }
    else
    {
      f = mid + 1;
    }
  }
  return -1;
}

int find_ans(int a[], int key)
{
  int high, low;
  low = 0;
  high = 1;
  int val = a[high];
  while (val < key)
  {
    low = high;
    high = high * 2;
    val = a[high];
  }
  // now we would get the correct range
  cout << "low is " << low << " high is " << high << "\n";
  return bs(a, high, low, key);
}
int main()
{
  int a[10] = {1, 3, 5, 7, 10, 120, 150, 170};

  // Then low will go from 0 and high will be the 2nd element, then change the low as high and high = high*2 and do binary search over it
  int key = 10;
  int ans = find_ans(a, key);
  if (ans == -1)
    cout << "ele not found";
  else
    cout << "ele is " << ans;
  return 0;
}