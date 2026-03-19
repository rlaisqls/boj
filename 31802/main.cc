#include<iostream>
using namespace std;
long long p,v[100001],pre[100001];

long long f(long long x){
	long long q=x/p,r=x%p;
	if(r<0){
    q--;
    r+=p;
  }
	return q*pre[p]+pre[r];
}

int main(){
	cin>>p;
	for(int i=0;i<p;i++){
    cin>>v[i];
    pre[i+1]=pre[i]+v[i];
  }

	long long a,b;
  cin>>a>>b;

	cout<<f(b)-f(a)<<"\n";
}
