#include<bits/stdc++.h>
using namespace std;
long long h[1000000],m[1000000],a[1000000],b[1000000],c[1000000];
int zig(int n)
{
    int f=0,g=0;
    for(int i=0;i<n-1;i++)
    {
        if(h[i]-h[i+1]==0)
            return 0;
        else if(h[i]-h[i+1]>0){
            if(f==0)
            {
                f=1;
                g=0;
            }
            else
                return 0;
        }
        else if(h[i]-h[i+1]<0){
            if(g==0)
            {
                g=1;
                f=0;
            }
            else
                return 0;
        }
    }
    return 1;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        int f=0,k=0,g=0,g1=0,flag=1,flag1=0,flag2=0;
        long cnt=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>h[i]>>m[i];
            c[i]=0;
        }
        if(n==1)
        {
            cout<<1<<endl;
            cout<<0<<" "<<"Inf"<<endl;
            continue;
        }
        else if(n==2)
        {
            if(m[0]==m[1])
            {
                if(h[0]==h[1])
                {
                    cout<<0<<endl;
                    continue;
                }
                else
                {
                    cout<<1<<endl;
                    cout<<0<<" "<<"Inf"<<endl;
                    continue;
                }
            }
            else if(m[0]<m[1])
            {
                if(h[0]<h[1])
                {
                    cout<<1<<endl;
                    cout<<0<<" "<<"Inf"<<endl;
                    continue;
                }
                else if(h[0]>h[1])
                {
                    for(int i=0;;i++)
                    {
                        if(h[0]==h[1]){
                            f=1;
                            b[0] = i-1;}
                        else if(h[0]<h[1]){
                            if(f==1){
                                flag2=1;
                                cout<<2<<endl;
                                cout<<0<<" "<<b[0]<<endl;
                                cout<<i<<" "<<"Inf"<<endl;
                                break;
                            }
                            else
                            {
                               flag2=1;
                              cout<<1<<endl;
                              cout<<0<<" "<<"Inf"<<endl;
                              break;
                            }
                        }
                        for(int j=0;j<n;j++)
                            h[j] = h[j] + m[j];
                    }
                }
                else
                {
                    cout<<1<<endl;
                    cout<<1<<" "<<"Inf"<<endl;
                    continue;
                }
            }
            else
            {
                if(h[0]>h[1])
                {
                    cout<<1<<endl;
                    cout<<0<<" "<<"Inf"<<endl;
                    continue;
                }
                else if(h[0]<h[1])
                {
                    for(int i=0;;i++)
                    {
                        if(h[0]==h[1]){
                            f=1;
                            b[0] = i-1;}
                        else if(h[0]>h[1]){
                            if(f==1){
                                flag2=1;
                                cout<<2<<endl;
                                cout<<0<<" "<<b[0]<<endl;
                                cout<<i<<" "<<"Inf"<<endl;
                                break;
                            }
                            else
                            {
                              flag2=1;
                              cout<<1<<endl;
                              cout<<0<<" "<<"Inf"<<endl;
                              break;
                            }
                        }
                        for(int j=0;j<n;j++)
                            h[j] = h[j] + m[j];
                    }
                }
                else
                {
                    cout<<1<<endl;
                    cout<<1<<" "<<"Inf"<<endl;
                    continue;
                }
        }
        if(flag2==1)
            continue;
        }
        else{
        int i;
        for(i=1;i<n-1;i++)
        {
            if((m[i]>m[i+1])&&(m[i]>m[i-1]))
                c[i]=1;
            else if((m[i]<m[i+1])&&(m[i]<m[i-1]))
                c[i]=-1;
            else if((m[i]==m[i+1])&&(m[i]==m[i-1]))
            {
                if((h[i]>h[i+1]&&h[i]>h[i-1]))
                    c[i]=1;
                else if((h[i]<h[i+1]&&h[i]<h[i-1]))
                    c[i]=-1;
                else
                    c[i]=-2;
            }
            else if(m[i]==m[i-1]&&m[i]>m[i+1])
            {
                if(h[i]>h[i-1])
                    c[i]=1;
                else
                    c[i]=-2;
            }
            else if(m[i]==m[i-1]&&m[i]<m[i+1])
            {
                if(h[i]<h[i-1])
                    c[i]=-1;
                else
                    c[i]=-2;
            }
            else if(m[i]<m[i-1]&&m[i]==m[i+1])
            {
                if(h[i]<h[i+1])
                    c[i]=-1;
                else
                    c[i]=-2;
            }
            else if(m[i]>m[i-1]&&m[i]==m[i+1])
            {
                if(h[i]>h[i+1])
                    c[i]=1;
                else
                    c[i]=-2;
            }
            else
            {
                if(m[i]>m[i+1]&&m[i]<m[i-1])
                {
                    if(h[i]>=h[i+1]&&h[i]<=h[i-1])
                        c[i]=-2;
                    else
                        c[i]=2;
                }
                else if(m[i]<m[i+1]&&m[i]>m[i-1])
                {
                    if(h[i]<=h[i+1]&&h[i]>=h[i-1])
                        c[i]=-2;
                    else
                        c[i]=2;
                }
                else
                    c[i]=2;
            }
        }
        for(int i=1;i<n-1;i++)
        {
            if(c[i]==2)
            {
                flag=0;
                break;
            }
        }
        for(int i=1;i<n-1;i++)
        {
            if(c[i]==-2)
            {
                flag1=1;
                break;
            }
        }
        for(int i=0;;i++)
        {
            g=g1=0;
            if(flag1==1)
                break;
            if(!zig(n)){
                if(f==1){
                    cnt++;
                    b[k++] = i-1;
                    f=0;
                }
            }
            else
            {
                if(f==0){
                a[k] = i;
                f=1;}
            }
            if(flag==1)
            {
                for(int j=1;j<n-1;j++)
                {
                    if(c[j]==1)
                    {
                        if(!(h[j]>h[j+1]&&h[j]>h[j-1])){
                            g=1;
                            break;}
                    }
                    else if(c[j]==-1)
                    {
                        if(!(h[j]<h[j+1]&&h[j]<h[j-1])){
                            g=1;
                            break;}
                    }
                }
                if(g==0){
                cnt++;
                break;}
            }
            else
            {
                for(int j=1;j<n-1;j++)
                {
                    //cout<<"HEY";
                    if(c[j]==2)
                    {
                        if(m[j]>m[j-1]&&m[j]<m[j+1])
                        {
                            if(!(h[j]<=h[j+1]&&h[j]>=h[j-1]))
                            {
                                g1=1;
                                break;
                            }
                        }
                        else if(m[j]<m[j-1]&&m[j]>m[j+1])
                        {
                            if(!(h[j]>=h[j+1]&&h[j]<=h[j-1]))
                            {
                                g1=1;
                                break;
                            }
                        }
                    }
                }
                if(g1==0)
                    break;
            }
            for(int j=0;j<n;j++)
            {
                h[j] = h[j] + m[j];
            }
        }
        cout<<cnt<<endl;
        if(cnt!=0){
        if(flag==1)
        {
            for(int i=0;i<k;i++)
                cout<<a[i]<<" "<<b[i]<<endl;
            cout<<a[k]<<" "<<"Inf"<<endl;
        }
        else
        {
            for(int i=0;i<k;i++)
                cout<<a[i]<<" "<<b[i]<<endl;
        }
        }
        }
    }
    return 0;
}