#include<bits/stdc++.h>

using namespace std;


long long getValue(long long a, long long b, long long c, long long d = -1, bool sep = false)
{
	//cout<<a<<" "<<b<<" "<<c<<" ----\n";
	long long i = 0;
	for(i = 1; i < 100; i++)
	{
		if(i == a) continue;
		else if(i == b) continue;
		else if(i == c) continue;
		else if(i == d) continue;
		else {
			if(sep) cout<<"\n"<<a<<" "<<b<<" "<<c<<" "<<d<<" - >"<<i<<"\n";
			return i;
		}
	}
	return i;
}

bool checkValue(long long i, long long j)
{
	if(i >= 0 && j >= 0 && i <= 50 && j <= 50) return true;
	else false;
}

int main()
{
	
	long long n ,  m, t;

	cin>>t;
	
	while(t--)
	{
		cin>>n>>m;
		long long i , j , k , l , o,p;
		map<int, string> mp;

		long long fst[90][90] = {0};

		if(n < m)
		{
			fst[2][2] = 1;
			fst[2][3] = 2;
			fst[3][2] = 1;
			fst[3][3] = 2;
		}
		else {
            fst[2][2] = 1;
			fst[2][3] = 1;
			fst[3][2] = 2;
			fst[3][3] = 2;
		}
			
			for(long long  i = 0; i < n+2; i++)
			{
				for(j = 0; /*j < i+1 &&*/ j <= i;j++)
				{
					fst[i][j] == -1;
					if((i == 2 && j == 2) || (i == 2 && j == 3) || (i == 3 && j == 2) || (i == 3 && j == 3))
					{}
					else if(i != 0 && i != 1 && j != 0 && j != 1)
					{
						if(n < m)
						{
							fst[j][i] = getValue(fst[j][i-2], fst[j-1][i-1],fst[j-2][i],fst[j+1][i-1]);
							fst[i][j] = getValue(fst[i][j-2], fst[i-1][j-1], fst[i-2][j], fst[i-1][j+1]);
							
						}
						else
						{
							fst[i][j] = getValue(fst[i][j-2], fst[i-1][j-1], fst[i-2][j], fst[i-1][j+1]);
							fst[j][i] = getValue(fst[j][i-2], fst[j-1][i-1],fst[j-2][i],fst[j+1][i-1]);
							
						}
						mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
						mp.insert(make_pair(fst[j][i], "yehh i like it, Fuck You Harder"));
					}
				}
			}

			cout<<mp.size()<<"\n";
			
			for(long long  i = 0; i < n+2; i++)
			{
				for(j = 0; j < m+2;j++)
				{
					cout<<fst[i][j]<<" ";
				}
				cout<<"\n";
			}
	}
	return 0;
};