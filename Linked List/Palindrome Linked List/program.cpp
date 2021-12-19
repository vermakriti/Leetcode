/*

Given the head of a singly linked list, return true if it is a palindrome.

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

*/

class Solution {
public:
    ListNode*reverse(ListNode*head){
        
        ListNode*curr=nullptr,*prev=nullptr,*next=head;
        while(next){
            prev=curr;
            curr=next;
            next=next->next;
            curr->next=prev;
        }
        return curr;
    }
    ListNode*findMiddle(ListNode*head){
        
        ListNode*slow=head,*fast=head,*prev=nullptr;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next)
            return true;
        ListNode*mid=findMiddle(head);
        ListNode*curr1=head,*curr2=mid->next;
        mid->next=nullptr;
        
        curr2=reverse(curr2);
        while(curr1 && curr2){
            if(curr1->val!=curr2->val)
                return false;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return true;
    
    }
};