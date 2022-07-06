#include <iostream>
#include <memory>

using namespace std;

class ListNode {
  private:
    int val;
    ListNode* next;

  public:
    ListNode()
      : val(0), next(nullptr) {}
    ListNode(int x)
      : val(x), next(nullptr) {}
    ListNode(int x,  ListNode* next) 
      : val(x), next(next) {}

    //~ListNode() = delete;
    //    ~ListNode() {
    //      free(this);
    //    }

    int getVal() {
      return val; 
    }

    void setVal(int v) {
      val = v;
    }

    ListNode* getNext() {
      return next;
    }

    void setNext(ListNode* n) {
      next = n;
    }

    ListNode& reverse();
    void printList() const;
};

ListNode& ListNode::reverse() {
  ListNode* prev = nullptr;
  ListNode* curr = this;

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
  ListNode list;

  list.setVal(1);    
  cout << "list value = " << list.getVal() << endl; 

  ListNode list3(3);
  ListNode list2(2, &list3);

  list.setNext(&list2);

  cout << "list next val = " << (list.getNext())->getVal() << endl;
  list.printList();

  //  ListNode listCopy = list; 
  //  cout << &listCopy << " " << &list << endl;
  //    cout << listNext->getVal() << endl;

  ListNode newList = list.reverse();
  newList.printList();

  return 0;
}
