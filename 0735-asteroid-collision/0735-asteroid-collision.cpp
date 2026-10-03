class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int top = -1;
        int i = 0;

        while(i < asteroids.size())
        {
            if(top == -1 || asteroids[top] < 0 || asteroids[i] > 0)
            {
                asteroids[++top] = asteroids[i];
                i++;
            }
            else if(asteroids[top] < -asteroids[i])
            {
                top--;
            }
            else if(asteroids[top] == -asteroids[i])
            {
                top--;
                i++;
            }
            else
            {
                i++;
            }
        }
        asteroids.resize(top + 1);
        return asteroids;
    }
};

/*

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
*/