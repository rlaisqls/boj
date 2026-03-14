#include <iostream>
#include <string>
using namespace std;

void solve() {
  string a, b;
  cin>>a>>b;

  int d120=0, d021=0;
  for (int i=0;i<a.length();i++) {
    if (a[i]!=b[i]) {
      if (a[i]=='1') d120++;
      else d021++;
    }
  }
  cout<<max(d120, d021)<<'\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin>>T;
  while (T--) solve();
}
