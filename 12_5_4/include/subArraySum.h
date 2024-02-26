#include <iostream>

bool subArraySum(const int arr[], int n, int sum)
{
    if (n < 1)
    {
        std::cout << "-1\n";
        return false;
    }

    if (arr[0] == sum)
    {
        std::cout << "0 0\n";
        return true;
    }

    for(int i = 0, j = 1, temp = arr[i]; j < n; )
    {
        if (temp < sum || i == j)
        {
            temp += arr[j];
            j++;
        }

        if (temp == sum)
        {
            std::cout << i << ' ' << j - 1 << '\n';
            return true;
        }

        if (temp > sum)
        {
            temp -= arr[i];
            i++;
        }
    }

    std::cout << -1 << std::endl;
    return false;
}