#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

void solve() {

  int j,n;
  cin>>j>>n;

  if (j==0) {
    cout<<"0"<<endl;
    return;
  }

  for (int i=0;i<n;i++) {
    int a,b;
    cin>>a>>b;
    arr[i]=a*b;
  }
  sort(arr, arr+n);

  int res=0;
  for (int i=n-1;i>=0;i--) {
    j-=arr[i];
    res++;
    if (j<=0) break;
  }
  cout<<res<<endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin>>T;
  while (T--) {
    solve();
  }
  return 0;
}
