#include<iostream>
using namespace std;

const int maxn=105;	//位置最大个数 
int n,m,dp[maxn][maxn][maxn];//dp[i][j][k]代表目前确定了i店，j个花，剩余酒为k 
int main()
{
	//状态转移方程： dp[i][j]+=dp[i-1][j]*2 ||dp[i][j-1]+1
	scanf("%d%d",&n,&m);		//n个店，m个花 
	dp[0][0][2] = 1;			// 初值
	for(int i = 0; i <=n; i++)	//店循环
	{	
		for(int j = 0; j <= m; j++)//花循环 
		{
			if(!i && !j)	continue;
			for(int k = 0; k <= m; k++) //酒循环 
			{
				if(k%2==0 && i)	dp[i][j][k] += dp[i-1][j][k/2];	//遇店 
				dp[i][j][k] += dp[i][j-1][k+1];	// 遇花
				dp[i][j][k] %= int(1e9 + 7);	// 取模 				
			}			
		}
	}
	cout<<dp[n][m-1][1];
	return 0;
}
