#include<bits/stdc++.h>
using namespace std;
int solve(int n,int m,vector<int>&weight,vector<int>&profit){
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
            else if(weight[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],profit[i-1]+dp[i-1][j-weight[i-1]]);
            }
        }
    }
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    } //*/
    // we find the objects that are selected
     vector<int>selected(n);
     int i=n,j=m;
     while(i>=0 and j>=0){
            if(dp[i][j]==dp[i-1][j]){
                selected[i]=0;
                i--;
            }
            else{
                selected[i]=1;
                i--;
                j=j-weight[i-1];
            }
     }
    // reverse(selected.begin(),selected.end());
     for(auto it:selected){
        cout<<it<<" ";
     }

    return dp[n][m];
}
int KnapsackRecursive(int n,int m,vector<int>&weight,vector<int>&profit){
        if (n == 0 || m== 0)
        return 0;
 
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (weight[n - 1] > m)
        return KnapsackRecursive(n-1, m, weight, profit);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            profit[n - 1]
                + KnapsackRecursive(n-1,m - weight[n - 1], weight, profit),
            KnapsackRecursive(n-1,m,weight,profit));
}
int main(){
   /* int n,m;
    cout<<"Enter the number of objects"<<endl;
    cin>>n;
    cout<<"Enter the capacity of the basket"<<endl;
    cin>>m;*/
    vector<int>profit={ 60, 100,120, 160,250,420,490 };
    vector<int>weight={ 10, 20, 30, 40, 50, 60, 70 };
   /* for(int i=0;i<n;i++){
        cout<<"Enter the weight of the obejct "<<i<<endl;
        cin>>weight[i];
        cout<<"Enter the profit associated with the object"<<i<<endl;
        cin>>profit[i];
    }*/
    int ans=solve(weight.size(),90,weight,profit);
    cout<<"the Maximum profit is "<<ans<<endl;
    return 0;
}