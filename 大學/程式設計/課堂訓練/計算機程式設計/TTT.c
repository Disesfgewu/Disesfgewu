#include<stdio.h>

#include<string.h>

#define N 1020

char map[40]="0123456789abcdefghijklmnopqrstuvwxyz";

int main()

{

	int m,n,i,j,sum,len,point,answer;

	char ans[N],str[N];

	int a[N];

	while(scanf("%d%d",&m,&n)!=EOF)

	{

		memset(ans,0,sizeof(ans));

		memset(a,0,sizeof(a));

		scanf("%s",str);

		len=strlen(str);

		if(len==1&&str[0]=='0')

		{		

			printf("0\n");

			continue;

		}

		for(i=0;str[i]!='\0';i++)

		{

			if(str[i]>='A'&&str[i]<='Z')

				a[i]=str[i]-'A'+10;

			else a[i]=str[i]-'0';

		}

		j=0;

		while(1)

		{

			answer=0;

			for(i=0;i<len;i++)

				if(a[i]!=0)

				{
					answer=1;
					break;

				}

				if(answer==0)

					break;

				sum=0;

				for(i=0;i<len;i++)

				{		

					sum=sum*m+a[i];

					sum=sum%n;

				}

				ans[j++]=map[sum];

				point=0;

				for(i=0;i<len;i++)

				{

					a[i]+=point*m;
	
					point=a[i]%n;

					a[i]/=n;

				}

			}

			for(j--;j>=0;j--)

				printf("%c",ans[j]);

			printf("\n");

		}

	return 0;

}
