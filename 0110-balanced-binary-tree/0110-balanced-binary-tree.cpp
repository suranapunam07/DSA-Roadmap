class Solution {
public:

    int checkHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int lh = checkHeight(root->left);

        if(lh == -1)
            return -1;

        int rh = checkHeight(root->right);

        if(rh == -1)
            return -1;

        if(lh - rh > 1 || rh - lh > 1)
            return -1;

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root)
    {
        return checkHeight(root) != -1;
    }
};

/*
class Solution {
public:

    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root)
    {
        if(root == NULL)
            return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if(lh - rh > 1 || rh - lh > 1)
            return false;

        return isBalanced(root->left) &&
               isBalanced(root->right);
    }
};
*/