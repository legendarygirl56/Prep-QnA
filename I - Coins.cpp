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
	double a[n+1];
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	double dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;j<=i;j++)
		{
			if(j==0)
			{
				dp[i][j]=dp[i-1][j]*(1-a[i]);
			}
			else
			{
				dp[i][j]=dp[i-1][j-1]*a[i] + dp[i-1][j]*(1-a[i]);
			}
		}
	}
	// for(ll i=0;i<=n;i++)
	// {
	// 	for(ll j=0;j<=n;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	double s=0;
	for(ll j=(n/2)+1;j<=n;j++)
	{
		s+=dp[n][j];
	}
	cout<<setprecision(10)<<fixed<<s<<endl;
	return 0;
}