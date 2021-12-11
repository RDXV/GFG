#include "iostream"
using namespace std;
class node
{
public:
  int data;
  node *nex;

  void insert_head(node *);
  void insert_end(node *);
  void reverse();
  void del();
  void del_list();
  void show();
} * start, *last, *ptr, *temp, *newptr;
// Try to do an implementation where head pointer is not global but inside the main()

node *create(int inf)
{
  ptr = new node;
  ptr->data = inf;
  ptr->nex = nullptr;
  return ptr;
}

void node::insert_head(node *n)
{
  if (start == nullptr) // check if the ll is empty
  {
    start = last = n;
  }
  else
  {
    temp = new node;
    temp = start;
    start = n;
    start->nex = temp;
  }
}

void node::insert_end(node *n)
{
  if (start == nullptr)
  {
    start = last = n;
  }
  else
  {
    last->nex = n;
    last = n; // new last pointer
  }
}

// can't insert at any node as we would need the previous node location too, although we can ask for position and then iterate to x-1 postion(pointer f1 and
// f2=f1->nex) changing it's nex to the new pointer(n) and then n->nex=f2

void node::del()
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
    temp = new node;
    temp = start;
    start = start->nex;
    delete temp;
  }
}

void del_list() // delete entire list
{
  node *next, *curr;
  next = nullptr; // declaring initally next as null for base case and default
  curr = start;
  while (curr != nullptr)
  {
    next = curr->nex;
    delete curr; // delete the data and free memory
    curr = next; // store the next value again in curr
  }
  // make the start again as nullptr as the list is deleted
  start = nullptr;
}

void node::show()
{
  node *s = start;
  if (s == nullptr)
  {
    cout << "\nthe ll is empty";
  }
  else
  {
    while (s != nullptr)
    {
      cout << s->data << " ";
      s = s->nex;
    }
  }
}

void node::reverse() // to reverse the ll
{
  node *curr, *prev, *next;
  curr = start;
  prev = nullptr;
  while (curr != nullptr)
  {
    next = curr->nex;
    curr->nex = prev;
    prev = curr;
    curr = next;
  }
  // we need to adjust the variable start
  start = prev;
}

/*
  1 -> 2 -> 3 -> 4 -> 5X  -> where X is null
  initially, prevNode=start,  currNode=start->nex, start=start->nex i.e., prevNode=1, currNode=2, start=2

  then prevNode->nex=nullptr i.e. X1 2 -> 3 -> 4 -> 5X where 1 points to nullptr

  in the loop till start points to nullptr

  a. start=start->nex meaning start points to 3 now i.e. start->data=3
  b. currNode->nex=prevNode means X1 <- 2 3 -> 4 -> 5X
  c. prevNode=currNode means prevNode->data=2 which was before 1
  d. Now, currNode=start means currNode points to it's next pointer to repeat the same process again. currNode->data=3

  So for each iteration, we must have total 3 pointers, prevNode, currNode and start where currNode points to the prevNode(the node previous) and start is
  currNode->nex. Then make the currnode as start(as now currNode->nex will point to prevNode and not start ), start=start->nex and so on...

*/

int main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  node newnode;
  int inf;
  start = last = temp = ptr = nullptr;
  char ch = 'y';
  do
  {
    /* code */
    cout << "Here are the following choices - " << endl;
    cout << "1. Insert top" << endl
         << "2. Insert end" << endl
         << "3. Delete top" << endl
         << "4. Reverse list" << endl
         << "5.Show list" << endl;
    cout << endl
         << "Enter choice";
    int x;
    cin >> x;
    int i;
    do
    {
      switch (x)
      {

      case 1:
        cout << "enter the info ";
        cin >> inf;
        newptr = create(inf);
        if (newptr == nullptr)
        {
          cout << "Memory not allocated. Exiting...";
          exit(0);
        }
        newnode.insert_head(newptr);
        newnode.show(); // the list always starts from 'start' so pass the start pointer

        break;

      case 2:
        cout << "enter info";
        cin >> inf;
        newptr = create(inf);
        if (newptr == nullptr)
        {
          cout << "Memory not allocated. Exiting...";
          exit(0);
        }
        newnode.insert_end(newptr);
        newnode.show();

        break;

      case 3: // delete a node
        if (start == nullptr)
        {
          cout << "the list is already empty";
        }
        newnode.del();
        newnode.show();
        break;

      case 4:
      {
        newnode.reverse();
        newnode.show();
      }
      break;

      case 5:
        newnode.show();
        break;

      default:
        cout << "Wrong choice entered.";
        break;
      }
      cout << "\nDo you want to continue? ";
      cin >> ch;
    } while (ch == 'y');
    cout << "\nDo you want to conitnue? ";
    cin >> ch;
  } while (ch == 'y');

  return 0;
}

// 1->2->3->4
// insert at head, we have to change the head to the new node and make new_node->next as the first element