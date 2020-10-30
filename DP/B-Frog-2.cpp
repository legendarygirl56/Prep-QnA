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

	ll n,k;
	cin>>n>>k;
	ll a[n+1];
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vector<ll> dp(n+1,INT_MAX);
	dp[1]=0;
	if(k>n)
		k=n;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+1;j<=i+k && j<=n;j++)
		{
			dp[j]=min(dp[j],dp[i]+abs(a[j]-a[i]));
		}
	}
	cout<<dp[n];
	return 0;
}