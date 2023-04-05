#include<bits/stdc++.h> 
using namespace std; 
int ans = 0; 
int cnt = 0; 
int path[100]; 
void dfs (int n, int m, int ac) //ac代表对应的酒
{ 
  if (ac <= 0) return ; //边界：酒喝完
  if (ac > m || (ac >= m && n)) return ; //剩余酒量大于花,说明酒量肯定无法喝光；剩余酒量等于花 且店还有，酒也无法喝光
  if (n == 0 && m == 1)     //边界：枚举到剩余酒量为1，n和m刚好用完
  {
    if (ac == 1) ans ++; 
    return ; 
  } 
  if (n > 0) dfs (n-1, m, ac << 1); //遇到店，酒乘2
  if (m > 0) dfs(n, m-1, ac - 1); //遇到花，酒减1
} 
int main() 
{ 
  int n, m;     //店：n；花：m
  cin >> n >> m; 
  dfs (n, m, 2); //2代表初始的酒量，两斗
  ans%=1000000007;
  cout <<ans<< endl;
  return 0; 
  }
