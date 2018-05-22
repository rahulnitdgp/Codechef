#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int array[n],array1[n],array2[n];
		int count=0,count1=0;
		cin>>n;
		int j=0,k=0;
		for(int i=0;i<n;i++)
		{
			cin>>array[i];
			if(array[i]==0)
			{
				count1++;
				array1[j++]=i;
				count+=1000;
			}
			else
				array2[k++]=i;
		}
			int count2 = n-count1;
			j=k=0;
			for(int i=0;i<n;i++)
			{
				if(count2>0)
				{
					if(array[i]==0)
						count+=100;
					array[i] = 1;
					array[array2[k++]] = 0;
					count2--;		
				}
				else
				{
					array[i] = 0;
					count+=100;
				}
			}
		cout<<count<<endl;
	}
	return 0;
}