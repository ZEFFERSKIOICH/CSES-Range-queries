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
int n,q;
 
struct sub
{
	lli sum,pref,suf,ans;
};
 
vector<lli> v;
vector<sub> seg;
 
void init()
{
	v=vector<lli> (n,0);
	seg=vector<sub> (4*n);
}
 
 
 
void combinator(sub &a,sub &b,sub &c)
{
	a.sum=b.sum+c.sum;
	a.pref=max(b.pref,b.sum+c.pref);
	a.suf=max(c.suf,c.sum+b.suf);
	a.ans=max(max(b.ans,c.ans),b.suf+c.pref);
}
 
 
void build(int l=0,int r=n-1,int pos=1)
{
	if(l>r) return;
	if(l==r)
	{
		seg[pos].sum=v[l];
		seg[pos].ans=max((lli)0,v[l]);
		seg[pos].pref=v[l];
		seg[pos].suf=v[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	combinator(seg[pos],seg[pos<<1],seg[pos<<1|1]);
}
 
void update(int qpos,lli qval,int l=0,int r=n-1,int pos=1)
{
	if(l>r) return;
	if(l==r)
	{
		seg[pos].sum=qval;
		seg[pos].ans=max((lli)0,qval);
		seg[pos].pref=qval;
		seg[pos].suf=qval;
		return;
	}
	int mid=(l+r)>>1;
	if(qpos>mid)
	{
		update(qpos,qval,mid+1,r,pos<<1|1);
	}
	else
	{
		update(qpos,qval,l,mid,pos<<1);
	}
	combinator(seg[pos],seg[pos<<1],seg[pos<<1|1]);
}
 
		
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(10);
    
    cin>>n>>q;
    init();
    forr(i,0,n) cin>>v[i];
    
    build();
    
    while(q--)
    {
		int pos;lli val;
		cin>>pos>>val;
      --pos;
		update(pos,val);
		cout<<seg[1].ans<<"\n";
	}
    
	
 
    return 0;
}
