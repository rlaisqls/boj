#include<iostream>
using namespace std;

int main(){
  long long n,r=1;
  cin>>n;
  for (int i=1;i<=n;i++) r*=i;
  cout<<r;
}
