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
vector<int> v;
vector<vector<int>> seg;
map<int,int> npos;
 
void combo(vector<int> &a,vector<int> &b,vector<int> &c)
{
	int pb=0,pc=0;
	while(pb<b.size() && pc<c.size())
	{
		if(b[pb]<c[pc]) {a.eb(b[pb]);pb++;}
		else 			{a.eb(c[pc]);pc++;}
	}
	while(pb<b.size())	{a.eb(b[pb]);pb++;} 
	while(pc<c.size())	{a.eb(c[pc]);pc++;} 
}
 
 
void build(int l,int r,int pos)
{
	if(l==r) {seg[pos].eb(v[l]);return;}
	int mid=l+((r-l)>>1);
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	combo(seg[pos],seg[pos<<1],seg[pos<<1|1]);
}
 
int query(int l,int r,int pos,int ql,int qr)
{
	if(l>qr || r<ql) return 0;
	if(l>=ql && r<=qr)
	{
		int c=distance(upper_bound(seg[pos].begin(),seg[pos].end(),qr),seg[pos].end());
		return c;
	}
	int mid=l+((r-l)>>1);
	return query(l,mid,pos<<1,ql,qr)+query(mid+1,r,pos<<1|1,ql,qr);
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
   	
	
	cin>>n>>q;
	v=vector<int> (n,0);
	vector<int> vec(n,0);
	seg=vector<vector<int>> (4*n);
	forr(i,0,n) cin>>vec[i];
	for(int i=n-1;i>=0;i--)
	{
		if(npos[vec[i]]!=0)	{v[i]=npos[vec[i]];npos[vec[i]]=i;}
		else 				{v[i]=INT_MAX;npos[vec[i]]=i;}
	}
	build(0,n-1,1);
 
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--;r--;
		cout<<query(0,n-1,1,l,r)<<"\n";
	}
 
 
	return 0;
}
 
 
 
 
 
