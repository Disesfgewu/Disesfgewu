#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	int x1,x2;
	while(cin>>a>>b>>c)
	{
		d=2*a;
		e=sqrt(b*b-a*4*c);
		f=0-b;
		if ((b*b-a*4*c)<0)
		{
		    cout <<"No real root" << endl;
		    continue;
	    }
	    x1=(f+e)/d;
	    x2=(f-e)/d;
	    if (x1==x2)
	    {
	    	cout << "Two same roots x="<<x1<<endl;
			continue; 
		}
		else
		{
			if (x1>x2)
			{
			cout << "Two different roots x1=" <<x1<<" , x2="<<x2<<endl;
			continue;
		    }
			else
			{
			cout << "Two different roots x1=" <<x2<<" , x2="<<x1<<endl;
			continue;
		}   
		}
	    
	}
	return 0;
}
