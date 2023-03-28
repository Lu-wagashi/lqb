#include <bits/stdc++.h>
using namespace std;
//sum所有数的总和，ans:dfs所走路径的数字总和，cnt:dfs所走路径的点的个数，res:答案-合格组的最少数字个数 
//a[][]记录对应位置的数字 
int a[12][12], n, m, sum, ans, res, cnt;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};  //分别对应 右下上左 四个方向的移动 
bool judge[12][12]; //判断每一个点是否走过

//未判断连通块-是否会产生三块（题目要求只有两块）

void dfs(int x, int y)
{
    if(cnt >= res ) return; //递归边界1：cnt数量大于全局变量答案res，直接返回，剪枝 
    if(ans == sum/2) {	    //递归边界2：条件符合，选出最小的路径点数
        res = min(res ,cnt);
        return ;
    }
    if(ans > sum/2) return ;//递归边界3：ans上限为总和sum的一半，剪枝
    //遍历四个方向，进行深搜 
    for(int i = 0; i < 4; i++){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        //边界、点检测
        if(dx<=0 || dy<=0 || dx>n || dy>m || judge[dx][dy]==true) continue;//点超出边界范围且未用过，跳过此次循环 
        cnt++; ans += a[dx][dy]; judge[dx][dy] = true;//加入该点 
        dfs(dx,dy);
        cnt--; ans -= a[dx][dy]; judge[dx][dy] = false;//用完该点 
    }
}
int main()
{
    memset(judge,false,sizeof(judge));	//初始化函数 
    sum = 0;
    scanf("%d%d",&m,&n); 
    for(int i = 1; i <= n; i++)
    	for(int j = 1; j <= m; j++)
    	{
        	cin >>a[i][j];
        	sum += a[i][j];
    	}
    //初始化起始
    cnt = 1;  res = 110;	//最多有100个数 
    ans = a[1][1];
    //奇数判断:sum无法平均分为两份 
	if(sum%2==1)	cout<<0<<endl;
	else dfs(1,1);	//从1,1开始搜索 
    //输出结果res
    if(res == 110) cout <<0;
    else cout <<res;
    return 0;
}
