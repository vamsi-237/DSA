#include<bits/stdc++.h>
using namespace std;

//Recursion
int frog_jump(vector<int>vec,int n){
	if(n==0) return 0;
	if(n==1) return abs(vec[0]-vec[1]);
	int left=frog_jump(vec,n-1) + abs (vec[n]-vec[n-1]);
	int right = frog_jump(vec,n-2) + abs (vec[n]-vec[n-2]);
	// cout<<left<<" "<<right<<endl;
	return min(left,right);
}

//Memoization
int fun(int n,vector<int>height,vector<int>&dp){
	if(n==0) return 0;
	if(n==1) return abs(height[0]-height[1]);
	if(dp[n]!=-1) return dp[n];
	int left=fun(n-1,height,dp ) + abs(height[n]-height[n-1]);
	int right=fun(n-2,height,dp)+abs(height[n]-height[n-2]);
	dp[n]=min(left,right);
	return dp[n];
}

//Tabulation
int frog(int n,vector<int>height){
	vector<int>dp(n+1,-1);
	dp[0]=0;
	dp[1]=abs(height[0]-height[1]);
	for(int i=2;i<n;i++){
		int fs = dp[i-1] + abs(height[i]-height[i-1]);
		int ss=dp[i-2] + abs(height[i]-height[i-2]);
		dp[i]=min(fs,ss);
	}
	return dp[n-1];
}

// Space Optimized and best Solution
int frg(int n,vector<int>height){
	int fs=0;
	int ss=abs(height[0]-height[1]);
	for(int i=2;i<n;i++){
		int first =ss +abs(height[i]-height[i-1]);
		int second= fs +abs(height[i]-height[i-2]);
		fs = ss;
		ss = min(first,second);
	}
	return ss;
}
int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif 
	
	int n;
	cin>>n;
	vector<int>height(n);
	for(int i=0;i<n;i++){
		cin>>height[i];
	}

	Recursion
	int energy_required=frog_jump(height,n-1);
	cout<<energy_required<<endl;

	//Memoization
	vector<int>dp(n+1,-1);
	int energy=fun(n,height,dp);
	cout<<dp[n-1]<<endl;

	//Tabulation
	int energy_req=frog(n,height);
	cout<<energy_req<<endl;



	//Space Optimized
	int energy_used=frg(n,height);
	cout<<energy_used;


	return 0;


}