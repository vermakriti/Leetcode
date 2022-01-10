/*

n a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

Example 1:

Input: head = [5,4,2,1]
Output: 6

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
    ListNode*mid(ListNode*head){
        
        ListNode*slow=head,*fast=head,*prev=nullptr;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        
        ListNode*midNode=mid(head);
        
        ListNode*curr1=head;
        ListNode*curr2=midNode->next;
        
        midNode->next=nullptr;
        curr2=reverse(curr2);
        
        int ans=0;
        
        while(curr1 && curr2){
            
            ans=max(ans,curr1->val+curr2->val);
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return ans;
        
        
    }
};