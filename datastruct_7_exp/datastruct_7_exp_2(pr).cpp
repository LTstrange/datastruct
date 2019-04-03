#include<iostream>
#include<string.h>
using namespace std;

/*
 * 算法解释：
 * 我们可以知道，在我们比对字符串的时候，如果前一个是不同的，那么后面的也就不用比对了。
 *
 * 这样来看的话，当我们组建一个以第一个字符串长度为行数，第二个字符串为列数的二维数组，
 * 用来记录每个位置前面的匹配长度。例如：
 *   a b c d e f
 * b 0 1 0 0 0 0
 * c 0 0 2 0 0 0
 * d 0 0 0 3 0 0
 * e 0 0 0 0 4 0
 * c 0 0 1 0 0 0
 * d 0 0 0 2 0 0
 *
 * 所以，当前位置的数值，取决于当前和斜上角。可用这个公式表达：
 * L[i+1, j+1] = (s[i] == t[j] ? L[i,j]+1 : 0)
 */


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
	for (int i=0; i<=a.size(); i++){
	    for (int j =0; j<=b.size(); j++){
	        cout<<c[i][j]<<' ';
	    }
	    cout<<endl;
	}
	return 0;}
