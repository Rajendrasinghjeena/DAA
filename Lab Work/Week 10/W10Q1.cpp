#include <bits/stdc++.h>
using namespace std;
 
void printMaxActivities(int s[], int f[], int n)
{
    
    int i, j;
    vector<int>ans;
    
 
    i = 0;
    ans.push_back(i+1);
    int count=1;
 
    for (j = 1; j < n; j++)
    {
      if (s[j] >= f[i])
      {
          count+=1;
          ans.push_back(j+1);
          i = j;
      }
    }
    cout <<"No. of non-conflicting activities: "<<count <<endl;
    cout <<"Following activities are selected : ";
    for(int i=0;i<=ans.size()-1;i++)
    {
        cout<<ans[i]<<" ";
    }

}
int main()
{
    int n ;
    cin>>n;
    
    int s[n] ;
    for(int i=0;i<=n-1;i++)
    {
        cin>>s[i];
    }
    int f[n] ;
    for(int i=0;i<=n-1;i++)
    {
        cin>>f[i];
    }
    
    printMaxActivities(s, f, n);
    return 0;
}
