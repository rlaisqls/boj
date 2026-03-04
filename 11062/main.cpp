#include <iostream>
#include <cstring>
using namespace std;

int arr[1001];
int dp[1001][1001];
int sum[1002];

int solve() {
  int n;
  cin>>n;
  for (int i=0;i<n;i++) cin>>arr[i];

  for (int i=0;i<n;i++) sum[i+1]=sum[i]+arr[i];
  for (int i=0;i<n;i++) dp[i][i]=arr[i];

  for (int len=2;len<=n;len++) {
    for (int i=0;i+len-1<n;i++) {
      int j=i+len-1;
      int sum=sum[j+1]-sum[i];
      dp[i][j]=max(sum-dp[i+1][j], sum-dp[i][j-1]);
    }
  }
  return dp[0][n-1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin>>T;
  while (T--) cout<<solve()<<"\n";

  return 0;
}
