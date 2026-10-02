class Solution {
    vector <string> ans;
    int nn;
    
    void calc(string s,int o,int c)
    {
        if( s.size()==2*nn)
        {
            if(o==c)
            ans.push_back(s);
            return ;
        }
        if(o>=c){
        calc( (s+')') , o , c+1);
         calc((s+'(') ,o+1,c);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        nn=n;
        calc("",0,0);
        return ans;
    }
};