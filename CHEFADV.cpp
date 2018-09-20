//https://www.codechef.com/SEPT18B/problems/CHEFADV

//auther : sunny singh yadav

#include <iostream>

using namespace std;

int main()
{
	int numberOfTestCase, N, M, X, Y, S, i;
	
	cin>>numberOfTestCase;
	
	while(numberOfTestCase--)
	{
		cin>>N>>M>>X>>Y;
		
		N = N-1;
		M = M-1;
		
		if( (N >= 0) && ((N)%X == 0) && (M >= 0) && ((M)%Y == 0) )
		{
			cout<<"Chefirnemo\n";
			continue;
		}
		
		N = N-1;
		M = M-1;
		
		if( (N >= 0) && ((N)%X == 0) && (M >= 0) && ((M)%Y == 0)  )
			cout<<"Chefirnemo\n";
		else cout<<"Pofik\n";
	}
	
	return 0;
}
