#include <iostream>

using namespace std;

class ListNode {
  public:
    int val;
    ListNode* next;

    ListNode(int x)
      : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n)
      : val(x), next(n) {}
};

class Solution {
  public:
    bool hasCycle(ListNode* head) {
      unordered_set<ListNode*> seen;

    }
};

int main() {
  ListNode list3(3);
  ListNode list2(2, &list3);
  ListNode list(1, &list2);

  list3.next = &list;
  Solution s;
  cout << "head out " << &list<< endl;
  bool res = s.hasCycle(&list);
  cout << res << endl;

  return 0;
}
