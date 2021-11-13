#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};


bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);
 
   
 
    int curWeight = 0; 
    double finalvalue = 0.0;
    vector<int>val;
    vector<int>frac;
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {

            curWeight += arr[i].weight;
            finalvalue += arr[i].value;

        }
        else {
            int remain = W - curWeight;
            finalvalue += arr[i].value
                          * ((double)remain
                             / (double)arr[i].weight);
            break;
        }
    }
 
    return finalvalue;
}

int main()
{
    int t;
    cin>>t;
    cout<<setprecision(2)<<fixed;
    while(t--){
        int n, W;
        cin>>n>>W;
        
        Item arr[n];
        //value and weight of each item
        for(int i=0;i<n;i++){
            cin>>arr[i].value>>arr[i].weight;
        }
        
        //function call
        cout<<"Maximum Weight : "<<fractionalKnapsack(W, arr, n)<<endl;
    }
    return 0;
}
