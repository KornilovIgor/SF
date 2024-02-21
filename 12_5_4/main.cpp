#include <iostream>
using namespace std;

bool subArraySum(int arr[], int n, int sum)
{


    // Если не нашли подмассив с заданной суммой
    cout << -1 << endl;
    return false;
}

int main()
{
    int arr1[] = {1, 4, 20, 3, 10, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int sum1 = 33;

    if (subArraySum(arr1, n1, sum1))
    {
        cout << "Подмассив найден" << endl;
    }
    else
    {
        cout << "Подмассив не найден" << endl;
    }

    int arr2[] = {1, 5, 3, 6, 5, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int sum2 = 6;

    if (subArraySum(arr2, n2, sum2))
    {
        cout << "Подмассив найден" << endl;
    }
    else
    {
        cout << "Подмассив не найден" << endl;
    }

    return 0;
}