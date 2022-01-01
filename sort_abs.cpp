#include <iostream>
#include "map"
using namespace std;

// rather than storing in a map we can store it in multimap which already stores in sorted order
int main()
{
  int a[] = {10, 5, 3, 9, 2};
  int x = 7;
  int length = sizeof(a) / sizeof(a[0]);
  // map<int, int> ans;
  multimap<int, int> ans;
  for (size_t i = 0; i < length; i++)
  {
    ans.insert(make_pair(abs(x - a[i]), a[i]));
    // multimap stores as key-value pair and sorts based on the key. Note - we can't use map here bcos map only stores unique values so it will sort based on unique numbers
    // and not difference (x-a[i])
  }
  for (auto j : ans)
  {
    cout << j.second << "\n";
  }
  // ans sorted based on key -> abs(x-a[i])
  return 0;
}