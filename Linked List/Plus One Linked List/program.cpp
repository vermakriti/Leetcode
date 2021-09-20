/*

Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.

 

Example 1:

Input: head = [1,2,3]
Output: [1,2,4]

Example 2:

Input: head = [0]
Output: [1]

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
    ListNode* plusOne(ListNode* head) {
        if(!head)
            return head;
        ListNode*prev=nullptr,*curr;
        int c=0,carry;
        head=reverse(head);
        curr=head;
        
        while(curr){
            if(curr==head){
                c=(curr->val+1)/10;
                curr->val=(curr->val+1)%10;
            }
            else{
                carry=(curr->val+c)/10;
                curr->val=(curr->val+c)%10;
                c=carry;
            }    
            prev=curr;
            curr=curr->next;
        }
        if(c){
            ListNode*node=new ListNode(c);
            prev->next=node;
        }
        head=reverse(head);
        return head;
    }
};