#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i, j , a, b, t, n, count = 0;

	cin>>n;

//	vector<int> graph[n+1];
	long long arr[100000];
	map<long long, long long> mp;

	for(i = 0; i <= n; i++)
		arr[i] = 0;

	for(i = 1; i< n; i++)
	{
		cin>>a>>b;

	//	graph[a].push_back(b);
	//	graph[b].push_back(a);
        
        mp[a]++;
		arr[a] += b;
//		arr[b] += arr[a];
	} 

    

	for(i = 1; i< n; i++)
	{
	    if(arr[i] >1)
		{
		    count++;
	//	    cout<<"\ni -->  "<<i<<" <-> arr[i] ->"<<arr[i] <<" \n";
		}
		if(arr[i] > 1)
		for(j = 2; j <= arr[i]/2; j++)
		{
		//     cout<<"\narr[i]%j -->  "<<arr[i]<<" % "<<j<<" -> "<<arr[i]%j<<" -- \n";
			if(arr[i]%j == 0) {
		//	    cout<<"\n boom \n";
				count--;
				break;
			}
		}
	} 

	cout<<count<<"\n";

}