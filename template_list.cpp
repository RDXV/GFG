// template for list insertion, deletion and reversal

#include "iostream"
using namespace std;

// node definition which can be initialized through objects
class node
{
public:
  int inf;
  node *nex;
};

void push_start(node **head, int data) // insert at head
{
  node *temp = new node;
  temp->inf = data;
  temp->nex = *head;
  *head = temp;
}

void push_end(node **head_node, int data) // insert at end
{
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

void show(node *h) // print the list
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

node *reverse(node *head) // reverse a list
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

  // head = reverse(head); as the function in main()
}

node *del(node *start) // delete node at head
{
  if (start == nullptr)
  {
    cout << "Empty linked list so nothing can be deleted";
    exit(0);
  }
  else if (start->nex == nullptr)
  {
    cout << "element deleted. Now the list is empty";
    start = nullptr;
  }
  else
  {
    node *temp = new node;
    temp = start;
    start = start->nex;
    delete temp;
  }
  return start;
}

int main()
{
  node *head = nullptr;
  push_start(&head, 2);
  push_start(&head, 3);
  push_start(&head, 4);
  push_end(&head, 1);
  cout << "\n";
  show(head);
  head = reverse(head);
  cout << "\n";
  show(head);
  return 0;
}

/*  https://stackoverflow.com/questions/7271647/what-is-the-reason-for-using-a-double-pointer-when-adding-a-node-in-a-linked-lis

  using double pointer makes sense as the address value is being copied over to the function parameter. Due to the function's scope, 
  that copy will vanish once it returns
  By using a double pointer, you will be able to update the original pointer's value. The double pointer will still be copied by value, 
  but that doesn't matter. All you really care is modifying the original pointer, thereby bypassing the function's scope or stack.
  */