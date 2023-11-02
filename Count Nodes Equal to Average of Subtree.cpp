/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNoOfNode(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+countNoOfNode(root->left)+countNoOfNode(root->right);
    }
    int countSubtree(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return root->val + countSubtree(root->left) + countSubtree(root->right);
    }
    void preOrder(TreeNode* root,int &ans){
        if(root==NULL){
            return;
        }
        int n=0;
        n=countNoOfNode(root);
        int m=0;
        m=countSubtree(root);
        if(root->val==(m/n)){
            ans++;
        }
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        preOrder(root,ans);
        return ans;
    }
};
