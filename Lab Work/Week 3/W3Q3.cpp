//Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not. (use sorting) (Time Complexity = O(n log n))
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        sort(arr,arr+n);
        int found=0;
        for(int i=0;i<n-1;i++)
            if(arr[i]==arr[i+1])
            {
                found=1;
                break;
            }
        if(found)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}
