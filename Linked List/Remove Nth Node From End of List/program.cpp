/*

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

*/

// TC-O(N) SC-O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head,*fast=head,*prev=nullptr;
        n--;
        while(n--){
            fast=fast->next;
        }
        while(fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(prev==nullptr)
            head=head->next;
        else prev->next=slow->next;
        return head;
    }
};