class Solution {
    int l,h;
    vector <int> ans;
    set <int> st;
    void calc(string s,int i, int l ,int h)
    {
        if(i==17) return ;
        long long num=stoi(s);

        if(num>=l && num<=h)st.insert(num);

        string ns=(s+(char)(s.back()+1) );
        calc(  ns,i+1,l,h);
    }
    
public:
    vector<int> sequentialDigits(int low, int high) {
        int l=low,h=high;
        for(int i=1;i<10;i++)calc(to_string(i),0,l ,h);
        for(auto i:st)ans.push_back(i);
        return ans;
    }
};