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
vector<int> v,seg;
bool flag=true;
int n,q,ans=0;
void init()
{
	v=vector<int> (n,0);
	seg=vector<int> (4*n,0);
}
 
void build(int l,int r,int pos)
{
	if(l==r) 
   {
      seg[pos]=v[l];
      return;
   }
 
   int mid=(l+r)>>1;
   build(l,mid,pos<<1);
   build(mid+1,r,pos<<1|1);
   seg[pos]=max(seg[pos<<1],seg[pos<<1|1]);
}
 
void query(int l,int r,int pos,int val)
{
	if(flag)	return ;
	if(seg[pos]<val) return;
 
   if(l==r)
   {
      if(seg[pos]>=val) 
      {
       ans=min(ans,l);flag=true;
       return;
      }
      else return;
   }
   
    int mid=(l+r)>>1;
 
   if(seg[pos]>=val) 
   {
      query(l,mid,pos<<1,val);
      query(mid+1,r,pos<<1|1,val);
   }
}
 
 
void update(int l,int r,int pos,int qpos,int val)
{
   if(l==r)
   {
      seg[pos]-=val;
      return;
   }
 
   int mid=(l+r)>>1;
   if(qpos>mid)
   {
      update(mid+1,r,pos<<1|1,qpos,val);
   }
   else
   {
      update(l,mid,pos<<1,qpos,val);
   }
   
   seg[pos]=max(seg[pos<<1],seg[pos<<1|1]);
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
	
	build(0,n-1,1);
 
 
	while(q--)
   {
	   flag=false;
      ans=n+1;
      int val;
      cin>>val;
      query(0,n-1,1,val);
      
      if(ans<=n)  
      {
		  cout<<ans+1<<" ";
		  update(0,n-1,1,ans,val);
	  }
      else        cout<<"0 ";
   }
 
    return 0;
}
