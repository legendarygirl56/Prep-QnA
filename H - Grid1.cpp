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
	ll dp[n][m];
	memset(dp,0,sizeof(dp));
	char a[n][m];
	ll g=0;
	for(ll i=0;i<n;i++)
	{
		ll f=0;
		for(ll j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='#')
				dp[i][j]=0;
			if(i==0 && f==0)
			{
				if(a[i][j]=='.')
				{
					dp[i][j]=1;
				}
				else
				{
					f=1;
				}
			}
			else if(j==0 && g==0)
			{
				if(a[i][j]=='.')
				{
					dp[i][j]=1;
				}
				else
				{
					g=1;
				}
			}
			
		}
	}
	for(ll i=1;i<n;i++)
	{
		for(ll j=1;j<m;j++)
		{
			if(a[i][j]!='#')
			dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
		}
	}
	// for(ll i=0;i<n;i++)
	// {
	// 	for(ll j=0;j<m;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	cout<<(dp[n-1][m-1])%mod<<endl;
	return 0;
}