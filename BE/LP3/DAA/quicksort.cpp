#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high - 1];
    int i = low - 1;

    for (int j = low; j < high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high - 1]);
    return i + 1;
}

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low < high - 1)
    {
        int p = partition(arr, low, high);
        QuickSort(arr, low, p);
        QuickSort(arr, p + 1, high);
    }
}

void QuickSortR(vector<int> &arr, int low, int high, bool &firstPivotPrinted)
{
    if (low < high - 1)
    {
        int random = low + rand() % (high - low);
        
        // Print only the first random pivot
        if (!firstPivotPrinted)
        {
            cout << "First random pivot index: " << random << ", pivot value: " << arr[random] << endl;
            firstPivotPrinted = true;
        }
        
        swap(arr[random], arr[high - 1]);
        int p = partition(arr, low, high);
        QuickSortR(arr, low, p, firstPivotPrinted);
        QuickSortR(arr, p + 1, high, firstPivotPrinted);
    }
}

int main()
{
    srand(time(0)); // Seed for random number generation

    vector<int> x = {12,33,1,44,44,66,57,88};
    int low = 0;
    int high = x.size();

    cout << "Original Array: " << endl;
    for (auto i : x)
        cout << i << " ";
    cout << endl<<endl;
    
    cout << "Deterministic QuickSort:" << endl;
    QuickSort(x, low, high);
    for (auto i : x)
        cout << i << " ";
    cout << endl;

    x = {12,33,1,44,44,66,57,88}; // Reset array for randomized variant

    cout << "Randomized QuickSort:" << endl;
    bool firstPivotPrinted = false;
    QuickSortR(x, low, high, firstPivotPrinted);
    for (auto i : x)
        cout << i << " ";
    cout << endl<<endl;

    return 0;
}
