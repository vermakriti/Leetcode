/*
You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure incidate the result:

Build the result list and return its head.

Example 1:

Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [0,1,2,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.

*/

// TC-O(M+N) Sc-O(1)
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode*first=nullptr,*last=nullptr,*curr;
        int len=1;
        curr=list1;
        
        while(curr){
          
            if(len==a && a==b){
                first=curr;
                last=curr->next;
                break;
            }
            if(len==a){
                first=curr;
            }
            else if(len==b+1){
                last=curr;
                break;
            }
            curr=curr->next;
            len++;
        }
        
        curr=list2;
        while(curr->next){
            curr=curr->next;
        }
        
        first->next=list2;
        curr->next=last->next;
        return list1;
    }
};