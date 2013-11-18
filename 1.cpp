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

const int maxM = 40;

class FoxAndSightseeing
{ 	 
	public:
		int getMin(vector <int> position)
		{
			int n = position.size();
			
			int ans = 0,sum = 0;
			
			for(int i=1; i<n-1; i++)
			{
				int tmp = abs(position[i]-position[i-1])+abs(position[i+1]-position[i])-
					abs(position[i+1]-position[i-1]);
				if(tmp>ans) ans = tmp;
			} 
			for(int i=0; i<n-1; i++)
				sum += abs(position[i+1]-position[i]);
			return sum - ans;
		} 
};

int main()
{
}





