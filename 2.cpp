#include<string>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

const char ord[3] = {'R','G','B'};

class ColorfulRoad
{ 	 
	public:
		int fun(string road,int pre,int i,int n,int need)
		{
			if(i>=n) return 0;
			
			int ans = -1;
			for(int j=i; j<n; j++)
			{
				if(road[j]==ord[need])
				{
					int tmp = fun(road,j,j+1,n,(need+1)%3);
					if(tmp<0) continue;
					tmp += (j-pre)*(j-pre);
					if(tmp < ans || ans < 0) ans = tmp;
				}
			}
			return ans;
		}
		int getMin(string road)
		{
			int n = road.length();			
			return fun(road,0,1,n,1);
		} 
};

int main()
{
	ColorfulRoad t;
	cout<< t.getMin("RBRGBGBGGBGRGGG");

}





