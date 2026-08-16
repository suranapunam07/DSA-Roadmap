class Solution {
public:
    string convert(string s, int numRows) 
    {
       // T.C=O(n) S.C=O(1)

        if (numRows == 1 || numRows >= s.length())
        {
            return s;
        }

        string ans = "";

        int cycleLength = 2 * (numRows - 1);

        for (int row = 0; row < numRows; row++) {

            for (int j = row; j < s.length(); j += cycleLength) {

                // Vertical character
                ans += s[j];

                // Diagonal character (only for middle rows)
                int diagonal = j + cycleLength - 2 * row;

                if (row != 0 &&
                    row != numRows - 1 &&
                    diagonal < s.length()) {

                    ans += s[diagonal];
                }
            }
        }

        return ans;
    }
};

/*
T.C=O(N) AND S.C=0(N)
if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = true;

        for (int i = 0; i < s.length(); i++) {

            rows[currentRow] += s[i];

            if (currentRow == numRows - 1) {
                goingDown = false;
            }
            else if (currentRow == 0) {
                goingDown = true;
            }

            if (goingDown) {
                currentRow++;
            }
            else {
                currentRow--;
            }
        }

        string ans = "";

        for (int i = 0; i < numRows; i++) {
            ans += rows[i];
        }

        return ans;
*/