#include <bits/stdc++.h>
using namespace std;

// Day con lon nhat
int kadane(int a[], int n)
{
    int max = INT_MIN;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += a[i];
        max = std::max(max, sum);
        if (sum < 0)
            sum = 0;
    }
    return max;
}

// Selection Sort
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
            if (a[pos] > a[j])
                pos = j;
        swap(a[i], a[pos]);
    }
}

// Bubble Sort
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

// Insertion Sort
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int pos = i - 1;
        while (pos >= 0 && x < a[pos])
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

// Merge Func
void merge(int a[], int l, int m, int r)
{
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] <= y[j])
        {
            a[l] = x[i];
            i++;
            l++;
        }
        else
        {
            a[l] = y[j];
            j++;
            l++;
        }
    }

    while (i < x.size())
    {
        a[l] = x[i];
        i++;
        l++;
    }
    while (j < y.size())
    {
        a[l] = y[j];
        j++;
        l++;
    }
}

// Merge Sort
void mergeSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

// Heapify
void heapify(int a[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if (l < n && a[max] < a[l])
        max = l;
    if (r < n && a[max] < a[r])
        max = r;
    if (max != i)
    {
        swap(a[i], a[max]);
        heapify(a, n, max);
    }
}

// Heap Sort
void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// Lomuto Partition
int partition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}

// QuickSort Lomuto
void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

// Hoare Partition
int hoarePartition(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
            swap(a[i], a[j]);
        else
            return j;
    }
}

// Hoare QuickSort
void hoareQuickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int p = hoarePartition(a, l, r);
    hoareQuickSort(a, l, p);
    hoareQuickSort(a, p + 1, r);
}

int main()
{
    int a[6] = {-2, 11, -4, 13, -5, 2};
    cout << kadane(a, 6) << "\n";
    // selectionSort(a, 6);
    // bubbleSort(a, 6);
    // insertionSort(a, 6);
    // mergeSort(a, 0, 5);
    // heapSort(a, 6);
    // quickSort(a, 0, 5);
    hoareQuickSort(a, 0, 5);

    for (auto x : a)
        cout << x << " ";

    return 0;
}
