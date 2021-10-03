/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1;
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

*/

//TC-O(N) SC-O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head)return NULL;
        ListNode*curr=NULL,*prev=NULL,*next=head;
        
        while(next){
            prev=curr;
            curr=next;
            next=next->next;
            curr->next=prev;
        }
        return curr;
        
    }
};