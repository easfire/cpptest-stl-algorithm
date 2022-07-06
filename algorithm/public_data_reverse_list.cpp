#include <iostream>

using namespace std;

class ListNode {
  public:
    int val;
    ListNode* next;

    ListNode()
      : val(0), next(nullptr) {}
    ListNode(int x)
      : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) 
      : val(x), next(next) {}

    ListNode& reverse();
    void printList() const;
};

ListNode& ListNode::reverse() {
  ListNode* prev = nullptr;
  auto curr = this;

  while (curr) {
    auto next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next; 
  }
  return *prev;
}
void ListNode::printList() const {
  auto l = this;
  while (l) {
    cout << l->val << "(" << l << ")";
    if (l->next) {
      cout << "->";
    }
    l = l->next;
  } 
  cout << endl;
}

int main() {
  int a = 1;

  cout << sizeof(a) << endl;
  cout << sizeof(&a) << endl;

  ListNode list;
  cout << list.val << " " << list.next << endl;
  cout << sizeof(list) << endl;

  ListNode list1(1, &list);
  ListNode list2(2, &list1);
  ListNode list3(3, &list2);

  list3.printList();

  auto listReverse = list3.reverse();  

  listReverse.printList();

  return 0;
}
