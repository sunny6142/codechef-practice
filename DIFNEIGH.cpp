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
		long long a,b,c,d;
		map<int, string> mp;

		long long fst[90][90] = {0};
			
			for(long long  i = 0; i < n; i++)
			{
				for(j = 0; /*j < i+1 &&*/ j < m ;j++)
				{
					if(i < 2 && j > 2) continue;
					else if(i < 2 && j < 2)
					{
						if(n < m)
						{
							if(i == 0 && j == 0)
							{
								fst[0][0] = 1; 
								mp.insert(make_pair(fst[i][j],"Fuck You")); 
							}
							if(i == 0 && j == 1)
							{
								fst[0][1] = 2; 
								mp.insert(make_pair(fst[i][j],"Fuck You")); 
							}
							if(i == 1 && j == 0)
							{
								fst[1][0] = 1;
								mp.insert(make_pair(fst[i][j],"Fuck You")); 
							}
							if(i == 1 && j == 1)
							{
								fst[1][1] = 2;
								mp.insert(make_pair(fst[i][j],"Fuck You")); 
							}
							else continue;
						}
						else {
							if(i == 0 && j == 0)
							{
								fst[0][0] = 1; 
								mp.insert(make_pair(fst[i][j],"Fuck You")); 
							}
							if(i == 0 && j == 1)
							{
								fst[0][1] = 2; 
								mp.insert(make_pair(fst[i][j],"Fuck You")); 
							}
							if(i == 1 && j == 0)
							{
								fst[1][0] = 1;
								mp.insert(make_pair(fst[i][j],"Fuck You")); 
							}
							if(i == 1 && j == 1)
							{
								fst[1][1] = 2;
								mp.insert(make_pair(fst[i][j],"Fuck You")); 
							}
							else continue;
						}
					}
					else if(j == 0)
					{
						if(n < m) {

							fst[j][i] = getValue(checkValue(j,i-2)?fst[j][i-2]:-1, -1, checkValue(j+1,i-1)?fst[j+1][i-1]:-1);
						//	fst[i][j] = getValue(checkValue(i-2,j)?fst[i-2][j]:-1, -1, checkValue(i-1,j+1)?fst[i-1][j+1]:-1);

							mp.insert(make_pair(fst[i][j],"Fuck You")); 
							mp.insert(make_pair(fst[j][i], "Fuck You Harder")); 
						}
						else {
					//		cout<<"\n"<<i<<"-"<<j<<"*\n";
							fst[i][j] = getValue(checkValue(i-2,j)?fst[i-2][j]:-1, -1, checkValue(i-1,j+1)?fst[i-1][j+1]:-1);
						//	fst[j][i] = getValue(checkValue(j,i-2)?fst[j][i-2]:-1, -1, checkValue(j+1,i-1)?fst[j+1][i-1]:-1);
							mp.insert(make_pair(fst[i][j],"Fuck You")); 
							mp.insert(make_pair(fst[j][i], "Fuck You Harder")); 
						}

					}

					else if( j == (m-2) )
					{
						//cin>>o;
						if(n < m) {
					//		fst[j][i] = getValue(checkValue(j-2,i)?fst[j-2][i]:-1, checkValue(j,i-2)?fst[j][i-2]:-1, checkValue(j-1,i-1)?fst[j-1][i-1]:-1, checkValue(i+1,j-1)?fst[i+1][j-1]:-1);
							fst[i][j] = getValue(checkValue(i-2,j)?fst[i-2][j]:-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1, checkValue(i,j-2)?fst[i][j-2]:-1, checkValue(i-1,j+1)?fst[i-1][j+1]:-1);
							mp.insert(make_pair(fst[i][j],"Fuck You")); 
							mp.insert(make_pair(fst[j][i], "Fuck You Harder")); 
						}
						else {
						//	cout<<"\n [i][j]"<<i<<" "<<j<<" -> "<<fst[i][j]<<" => "<<fst[i-2][j]<<" "<<fst[i-1][j-1]<<" "<<fst[i][j-2]<<" "<<fst[i-1][j+1]<<"\n";
						
							fst[i][j] = getValue(checkValue(j,i-2)?fst[i-2][j]:-1, checkValue(j-1,i-1)?fst[i-1][j-1]:-1, checkValue(i,j-2)?fst[i][j-2]:-1, checkValue(i-1,j+1)?fst[i-1][j+1]:-1);
						//	fst[j][i] = getValue(checkValue(j-2,i)?fst[j-2][i]:-1, checkValue(j,i-2)?fst[j][i-2]:-1, checkValue(j-1,i-1)?fst[j-1][i-1]:-1, checkValue(i+1,j-1)?fst[i+1][j-1]:-1, true);
							mp.insert(make_pair(fst[i][j],"Fuck You")); 
							mp.insert(make_pair(fst[j][i], "Fuck You Harder")); 
						}
						
					}
					else if (j == (m-1))
					{
						fst[i][j] = getValue(checkValue(i-2,j)?fst[i-2][j]:-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1, checkValue(i,j-2)?fst[i][j-2]:-1);
					mp.insert(make_pair(fst[i][j], "Fuck You Harder")); 
					}
					else
					{
						if(n <= m)
						{
						//	fst[j][i] = getValue(checkValue(j-2,i)?fst[j-2][i]:-1,checkValue(j,i-2)?fst[j][i-2]:-1, checkValue(j-1,i-1)?fst[j-1][i-1]:-1, checkValue(j+1,i-1)?fst[j+1][i-1]:-1 );
							fst[i][j] = getValue(checkValue(j-2,i)?fst[j-2][i]:-1,checkValue(i-2,j)?fst[i-2][j]:-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1, checkValue(i-1,j+1)?fst[i-1][j+1]:-1 );
							mp.insert(make_pair(fst[i][j],"Fuck You")); 
					mp.insert(make_pair(fst[j][i], "Fuck You Harder")); 
						}
						else {
							fst[i][j] = getValue(checkValue(j-2,i)?fst[j-2][i]:-1, checkValue(i-2,j)?fst[i-2][j]:-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1, checkValue(i-1,j+1)?fst[i-1][j+1]:-1);
					//		fst[j][i] = getValue(checkValue(j-1,i)?fst[j-2][i]:-1, checkValue(j,i-2)?fst[j][i-2]:-1, checkValue(j-1,i-1)?fst[j-1][i-1]:-1, checkValue(j+1,i-1)?fst[j+1][i-1]:-1);
							mp.insert(make_pair(fst[i][j],"Fuck You")); 
							mp.insert(make_pair(fst[j][i], "Fuck You Harder")); 
						}
						
					}
					
				}

			}


			if(n < m)
			{
				//for(long long i = 0; i < n; i++)
				for(j = n; j < m; j++)
				{
					for(i = 0; i < n; i++)
					//for(j = n; j < m; j++)
					{
						if(j >= 1)
						{
							if(i == 0){
							//	cout<<"\n->"<<fst[i][j-2]<<" "<<fst[i+1][j-1]<<"\n";
								fst[i][j] = getValue(checkValue(i,j-2)?fst[i][j-2]:-1, checkValue(i+1,j-1)?fst[i+1][j-1]:-1, -1);
								mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
							}
							else if(i == n-2){
								
								fst[i][j] = getValue(checkValue(i,j-2)?fst[i][j-2]:-1, checkValue(i+1,j-1)?fst[i+1][j-1]:-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1, checkValue(i-2,j)?fst[i-2][j]:-1);
								mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
								
							}
							else if(i == n-1){
								fst[i][j] = getValue(checkValue(i,j-2)?fst[i][j-2]:-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1,-1, checkValue(i-2,j)?fst[i-2][j]:-1);
								mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
								//cout<<"\n"<<fst[i-1][j-1]<<" "<<fst[i][j-2]<<" "<<fst[i+1][j-1]<<" "<<fst[i][j]<<"\n";
							}
							else if(i == 1){

									fst[i][j] = getValue(checkValue(i,j-2)?fst[i][j-2]:-1, checkValue(i+1,j-1)?fst[i+1][j-1]:-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1);
									mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
							}
							else
							{
								fst[i][j] = getValue(checkValue(i,j-2)?fst[i][j-2]:-1,checkValue(i-1,j-1)?fst[i-1][j-1]:-1,checkValue(i+1,j-1)?fst[i+1][j-1]:-1, checkValue(i-2,j)?fst[i-2][j]:-1);
								mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
							}
						}
						else if (j == 1){
								if(i == 0){
									fst[i][j] = getValue(-1, checkValue(i+1,j-1)?fst[i+1][j-1]:-1, -1);
								}
								else if(i == 1){
									if(i+2 < n)
									{
										fst[i][j] = getValue(-1, checkValue(i+1,j-1)?fst[i+1][j-1]:-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1, checkValue(i+2,j)?fst[i+2][j]:-1);
										mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
									}
									else {
										fst[i][j] = getValue(-1, checkValue(i+1,j-1)?fst[i+1][j-1]:-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1);
										mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
									}
								}
								else if(i == n-2){

									if(i-2 > 0)
									{
										fst[i][j] = getValue(-1, checkValue(i+1,j-1)?fst[i+1][j-1]:-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1, checkValue(i-2,j)?fst[i-2][j]:-1);
										mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
									}
									else {
										fst[i][j] = getValue(-1, checkValue(i+1,j-1)?fst[i+1][j-1]:-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1);
										mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
									}
								}
								else if(i == n-1){
									fst[i][j] = getValue(-1, checkValue(i-1,j-2)?fst[i-1][j-1]:-1, checkValue(i-2,j)?fst[i-2][j]:-1);
									mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
								}
								else
								{
									fst[i][j] = getValue(-1, checkValue(i-1,j-1)?fst[i-1][j-1]:-1,checkValue(i+1,j-1)?fst[i+1][j-1]:-1, checkValue(i-2,j)?fst[i-2][j]:-1);
									mp.insert(make_pair(fst[i][j], "yehh i like it, Fuck You Harder"));
								}
						}
					}
				}
			}
			cout<<mp.size()<<"\n";
			
			for(long long  i = 0; i < n; i++)
			{
				for(j = 0; j < m ;j++)
				{
					cout<<fst[i][j]<<" ";
				}
				cout<<"\n";
			}
	}
	return 0;
};