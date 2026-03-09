#include <iostream>
using namespace std;
int arr[101], buf[101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin>>n>>m;

  for (int i=1;i<n+1;i++) arr[i] = i;

  for (int i=0;i<m;i++) {
    int a, b;
    cin>>a>>b;
    for (int j=a;j<=b;j++) buf[a+b-j] = arr[j];
    for (int j=a;j<=b;j++) arr[j] = buf[j];
  }

  for (int i=1;i<n+1;i++) cout<<arr[i]<<" ";
  return 0;
}
