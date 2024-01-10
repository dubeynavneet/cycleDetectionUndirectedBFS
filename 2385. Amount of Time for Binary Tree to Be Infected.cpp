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
    void getAdjList(TreeNode* root,unordered_map<int,vector<int>>& umap){
        if(root == NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        if(root->left!=NULL)
        {
            umap[root->val].push_back(root->left->val);
            umap[root->left->val].push_back(root->val);
        }
        if(root->right!=NULL){
            umap[root->val].push_back(root->right->val);
            umap[root->right->val].push_back(root->val);
        }
        getAdjList(root->left,umap);
        getAdjList(root->right,umap);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> umap;
        set<int> s;
        getAdjList(root,umap);
        queue<int> q;
        q.push(start);
        int time = 0,t = 0;
        while(!q.empty()){
            t = q.size();
            for(int i=0;i<t;i++){
                int front = q.front();
                s.insert(front);
                for(int x:umap[front]){
                    if(s.find(x)==s.end())
                        q.push(x);
                }
                if(i==0){
                    time++;
                }
                q.pop();
            }
        }
        return time-1;
    }
};
