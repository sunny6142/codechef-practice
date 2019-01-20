#include<bits/stdc++.h>

using namespace std;

int main()
{

	long long i, j , l , m , n;
	long long t, p;

	cin>>t;

	while(t--)
	{
		cin>>n>>p;

		long long maxReminder = 0;
		long long noOElProduceLR = 0;
		long long totalNumberOfPPermu = 1;
		long long totalRequiredNumber = 0;
		long long totalEProduceLessReminder = 0;
        long long totalEProduceMoreReminder = 0;                         	
		i = 1;
                                    	
	
		maxReminder = n %(n/2 +1);
		//if(n <= 1)	maxReminder = 0;
		totalRequiredNumber = (p-maxReminder);

		if(maxReminder == 0)
		{
            totalNumberOfPPermu = (totalRequiredNumber * totalRequiredNumber * totalRequiredNumber);
		}
		else if(n < p)
			totalNumberOfPPermu = (totalRequiredNumber * totalRequiredNumber ) + 
								  ( (-n+p) * totalRequiredNumber)  + 
								  ( (-n+p) * (-n+p) );

		else
			totalNumberOfPPermu = (totalRequiredNumber * totalRequiredNumber);


		cout<<totalNumberOfPPermu<<"\n";

		//3, 4

		//maxReminder = 1;

		//((2) *  3 * 3) +  {(3-4) * (2) * 3} + (3-4) * (3-4) * (2);
	}
	return 0;
}