#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int dims[], int i, int j)
{
    if (j <= i + 1) {
        return 0;
    }

    int min = INT_MAX;

    for (int k = i + 1; k <= j - 1; k++)
    {
        int cost = matrixChainMultiplication(dims, i, k);
        cost += matrixChainMultiplication(dims, k, j);
        cost += dims[i] * dims[k] * dims[j];

        if (cost < min) {
            min = cost;
        }
    }
    return min;
}

int main()
{
    // Matrix `M[i]` has dimension `dims[i-1] × dims[i]` for `i = 1…n`
    // input is `10 × 30` matrix, `30 × 5` matrix, `5 × 60` matrix
    int dims[] = {  10,30,5,60 };
    int n = sizeof(dims) / sizeof(dims[0]);

    cout << "The minimum cost is " << matrixChainMultiplication(dims, 0, n - 1);

    return 0;
}
