class Solution {
public:
    int calPoints(vector<string>& opt) 
    {
        vector<int> stack;

        for(string op:opt)
        {
            if(op == "+")
            {
                int n = stack.size();
                stack.push_back(stack[n-1]+stack[n-2]);
            }
            else if(op == "D")
            {
                stack.push_back(2 * stack.back());
            }
            else if(op == "C")
            {
                stack.pop_back();
            }
            else
            {
                stack.push_back(stoi(op));//atoi is string to integer.
            }
        }
        int total = 0;
        for(int score : stack)
        {
            total += score;
        }
        return total;
    }
};