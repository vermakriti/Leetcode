/*
Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

Example 1:

Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.

Example 2:

Input: tree = [7], target =  7
Output: 7

*/

// TC-O(N) SC-O(N)
class Solution {
public:
    TreeNode*ans=nullptr;
    void inorder(TreeNode*original,TreeNode*cloned,TreeNode*target){
        if(!original)
            return;
        inorder(original->left,cloned->left,target);
        if(original==target){
            ans=cloned;
            return;
        }    
        inorder(original->right,cloned->right,target);
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inorder(original,cloned,target);
        return ans;
    }
};