//Fibonacci series

#include<bits/stdc++.h>
using namespace std;

// Recursion;
int fibonacci(int n){
	if(n<=2) return n-1;
	int left=fibonacci(n-1);
	int right=fibonacci(n-2);
	return left+right;
}

// Memoization

int fibo(vector<int>&dp,int n){
	if(n<=1) {
		dp[n]=n;
		return n;
	}
	if(dp[n]!=-1) return dp[n];
    int left=fibo(dp,n-1);
    int right=fibo(dp,n-2);
    dp[n]=left+right;
    return dp[n];

}

//Tabulation
int fib(vector<int>&vec,int n){
	vec[0]=0;
	vec[1]=1;
	for(int i=2;i<=n;i++){
		vec[i]=vec[i-1]+vec[i-2];

	}
	return vec[n-1];
}

//Space Optimized ----- Best Solution

int fi(int n){
	int first=0;
	int second=1;
	int ans=0;
	for(int i=2;i<=n;i++){
		ans = first+second;
		second=first;
		first=ans;
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	//recursion
	int nth_fibo=fibonacci(n);
	cout<<nth_fibo<<endl;


	//Memoization
	vector<int>dp(n+1,-1);
	int nth_fibo1=fibo(dp,n);
	cout<<dp[n-1]<<endl;


	//tabulation
	vector<int>v(n+1,-1);
	int nth_fibo2=fib(v,n);
	cout<<nth_fibo2<<endl;

	//Space Optimized
	int nth_fibo3=fi(n);
	cout<<nth_fibo3;

	return 0;

}