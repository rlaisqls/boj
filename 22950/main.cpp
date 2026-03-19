#include <iostream>
#include <string>
using namespace std;

int main() {
  int n,k;
  string m;
  cin>>n>>m>>k;

  if(k==0) {cout<<"YES\n";return 0;}

  int zeros=0;
  for(int i=n-1;i>=0;i--) {
    if(m[i]=='0') zeros++;
    else break;
  }

  // M이 0이면 (모든 자릿수가 0) 항상 나누어 떨어짐
  if(zeros==n) cout<<"YES\n";
  else cout<<(zeros>=k?"YES":"NO")<<"\n";
  return 0;
}
