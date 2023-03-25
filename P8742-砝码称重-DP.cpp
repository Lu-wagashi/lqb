#include<bits/stdc++.h>
using namespace std;

const int maxn=105;	//数字最大个数 
const int maxm=200005; //所有数字的和的最大数 
int n,w[maxn],sum,ans;
bool dp[maxn][maxm];
int main()
{
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)	//存储各个砝码重量，和记为sum 
	{
		scanf("%d",&w[i]);
		sum+=w[i];
	}
	/* 状态转移方程： 
	dp[i][j]=dp[i-1]dp[j] || dp[i-1]dp[j+w[i]] || dp[i-1]dp[j-w[i]]; 
	*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j==w[i])	dp[i][j]=1;   //dp的边界dp[0][0]=1;
			else if(dp[i-1][j]==1)	dp[i][j]=1;
			else if(dp[i-1][j+w[i]]==1)	dp[i][j]=1;
			else if(dp[i-1][abs(j-w[i])]==1)	dp[i][j]=1;
		}
	}
	for(int i=1;i<=sum;i++)	ans+=dp[n][i];
	cout<<ans;
	return 0;
}
