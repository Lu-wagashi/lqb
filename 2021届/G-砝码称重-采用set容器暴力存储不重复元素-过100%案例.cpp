#include <iostream>
#include <stdlib.h>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;
int n;
// w存放砝码的初始值
int w[103];
// set1用于存放称出的不同重量
set<int> set1;
// tem为每次暂存得到的重量
int tem[200010];
 
int main() {
	cin >> n;
	int a;
	for (int i = 1; i <= n; i++) {
		// 每放置一个砝码，就把他和之前得到的值+-，最后存到set里
		// 但是要注意，不能立刻存进去，否则会出现死循环
		cin >> w[i];
		int tem_len = 0;
		//通过迭代器循环访问set容器， 
		set<int>::iterator it = set1.begin();
		for (; it != set1.end(); it++) {
			tem[tem_len++] = *it + w[i];
			tem[tem_len++] = abs(*it - w[i]);
		}
		for (int i = 0; i < tem_len; i++) {
			set1.insert(tem[i]);
		}
		
		// 最后注意，一定要把自己加进去，否则set1将一直为空
		// 同时清空数组
		set1.insert(w[i]);
		memset(tem, 0, tem_len);
	}
	set1.erase(0);
	cout << set1.size() << endl;
	return 0;
}
