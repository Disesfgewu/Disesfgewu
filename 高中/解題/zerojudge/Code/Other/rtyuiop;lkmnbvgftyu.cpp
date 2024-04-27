#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct _node{
  int x;
  int y;
  double r;
  int h;        
} Node;
bool compare (Node a,Node b){
   return a.r < b.r; 
}
Node tree[100001];
int L[100001];
int R[100001];
int main (){
  int n,x,y,h,max;
  while (scanf("%d",&n) != EOF){
  	max=0;
  	for(int i=0;i<n;i++){
  	  scanf("%d %d %d",&x,&y,&h);
	  tree[i].x=x;
	  tree[i].y=y;
	  tree[i].h=h;
	  tree[i].r=sqrt(x*x+y*y);	
	}
    sort(tree,tree+n,compare);
    L[0]=tree[0].h;
    for(int i=1;i<n;i++){
      if(L[i-1] > tree[i-1].h) L[i]=L[i-1];
      else L[i]=tree[i-1].h;
    }
    R[n-1]=tree[n-1].h;
    for(int i=n-2;i>=0;i--){
      if(tree[i].h > R[i+1]) R[i]=R[i+1];
      else R[i]=tree[i].h;
    }
    for(int i=0;i<n-1;i++){
      if((L[i]-R[i])>max) max=L[i]-R[i];
    }
    printf("%d\n",max);
  }
}
