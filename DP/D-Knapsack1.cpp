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
	
	ll n,m;
	cin>>n>>m;
	ll dp[101][100001];
	memset(dp,0,sizeof(dp));
	vector<pair<ll,ll>> v;
	for(ll i=0;i<n;i++)
	{
		ll w,p;
		cin>>w>>p;
		v.push_back(make_pair(w,p));
	}
	for(ll i=1;i<n+1;i++)
	{
		for(ll j=1;j<m+1;j++)
		{
			if(j-(v[i-1].first)>=0)
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-(v[i-1].first)] +(v[i-1].second));
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][m]<<endl;

	return 0;
}