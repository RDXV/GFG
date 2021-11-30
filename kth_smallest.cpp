#include "iostream"
#include "set"
#include "map"
using namespace std;

int findK(int a[], int size, int k);
int main()
{
  int a[] = {12, 3, 5, 7, 19};
  int size = sizeof(a) / sizeof(a[0]);
  set<int> s(a, a + size);
  // Creating a set from a[0] to a[size]
  set<int>::iterator i = s.begin();
  // set iterator starting at start of set s
  int k = 3;
  advance(i, k - 1);
  // This above function makes the i pointer point to the kth position
  cout << *i;
  // for (i = s.begin(); i != s.end(); i++)
  // {
  //   cout << *i << " ";
  // }
  // The above prints the whole set in increasing order as it stores in bst
  // for getting a specific indexed element of a set you will have to use advance()
  // function taking iterator and position to be stored in it and then show the element
  // by *i bcos i is the location

  // Since the whole set is a bst, when we initialize it, it stores it in a BST which has
  // O(logn) search time but also O(n) space
  cout << "\nThe answer again is " << findK(a, size, k);
  return 0;
}

// you can also use map and based on the frequency of the elements and the elements get the
// kth element

int findK(int a[], int size, int k)
{
  map<int, int> map1;
  for (int i = 0; i < size; i++)
  {
    map1[a[i]] += 1; //store the values in map
  }
  int freq = 0;
  for (auto i = map1.begin(); i != map1.end(); i++)
  {
    // here i is a iterator pointer not int
    // first is a[i], second is map1[a[i]] value
    freq += i->second;
    if (freq >= k)
    {
      return i->first;
    }
  }
  return -1;
}
/*
     Each map has the a[i] which is stored in sorted order inside like -
     a[]={7,0,25,6,16,17,0} and k=3
        No.  Freq
        0     2
        6     1
        7     1
        16    1
        17    1
        25    1

   This is how it is stored inside the map. Now iterate the map so that 
    freq+=itr->second;
    where if freq>=k return itr->first    

    */