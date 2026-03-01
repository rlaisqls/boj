#include <iostream>
using namespace std;

int arr[31];
bool dp[31][100001];

/*
  dp[0][..] = 0번 추만 사용해서 만들 수 있는 무게 를 true로 하고 아닌건 false = 0번 추 무게 딱 하나만 true
  dp[1][..] = 0번 추 + 1번 추만 사용해서 만들 수 있는 무게 를 true로 하고 아닌건 false
     - 0번 추
     - 1번 추
     - 0번 추 + 1번 추
     - 0번 추 - 1번 추
     - 1번 추 - 0번 추
  dp[2][..]
  dp[3][..]
  dp[4][..]
  dp[5][..]
  dp[6][..]
  dp[7][..]
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  int sum=0;

  cin>>n;
  for (int i=0;i<n;i++) {
    cin>>arr[i];
    sum += arr[i];
  }

  for (int i=0;i<n;i++) {
    dp[i][arr[i]+40001] = 1;
    dp[i][-arr[i]+40001] = 1;
  }

  for (int j=1;j<n;j++) {
    for (int i=-sum;i<=sum;i++) {

      if (dp[j-1][i+40001]) {
        dp[j][i+40001] = 1;
      }

      if (dp[j-1][i-arr[j]+40001]) {
        dp[j][i+40001] = 1;
      }

      if (dp[j-1][i+arr[j]+40001]) {
        dp[j][i+40001] = 1;
      }
    }
  }

  for (int j=0;j<n;j++) {
    for (int i=-sum;i<=sum;i++) {
      if (i%10==0) cout<<"|";
      if (i==0) cout<<"|";
      cout<<dp[j][i+40001];
      if (i==0) cout<<"|";
      if (i%10==0) cout<<"|";
      cout<<" ";
    }
    cout<<"\n";
  }

  cin>>m;
  for (int i=0;i<m;i++) {

    int a;
    cin>>a;

    if (dp[n-1][a+40001] || dp[n-1][-a+40001]) {
      cout<<"Y ";
    } else {
      cout<<"N ";
    }
  }
  
  return 0;
}

