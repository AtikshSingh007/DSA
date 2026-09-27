class Solution {
public:
    string reverseParentheses(string s) {
    string res="";
    vector<int> ind;
    int n=s.size();

    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')ind.push_back(res.size());
        else if(s[i]==')'){
            int st=ind.back();
            reverse(res.begin()+st,res.end());
            ind.pop_back();
        }
        else 
        res.push_back(s[i]);

    }
    return res;
    }
};