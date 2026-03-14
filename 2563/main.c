#include<unistd.h>
unsigned char g[1276];char B[128];int P,L;
char rc(){if(P>=L)L=read(0,B,128),P=0;return P<L?B[P++]:-1;}
int ri(){char c;int r=0;while((c=rc())<48||c>57);r=c-48;while((c=rc())>47&&c<58)r=r*10+c-48;return r;}
int main(){}
void __libc_start_main(){int n=ri(),s=0,a,b,i,j,x;while(n--){a=ri();b=ri();for(i=0;i<10;i++)for(j=0;j<10;j++){x=(a+i)*101+b+j;if(!(g[x>>3]&1<<(x&7)))s++,g[x>>3]|=1<<(x&7);}}
char o[8];int p=7;o[p--]=10;if(!s)o[p--]=48;while(s)o[p--]=48+s%10,s/=10;write(1,o+p+1,7-p);_Exit(0);}
