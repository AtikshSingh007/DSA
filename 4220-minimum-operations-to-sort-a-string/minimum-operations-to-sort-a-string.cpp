class Solution {
public:
    int minOperations(string s) {
int n=s.size();
        string temp=s;
        sort(temp.begin(),temp.end());
        char str=temp[0],en=temp.back();
        
        if(s==temp)return 0;
        else if(n==2)return -1;
        else if (s[0]==en && s.back()==str )
        {
            if(temp[n-2]==temp.back() || temp[0]==temp[1])
            return 2;
            else 
            return 3;
        }
        else if(s[0]==str || s.back()==en)return 1;
        else return 2;
        
        
    }
};