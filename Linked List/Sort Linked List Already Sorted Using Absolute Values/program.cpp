/*

Given the head of a singly linked list that is sorted in non-decreasing order using the absolute values of its nodes, return the list sorted in non-decreasing order using the actual values of its nodes.
 

Example 1:

Input: head = [0,2,-5,5,10,-10]
Output: [-10,-5,0,2,5,10]
Explanation:
The list sorted in non-descending order using the absolute values of the nodes is [0,2,-5,5,10,-10].
The list sorted in non-descending order using the actual values is [-10,-5,0,2,5,10].

Example 2:

Input: head = [0,1,2]
Output: [0,1,2]
Explanation:
The linked list is already sorted in non-decreasing order.

Example 3:

Input: head = [1]
Output: [1]
Explanation:
The linked list is already sorted in non-decreasing order.

*/


// TC - O(N) SC-O(1)
class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        
        if(!head)return head;
        
        ListNode*positiveList,*negativeList=nullptr,*positiveListTail=new ListNode(-1),*negativeListTail,*next;
        positiveList=positiveListTail;
      
        while(head){
            next=head->next;
            head->next=nullptr;
            if(head->val>=0){
                positiveListTail->next=head;
                positiveListTail=head;
            }
            else{
                head->next=negativeList;
                if(negativeList==nullptr)
                    negativeListTail=head;
                negativeList=head;
            }
            head=next;
        }
        positiveList=positiveList->next;
        if(negativeList){
            negativeListTail->next=positiveList;
            return negativeList;
        }
        else return positiveList;
    }
};