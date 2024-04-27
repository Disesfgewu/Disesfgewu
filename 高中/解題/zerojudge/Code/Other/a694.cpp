#include<stdio.h>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int fullness[n][n],cord[4];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&fullness[i][j]);
        for(int h=0;h<m;h++)
        {
            int sum=0;
            for(int i=0;i<4;i++)
                scanf("%d ",&cord[i]);
            for(int i=cord[0]-1;i<cord[2];i++)
                for(int j=cord[1]-1;j<cord[3];j++)
                    sum+=fullness[i][j];
            printf("%d\n",sum);
        }
    }
    return 0;
}
