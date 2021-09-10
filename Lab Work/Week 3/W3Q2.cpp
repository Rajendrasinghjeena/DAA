// Selection Sort
#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n)
{
    int swap=0,comp=0;
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            comp++;
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        swap++;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"comparisons = "<<comp<<endl;
    cout<<"swaps = "<<swap<<endl;
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
        selectionSort(arr,n);
    }
    return 0;
}
