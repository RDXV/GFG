// we need to do memoization which is storing the value of a previous calculated entity
// In factorials, we have the factorial tree and we see repetition of fac(n) for lower trees formed so it would save time if we could
// check if we have older values saved and if not compute and save fac(n) in a map

#include "iostream"
#include "map"
using namespace std;
map<int, long long> ans; // global variable
long long a[100];

long long fib_arr(int n);

long long fib(int n)
{
  // check the presence of value
  if (ans.find(n) != ans.end()) // see if element present and not goes till end of map
  {
    return ans[n];
  }
  // initial conditions - 1st and 2nd fibonacci numbers are 1 so return 1(not counting 0 as first fibonacci)
  if (n <= 2)
    return 1;
  ans[n] = fib(n - 1) + fib(n - 2); // save the previous answers
  return ans[n];
}

int main()
{
  cout << fib(47) << "\n";
  // passing the map again in the fib() makes the program take too long
  for (int i = 0; i < 100; i++)
  {
    a[i] = -1;
  }
  cout << fib_arr(47);
  return 0;
}

long long fib_arr(int n)
{
  if (n <= 2)
    return 1;

  if (a[n] != -1) // element exists
  {
    return a[n];
  }
  a[n] = fib_arr(n - 1) + fib_arr(n - 2); // calculate the fibonacci
  return a[n];
}