/*

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:

Input: root = [2,2,5,null,null,5,7]
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.

*/

// TC- O(N) SC-O(N)
class Solution {
public:
    void solve(TreeNode*root,int& firstMin,int& secondMin,bool &check){
        if(!root)
            return;
        if(root->val<=firstMin)
            firstMin=min(firstMin,root->val);
        else{
            if(root->val==INT_MAX)
                check=true;
            secondMin=min(secondMin,root->val);
        }    
        solve(root->left,firstMin,secondMin,check);
        solve(root->right,firstMin,secondMin,check);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int firstMin=INT_MAX,secondMin=INT_MAX;
        bool check=false;
        solve(root,firstMin,secondMin,check);
        if(secondMin==INT_MAX && !check)
            return -1;
        return secondMin;
    }
};