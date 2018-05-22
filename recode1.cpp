#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100000],even=0,odd=0;
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=0;i<100000;i++)
		a[i]=0;
	int j=0;
	for(int i=0;i<s.length();i++)
	{
		a[j]++;
		if(i>=s.length() - 1)
			break;
		if(s[i]!=s[i+1])
			j++;
	}
	for(int i=0;i<=j;i++)
	{
	//	cout<<a[i]<<endl;
		if(a[i]%2==0)
			even++;
		else
			odd++;
	}
	//cout<<even<<" "<<odd;
	if(odd==0 || odd==1)
		cout<<"YES";
	else
		cout<<"NO";
return 0;
}