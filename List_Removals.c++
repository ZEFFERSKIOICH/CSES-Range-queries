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
int n;
vector<int> v,rem,seg;
int val=0,ans=0;
 
void build(int l,int r,int pos)
{
	if(l==r){seg[pos]=1;return;}
	int mid=l+((r-l)>>1);
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	seg[pos]=seg[pos<<1]+seg[pos<<1|1];
}
 
void update(int l,int r,int pos,int qpos)
{
	if(l==r) {seg[pos]=0;return;}
	int mid=l+((r-l)>>1);
	if(mid>=qpos) update(l,mid,pos<<1,qpos);
	else update(mid+1,r,pos<<1|1,qpos);
	seg[pos]=seg[pos<<1]+seg[pos<<1|1];
}
 
void query(int l,int r,int pos)
{
	if(!(val)) return;
	if(l==r && seg[pos]) {val--;ans=l;return;}
	int mid=l+((r-l)>>1);
	if(seg[pos]>=val)	query(l,mid,pos<<1);
	else 				{val-=seg[pos];return;}
	if(val) query(mid+1,r,pos<<1|1);
}
	
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
    cin>>n;
	v=rem=vector<int> (n,0);
	seg=vector<int> (4*n,0);
 
	forr(i,0,n) cin>>v[i];
	build(0,n-1,1);
 
	forr(i,0,n)
	{
		int a;
		cin>>a;
		val=a;
		ans=-1;
		query(0,n-1,1);
		cout<<v[ans]<<" ";
		update(0,n-1,1,ans);
	}		
 
 
    return 0;
}
 
