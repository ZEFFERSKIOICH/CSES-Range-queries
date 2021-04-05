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
vector<lli> v,seg;
#define x first
#define y second
vector<pair<lli,lli>> lazy;
 
//boolean true= multiply opeartion 
void build(int l,int r,int pos)
{
	if(l==r) {seg[pos]=v[l];return;}
	int mid=l+((r-l)>>1);
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	seg[pos]=seg[pos<<1]+seg[pos<<1|1];
}
 
void update(int l,int r,int pos,int ql,int qr,lli val,bool flag)
{
	if(lazy[pos].x!=1 || lazy[pos].y!=0)
	{
		seg[pos]=seg[pos]*lazy[pos].x;
		seg[pos]+=(r-l+1)*lazy[pos].y;
		if(l!=r)
		{
			lazy[pos<<1].x*=lazy[pos].x;lazy[pos<<1].y*=lazy[pos].x;
			lazy[pos<<1].y+=lazy[pos].y;
			lazy[pos<<1|1].x*=lazy[pos].x;lazy[pos<<1|1].y*=lazy[pos].x;
			lazy[pos<<1|1].y+=lazy[pos].y;
		}
	}
	lazy[pos].x=1;lazy[pos].y=0;
 
	if(l>qr || r<ql) return;
	if(l>=ql && r<=qr)
	{
		if(flag)	seg[pos]*=val;
		else 		seg[pos]+=(r-l+1)*val;
 
		if(l!=r)
		{
			if(flag) {lazy[pos<<1].x*=val;lazy[pos<<1].y*=val; lazy[pos<<1|1].x*=val;lazy[pos<<1|1].y*=val;}
			else 	 {lazy[pos<<1].y+=val;lazy[pos<<1|1].y+=val;}
		}
		return;
	}
 
	int mid=l+((r-l)>>1);
	update(l,mid,pos<<1,ql,qr,val,flag);
	update(mid+1,r,pos<<1|1,ql,qr,val,flag);
	seg[pos]=seg[pos<<1]+seg[pos<<1|1];
}
			
lli query(int l,int r,int pos,int ql,int qr)
{	
	if(lazy[pos].x!=1 || lazy[pos].y!=0)
	{
		seg[pos]=seg[pos]*lazy[pos].x;
		seg[pos]+=(r-l+1)*lazy[pos].y;
		if(l!=r)
		{
			lazy[pos<<1].x*=lazy[pos].x;lazy[pos<<1].y*=lazy[pos].x;
			lazy[pos<<1].y+=lazy[pos].y;
			lazy[pos<<1|1].x*=lazy[pos].x;lazy[pos<<1|1].y*=lazy[pos].x;
			lazy[pos<<1|1].y+=lazy[pos].y;
		}
	}
	lazy[pos].x=1;lazy[pos].y=0;
 
 
	if(l>qr || r<ql) return 0;
	if(l>=ql && r<=qr) return seg[pos];
	int mid=l+((r-l)>>1);
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
	seg=vector<lli> (4*n,0);
	lazy=vector<pair<lli,lli>> (4*n,{1,0});
	forr(i,0,n) cin>>v[i];
	build(0,n-1,1);
 
	while(q--)
	{
		int ch;
		cin>>ch;
		if(ch==1)
		{
			//update
			int l,r;lli val;
			cin>>l>>r>>val;
			l--;r--;
			update(0,n-1,1,l,r,val,0);
 
		}
		else if(ch==2)
		{
			//setting a value in a range
			int l,r;lli val;
			cin>>l>>r>>val;
			l--;r--;
			update(0,n-1,1,l,r,0,1);
			update(0,n-1,1,l,r,val,0);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			l--;r--;
			cout<<query(0,n-1,1,l,r)<<"\n";
		}
	}
	return 0;
}
 
