class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> q;

        for (int student : students) 
        {
            q.push(student);
        }

        int sandwichidx = 0;
        int count = 0;

        while (!q.empty() && count < q.size()) 
        {

            if (q.front() == sandwiches[sandwichidx]) 
            {
                q.pop();
                sandwichidx++;
                count = 0;
            }
            else 
            {
                q.push(q.front());
                q.pop();
                count++;
            }
        }

        return q.size();
    }
};