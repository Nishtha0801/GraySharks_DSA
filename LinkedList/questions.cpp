#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  //leetcode 876
  ListNode* middleNode(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // leetcode 206 ====> by reversing
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* forw = curr->next;

            //linking
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }


    // leetcode 206 by swapping the data ============
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode2( ListNode* head){
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* forw = curr->next;

            //linking
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

    void reverseData(ListNode* head) {
       if(head == nullptr || head->next == nullptr){
           return;
       }
       ListNode* mid = middleNode2(head);
       ListNode* thead = mid->next;

       mid->next = nullptr;

       thead = reverseList(thead);
       ListNode* c1 = head;
       ListNode* c2 = thead;

       while(c1 != nullptr && c2 != nullptr){
           int temp = c1->val;
           c1->val = c2->val;
           c2->val = temp;

           c1 = c1->next;
           c2 = c2->next;
       }

       thead = reverseList(thead);
       mid->next = thead;
    }

    ListNode* reverseList(ListNode* head) {
        reverseData(head);
       return head;
    }
};