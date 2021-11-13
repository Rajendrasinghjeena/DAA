
#include <bits/stdc++.h>
using namespace std;

bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;

    for (i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    bool part[sum / 2 + 1];

    for (i = 0; i <= sum / 2; i++) {
        part[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = sum / 2; j >= arr[i];
            j--) { 
            if (part[j - arr[i]] == 1 || j == arr[i])
                part[j] = 1;
        }
    }

    return part[sum / 2];
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        bool ans=findPartiion(arr,n);
        if(ans==true)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
    return 0;
}  
