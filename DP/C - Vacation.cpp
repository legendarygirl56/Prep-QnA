#include<bits/stdc++.h>

#define ll long long int
#define llu unsigned long long int
#define f(n) for(ll i=0;i<n;i++)
#define fr(n) for(ll i=n-1;i>=0;i--)
#define endl "\n"
#define mod 1000000007

using namespace std;


ll a[100001][3];
ll dp[100001][4];


ll fun(ll day,ll act,ll n)
{
	if(day==n)
		return 0;

	if(dp[day][act]!=-1)
		return dp[day][act];

	ll maxi=-1;
	if(act==0)
	{
		maxi=max(maxi,a[day][1]+fun(day+1,1,n));
		maxi=max(maxi,a[day][2]+fun(day+1,2,n));
	}
	else if(act==1)
	{
		maxi=max(maxi,a[day][0]+fun(day+1,0,n));
		maxi=max(maxi,a[day][2]+fun(day+1,2,n));
	}
	else
	{
		maxi=max(maxi,a[day][0]+fun(day+1,0,n));
		maxi=max(maxi,a[day][1]+fun(day+1,1,n));
	}
	return dp[day][act]=maxi;
}

int main()
{
	//#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//#endif
	std::ios_base::sync_with_stdio(false);

	ll n;
	cin>>n;
	
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<max(fun(0,0,n),max(fun(0,1,n),fun(0,2,n)))<<endl;
	return 0;
}