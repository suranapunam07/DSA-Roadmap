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
    int minDepth(TreeNode* root) 
    {
        if(root == NULL)
        {
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;

        while(!q.empty())
        {
            int n = q.size();
            depth++;

            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left == NULL && node->right == NULL)
                {
                    return depth;
                }
                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
            }
        }
        return depth;
    }
};

/*

class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }

        if(root->left == NULL)
        {
            return 1 + minDepth(root->right);
        }

        if(root->right == NULL)
        {
            return 1 + minDepth(root->left);
        }

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
*/