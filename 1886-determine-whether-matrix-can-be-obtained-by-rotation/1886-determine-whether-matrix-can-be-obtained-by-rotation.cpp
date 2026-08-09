class Solution {
public:

    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();

        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Reverse every row
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool same(vector<vector<int>>& mat,
              vector<vector<int>>& target) {

        return mat == target;
    }

    bool findRotation(vector<vector<int>>& mat,
                      vector<vector<int>>& target) {

        for (int rotation = 0; rotation < 4; rotation++) {

            if (same(mat, target))
                return true;

            rotate(mat);
        }

        return false;
    }
};