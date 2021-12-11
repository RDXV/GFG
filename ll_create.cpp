// This program is for defining ll or linked list by ourself and not using the stl libraries
#include "iostream"
using namespace std;

// node definition which can be initialized through objects
class node
{
public:
  int data;
  node *nex;
};

int main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  node *first = nullptr;
  node *second = nullptr;
  node *third = nullptr;

  // allocate nodes in heap
  first = new node();
  second = new node();
  third = new node();
  // if you don't allocate, the program would not give any output

  first->data = 0;
  first->nex = second;
  second->data = 2;
  second->nex = third;
  third->data = 4;
  third->nex = nullptr;

  while (first != nullptr)
  {
    cout << first->data << "\n";

    first = first->nex;
  }
  return 0;
}