#include<cstdio>

bool white[101][101];

int main() {
  int n,res=0;
  scanf("%d",&n);

  for (int i=0;i<n;i++) {
    int a,b;
    scanf("%d %d",&a,&b);
    for (int j=0;j<10;j++) {
      for (int k=0;k<10;k++) {
        if (a+j-1>100 || b+k-1>100) continue;
        if (!white[a+j-1][b+k-1]) {
          res++;
          white[a+j-1][b+k-1] = true;
        }
      }
    }
  }
  printf("%d",res);
  return 0;
}
