#include <iostream>
using namespace std;

int arr[41];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin>>n;

  arr[0]=1;
  arr[1]=1;
  for (int i=2;i<=n;i++) {
    arr[i] = arr[i-1]+arr[i-2];
  }
  cout<<arr[n-1]<<" "<<n-2;

  return 0;
}
