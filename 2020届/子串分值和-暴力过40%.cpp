#include <bits/stdc++.h>
using namespace std;
 
int count(string ss) {
	set<char> sset;
	int cnt = 0;
	for (int i = 0; i < ss.size(); i++) {
		if (sset.count(ss[i]) == 0) {	//统计ss[i]在sset中出现的次数，==0代表没出现过 
			sset.insert(ss[i]);	//将ss[i]插入sset容器中， 
		}
	}
	cnt=sset.size();				//统计只出现过一次的字符数 
	return cnt;
}
 
int main() {
	string S, sub;
	cin >> S;//存入字符串 
	long long ans = 0;
	int len = S.size();//字符串长度 
	for (int i = 0; i < len; i++) {//穷举各个字符 
		for (int j = i; j < len; j++) {//枚举从循环字符位置i之后的字符 
			sub = S.substr(i, (j-i+1));  // 返回从pos号位i开始、长度为len的子串sub，
			ans += count(sub);		//统计这一子串sub的非重复数字 
		}
	}
	cout << ans;
	return 0;
}
