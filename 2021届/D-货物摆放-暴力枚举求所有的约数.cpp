#include<bits/stdc++.h>
using namespace std;
long long int n=2021041820210418, num=0, i, j, k;
vector<long long> a;
int main() {
	int count=0;
	
	//平方是最中间的数，则在平方的左侧和右侧存在对应的俩个数使其相乘等于n，循环时可以减少时间 
	for(i=1; i<=sqrt(n); i++) {
		if(n%i==0) {
			a.push_back(i);
			if(n/i!=i) {
				a.push_back(n/i);//另一侧因数 ，i* n/i=n
			}
		}
	}
	
//	for(i=0;i<a.size();i++){
//		printf("%d ", a[i]);
//	}

	for(i=0; i<a.size(); i++) {
		for(j=0; j<a.size(); j++) {
			for(k=0; k<a.size(); k++) {
				if(a[i]*a[j]*a[k]==n) {
					count++;
					//printf("%lld %lld %lld\n", a[i], a[j], a[k]);

				}
			}
		}
	}

	cout<<count;
	return 0;
}
