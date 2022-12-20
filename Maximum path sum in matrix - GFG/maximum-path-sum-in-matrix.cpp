//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,vector<vector<int>> &Matrix,vector<vector<int>> &dp)
    {
        int N = Matrix.size();
        if( j<0 || j>=N)return -10000000;
        
        if(i == N-1)return Matrix[i][j];
        
        
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int fp = Matrix[i][j] + solve(i+1,j,Matrix,dp);
        int sp = Matrix[i][j] + solve(i+1,j-1,Matrix,dp);
        int tp = Matrix[i][j] + solve(i+1,j+1,Matrix,dp);
        
        return dp[i][j] = max(fp,max(sp,tp));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int ans = -10000;
        vector<vector<int>> dp(N,vector<int>(N,-1));
        for(int j=0;j<N;j++)
        {
            ans = max(ans,solve(0,j,Matrix,dp));
        }
        return ans;
    }
    
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends