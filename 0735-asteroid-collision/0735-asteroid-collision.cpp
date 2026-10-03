class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> st;

        for(int asteroid : asteroids)
        {
            bool destroyed = false;

            while(!st.empty() && st.back() > 0 && asteroid < 0)
            {
                if(st.back() < -asteroid)
                {
                    st.pop_back();
                }
                else if(st.back() == -asteroid)
                {
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else
                {
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed)
            {
                st.push_back(asteroid);
            }
        }

        return st;
    }
};