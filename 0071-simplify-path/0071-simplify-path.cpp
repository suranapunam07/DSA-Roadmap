class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string temp = "";

        for (int i = 0; i <= path.size(); i++) {
            
            if (i < path.size() && path[i] != '/') 
            {
                temp += path[i];
            }
            else 
            {
                if (temp == "..") 
                {
                    if (!st.empty()) 
                    {
                        st.pop();
                    }
                }
                else if (temp != "" && temp != ".") 
                {
                    st.push(temp);
                }
                temp = "";
            }
        }
        string result = "";
        while (!st.empty()) 
        {
            result = "/" + st.top() + result;
            st.pop();
        }

        if (result == "") 
        {
            return "/";
        }
        return result;
    }
};