#include<iostream>
#include<map>
#include<iterator>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        map<int,int>m;
        long long int n;
        cin>>n;
        int static arr[1000000];
        for(int i=0;i<=n-1;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<=n-1;i++)
        {
            auto it=m.find(arr[i]);
            if(it==m.end())
            {
                m.insert(pair<int,int>(arr[i],1));
            }
            else
            {
                it->second+=1;
            }
        }
        int count=0;
        for(int i=0;i<=m.size();i++)
        {
            if(m[arr[i]]>=(n/2)+1)
            {
                cout<<"Yes"<<endl;
                count+=1;
                break;
            }
        }
        if(count==0)
        {
            cout<<"No"<<endl;
        }
        cout<<arr[n/2]<<endl;
    }
    return 0;
}
