// recursive factorial
#include "iostream"
using namespace std;

int fac(int n)
{
  if (n == 0 || n == 1)
    return 1;
  return fac(n - 1) + fac(n - 2); // the condition for finding a factorial
}

int main()
{
  cout << fac(50);
  return 0;
}