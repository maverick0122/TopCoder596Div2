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

class SparseFactorialDiv2
{ 	 
	public:
		long long getCount(long long lo, long long hi, long long divisor)
		{
			long long rc[1000];
			memset(rc,-1,sizeof(rc));
			
			rc[0] = 1;
			for(long long i=1; i*i<hi; i++)
			{
				long long a = (i*i)/divisor;
				long long b = (i*i)%divisor;
				
				if(rc[b]<0) rc[b] = a+1;
			}
			
			long long st = -1, cnt = 0;
			for(long long i=0; i<divisor; i++)
			{
				if(rc[i]>-1) cnt++;
				if(rc[i]>st) st = rc[i];
			}
			
			long long lefta = lo/divisor;
			long long leftb = lo%divisor;
			long long righta = hi/divisor;
			long long rightb = hi%divisor;
			
			long long ans = 0;
			
			if(lefta==righta)
			{
				for(long long i=leftb; i<=rightb; i++) 
					if(rc[i]>0 && lefta >= rc[i]) ans++;
			}
			else
			{
				for(long long i=leftb; i<divisor; i++) 
					if(rc[i]>0 && lefta >= rc[i]) ans++;
				
				lefta++;
				for(; lefta < st && lefta < righta; lefta++)
				{
					for(long long i=0; i<divisor; i++)
						if(rc[i]>0 && lefta >= rc[i]) ans++;
				}
				for(long long i=0; i<=rightb; i++) 
					if(rc[i]>0 && righta >= rc[i]) ans++;
				
				ans += cnt*(righta-lefta);
			}
			return ans;
		}
};

int main()
{

}





