#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N =2e5+10,mod = 1000000007;
int n;
LL ar[N],br[N],ans;
priority_queue<LL> q;
void solve()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&ar[i]);
        if(ar[i]>1) q.push(ar[i]);
    }
    while(!q.empty())
    {
        LL x = q.top(); q.pop();//利用优先队列的top函数导出队列最大值
        LL z = sqrt(x/2+1);
        if(z>1) q.push(z);
        for(int i=1; i<=n; i++)//找相等区间
        {
            if(ar[i]==x&&ar[i]==ar[i-1]) continue;
            if(ar[i]==x) ans++;
        }
        for(int i=1; i<=n; i++) if(ar[i]==x) ar[i]=z;//进行替换
    }


    printf("%lld\n",ans);

}

int main()
{

    solve();
    return 0;
}
