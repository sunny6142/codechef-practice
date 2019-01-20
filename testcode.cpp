#include <bits/stdc++.h>

using namespace std;

int isSame(long long a, long long b)
{
    return (a == b);
}



map<long long,map<long long,int> > getBitValue(map<long long, map<long long, int> > m, long long a)
{
    long long i = 0;
    long long val = a;
    while(a > 0)
    {
        m[val][i] = a % 2;
        a = a / 2;
        i++;
    }    
    while(i < 65)
    {
        m[val][i] = 0;
        i++;
    }
    return m;
}

int findBitValue(bool isSame, long long c)
{
    if(isSame) 
        return c;
    else 
        return (c == 0)?1:0;
}

int findBitValue(int a, int b, int c)
{
    if(a == 0 && b == 0 && c == 0) return c;
    if(a == 0 && b == 0 && c == 1) return c;
    if(a == 0 && b == 1 && c == 1) return a;
    if(a == 1 && b == 0 && c == 1) return b;
    if(a == 0 && b == 1 && c == 0) return b;
    if(a == 1 && b == 1 && c == 0) return c;
    if(a == 1 && b == 0 && c == 0) return a;
    if(a == 1 && b == 1 && c == 1) return a;
}


int main()
{
	long t;
    long long a, b, c, d, e, f;

    cin>>t;
    
    while(t--)
    {
        long n;
        cin>>n;
        long long toToPower[62];
        map<long long,map<long long,int> > m;
        
        long long Arr[100000] = {0};
        toToPower[0] = 1;
        
        for(int i = 1; i < 62; i++)
        {
            toToPower[i] = 2 * toToPower[i-1];
        }

        cout<<"1 "<<"1 "<<"2 "<<"3\n";

        cin>>a;
        
        cout<<"1 "<<"1 "<<"2 "<<"4\n";

        cin>>b;
        
        cout<<"1 "<<"5 "<<"6 "<<"7\n";

        cin>>c;
        
        cout<<"1 "<<"5 "<<"6 "<<"8\n";

        cin>>d;

        cout<<"1 "<<"3 "<<"4 "<<"5\n";

        cin>>e;
        
        cout<<"1 "<<"3 "<<"4 "<<"7\n";

        cin>>f;

        Arr[5] =  a ^ b ^ e;                                 
        Arr[7] =  a ^ b ^ f;
        Arr[8] =  c ^ d ^ Arr[7];
        Arr[6] =  c ^ Arr[5] ^ Arr[7];
        Arr[4] =  b ^     

        for(long long i = 1 ;i <= n ; i++)
        {
           cout<<Arr[i]<<" ";
        }   cout<<"\n"; cin>>a;

    }

	return 0;
}