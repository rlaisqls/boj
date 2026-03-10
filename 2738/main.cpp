#include <iostream>
using namespace std;

int a[101][101], b[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin>>n>>m;

  for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin>>a[i][j];
  for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin>>b[i][j];

  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) cout<<a[i][j]+b[i][j]<<" ";
    cout<<'\n';
  }

  return 0;
}
