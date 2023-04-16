#include <iostream>
using namespace std;

int arr[100003];
int main()
{
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n % 4 == 2 || n % 4 == 1)
    {
        cout << "NO\n";
        return 0;
    }
    else if (n % 4 == 0)
    {
        cout << "YES\n";
        for (i = 0; i < n; i++)
        {
            if (arr[i] <= n / 2)
            {
                if (arr[i] % 2)
                {
                    cout << "+";
                }
                else cout << "-";
            }
            else
            {

                if (arr[i] % 2)
                {
                    cout << "-";
                }
                else cout << "+";
            }
        }
    }
    else
    {
        cout << "YES\n";
        for (i = 0; i < n; i++)
        {
            if (arr[i] == 1 || arr[i] == 2)
            {
                cout << "+";
                continue;
            }
            else if (arr[i] == 3)
            {
                cout << "-";
                continue;
            }
            if (arr[i] <= (n - 3) / 2 + 3)
            {
                if (arr[i] % 2)
                {
                    cout << "+";
                }
                else cout << "-";
            }
            else
            {

                if (arr[i] % 2)
                {
                    cout << "-";
                }
                else cout << "+";
            }
        }
    }
    return 0;
}