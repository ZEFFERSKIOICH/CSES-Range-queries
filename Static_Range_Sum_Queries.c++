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
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
    
	int n,q;
	cin>>n>>q;
	vector<lli> v(n+1,0);
	forr(i,1,n+1) cin>>v[i];
	
	forr(i,1,n+1)
	{
		v[i]+=v[i-1];
	}
	
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		cout<<v[b]-v[a-1]<<"\n";
	}
	
	return 0;
}
