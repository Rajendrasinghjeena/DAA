//Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int &i:arr)
            cin>>i;
        int flag=0;
        int i,j,k;
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {    
                for(k=j+1;k<n;k++)
                {
                    if(arr[i]+arr[j]==arr[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(flag)
            cout<<i+1<<", "<<j+1<<", "<<k+1<<endl;
        else
            cout<<"No sequence found."<<endl;
    }
    return 0;
}
