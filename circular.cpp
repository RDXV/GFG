#include "iostream"
using namespace std;

class node
{
public:
  int inf;
  node *nex;
};

void push_start(node **head, int data) // add at the beginning of the circular list
{
  node *ptr1 = new node;
  node *temp = *head; // store the value of *head in another pointer
  ptr1->inf = data;
  ptr1->nex = *head; // the first node points to the head of the cirular list

  if (*head != nullptr)
  {
    while (temp->nex != *head)
    {
      temp = temp->nex;
    }
    temp->nex = ptr1;
  }
  else // for empty circular list
  {
    ptr1->nex = ptr1; // for first node
    // *head = ptr1; -> this statement outside the else loop else wrong ouput
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

int main()
{
  node *head = nullptr;
  push_start(&head, 12);
  push_start(&head, 56);
  show(head);
  push_start(&head, 2);
  push_start(&head, 11);

  return 0;
}
