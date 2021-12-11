// insert element in sorted circular
#include "iostream"
using namespace std;

class node
{
public:
  int inf;
  node *nex;
};

void push_start(node **head, int data)
{
  node *ptr1 = new node;
  node *temp = *head;
  ptr1->inf = data;
  ptr1->nex = *head;

  if (*head != nullptr)
  {
    while (temp->nex != *head)
    {
      temp = temp->nex;
    }
    temp->nex = ptr1;
  }
  else
  {
    ptr1->nex = ptr1;
  }
  *head = ptr1;
}

void show(node *head)
{
  node *temp = head;
  if (head == nullptr)
  {
    cout << "the list is empty";
    exit(0);
  }
  do
  {
    cout << temp->inf << " ";
    temp = temp->nex;
  } while (temp != head);
}

void insert_sorted(node **head, int data)
{
  // cout << "0\n";
  node *next = *head;
  node *newnode = new node;
  newnode->inf = data;
  if (*head == nullptr) // case 1 - empty ll
  {
    newnode->nex = newnode;
    *head = newnode;
  }

  else if (next->inf >= newnode->inf) // case 2 - insert before head
  {
    // if the element has to be inserted just before the head
    /* If value is smaller than head's value then
        we need to change next of last node */
    while (next->nex != *head)
    {
      next = next->nex;
    }
    // now we have the last node(next) , node before last(newnode) and head
    next->nex = newnode;
    newnode->nex = *head;
    // making newnode as new head as element smaller than head and list is sorted
    *head = newnode;
  }
  else // case 3 - element after head
  {
    while (next->nex != *head) // going back to the same value
    {
      if (next->inf < data && next->nex->inf > data)
      {
        // cout << "1\n";
        node *second_next = next->nex;
        next->nex = newnode;
        newnode->nex = second_next;
      }
      next = next->nex;
      // don't forget adding this statement else program runs in forever while loop
    }
  }
}

int main()
{
  node *head = nullptr;
  push_start(&head, 5);
  push_start(&head, 3);
  push_start(&head, 2);
  push_start(&head, 1);
  show(head);
  insert_sorted(&head, 4);
  cout << "\n";
  show(head);
  return 0;
}