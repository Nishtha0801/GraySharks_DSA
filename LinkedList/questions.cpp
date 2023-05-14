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

       thead = reverse(thead);
       ListNode* c1 = head;
       ListNode* c2 = thead;

       while(c1 != nullptr && c2 != nullptr){
           int temp = c1->val;
           c1->val = c2->val;
           c2->val = temp;

           c1 = c1->next;
           c2 = c2->next;
       }

       thead = reverse(thead);
       mid->next = thead;
    }

    ListNode* reverseList(ListNode* head) {
        reverseData(head);
       return head;
    }
};



// leetcode 234 ===========================
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
           return true;
       }
       ListNode* mid = middleNode2(head);
       ListNode* thead = mid->next;

       mid->next = nullptr;


       thead = reverse(thead);

       ListNode* c1 = head;
       ListNode* c2 = thead;

        bool res = true;
       while(c1!=nullptr && c2 != nullptr){
           if(c1->val != c2->val){
               res = false;
               break;
           }
           c1 = c1->next;
           c2 = c2->next;
       }

       thead = reverse(thead);
       mid -> next = thead;

       return res;

    }

    // leetcode 143
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }
        ListNode* mid = middleNode2(head);
        ListNode* thead = mid->next;

        mid->next = nullptr;

        thead = reverseList(thead);
        ListNode* c1 = head;
        ListNode* c2 = thead;

        ListNode* f1 = nullptr;
        ListNode* f2 = nullptr;

        while(c1 != nullptr && c2!=nullptr){
            f1 = c1->next;
            f2 = c2->next;
            

            c1->next = c2;
            c2->next = f1;

            c1 = f1;
            c2 = f2;
        }
        
    }
    
    //leetcode 21 ===========================================
      ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr){
            return (l1 == nullptr ? l2 : l1);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;

        ListNode* c1 = l1;
        ListNode* c2 = l2;
        while(c1 != nullptr && c2 != nullptr){
            if(c1->val < c2->val){
                prev->next = c1;
                c1 = c1->next;
            }
            else {
                prev->next = c2;
                c2 = c2->next;
            }
            prev = prev->next;
        }

        if(c1 != nullptr){
            prev->next = c1;
        }

        else {
            prev->next = c2;
        }

        return dummy->next;
    }

    // leetcode 148 ==================================================

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
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr){
            return (l1 == nullptr ? l2 : l1);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;

        ListNode* c1 = l1;
        ListNode* c2 = l2;
        while(c1 != nullptr && c2 != nullptr){
            if(c1->val < c2->val){
                prev->next = c1;
                c1 = c1->next;
            }
            else {
                prev->next = c2;
                c2 = c2->next;
            }
            prev = prev->next;
        }

        if(c1 != nullptr){
            prev->next = c1;
        }

        else {
            prev->next = c2;
        }

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* mid = middleNode2(head);
        ListNode* nhead = mid->next;
        mid->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(nhead);

        return mergeTwoLists(l1, l2);
    }
