#include<bits/stdc++.h>
using namespace std;

int minComputation(int size, int files[])
{
    
    priority_queue<int, vector<int>,
        greater<int>> pq;

    for(int i = 0; i < size; i++)
    {
        
        pq.push(files[i]);
    }
    
    int count = 0;

    while(pq.size() > 1)
    {
        int first_smallest = pq.top();
        pq.pop();
        int second_smallest = pq.top();
        pq.pop();
        
        int temp = first_smallest + second_smallest;

        count += temp;

        pq.push(temp);
    }
    return count;
}

int main()
{
    
    int n = 10;
    
    int files[] = {10, 5, 100, 50, 20, 15, 5, 20, 100, 10};
    
    cout << "Minimum Computations = "
        << minComputation(n, files);

    return 0;
}
