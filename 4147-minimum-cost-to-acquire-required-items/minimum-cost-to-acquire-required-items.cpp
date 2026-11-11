class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long  mn=min(need1,need2),mx=max(need1,need2);
        long long ans=0;
        if((cost1+cost2)<costBoth)
        ans+=(cost1+cost2)*mn;
        else
        ans+=costBoth*mn;

        if(costBoth > cost1)
        ans+=cost1*(need1-mn);
        else 
        ans+=costBoth*(need1-mn);

        if(costBoth > cost2)
        ans+=cost2*(need2-mn);
        else 
        ans+=costBoth*(need2-mn);
return ans;
    }
};