class Solution {
    
public:
    int totalNumbers(vector<int>& digits) {
        vector <int> freq(10,0);
        for(auto i:digits)freq[i]++;

        int ans=0;

        for(int i=1;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                for(int k=0;k<10;k+=2)
                {
                    vector<int> cnt(10,0);
                    cnt[i]++;
                    cnt[j]++;
                    cnt[k]++;
                    if(cnt[i]<=freq[i] && cnt[j]<=freq[j] && cnt[k]<=freq[k] )ans++;


                }
            }
        }
        return ans;
    }
};