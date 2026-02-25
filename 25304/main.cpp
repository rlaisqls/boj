#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m,n;
  cin>>m>>n;

  int sum=0;
  for (int i=0;i<n;i++) {
    int a,b;
    cin>>a>>b;
    sum+=a*b;
  }
  
  if (sum==m) cout<<"Yes";
  else cout<<"No";

  return 0;
}
