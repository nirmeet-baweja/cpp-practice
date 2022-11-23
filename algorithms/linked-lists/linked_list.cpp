/**
 * @file linked_list.cpp
 * @author nirmeet baweja
 * @brief linked list revision
 * @version 0.1
 * @date 2022-11-23
 *
 * @copyright Copyright (c) 2022
 */
#include<iostream>
#include <vector>
#include <string>

/**
 * @brief class node for a single node in linked list
 */
class Node {
  private:
    int val;
    Node* next;

  public:
    Node(int initialVal)
    {
      val = initialVal;
      next = nullptr;
    }
    int getValue()
    {
      return val;
    }

    Node* getNext()
    {
      return next;
    }

    void setNext(Node* node)
    {
      next = node;
    }
};

/**
 * @brief display a given 1D vector
 *
 * @param v vector to display
 */
void display_vector(std::vector<int>& v)
{
  std::cout << "\n{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << " " << v[i];
  }
  std::cout << " }\n";
}

/**
 * @brief store the values of given linked list starting at head into a vector
 *
 * @param head
 * @return std::vector<int>
 */
std::vector<int> linkedListValues(Node* head)
{
  std::vector<int> values;

  for (Node *it = head; it != nullptr; it=it->getNext())
  {
    values.push_back(it->getValue());
  }

  return values;
}

/**
 * @brief return sum of values of linked list starting at head
 *
 * @param head
 * @return int
 */
// TC - O(n), SC - O(1)
int sumList(Node* head)
{
  int sum = 0;
  for (Node *it = head; it != nullptr; it=it->getNext())
  {
    sum += it->getValue();
  }
  return sum;
}

/**
 * @brief return sum of values of linked list starting at head
 *
 * @param head
 * @return int
 */
// TC - O(n), SC - O(n) because of the call stack
int sumListRecursive(Node* head)
{
  if(head == nullptr)
  {
    return 0;
  }

  return head->getValue() + sumListRecursive(head->getNext());
}


/**
 * @brief find the given value in the given linked list
 *
 * @param head
 * @param val
 * @return true if val found,
 * @return false if val not found
 */
bool find(Node* head, int val)
{
  for (Node *it = head; it != nullptr; it=it->getNext())
  {
    if(it->getValue() == val){
      return true;
    }
  }
  return false;
}

/**
 * @brief find the given value in the given linked list
 *
 * @param head
 * @param val
 * @return true if val found,
 * @return false if val not found
 */
bool findRecursive(Node* head, int val)
{
  if(head == nullptr)
  {
    return false;
  }
  if(head->getValue() == val)
  {
    return true;
  }

  return findRecursive(head->getNext(), val);
}

/**
 * @brief Get the value of the linked list at given index
 *
 * @param head
 * @param index
 * @return int
 */
int getValue(Node* head, int index)
{
  int pos = 0;
  for (Node *it = head; it != nullptr; it=it->getNext())
  {
    if(pos == index)
    {
      return it->getValue();
    }
    pos++;
  }
  return -1;
}

/**
 * @brief Get the value of the linked list at given index
 *
 * @param head
 * @param index
 * @return int
 */
int getValueRecursive(Node* head, int index)
{
  if(index == 0)
  {
    return head->getValue();
  }

  if(head == nullptr)
  {
    return -1;
  }

  return getValueRecursive(head->getNext(), index - 1);
}

/**
 * @brief in-place reversal of given linked list
 *
 * @param head
 * @return Node* new head node after reversal
 */
Node* reverseList(Node* head)
{
  Node* prev = nullptr;
  Node* current = head;
  Node* next;

  while (current != nullptr)
  {
    next = current->getNext();
    current->setNext(prev);
    prev = current;
    current = next;
  }
  return prev;
}

Node* reverseListRecursive(Node* head, Node* prev = nullptr)
{
  if(head == nullptr)
  {
    return prev;
  }
  Node *next = head->getNext();
  head->setNext(prev);
  return reverseListRecursive(next, head);
}

Node* zipperLists(Node* head1, Node* head2) {
  Node *current1 = head1;
  Node *current2 = head2;
  Node *next1;
  Node *next2;

  while(current1 != nullptr && current2 != nullptr)
  {
    next1 = current1->getNext();
    next2 = current2->getNext();
    current1->setNext(current2);
    if(next1 != nullptr)
    {
      current2->setNext(next1);
    }
    current1 = next1;
    current2 = next2;
  }

  return head1;
}

Node* zipperLists2(Node* head1, Node* head2)
{
  int count = 0;
  Node *tail = head1;
  Node *current1 = head1->getNext();
  Node *current2 = head2;

  while(current1 != nullptr && current2 != nullptr)
  {
    if(count % 2 == 0)
    {
      tail->setNext(current2);
      current2 = current2->getNext();
    } else {
      tail->setNext(current1);
      current1 = current1->getNext();
    }
    tail = tail->getNext();
    count++;
  }

  if(current1 != nullptr)
  {
    tail->setNext(current1);
  }
  if(current2 != nullptr)
  {
    tail->setNext(current2);
  }
  return head1;
}

Node* zipperListsRecursive(Node* head1, Node* head2)
{
  if(head1 == nullptr && head2 == nullptr)
    return nullptr;

  if(head1 == nullptr)
    return head2;

  if(head2 == nullptr)
    return head1;

  Node *next1 = head1->getNext();
  Node *next2 = head2->getNext();

  head1->setNext(head2);
  head2->setNext(zipperListsRecursive(next1, next2));

  return head1;
}

int main()
{
  Node a(5);
  Node b(2);
  Node c(7);
  Node d(3);

  a.setNext(&b);
  b.setNext(&c);
  c.setNext(&d);

  int val = 15;
  int index = 2;

  // a -> b -> c -> d -> nullptr

  std::vector<int> values = linkedListValues(&a); // -> [ "a", "b", "c", "d" ]
  display_vector(values);

  std::cout << "\nThe sum of the list values is: " << sumList(&a) << std::endl;
  std::cout << "\nThe sum of the list values (recursive) is: "
            << sumListRecursive(&a) << std::endl;

  std::cout << "\nFound " << val << " in linked list : " << find(&a, val)
            << std::endl;
  std::cout << "\nFound(recursive) " << val << " in linked list : "
            << findRecursive(&a, val) << std::endl;

  std::cout << "\nThe value at index: " << index << " is: "
            << getValue(&a, index) << std::endl;
  std::cout << "\nThe value at index (recursive): " << index << " is: "
            << getValueRecursive(&a, index) << std::endl;

  Node* new_head = reverseList(&a);
  std::vector<int> reversed_values = linkedListValues(new_head);
  std::cout << "\nReversed linked list: ";
  display_vector(reversed_values);

  new_head = reverseListRecursive(new_head);
  reversed_values = linkedListValues(new_head);
  std::cout << "\nReversed linked list (recursive): ";
  display_vector(reversed_values);

  Node u(1);
  Node v(2);
  Node w(3);
  Node p(4);
  Node q(5);
  Node r(6);
  u.setNext(&v);
  v.setNext(&w);
  w.setNext(&p);
  p.setNext(&q);
  q.setNext(&r);
  // 1 -> 2 -> 3

  Node x(10);
  Node y(20);
  Node z(30);
  // Node p(40);
  // Node q(50);
  // Node r(60);
  x.setNext(&y);
  y.setNext(&z);
  // z.setNext(&p);
  // p.setNext(&q);
  // q.setNext(&r);
  // 10 -> 20 -> 30

  Node* zip_list = zipperListsRecursive(&u, &x);
  // 1 -> 10 -> 2 -> 20 -> 3 -> 30
  std::vector<int> zipped_values = linkedListValues(zip_list);
  std::cout << "\nZipped linked list: ";
  display_vector(zipped_values);
}