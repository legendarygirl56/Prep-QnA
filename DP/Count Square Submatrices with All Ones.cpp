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

	ll m,n;
	cin>>m>>n;
	ll a[m][n];
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}

	ll dp[m][n]={0};
	ll f[100000]={0},sum=0,ans=0;
	for(ll i=0;i<m;i++)
	{
		dp[i][0]=a[i][0];
	}

	for(ll j=0;j<n;j++)
	{
		dp[0][j]=a[0][j];
	}
	for(ll i=1;i<m;i++)
	{
		for(ll j=1;j<n;j++)
		{
			if(a[i][j]==1)
			dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
		}
	}

	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(dp[i][j]>0)
			{
				f[dp[i][j]]++;
				sum+=1;
			}
		}
	}
	ans+=sum;
	//cout<<sum<<endl;
	for(ll i=1;i<=max(m,n);i++)
	{
		ans+=(sum-f[i]);
		sum-=f[i];
	}
	cout<<ans<<endl;
	return 0;
}

/*
input
0 1 1 1 
1 1 1 1
0 1 1 1

Step-1
solving -dp array
0 1 1 1
1
0

step 2 ->check all 3 and pick minimum of them and add 1 to it(only if the input array had 1 at the same position)
0 1 1 1 
1 1 2 2
0 1 2 3 (min of left ,min of up,min of up diagonal left)+1

So max array of square matrix can be 3*3 size

*/