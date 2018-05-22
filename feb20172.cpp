#include<bits/stdc++.h>
using namespace std;
long long array[10000000], ar[10000000][3], mini[10000000],hash[10000000], maxx[10000000];
int main()
{
	long long n,l,r,count=0,k=0,c=0,d=0;
	cin>>n>>l>>r;
	for(long long i=0;i<n;i++)
	{
		cin>>array[i];
	}
	for(long long i=0;i<10000000;i++)
	{
		mini[i] = maxx[i] = hash[i]=0;
		for(long long j=0;j<3;j++)
		{
			ar[i][j] = 0;
		}
	}
	sort(array,array+n);
	long long j=0;
	for(long long i=0;i<n-1;i++)
	{
		mini[0] = array[i+1] - array[i] + 1;
		maxx[0] = array[i+1] + array[i] - 1;
		ar[i][j++] = mini[0];
		ar[i][j] = maxx[0];
		j=0;
	}	
	j=0;
	mini[j] = ar[0][0];
	maxx[j] = ar[0][1];
	for(long long i=1;i<n-1;i++)
	{
		for(k=0;k<=j;k++)
			hash[k]=0;
		for(k=0;k<=j;k++)
		{
			if(ar[i][0] <=mini[k])
				break;
		}
		if(k==j+1)
		{
			if(ar[i][0]<=maxx[j])
			{
				//mini[j] = ar[i][0];
				
				maxx[j] = ar[i][1];
			}
			else
			{
				j++;
				mini[j] = ar[i][0];
				maxx[j] = ar[i][1];
			}
		}
		else
		{
			if(k!=0)
			{
				if( ar[i][0] <= maxx[k-1] )
				{
					maxx[k-1] = ar[i][1];
					for(c=k;c<=j;c++)
					{ 
						if(mini[c]<=maxx[c-1])
						{
							mini[c] = mini[c-1];
							maxx[c] = max(maxx[c-1],maxx[c]);
							hash[c-1] = 1;
						}
					}
					d=0;
					for(c=0;c<=j;c++)
					{
						if(hash[c]==0)
						{
							mini[d] = mini[c];
							maxx[d] = maxx[c];
							d++;
						}
					}
					j=d-1;
				}
				else
				{
					mini[k] = ar[i][0];
					maxx[k] = ar[i][1];
					for(c=k+1;c<=j;c++)
					{ 
						if(mini[c]<=maxx[c-1])
						{
							mini[c] = mini[c-1];
							maxx[c] = max(maxx[c-1],maxx[c]);
							hash[c-1] = 1;
						}
					}
					d=0;
					for(c=0;c<=j;c++)
					{
						if(hash[c]==0)
						{
							mini[d] = mini[c];
							maxx[d] = maxx[c];
							d++;
						}
					}
					j=d-1;
				}
			}
			else
			{
				mini[k] = ar[i][0];
				maxx[k] = ar[i][1];
				for(c=k+1;c<=j;c++)
				{ 
					if(mini[c]<=maxx[c-1])
					{
						mini[c] = mini[c-1];
						maxx[c] = max(maxx[c-1],maxx[c]);
						hash[c-1] = 1;
					}
				}
				d=0;
				for(c=0;c<=j;c++)
				{
					if(hash[c]==0)
					{
						mini[d] = mini[c];
						maxx[d] = maxx[c];
						d++;
					}
				}
				j=d-1;
			}
		}
	}
	/*for(int i=0;i<n-1;i++)
	{
		for(int k=0;k<2;k++)
		{
			cout<<ar[i][k]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<=j;i++)
	{
		cout<<mini[i]<<" "<<maxx[i]<<endl;
	}*/
	for(long long i=0;i<=j;i++)
	{
		if(mini[i]>r || maxx[i]<l)
				continue;
		else if(mini[i]>=l && maxx[i]<=r)
			count = count + (maxx[i] - mini[i] + 1);
		else if(mini[i]>=l && maxx[i]>r)
			count = count + (r - mini[i] + 1);
		else if(mini[i]<l && maxx[i]>r)
			count = count + (r-l+1);
		else if(mini[i]<l && maxx[i]<=r)
			count = count + (maxx[i]-l+1);
		//count = count + (maxx[i] - mini[i] + 1);
	}
	cout<<count<<endl;
	return 0;
}