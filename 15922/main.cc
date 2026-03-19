#include<bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin>>n;

  long long ans=0;
  int cs=-2e9,ce=-2e9;

  while(n--){
    int x,y;
    cin>>x>>y;
    if(x>ce){
      ans+=ce-cs;
      cs=x;
      ce=y;
    } else ce=max(ce,y);
  }
  ans += ce-cs;
  cout<<ans;
}
