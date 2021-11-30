// Move all zeroes to end of array
// Given an array, move all the zeroes to the end of the array
// a[]={1,0,2,3,4,5,0,0} - Now, here we can think of sorting the array but we don't want the array
// arrangement to change for the non-zero elements so af[]={1,2,3,4,5,0,0,0}
// We can think of finding the places where we have zeroes and replace them non-zero elements
// but we can't simply replace them as then the 0 would be in some other position and we will
// have to change the position again. Since we care more about the order of the non-zero elements
// We can later put the zeroes but first we need the non-zero elements in order
#include "iostream"
using namespace std;
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int a[] = {1, 0, 2, 3, 4, 0, 5, 0};
  int size = sizeof(a) / sizeof(a[0]);
  cout << "size is " << size << "\n";
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    if (a[i] != 0) //if not zero then store the elements
    {
      a[count++] = a[i];
    }
  }
  // at end we have array as a[]={1,2,3,4,5,0,5,0} and then count to n-1 make all elements 0
  while (count < size)
  {
    a[count++] = 0;
  }
  for (int i = 0; i < size; i++)
  {
    cout << a[i] << " ";
  }
  return 0;
}
