#include<bits/stdc++.h>

const double pi=3.14159265358979323846;
typedef long long ll;

using namespace std;
int a[5005];
bool cmp1(int a,int b){
	return a<b;
}
bool cmp2(int a,int b){
	return a>b;
}
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i]=i;
	while(m--){//执行m次操作
		int x,y;
		cin>>x>>y;
		if(x==1){
			sort(a+y,a+n+1,cmp1);//自定义cmp，==1时升序
		}	
		else {
			sort(a+1,a+1+y,cmp2);//自定义cmp，==0时降序
		}
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
  return 0;
}
