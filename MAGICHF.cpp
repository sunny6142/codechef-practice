//https://www.codechef.com/SEPT18B/problems/MAGICHF

//auther : sunny singh yadav

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int numberOfTestCase, N, X, S, i, a, b;
	
	cin>>numberOfTestCase;
	
	while(numberOfTestCase--)
	{
		cin>>N>>X>>S;
		
		for(int i = 0; i < S;i++)
		{
			cin>>a>>b;
			X = (X == a) ? b : ( (X == b) ? a : X );
		}
		cout<<X<<"\n";
	}
	
	return 0;
}
