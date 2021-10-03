/*

Given the head of a linked list and two integers m and n. Traverse the linked list and remove some nodes in the following way:

Start with the head as the current node.
Keep the first m nodes starting with the current node.
Remove the next n nodes
Keep repeating steps 2 and 3 until you reach the end of the list.
Return the head of the modified list after removing the mentioned nodes.

Example 1:

Input: head = [1,2,3,4,5,6,7,8,9,10,11,12,13], m = 2, n = 3
Output: [1,2,6,7,11,12]

Example 2:

Input: head = [1,2,3,4,5,6,7,8,9,10,11], m = 1, n = 3
Output: [1,5,9]

Example 3:

Input: head = [1,2,3,4,5,6,7,8,9,10,11], m = 3, n = 1
Output: [1,2,3,5,6,7,9,10,11]

*/


// TC-O(N) SC-O(1)
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        
        ListNode*curr=head,*last=head;
        int mCount=0,nCount=0;
        while(curr){
            mCount=m;
            while(curr && mCount){
                last=curr;
                curr=curr->next;
                mCount--;
            }
            nCount=n;
            while(curr && nCount){
                curr=curr->next;
                nCount--;
            }
            last->next=curr;
        }
        return head;
    }
};