#include<iostream>
#include<algorithm>

using namespace std;

int l,r,mid,n,k,a[10];
bool check(int x)//判断此时的等长木棒根数是否大于/小于K 
{
	for(int i=0;i<n;i++)
	{
		sum+=a[i]/x;
	}
}
int main()
{
	scanf("%d%d",&n,&k);//n根木棒，需要得到k段等长度的木棒 
	for(int i=0;i<n;i++) scanf("%d",&a[i]);//各根木棒的长度 ，最大长度=1000 
	sort(a,a+n-1); 
	l=0,r=a[n-1];
	while(l<r)
	{
		mid=r+l<<1;
		if(check(mid)=true )  l=mid;
		else r=mid;		
	}
	
	cout<<L<<endl;
	return 0; 
	//长度=L，L越小，越容易满足K段（		L=1)  10+24+15=49>7
	//L=10， 1+2+1=4 
	//明显的单调区间，(l,r)，l能满足，但是r不能满足，二分特点 
	
	


	
 } 
