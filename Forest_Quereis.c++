// coded by zeffy
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zeroupper") //Enable AVX
#pragma GCC target("avx","popcnt")  //Enable AVX
#include <x86intrin.h> //SSE Extensions
#include <bits/stdc++.h> 
using namespace std;
#define eb emplace_back
#define mp make_pair
#define hello cout<<"hello"<<"\n"
#define forr(i,a,b) for(int i=a;i<b;i++)
#define it(s)	for(auto itr:s)
#define dvg(s) 	for(auto itr:s)	cout<<itr<<" ";cout<<endl;
#define dbg(s)	cout<<#s<<"= "<<s<<endl;
typedef long long int lli;
typedef unsigned long long int ulli;
const lli INF=(lli)1e17+5;
const ulli MOD=1e8+7;
 
int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(10);
    
	int n,q;
	cin>>n>>q;
	int a[n+1][n+1];
	
	memset(a,0,sizeof(a));
	
	for(int i=1;i<n+1;i++)
	{
		char ch[n];
		cin>>ch;
		for(int j=1;j<n+1;j++)
		{
			if(ch[j-1]=='*') 
			{
				a[i][j]=1;
			}
		}
	}
	
	
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			a[j][i]+=a[j-1][i];
		}
	}
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			a[i][j]+=a[i][j-1];
		}
	}
	
 
	
	while(q--)
	{
		int y1,x1,y2,x2;
		cin>>y1>>x1>>y2>>x2;
		cout<<a[y2][x2]+a[y1-1][x1-1]-a[y1-1][x2]-a[y2][x1-1]<<"\n";
	}
			
	
		
    return 0;
}
