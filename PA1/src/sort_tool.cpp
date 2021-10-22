// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int> &data) {
    for (int i = 1; i < data.size(); ++i) {
        for (int j = i; j > 0; --j) {
            if (data[j] < data[j - 1]) {
                int temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
            } else
                break;
        }
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int> &data) {
    QuickSortSubVector(data, 0, data.size());
}

// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int> &data, int low, int high) {
    if (low < high) {
        int q = Partition(data, low, high);
        QuickSortSubVector(data, low, q - 1);
        QuickSortSubVector(data, q + 1, high);
    }
}

int SortTool::Partition(vector<int> &data, int low, int high) {
    int x = data[high];
    int i = low - 1;
    for (int j = low; j < high - 1; ++j) {
        if (data[j] <= x) {
            i++;
            int temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
    }
    int temp = data[i + 1];
    data[i + 1] = data[high];
    data[high] = temp;
    return i + 1;
}

// Merge sort method
void SortTool::MergeSort(vector<int> &data) {
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int> &data, int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;
        MergeSortSubVector(data, low, middle);
        MergeSortSubVector(data, middle + 1, high);
        Merge(data, low, middle, middle + 1, high);
    }
}

// Merge
void SortTool::Merge(vector<int> &data, int low, int middle1, int middle2, int high) {
//    vector<int> left(data.begin() + low, data.begin() + middle1), right(data.begin() + middle2, data.begin() + high);
    vector<int> left, right;
    for (int i = low; i <= middle1; ++i) {
        left.push_back(data[i]);
    }
    for (int i = middle2; i <= high; ++i) {
        right.push_back(data[i]);
    }
    left.push_back(2147483647);
    right.push_back(2147483647);
    int indexLeft = 0, indexRight = 0;
    for (int i = low; i <= high; ++i) {
        if (left[indexLeft] < right[indexRight])
            data[i] = left[indexLeft++];
        else
            data[i] = right[indexRight++];
    }
}

// Heap sort method
void SortTool::HeapSort(vector<int> &data) {
    BuildMaxHeap(data);
    for (int i = heapSize - 1; i >= 0; i--) {
        swap(data[0], data[i]);
        heapSize--;
        MaxHeapify(data, 0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int> &data, int root) {
    int left = 2 * root + 1, right = 2 * root + 2, largest = root;
    if (right >= heapSize && left < heapSize && data[left] > data[root]) {
        swap(data[left], data[root]);
        MaxHeapify(data, left);
    }
    if (right < heapSize) {
        if (data[left] > data[right]) {
            if (data[left] > data[root]) {
                swap(data[left], data[root]);
                MaxHeapify(data, left);
            }
        } else {
            if (data[right] > data[root]) {
                swap(data[right], data[root]);
                MaxHeapify(data, right);
            }
        }
    }
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int> &data) {
    heapSize = data.size();
    for (int i = heapSize / 2; i >= 0; --i)
        MaxHeapify(data, i);
}
