#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  int b;
  cin>>n>>b;

  string res;
  while (n>0) {
    int r=n%b;
    if (r<10) res+=(char)('0'+r);
    else res+=(char)('A'+r-10);
    n/=b;
  }
  reverse(res.begin(),res.end());
  cout<<res;
  return 0;
}
