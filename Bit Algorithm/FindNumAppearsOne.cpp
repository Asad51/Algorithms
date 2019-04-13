#include <cstdio>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 1, 2};
    int n = 0;
    for (int i = 0; i < 5; i++)
        n ^= arr[i];
    printf("%d\n", n);
    return 0;
}
