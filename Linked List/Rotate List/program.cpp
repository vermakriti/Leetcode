/*

Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]


*/

// TC-O(N) SC-O(1)
class Solution {
public:
    int findLength(ListNode*head){
        int length=0;
        while(head){
            length++;
            head=head->next;
        }
        return length;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        int len=findLength(A);
        if(len==0 || B%len==0)
            return head;
        int r=B%len;
        ListNode*first=head,*second=head,*prev=nullptr;
        r--;
        while(second->next && r--){
            second=second->next;
        }
        while(second->next){
            prev=first;
            first=first->next;
            second=second->next;
        }
        second->next=head;
        head=first;
        prev->next=nullptr;
        return head;
    }
};