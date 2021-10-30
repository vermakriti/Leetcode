/*

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:

Input: head = []
Output: []

Example 3:

Input: head = [0]
Output: [0]

Example 4:

Input: head = [1,3]
Output: [3,1]

*/

// TC-O(N) SC-O(N)
class Solution {
public:
    TreeNode* builtBST(int start,int end, vector<int>&v){
        if(start>end)
            return nullptr;
        int mid=start+(end-start)/2;
        TreeNode*node= new TreeNode(v[mid]);
        if(start==end)
            return node;
        node->left=builtBST(start,mid-1,v);
        node->right=builtBST(mid+1,end,v);
        
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        int n=v.size()-1;
        return builtBST(0,n,v);
        
    }
};


class Solution {
public:
    ListNode*findMid(ListNode*head,ListNode**prev){
      
        ListNode*slow=head,*fast=head;
        while(fast && fast->next){
            *prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        
        ListNode*mid,*prev=nullptr;
        mid=findMid(head,&prev);
        ListNode*next=mid->next;
        mid->next=nullptr;
        
        TreeNode*node= new TreeNode(mid->val);
        if(prev==nullptr)
            return node;
        prev->next=nullptr;
        
        node->left=sortedListToBST(head);
        node->right=sortedListToBST(next);
        
        return node;
    }
};