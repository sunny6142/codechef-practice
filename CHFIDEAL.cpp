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
    long long a, b, c, d;

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

        for(long long $currentValue= 1; $currentValue <= n; $currentValue  = $currentValue + 4)
        {
            cout<<"1 "<<$currentValue<<" "<<$currentValue+1<<" "<<$currentValue+2<<"\n";

            cin>>a;
            m = getBitValue(m,a);

            cout<<"1 "<<$currentValue<<" "<<$currentValue+1<<" "<<$currentValue+3<<"\n";

            cin>>b;
            m = getBitValue(m,b);

            cout<<"1 "<<$currentValue+2<<" "<<$currentValue+3<<" "<<$currentValue<<"\n";

            cin>>c;
            m = getBitValue(m,c);

            cout<<"1 "<<$currentValue+2<<" "<<$currentValue+3<<" "<<$currentValue+1<<"\n";

            cin>>d;
            m = getBitValue(m,d);

            for(long long i = 0 ;i < 62 ; i++)
            {
                Arr[$currentValue] += findBitValue((m[a][i] == m[b][i]),m[c][i] ) * toToPower[i];
                Arr[$currentValue+1] += findBitValue((m[a][i] == m[b][i]),m[d][i] ) * toToPower[i];
            }

            for(long long i = 0 ;i < 62 ; i++)
            {
                Arr[$currentValue+2] += findBitValue( m[c][i] , m[d][i] , m[a][i] ) * toToPower[i];
            }
            for(long long i = 0 ;i < 62 ; i++)
            {
                Arr[$currentValue+3] += findBitValue( m[c][i] , m[d][i] , m[b][i] ) * toToPower[i];
            }
        }
        /*
        for(long long j = 5; j <= n; j++)
        {
            cout<<"1 "<<"1 "<<"2 "<<j<<"\n";
            cin>>a;
            m = getBitValue(m,a);
            for(long long i = 0 ;i < 62 ; i++)
            {
                Arr[j] += findBitValue( m[c][i] , m[d][i] , m[a][i] ) * toToPower[i];
            }
        } */

        cout<<"2 ";
        for(long long i = 1 ;i <= n ; i++)
        {
           cout<<Arr[i]<<" ";
        }   cout<<"\n"; cin>>a;

    }

	return 0;
}