#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
void dfs(int dian,int hua,int jiu)
{
	if(dian>n || hua>m-1 || jiu<0 || jiu>m) return;//递归边界 
	if(dian==n && hua==m-1 && jiu==1){ans++;return;}
	dfs(dian,hua+1,jiu-1);//遇到花
	dfs(dian+1,hua,jiu *2);//遇到店	 
}
int main()
{
	scanf("%d%d",&n,&m); //n-店数，m-花数 
	dfs(0,0,2);
	cout<<ans;
	return 0;
}
