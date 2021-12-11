#include "iostream"
using namespace std;
class node
{
public:
  int data;
  node *nex;
} * head;

node *reverse(node *head)
{
  struct node *curr, *next, *prev;
  curr = head;
  prev = nullptr;
  while (curr != nullptr)
  {
    next = curr->nex;
    curr->nex = prev;

    prev = curr;
    curr = next;
  }
  head = prev;
  return head;
}

node *insert(node *h, int val)
{
  node *new_node = new node();
  new_node->data = val;
  new_node->nex = h;
  h = new_node;
}
int main()
{

  return 0;
}