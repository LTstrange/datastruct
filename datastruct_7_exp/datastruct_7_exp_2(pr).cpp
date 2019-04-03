#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string a,b;
	int c[100][100];
	int h=0,k=0;

	getline(cin,a);
	getline(cin,b);
	int max=-1;
	for(int i=1;i<=a.size();i++)
	{
		for(int j=1;j<=b.size();j++)
		{
			if(a[i-1]!=b[j-1])
			c[i][j]=0;
			else if(a[i-1]==b[j-1])
			c[i][j]=c[i-1][j-1]+1;
			if(max<c[i][j])
			{
				max=c[i][j];
				h=i;
				k=j;
			}}}
	if(max<1)
	cout<<"no"<<endl;
	else
	for(int p=max;p>0;p--)
	cout<<a[h-p];
	return 0;}
