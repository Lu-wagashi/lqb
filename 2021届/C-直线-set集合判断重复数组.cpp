#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
	set<pair<double,double> > a;//定义一个pair二重的set容器 
    for (int x1 = 0; x1 < 20; x1 ++ )
        for (int y1 = 0; y1 < 21; y1 ++ )
            for (int x2 = 0; x2 < 20; x2 ++ )
                for (int y2 = 0; y2 < 21; y2 ++ )
                    if (x1 != x2)
                    {
                        double k=(double)(y2-y1)/(x2-x1);
                        double b=(double)(x1*y2-x2*y1)/(x1-x2);
                        a.insert({k,b});//把k，b存入容器中，set容器为不重复元素
                    }
	cout<<a.size()+20;		
    return 0;
}
