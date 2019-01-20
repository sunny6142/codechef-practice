#include <stdio.h>

int main()
{
	long long i,n,a,m = 0, sum = 0;

    long long arr[10000];

	scanf("%lld",&n);

	for(i = 0; i < n; i++)
	{
		scanf("%lld",&arr[i]);
        
		if(arr[i] > m) m = arr[i];

		sum += arr[i];
	}
	
	m = 99999999;
//	printf("%lld\n",sum);
	
	for(i = 0; i < n; i++)
	{
//	    printf("\n%lld -> %lld - %lld -> %lld\n",m,sum,arr[i],(sum - arr[i]));
	    
		if((sum - arr[i]) < m) 
		    m = sum - arr[i];
	}

printf("%lld\n",m);
	///cout<<sum - m<<"\n";

	return 0;
}