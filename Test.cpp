#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
typedef std::chrono::high_resolution_clock Clock;

void swap(unsigned long long int *a, unsigned long long int *b)
{
    unsigned long long int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(unsigned long long int *arr, unsigned long long int n)
{
    for (unsigned long long int i = 0; i < n - 1; i++)
    {
        for (unsigned long long int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
int main()
{
    auto start_time = Clock::now();
    unsigned long long int n = 1000;
    unsigned long long int arr[n];
    for (unsigned long long int i = n; i >= 1; i--)
    {
        arr[n - i] = i;
    }
    bubblesort(arr, n);
    auto end_time = Clock::now();
    std::cout << "Time difference: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << " nanoseconds" << std::endl;
    return 0;
}