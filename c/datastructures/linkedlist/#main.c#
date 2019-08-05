#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void push(struct Node* head, int data);
void insert(struct Node* previousNode, int data);
void append(struct Node* head, int data);
void pop_back(struct Node* head);
void printList(struct Node *node);

int main()
{
  // 3 nodes in linked list
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;
  
  // allocate 3 nodes in the heap
  head = (struct Node*) malloc(sizeof(struct Node));
  second = (struct Node*) malloc(sizeof(struct Node));
  third = (struct Node*) malloc(sizeof(struct Node));

  // assign values to each node
  head->data = 1;
  head->next = second;
  second->data = 2;
  second->next = third;
  third->data = 3;
  third->next = NULL;

  // insert new node after 2
  insert(head->next, 23);
  
  // push new node
  push(head, 0);

  // append node to end
  append(head, 4);

  // append another node to end, to be removed
  append(head, 5);

  // remove the end node
  pop_back(head);
  
  // print all nodes
  printList(head);
  
  return 0;
}

void push(struct Node* head, int data)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));

  node->data = data;
  node->next = head;
  head = node;
}

void insert(struct Node* prev_node, int data)
{
  if (prev_node == NULL)
    return;

  struct Node* node = (struct Node*) malloc(sizeof(struct Node));

  node->data = data;
  node->next = prev_node->next;
  prev_node->next = node;
}

void append(struct Node* head, int data)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  struct Node* last = head;

  node->data = data;
  node->next = NULL;

  // if linked list is empty, make the new node head
  if (head == NULL)
  {
    head = node;
    return;
  }

  // else traverse until the last node
  while (last->next != NULL)
    last = last->next;

  // change the next of last node
  last->next = node;
}

void pop_back(struct Node* head)
{
  struct Node* second_to_last = NULL;
  struct Node* last = head;
  
  // if linked list is empty, return
  if (head == NULL)
    return;

  // else traverse until the last node
  while (last->next != NULL)
  {
    last = last->next;
    if (last->next != NULL && last->next->next == NULL)
      second_to_last = last;
  }
  
  // free last node
  second_to_last->next = NULL;
  free(last);
}

void printList(struct Node *node)
{
  while (node != NULL) 
  { 
     printf("%d\n", node->data); 
     node = node->next; 
  }
}
