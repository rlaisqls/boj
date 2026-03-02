#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin>>n>>m;

  for (int i=0;i<m;i++) {
    int a, b, c;
    cin>>a>>b>>c;

    for (int j = a - 1; j < b; j++) {
      arr[j] = c;
    }
  }

  for (int i=0;i<n;i++) {
    cout<<arr[i]<<' ';
  }

  return 0;
}
