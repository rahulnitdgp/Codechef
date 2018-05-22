#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int flag=0;
		map<char,int> hash;
		for(int i=0;i<s.length();i++)
		{
			if(hash[s[i]] == 1)
			{
				flag = 1;
				break;
			}
			hash[s[i]] = 1;
		}
		if(flag==1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}