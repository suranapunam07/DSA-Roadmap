
class Solution {
public:
    string predictPartyVictory(string senate) 
    {
        queue<int> radiant, dire;
        int n = senate.size();

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            radiant.pop();

            int d = dire.front();
            dire.pop();

            if (r < d)
                radiant.push(r + n);
            else
                dire.push(d + n);
        }

        return radiant.empty() ? "Dire" : "Radiant";
        
    }
};

/*
int n = senate.size();
        int rCount = 0, dCount = 0;
        int r = 0, d = 0;

        while (r < n && d < n) {
            for (int i = 0; i < n; i++) {
                if (senate[i] == 'R') {
                    if (rCount > 0) {
                        rCount--;
                        senate[i] = 'X';
                    } else {
                        dCount++;
                    }
                }
                else if (senate[i] == 'D') {
                    if (dCount > 0) {
                        dCount--;
                        senate[i] = 'X';
                    } else {
                        rCount++;
                    }
                }
            }

            r = 0;
            d = 0;

            for (int i = 0; i < n; i++) {
                if (senate[i] == 'R')
                    r++;
                else if (senate[i] == 'D')
                    d++;
            }

            if (r == 0 || d == 0)
                break;
        }

        return (r > 0) ? "Radiant" : "Dire";
*/
