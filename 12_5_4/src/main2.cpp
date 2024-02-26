#include <iostream>

using namespace std;

bool subArraySum(int arr[], int n, int sum)
{
    if (n == 0)
        return false;

    int s = arr[0];
    int i = 0;
    int j = 0;

    while (i < n) {
        if (s < sum) 
            s += arr[++i];
        if (s > sum) {
            s -= arr[j++];            
            if (j > i && i<n)                 
                s += arr[++i];            
        }

        if (s == sum) {
            cout << j << " " << i << std::endl;
            return true;
        }
    }

    std::cout << -1 << std::endl;
    return false;
}

int main()
{
    int arr1[] = {2,1,1,0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int sum1 = 0;

    if (subArraySum(arr1, n1, sum1))
    {
        std::cout << "Подмассив найден" << std::endl;
    }
    else
    {
        std::cout << "Подмассив не найден" << std::endl;
    }

    int arr2[] = {1, 5, 3, 6, 5, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int sum2 = 9;

    if (subArraySum(arr2, n2, sum2))
    {
        std::cout << "Подмассив найден" << std::endl;
    }
    else
    {
        std::cout << "Подмассив не найден" << std::endl;
    }

    int arr3[] = {0, 89, 0, 1, 90};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int sum3 = 90;

    if (subArraySum(arr3, n3, sum3))
    {
        std::cout << "Подмассив найден" << std::endl;
    }
    else
    {
        std::cout << "Подмассив не найден" << std::endl;
    }

    return 0;
}