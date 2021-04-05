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
int n,q;
vector<lli> v,seg,lazy,c;
int ans=INT_MAX;
 
void build(int l,int r,int pos)
{
	if(l==r) {seg[pos]=v[l];return;}
	int mid=l+((r-l)>>1);
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	seg[pos]=seg[pos<<1]+seg[pos<<1|1];
}
 
void update(int l,int r,int pos,int ql,int qr)
{
	lli mid=l+((r-l)>>1);
	if(lazy[pos]!=0)
	{
		lli  num=(r-l+1);
		lli a=lazy[pos];
		lli d=c[pos];
		seg[pos]+=(num*(2*a+(num-1)*d))/2;
		if(l!=r)
		{
			lazy[pos<<1]+=lazy[pos];
			c[pos<<1]+=c[pos];
			lazy[pos<<1|1]+=lazy[pos]+c[pos]*(mid+1-l);
			c[pos<<1|1]+=c[pos];
		}
	}
	lazy[pos]=0;c[pos]=0;
	if(l>qr || r<ql) return;
	if(l>=ql && r<=qr)
	{
		lli a=l-ql+1;
		lli	num=r-l+1;
		seg[pos]+=(num*(2*a+(num-1)))/2;
		if(l!=r)
		{
			lazy[pos<<1]+=a;
			c[pos<<1]++;
			lazy[pos<<1|1]+=mid+1-l+a;
			c[pos<<1|1]++;
		}
		return;
	}
	update(l,mid,pos<<1,ql,qr);
	update(mid+1,r,pos<<1|1,ql,qr);
	seg[pos]=seg[pos<<1]+seg[pos<<1|1];
}
 
 
lli query(int l,int r,int pos,int ql,int qr)
{
	lli mid=l+((r-l)>>1);
	if(lazy[pos]!=0) 
	{	
		lli  num=(r-l+1);
		lli a=lazy[pos];
		lli d=c[pos];
		seg[pos]+=(num*(2*a+(num-1)*d))/2;
		if(l!=r)
		{
			lazy[pos<<1]+=lazy[pos];
			c[pos<<1]+=c[pos];
			lazy[pos<<1|1]+=lazy[pos]+c[pos]*(mid+1-l);
			c[pos<<1|1]+=c[pos];
		}
	}
	lazy[pos]=0;c[pos]=0;
 
	if(l>qr || r<ql) return 0;
	if(l>=ql && r<=qr) return seg[pos];
	return query(l,mid,pos<<1,ql,qr) + query(mid+1,r,pos<<1|1,ql,qr);
}
 
	
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
    
	cin>>n>>q;
	v=vector<lli> (n,0);
	c=lazy=seg=vector<lli> (4*n,0);
	forr(i,0,n) cin>>v[i];
	build(0,n-1,1);
 
	while(q--)
	{
		int ch;
		cin>>ch;
		if(ch==1)
		{
			//update
			int l,r;
			cin>>l>>r;
			l--;r--;
			update(0,n-1,1,l,r);
		}
		else
		{
			//query
			int l,r;
			cin>>l>>r;
			l--;r--;
			cout<<query(0,n-1,1,l,r)<<"\n";
		}
	}
	return 0;
}
 
