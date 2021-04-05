#include <bits/stdc++.h>
using namespace std;
#define eb push_back
#define mp make_pair
#define hello cout<<"hello"<<"\n"
#define forr(i,a,b) for(int i=a;i<b;i++)
#define it(s)	for(auto itr:s)
#define dvg(s) 	for(auto itr:s)	cout<<itr<<" ";cout<<endl;
#define dbg(s)	cout<<#s<<"= "<<s<<endl;
typedef long long int lli;
typedef unsigned long long int ulli;
const lli INF=(lli)1e9+5;
const ulli MOD=1e8+7;
int n,q;
 
void build(vector<lli> &v,vector<lli> &seg)
{
	for(int i=0;i<n;i++)
	{
		seg[i+n]=v[i];
	}
	
	for(int i=n-1;i>0;i--)
	{
		seg[i]=seg[i<<1]+seg[i<<1|1];
	}
	
}
 
lli query(int l,int r,vector<lli> &seg)
{
	lli s=0;
	l+=n;r+=n;
	while(l<=r)
	{
		if(l&1)		{s+=seg[l];l++;}
		if(r%2==0)	{s+=seg[r];r--;}
		l=l>>1;r=r>>1;
	}
	return s;
}
 
void update(vector<lli> &seg,int pos,lli val)
{
	pos+=n;
	seg[pos]=val;
	for(int i=pos;i>1;i=i>>1)
	{
		seg[i>>1]=seg[i]+seg[i^1];
	}
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
    
	cin>>n>>q;
	vector<lli> v(n,0);
	forr(i,0,n) cin>>v[i];
	
	vector<lli> seg(2*n,0);
	
	build(v,seg);
	while(q--)
	{
		int ch;
		cin>>ch;
		if(ch==1)
		{
			int pos;lli val;
			cin>>pos>>val;
			pos--;
			update(seg,pos,val);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			l--;r--;
			cout<<query(l,r,seg)<<"\n";
		}
	}
	
	return 0;
}
