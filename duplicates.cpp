// Given 3 arrays find the common elements in all
// https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/

#include <iostream>
#include "unordered_set"
using namespace std;

// one way is to move in a while loop where i<l1 and j<l2 and k<l3 checking if all elements are same, then print
// else if i<j i++, kj<k then j++ else k++

// a more optimal solution will be to use 3 sets and find occurences of elements in each
int main()
{
  int a[] = {1, 5, 10, 20, 40, 80};          // l1
  int b[] = {6, 7, 20, 80, 100};             // l2
  int c[] = {3, 4, 15, 20, 30, 70, 80, 120}; // l3
  int n1 = sizeof(a) / sizeof(a[0]);
  int n2 = sizeof(b) / sizeof(b[0]);
  int n3 = sizeof(c) / sizeof(c[0]);
  unordered_set<int> set1, set2, set3;
  int i;
  for (i = 0; i < n1; i++)
  {
    set1.insert(a[i]);
  }

  for (i = 0; i < n2; i++)
  {
    set2.insert(b[i]);
  }
  // enter the elements in first 2 sets and then check if element is present in set3, if not enter
  for (i = 0; i < n3; i++)
  {
    if (set1.find(c[i]) != set1.end() && set2.find(c[i]) != set2.end()) // checking elements of c[i] in set1 and set2 or not
    {
      if (set3.find(c[i]) == set3.end()) // checking if element not in set3 to avoid duplicates
      {
        cout << c[i] << " ";
      }
      set3.insert(c[i]); // insert c[i] everytime in set3
    }
  }

  return 0;
}