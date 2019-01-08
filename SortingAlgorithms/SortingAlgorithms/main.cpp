#include <iostream>
#include <array>
#include <vector>

void selectionSort(std::array<int, 10>&numbersArray);
void bubbleSort(std::array<int, 10>&numbersArray);
void insertionSort(std::array<int, 10>&numbersArray);
void mergeSort(std::array<int, 10>&numbersArray, int l, int r);
void quickSort(std::array<int, 10>&numbersArray, int low, int high);

void merge(std::array<int, 10>&numbersArray, int l, int m, int r);
int partitionQS(std::array<int, 10>&numbersArray, int low, int high);

int main(int argc, char* argv[])
{
    std::array<int, 10>numbersArray1 = { 8, 9, 4, 6, 5, 7, 1, 0, 3, 2 };
    std::array<int, 10>numbersArray2 = { 2, 8, 9, 4, 6, 5, 7, 1, 0, 3 };
    std::array<int, 10>numbersArray3 = { 3, 2, 8, 9, 4, 6, 5, 7, 1, 0 };
    std::array<int, 10>numbersArray4 = { 0, 3, 2, 8, 9, 4, 6, 5, 7, 1 };
    std::array<int, 10>numbersArray5 = { 1, 0, 3, 2, 8, 9, 4, 6, 5, 7 };

    std::cout << "Array before being sorted:\t";
    for (int i = 0; i < static_cast<int>(numbersArray1.size()); ++i)
    {
        std::cout << numbersArray1[i] << " ";
    }
    std::cout << std::endl << std::endl;

    selectionSort(numbersArray1);

    std::cout << "SelectionSort:\t\t\t";
    for (int i = 0; i < static_cast<int>(numbersArray1.size()); ++i)
    {
        std::cout << numbersArray1[i] << " ";
    }
    std::cout << std::endl << std::endl << std::endl << std::endl;

    /* ----------------------------------------------------------- */

    std::cout << "Array before being sorted:\t";
    for (int j = 0; j < static_cast<int>(numbersArray2.size()); ++j)
    {
        std::cout << numbersArray2[j] << " ";
    }
    std::cout << std::endl << std::endl;

    bubbleSort(numbersArray2);

    std::cout << "BubbleSort:\t\t\t";
    for (int j = 0; j < static_cast<int>(numbersArray2.size()); ++j)
    {
        std::cout << numbersArray2[j] << " ";
    }
    std::cout << std::endl << std::endl << std::endl << std::endl;

    /* ----------------------------------------------------------- */

    std::cout << "Array before being sorted:\t";
    for (int k = 0; k < static_cast<int>(numbersArray3.size()); ++k)
    {
        std::cout << numbersArray3[k] << " ";
    }
    std::cout << std::endl << std::endl;

    insertionSort(numbersArray3);

    std::cout << "InsertionSort:\t\t\t";
    for (int k = 0; k < static_cast<int>(numbersArray3.size()); ++k)
    {
        std::cout << numbersArray3[k] << " ";
    }
    std::cout << std::endl << std::endl << std::endl << std::endl;

    /* ----------------------------------------------------------- */

    std::cout << "Array before being sorted:\t";
    for (int l = 0; l < static_cast<int>(numbersArray4.size()); ++l)
    {
        std::cout << numbersArray4[l] << " ";
    }
    std::cout << std::endl << std::endl;

    mergeSort(numbersArray4, 0, numbersArray1.size() - 1);

    std::cout << "MergeSort:\t\t\t";
    for (int l = 0; l < static_cast<int>(numbersArray4.size()); ++l)
    {
        std::cout << numbersArray4[l] << " ";
    }
    std::cout << std::endl << std::endl << std::endl << std::endl;

    /* ----------------------------------------------------------- */

    std::cout << "Array before being sorted:\t";
    for (int m = 0; m < static_cast<int>(numbersArray5.size()); ++m)
    {
        std::cout << numbersArray5[m] << " ";
    }
    std::cout << std::endl << std::endl;

    quickSort(numbersArray5, 0, numbersArray1.size() - 1);

    std::cout << "QuickSort:\t\t\t";
    for (int m = 0; m < static_cast<int>(numbersArray5.size()); ++m)
    {
        std::cout << numbersArray5[m] << " ";
    }
    std::cout << std::endl << std::endl << std::endl << std::endl;

    std::cin.get();

    return 0;
}

void selectionSort(std::array<int, 10>&numbersArray)
{
    int n = numbersArray.size();
    int temp = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (numbersArray[j] < numbersArray[minIdx])
            {
                minIdx = j;
            }
        }

        temp = numbersArray[i];
        numbersArray[i] = numbersArray[minIdx];
        numbersArray[minIdx] = temp;
    }
}
void bubbleSort(std::array<int, 10>&numbersArray)
{
    int temp = 0;
    for (int i = 0; i < static_cast<int>(numbersArray.size() - 1); ++i)
    {
        for (int j = 0; j < static_cast<int>(numbersArray.size() - i - 1); ++j)
        {
            if (numbersArray[j] > numbersArray[j + 1])
            {
                temp = numbersArray[j];
                numbersArray[j] = numbersArray[j + 1];
                numbersArray[j + 1] = temp;
            }
        }
    }
}
void insertionSort(std::array<int, 10>&numbersArray)
{
    int j = 0;
    int key = 0;

    for (int i = 1; i < static_cast<int>(numbersArray.size()); ++i)
    {
        key = numbersArray[i];
        j = i - 1;

        while (j >= 0 && numbersArray[j] > key)
        {
            numbersArray[j + 1] = numbersArray[j];
            j = j - 1;
        }
        numbersArray[j + 1] = key;
    }
}
void mergeSort(std::array<int, 10>&numbersArray, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(numbersArray, l, m);
        mergeSort(numbersArray, m + 1, r);
        merge(numbersArray, l, m, r);
    }
}
void quickSort(std::array<int, 10>&numbersArray, int low, int high)
{
    if (low < high)
    {
        int pi = partitionQS(numbersArray, low, high);

        quickSort(numbersArray, low, pi - 1);
        quickSort(numbersArray, pi + 1, high);
    }
}

void merge(std::array<int, 10>&numbersArray, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (i = 0; i < n1; ++i)
        L[i] = numbersArray[l + i];
    for (j = 0; j < n2; ++j)
        R[j] = numbersArray[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            numbersArray[k] = L[i];
            ++i;
        }
        else
        {
            numbersArray[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        numbersArray[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        numbersArray[k] = R[j];
        ++j;
        ++k;
    }
}
int partitionQS(std::array<int, 10>&numbersArray, int low, int high)
{
    int pivot = numbersArray[high];
    int i = (low - 1);
    int temp = 0;

    for (int j = low; j <= high - 1; ++j)
    {
        if (numbersArray[j] <= pivot)
        {
            ++i;
            temp = numbersArray[i];
            numbersArray[i] = numbersArray[j];
            numbersArray[j] = temp;
        }
    }
    temp = numbersArray[i + 1];
    numbersArray[i + 1] = numbersArray[high];
    numbersArray[high] = temp;

    return (i + 1);
}