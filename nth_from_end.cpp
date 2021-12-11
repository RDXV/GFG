#include "iostream"
using namespace std;

struct node
{
  int inf;
  node *nex;
};

node *push(node *head, int data)
{
  node *temp = new node;
  temp->inf = data;
  temp->nex = head;

  return temp;
}

void push_end(node **head_node, int data) // if we simply use *head_node then we are copying the head from main() and not using it's address ny passing it ny refernce
{
  // we don't want to create a new head_node and then create nodes after it but use the old head and make the new nodes after it
  node *temp = new node;
  node *last = *head_node;
  temp->inf = data;
  temp->nex = nullptr;
  if (*head_node == nullptr)
  {
    *head_node = temp;
    return;
  }
  while (last->nex != nullptr)
  {
    last = last->nex;
  }

  last->nex = temp;
  return;
}

void show(node *h)
{
  if (h == nullptr)
  {
    cout << "the list is empty";
  }
  else
  {
    while (h != nullptr)
    {
      cout << h->inf << " ";
      h = h->nex;
    }
  }
}

int main()
{
  node *head = nullptr;
  // head = push(head, 1);
  // head = push(head, 2);
  // head = push(head, 3);
  // head = push(head, 4);
  push_end(&head, 1);
  push_end(&head, 2);
  push_end(&head, 3);
  push_end(&head, 4);
  show(head);
  return 0;
}