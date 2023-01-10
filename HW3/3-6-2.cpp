#include <stdio.h>

int arr[700][700];

int main()
{
    int M, N;
    scanf("%d", &M);
    scanf("%d", &N);
    for(int i = 0; i < M; i++)
    {
        arr[i][0] = 1;
    }
    for(int i = 0; i < N; i++)
    {
        arr[0][i] = 1;
    }
    for(int i = 1 ; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 100000007;
        }
    }
    printf("%d", arr[M - 1][N - 1]);
    return 0;
}
