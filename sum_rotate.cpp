// Given a sorted and rotated array, find if there is a pair with a given sum
// https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
/*
a[]={6,1,2,3,4,5}, x=4 then find pair(3,1)
Now, here we could sort the array and then move 2 pointers first and last from the smallest and 
largest element of the array and find if sum=x
if a[f]+a[l]==x then return true
else if a[f]+a[l] < x increase f
else decrease l

Here since it is already sorted, we don't need to sort it otherwise the total took O(n^2)
Since we need only the first and last of the sorted(assuming in increasing) we need tp follow the
condition that if a[i]>a[i+1] for i=0 to n-1 then last=i and first=(i+1)%n (bcos i can be n-1) and 
i=n gives error without modulus
*/

#include "iostream"
using namespace std;

int main()
{
  freopen("input.txt", "r", stdin);
}