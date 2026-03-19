#include <iostream>
using namespace std;

int main() {
  int n,k;
  cin>>n>>k;
  int a[101];
  for(int i=0;i<n;i++) cin>>a[i];

  int sum=0;
  for(int i=0;i<k;i++) sum+=a[i];
  int mx=sum;
  for(int i=k;i<n;i++) {
    sum+=a[i]-a[i-k];
    if(sum>mx) mx=sum;
  }
  cout<<mx<<"\n";
  return 0;
}
