#include <iostream>
using namespace std;
#define MAX_SIZE 100000 + 5
int num, sum, prime_list[MAX_SIZE];
int prime(int);
int main()
{
    int L;
    cin >> L;
    prime(L);
    for (int i = 0; i < num - 1; i++)
    {
        cout << prime_list[i] << endl;
    }
    cout << num - 1 << endl;
    return 0;
}
int prime(int n)
{
    bool isnprime[MAX_SIZE] = {1, 1, 0};
    for (int i = 2; sum <= n; i++)
    {
        if (!isnprime[i])
        {
            prime_list[num++] = i;
            sum += i;
            for (int j = i * i; j <= n; j += i)
            {
                isnprime[j] = true;
            }
        }
    }
    return num;
}