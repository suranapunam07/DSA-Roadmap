class Solution {
public:
    bool isAnagram(string s, string t) 
    {
       if(s.size() != t.length())
       {
        return false;
       }

       unordered_map<char,int>m;

       for(char c : s)
       {
        m[c]++;
       }
       for(char c : t)
       {
        m[c]--;

        if(m[c] < 0)
        {
            return false;
        }
       }
       return true;  
    }
};

/*
 if(s.size() != t.length())
       {
        return false;
       }

       sort(s.begin(),s.end());
       sort(t.begin(),t.end());

       return s==t;
*/