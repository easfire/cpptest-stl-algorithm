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
      cout << "head in " << head << endl;
      if (head == nullptr || head->next == nullptr) {
        return false;
      }

      // because it is while loop, slow is not equal with fast, and then can into the while loop
      // also it can be do-while loop. with fast == slow
      ListNode* slow = head; 
      ListNode* fast = head->next;

      while (slow != fast){
        // if fast is at the end, so it hasn't cycle.
        if (fast == nullptr || fast->next == nullptr) {
          return false;
        }
        slow = slow->next;
        fast = fast->next->next;
      }
      return true;
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
