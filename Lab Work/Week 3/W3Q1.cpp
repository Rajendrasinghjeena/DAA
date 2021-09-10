// Insertion Sort
#include<bits/stdc++.h>
using namespace std;
int insertionSort(int arr[],int n)
{
    int comp=0;
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(arr[j]>key && j>=0)
        {
            comp++;
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }    
    return comp;
}
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
            
        int comp=insertionSort(arr,n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        cout<<"comparisons = "<<comp<<endl;
        cout<<"swaps = "<<comp+n-1<<endl;
    }
    return 0;
}
