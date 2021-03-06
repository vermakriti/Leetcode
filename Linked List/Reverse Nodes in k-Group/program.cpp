/*

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]

Example 4:

Input: head = [1], k = 1
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode*curr=head,*temp,*prev=nullptr,*next=nullptr;
        while(curr){
            int length=0;
            temp=curr;
            while(temp){
                length++; 
                if(length==k)
                    break;
                temp=temp->next;
            }
            if(length==k){
                if(temp){
                    next=temp->next;
                    temp->next=nullptr;
                }    
                else next=nullptr;
                
                ListNode*revHead=reverse(curr);
                if(prev==nullptr)
                    head=revHead;
                else prev->next=revHead;
                prev=curr;
                curr=next;
            }
            else{
                if(prev!=nullptr)
                prev->next=curr;
                break;
            }    
        }
        
        return head;
    }
};