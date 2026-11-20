
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty())
        {
            int n = q.size();

            vector<int> level(n);

            for(int i = 0; i < n; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                int index;

                if(leftToRight)
                    index = i;
                else
                    index = n - 1 - i;

                level[index] = curr->val;

                if(curr->left != NULL)
                    q.push(curr->left);

                if(curr->right != NULL)
                    q.push(curr->right);
            }

            ans.push_back(level);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};
