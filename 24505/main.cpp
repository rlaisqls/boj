#include <iostream>
using namespace std;

const int MOD=1000000007;
int n;
long long bit[12][100001];

void update(int k, int i, long long v) {
  for (;i<=n;i+=i&(-i)) bit[k][i]=(bit[k][i]+v)%MOD;
}

long long query(int k, int i) {
  long long s = 0;
  for (;i>0;i-=i&(-i)) s=(s+bit[k][i])%MOD;
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>n;
  for (int i=0;i<n;i++) {
    int a;
    cin>>a;
    for (int k=11;k>=2;k--) {
      long long cnt=query(k-1,a-1);
      if (cnt>0) update(k,a,cnt);
    }
    update(1,a,1);
  }

  cout<<query(11,n)<<"\n";
  return 0;
}
