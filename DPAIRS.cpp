#include<iostream> 
#include<iterator> 
#include<map> 

using namespace std;

long long a[1000000];
long long b[1000000];

int main()
{
	
	long long n ,  m, t;

		cin>>n>>m;
		long long i , j , k , l , o,p, n1,m1;
		

		map<long long, pair<long long, long long>> mp;
		map<long long, long long > mk;

		for(i = 0; i < n; i++)
		{
			cin>>o;
			if(mk[o] == 0)
			{
				mk[o] = 1; 
				a[i] = o;
				n1++;
			}
		}
		mk.clear();
		for(i = 0; i < m;i++)
		{
			cin>>o;
			if(mk[o] == 0)
			{
				mk[o] = 1; 
			//	a[i] = o;
				b[i] = o;
				m1++;
				mp.insert(make_pair(b[i] + a[0],make_pair(0, i)));
			}

		}

			i = 1;
			if(n > 1)
			for(j = 0; j< m1; j++)
			{
				mp.insert(make_pair(b[j] + a[i],make_pair(i, j)));
				if(mp.size() == n+m-1) break;
			}

			i = 2;
			if(n > 2)
			for(j = 0; j< m1; j++)
			{
				mp.insert(make_pair(b[j] + a[i],make_pair(i, j)));
				if(mp.size() == n+m-1) break;
			}

		// fnd
		long long c = 0;
		map<long long,pair<long long, long long> >::iterator itr;
		
		for(itr = mp.begin() ; itr != mp.end(); itr++){ 
			//cout<<"\n"<<itr->first<<" - "<<(itr->second).first<<" - "<<(itr->second).second<<" \n";
			cout<<(itr->second).first<<"  "<<(itr->second).second<<"\n";
			c++;
			if(c == n+m-1) break;
		}
	
	return 0;
};