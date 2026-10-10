class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector <int> diff;
        int n=nums1.size();
        for(int i=0;i<n;i++)
            diff.push_back(abs(nums1[i]-nums2[i]) );
        int limit=-1,k=k1+k2;
        int l=0,r=1e6;
        while(l<=r)
        {
            long long  mid=(l+r)/2,ktemp=0;
            for(int i=0;i<n;i++)
            {
                ktemp+=max(diff[i]-mid,0ll);
            }
            if(ktemp<=k)
            {
                limit=mid;
                r=mid-1;
                
            }
            else 
            l=mid+1;

        }
        cout<<limit<<endl;
        for(int i=0;i<n;i++)
        {
            k-=max(diff[i]-limit,0);
            diff[i]=min(diff[i],limit);
        }
        sort(diff.begin(),diff.end(),greater <int> ());
        for(int i=0;i<n && k>0;i++)
        {
            if(diff[i]>0){
            diff[i]--;
            k--;
            }
        }
        long long ans=0;
        for(auto i : diff)
        ans=(ans+1ll*i*i);

        return ans;

    }
};