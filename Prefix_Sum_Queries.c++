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
vector<lli> v,rem;
int n,q;
struct node
{
	lli sum;
	lli pref;
};
vector<node> seg;
vector<int> coll;
void combo(node & a,node &b,node &c)
{
	a.sum=b.sum+c.sum;
	a.pref=max(b.pref,max(b.sum+c.pref,b.sum+c.sum));
}
 
void build(int l,int r,int pos)
{
	if(l==r)
	{
		seg[pos].sum=v[l];
		seg[pos].pref=max(v[l],(lli)0);
		/* cout<<l+1<<" "<<r+1<<" "<<seg[pos].sum<<" "<<seg[pos].pref<<"\n"; */
		return ;
	}
	int mid=l+((r-l)>>1);
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	combo(seg[pos],seg[pos<<1],seg[pos<<1|1]);
	/* cout<<l+1<<" "<<r+1<<" "<<seg[pos].sum<<" "<<seg[pos].pref<<"\n"; */
}
 
void update(int l,int r,int pos,int qpos,lli val)
{
	if(l==r)
	{
		seg[pos].sum=val;
		seg[pos].pref=val;
		return;
	}
	int mid=l+((r-l)>>1);
	if(mid>=qpos)	update(l,mid,pos<<1,qpos,val);
	else update(mid+1,r,pos<<1|1,qpos,val);
	combo(seg[pos],seg[pos<<1],seg[pos<<1|1]);
}
 
void query(int l,int r,int pos,int ql,int qr)
{
	if(l>r) return;
	if(l>qr || r<ql) return;
	int mid=l+((r-l)>>1);
	if(l>=ql && r<=qr)
	{
		/* cout<<l+1<<" "<<r+1<<" "<<seg[pos].sum<<" "<<seg[pos].pref<<"\n"; */
		coll.eb(pos);
		return;
	}
    query(l,mid,pos<<1,ql,qr);
	query(mid+1,r,pos<<1|1,ql,qr);
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
   	
	cin>>n>>q;
	v=vector<lli> (n,0);
	seg=vector<node> (4*n,{0,0});
	forr(i,0,n) cin>>v[i];
	build(0,n-1,1);
	while(q--)
	{
		int ch;
		cin>>ch;
		if(ch==1)
		{
			int pos;lli val;
			cin>>pos>>val;pos--;
			update(0,n-1,1,pos,val);
		}
		else
		{
			lli	sum=0;lli maxi=0;
			int l,r;cin>>l>>r;l--;r--;
			query(0,n-1,1,l,r);
			bool flag=0;
			forr(i,0,coll.size())	{maxi=max(maxi,sum+seg[coll[i]].pref);sum+=seg[coll[i]].sum;}
			cout<<maxi<<"\n";
		
			coll.clear();
		}
	}
 
    
    
    
 
    return 0;
}
 
