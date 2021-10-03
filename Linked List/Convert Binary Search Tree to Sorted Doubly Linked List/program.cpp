/*

Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

Example 1:

Input: root = [2,1,3]
Output: [1,2,3]

*/ 

// TC-O(N) SC-O(N) 
// iterative 
class Solution {
public:
    
    Node* treeToDoublyList(Node* root) {
        
        if(!root) 
            return root;
        Node*head=nullptr,*prev=nullptr,*curr=root;
        stack<Node*> st;
        
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            if(head==nullptr)
                head=curr;
            else{
                prev->right=curr;
                curr->left=prev;
            }
            prev=curr;
            curr=curr->right;
        }
        prev->right=head;
        head->left=prev;
        
        return head;
    }
};