#include<iostream> 
#include<iterator> 
#include<map> 

using namespace std;

long long v[1000000];

int main()
{
	
	long long n ,  m, t;

	cin>>t;
	long long i , j , k , l , o, p, a, b;
   
   	
	while(t--)
	{
		cin>>n>>a>>b;

		long long bob = 0, alice = 0;

		int ch = 1;
		int lo = 0;
		for(i = 0; i < n; i++)
		{
			cin>>o;
			if(o == 0) continue;
			if((o % a) == 0 && (o % b) == 0) {
				if(ch == 1){
					lo++; ch = 0;
				}
				else {
					lo++; ch = 1;
				}

			}

			else if((o % a) == 0) bob++;
			else if((o % b) == 0) alice++;
		}

		//cout<<bob<<alice<<"\n";
		if(bob > alice){
			cout<<"BOB\n";
		}	
		else if(lo && bob+1 > alice ) cout<<"BOB\n"; else cout<<"ALICE\n";
	}

		
	return 0;
}