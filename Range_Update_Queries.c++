//coded by zeffy
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zeroupper") //Enable AVX machine compatible
#pragma GCC target("avx","popcnt")  //Enable AVX instruction set
#include <x86intrin.h> //SSE Extensions	instruction set
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
const lli INF=(lli)1e18+5;
const ulli MOD=1e9+7;
int n,q;
	
void build(vector<lli>&bit,int pos,lli val)
{
	pos++;
	while(pos<=n)
	{
		bit[pos]+=val;
		pos+=pos & (-pos);
	}
}
 
lli query(vector<lli>&bit,int pos)
{
	pos++;
	lli sum=0;
	while(pos>0)
	{
		sum+=bit[pos];
		pos-=pos & (-pos);
	}
	return sum;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
    
    cin>>n>>q;
    vector<lli> v(n,0),dif(n,0);
    forr(i,0,n) cin>>v[i];
    
    vector<lli> bit(n+1,0);
    
    dif[0]=v[0];
    forr(i,1,n)
    {
		dif[i]=v[i]-v[i-1];
	}
    
    forr(i,0,n)
    {
		build(bit,i,dif[i]);
	}
	
    while(q--)
    {
		int ch;
		cin>>ch;
		if(ch==1)
		{
			int l,r;lli val;
			cin>>l>>r>>val;
			l--;r--;
			build(bit,l,val);
			build(bit,r+1,-val);
		}
		else
		{
			int pos;
			cin>>pos;
			pos--;
			cout<<query(bit,pos)<<"\n";
		}
	}
			
  
    return 0;
}
