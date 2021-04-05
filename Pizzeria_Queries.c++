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
const ulli MOD=1e9+7;
vector<int> v;
vector<int> segl,segr;
int n,q;
 
void build()
{
	for(int i=0;i<n;i++)
	{
		segl[i+n]=v[i]-i-1;
		segr[i+n]=v[i]+i+1;
	}
	for(int i=n-1;i>0;i--)
	{
		segl[i]=min(segl[i<<1],segl[i<<1|1]);
		segr[i]=min(segr[i<<1],segr[i<<1|1]);
	}
}
 
 
void update(int pos,int val)
{
	segl[pos+n]=val-pos-1;segr[pos+n]=val+pos+1;
	pos+=n;
	for(int i=pos;i>1;i=i>>1)
	{
		segl[i>>1]=min(segl[i],segl[i^1]);
		segr[i>>1]=min(segr[i],segr[i^1]);
	}
}
 
int ql(int l,int r)	
{
	l+=n;r+=n;
	int mini=INT_MAX;
	while(l<=r)
	{
		if(l&1) mini=min(mini,segl[l++]);
		if(!(r&1))mini=min(mini,segl[r--]);
		l=l>>1;r=r>>1;
	}
	return mini;
}
 
 
int qr(int l,int r)	
{
	l+=n;r+=n;
	int mini=INT_MAX;
	while(l<=r)
	{
		if(l&1) mini=min(mini,segr[l++]);
		if(!(r&1))mini=min(mini,segr[r--]);
		l=l>>1;r=r>>1;
	}
	return mini;
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
   	
	cin>>n>>q;
	v=vector<int> (n+1,0);
	forr(i,0,n) cin>>v[i];
	segl=segr=vector<int> (2*n,INT_MAX);
	build();
	while(q--)
	{
		int ch;
		cin>>ch;
		if(ch==1)
		{
			int pos,val;
			cin>>pos>>val;
			pos--;
			update(pos,val);
		}
		else
		{
			int pos;
			cin>>pos;pos--;
			cout<<min(ql(0,pos)+pos+1,qr(pos,n-1)-pos-1)<<"\n";
		}
	}
 
    return 0;
}
 
 
