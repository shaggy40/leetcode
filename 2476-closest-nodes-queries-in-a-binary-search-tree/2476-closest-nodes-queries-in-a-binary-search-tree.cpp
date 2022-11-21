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
    vector<int> ans;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        int n = ans.size();
        vector<vector<int>> v;
        for(int q : queries){
            int l = 0 , h = n-1;
            int lb = INT_MIN , rb = INT_MAX;
            while(l <= h){
                int mid = (l + h) /2;
                if(ans[mid] == q){
                    lb = q , rb = q;
                    break;
                }else if(ans[mid] < q){
                    lb = max(lb , ans[mid]);
                    l = mid + 1;
                }else{
                    rb = min(rb , ans[mid]);
                    h = mid - 1;
                }
            }
            if(lb == INT_MIN) lb = -1;
            if(rb == INT_MAX) rb = - 1;
            v.push_back({lb , rb});
        }
        return v;
    }
};