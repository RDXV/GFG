#include "list"
#include "iostream"
using namespace std;

int main()
{
  list<int> a;
  a.push_back(1);
  a.push_back(21);
  a.push_back(3);
  a.push_back(69);
  a.push_back(49);
  int c = 1, pos = 4;
  // find 4th element
  list<int>::iterator i;
  for (i = a.begin(); i != a.end(); i++)
  {
    if (c == pos)
    {
      cout << *i;
    }
    c++;
    // cout << *i << " ";
  }
  return 0;
}