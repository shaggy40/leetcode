class Solution {
public:
    int minimumMountainRemovals(vector<int> &arr) 
    {
        if(arr.size()<3)return 0;
        int n= arr.size();
        
        vector<int> dp1(n,1);
      vector<int> dp2(n,1);
    int maxi = 1;
    for(int i = 0;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(arr[prev] < arr[i])
                dp1[i] = max(dp1[i],1+dp1[prev]);
        }
    }
    
    
    
    for(int i = n-1;i>=1;i--)
    {
        for(int prev=n-1;prev>=i;prev--)
        {
            if(arr[prev] < arr[i])
                dp2[i] = max(dp2[i],1+dp2[prev]);
        }
    }
    
    for(int i=0;i<n;i++)
    {
         if(dp1[i]==1 || dp2[i]==1)
                continue;
        maxi = max(maxi,dp1[i]+dp2[i]-1);
    }
        
    
    return arr.size()-maxi;
    }
};