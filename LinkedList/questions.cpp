#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
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

    // leetcode 61 ==========================================
     ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k==0){
            return head;
        }

        int len = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            curr = curr->next;
            len++;
        }

        k = k%len;

        if(k == 0){
            return head;
        }

        ListNode* c1 =head;
        ListNode* c2 = head;
        while(k-- > 0){
            c2 = c2->next;
        }

        while(c2->next != nullptr){
            c1 = c1->next;
            c2 = c2->next;
        }

        c2->next = head;
        head = c1->next;
        c1->next = nullptr;


        return head;


    }

   // https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

      Node* divide(int N, Node *head){
        // code here
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        Node* even = new Node(-1);
        Node* ep = even;
        
        Node* odd = new Node(-1);
        Node* op = odd;
        
        Node* curr = head;
        while(curr != nullptr){
            if(curr->data % 2 == 0){
                ep->next = curr;
                ep = ep->next;
            } else {
                op->next = curr;
                op = op->next;
            }
            curr = curr->next;
        }
        op->next = nullptr;
        ep->next = odd->next;

        return even->next;
    }


    //leetcode 328 ====================
        ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* evenHead = even;

        while(even != nullptr && even->next != nullptr){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;

        return head;
    }

    // leetcode 237 =========================
      void deleteNode(ListNode* node) {
        if(node == nullptr){
            return;
        }

        node->val = node->next->val;
        node->next = node->next->next;
    }

    // leetcode 141 ================
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                break;
            }
        }
        return slow == fast;
    }

    // leetcode 160========================
      ListNode* detectCycle(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                break;
            }
        }

        if(slow != fast){
            return nullptr;
        }

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        ListNode* prev = headA;
        ListNode* curr = headA;

        while(curr != nullptr){
            prev = curr;
            curr = curr->next;
        }

        prev->next = headB;
        ListNode* ans = detectCycle(headA);
        prev->next = nullptr;
        return ans;
    }
