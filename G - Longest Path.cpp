#include<bits/stdc++.h>

#define ll long long int
#define llu unsigned long long int
#define f(n) for(ll i=0;i<n;i++)
#define fr(n) for(ll i=n-1;i>=0;i--)
#define endl "\n"
#define mod 1000000007

using namespace std;
ll dp[100009];
vector<ll> v[100009];


ll solve(ll i)
{
	if(dp[i]!=-1)
		return dp[i];

	ll r=0;
	for(ll j=0;j<v[i].size();j++)
	{
		r=max(r,solve(v[i][j])+1);
	}
	return dp[i]=r;
}

int main()
{
	//#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	//#endif
	std::ios_base::sync_with_stdio(false);
	ll n,m;
	
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		x--;
		y--;
		v[x].push_back(y);
	}
	memset(dp,-1,sizeof(dp));
	ll ans=0;

	//to print 
	// for(ll i=1;i<=n;i++)
	// {
	// 	cout<<i<<" -> ";
	// 	for(ll j=0;j<v[i].size();j++)
	// 	{
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }


	for(ll i=0;i<n;i++)
	{
		ans=max(ans,solve(i));
	}
	cout<<ans<<endl;
	// for(ll i=0;i<n;i++)
	// 	cout<<dp[i]<<" ";
	return 0;
}