#include<cstdio>
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int n;scanf("%d",&n);
        int ans=0;
        while(n--){
            int cx,cy,r;scanf("%d%d%d",&cx,&cy,&r);
            long long d1=(long long)(x1-cx)*(x1-cx)+(long long)(y1-cy)*(y1-cy);
            long long d2=(long long)(x2-cx)*(x2-cx)+(long long)(y2-cy)*(y2-cy);
            long long r2=(long long)r*r;
            if((d1<r2)!=(d2<r2))ans++;
        }
        printf("%d\n",ans);
    }
}
