#include <iostream>
#include <cstdlib>
using namespace std;
void swap(int *x,int *y){
  int temp;
  temp=*x;
  *x=*y;   
  *y=temp;  
}    
int main (){
  int n,a[1000],b[1000],c[1000],nb[1000],sum[1000],bou[1000],bouk;
  while(cin >> n){
    for(int i=0;i<n;i++){
      cin >> a[i] >> b[i] >>c[i];
      sum[i]=a[i]+b[i]+c[i];
      nb[i]=i+1;    
    }
    for (int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if (sum[i] < sum[j]) {
           swap(sum+i,sum+j);
           swap(a+i,a+j);
           swap(b+i,b+j); 
           swap(c+i,c+j);
           swap(nb+i,nb+j);   
        }       
      }    
    }
    int k=1;
    bou[0]=0;
    for (int i=0;i<n-1;i++){
      if (sum[i]!=sum[i+1]){
        bou[k]=i+1;
        k++;  
      }       
    }
    bou[k]=n;
    bouk=k;
    for(int p=0;p<bouk;p++){ 
      for(int i=bou[p];i<bou[p+1];i++){
        for(int j=i+1;j<bou[p+1];j++){
          if (a[i] < a[j]) {  
           swap(a+i,a+j);
           swap(b+i,b+j); 
           swap(c+i,c+j);
           swap(nb+i,nb+j);                
          }       
        }     
      }
    }
    k=1;
    bou[0]=0;
    for (int i=0;i<n-1;i++){
      if ((sum[i]!=sum[i+1])||(a[i]!=a[i+1])){
        bou[k]=i+1;
        k++;  
      }       
    }
    bou[k]=n;
    bouk=k;
    for(int p=0;p<bouk;p++){  
      for(int i=bou[p];i<bou[p+1];i++){
        for(int j=i+1;j<bou[p+1];j++){
          if (nb[i] > nb[j]) {  
           swap(b+i,b+j); 
           swap(c+i,c+j);
           swap(nb+i,nb+j);                
          }       
        }     
      }
    }
    for(int i=0;i<5;i++){
      cout << nb[i] << " " << sum[i] <<endl;  
    }
    cout << endl;            
  }
}

