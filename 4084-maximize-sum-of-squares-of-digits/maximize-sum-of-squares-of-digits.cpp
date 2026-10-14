class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while(num--)
        {
            int limit=min(sum,9);
            //cout<<limit<<endl;
            sum-=limit;
        ans.push_back( ( ((char)('0'+limit)) ) );
        }
        if(sum)
        return "";
        return ans;;
    }
};