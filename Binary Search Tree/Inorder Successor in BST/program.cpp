/*

Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST. If the given node has no in-order successor in the tree, return null.

The successor of a node p is the node with the smallest key greater than p.val.

Example 1:

Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.

Example 2:

Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
 
*/ 

class Solution {
public:
    TreeNode*find(TreeNode*root,TreeNode*p){
        if(!root)
            return nullptr;
        if(p==root)
            return root;
        if(p->val>root->val)
            return find(root->right,p);
        return find(root->left,p);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
        TreeNode*curr=find(root,p);
        if(!curr)
            return nullptr;
        if(curr->right){
            TreeNode*temp=curr->right;
            while(temp->left)
                temp=temp->left;
            return temp;
        }
        else{
            TreeNode*successor=nullptr;
            TreeNode*ancestor=root;
            while(ancestor!=curr){
                if(ancestor->val>curr->val){
                    successor=ancestor;
                    ancestor=ancestor->left;
                }
                else ancestor=ancestor->right;
            }
            return successor;
        }
        return nullptr;
    }
};

// TC-O(logN)
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode*successor=nullptr;
        while(root){
            if(p->val<root->val){
                successor=root;
                root=root->left;
            }
            else root=root->right;
        }
        return successor;
    }
};