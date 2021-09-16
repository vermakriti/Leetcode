/*
Company - Facebook,Microsoft,Amazon,Google,Expedia

Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

 

Example 1:

Input: root = [4,2,5,1,3]
Output: [1,2,3,4,5]

Explanation: The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.

Example 2:

Input: root = [2,1,3]
Output: [1,2,3]

Example 3:

Input: root = []
Output: []
Explanation: Input is an empty tree. Output is also an empty Linked List.

Example 4:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
All the values of the tree are unique.

*/

// BFS traversal TC-O(N) SC(N) where N- no of nodes in tree

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

// DFS Traversal  TC-O(N) SC(N) - interal stack space 

class Solution{
  public:
    Node*head=NULL,*prev=NULL;
    void inorder(Node*root){
        if(!root)return;
        inorder(root->left);
        
        if(prev==NULL){
            head=root;
            prev=root;
        }
        else{
            prev->right=root;
            root->left=prev;
            prev=root;
        }
        inorder(root->right);
    }
    Node *treeToDoublyList(Node *root)
    {
        if(!root)return root;
        inorder(root);
        
        prev->right=head;
        head->left=prev;
        return head;
    }
};