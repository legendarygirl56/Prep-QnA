#include<bits/stdc++.h>

#define ll long long int
#define llu unsigned long long int
#define f(n) for(ll i=0;i<n;i++)
#define fr(n) for(ll i=n-1;i>=0;i--)
#define endl "\n"
#define mod 1000000007

using namespace std;

int main()
{
	//#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//#endif
	std::ios_base::sync_with_stdio(false);

	ll n;
	cin>>n;
	ll a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll dp[100001]={0};
	dp[1]=0;
	dp[2]=abs(a[2]-a[1]);
	//cout<<dp[1]<<" "<<dp[2]<<" ";
	for(ll i=3;i<=n;i++)
	{

		dp[i]=min((dp[i-1]+abs(a[i]-a[i-1])) , (dp[i-2]+abs(a[i]-a[i-2])));
		//cout<<dp[i]<<" ";
	}
	cout<<dp[n]<<endl;
	return 0;
}

/*
SAMPLE INPUT
4 -Num of stones
10 30 40 20  -Height of stones

SAMPLE OUTPUT
30

Problem Statement
There are N stones, numbered 1 to N.
Need to reach from 1 to nth stone by jumping i+1 or i+2 steps.
Cost of each step is difference of height of those two stone.


Solution

					4

			3				2(heigt[2]-height[1] + cost[1])

		2		1(0 cost)	1 (0 cost)

		1(0 cost)