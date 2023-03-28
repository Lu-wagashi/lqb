#include<iostream>
#include<algorithm>
using namespace std;

int n,k,len[100],l,r,sum,mid;
int main()
{
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i=0;i<n;i++) scanf("%d",&len[i]);
	sort(len,len+n);
	l=0,r=len[n-1];
	while(l<r)
	{
		sum=0;
		int mid=(l+r)>>1;
		for(int i=0;i<n;i++)	sum+=len[i]/mid;
		if(sum<k)	r=mid;	
		else l=mid+1;
	} 
	cout<<l-1;
	return 0;
}
