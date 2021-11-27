#include <iostream>
#include <fstream>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *arr, int front, int end) {
    int pivot = arr[end];
    int i = front - 1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}

void QuickSort(int *arr, int front, int end) {
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

void pathFinder(int *path, int *node, int **choose, int num, int i, int j) {
    if (i > j || j >= num || i < 0) return;
    static int count = 0;
    while (true) {
        if (choose[i][j] > choose[i][j - 1]) {
            if (i >= 0 && i < num && j >= 0 && j < num && i < j) {
                path[count++] = j;
            }
            break;
        }
        j--;
    }
    if (j >= num || j < 0) return;
    int k = node[j];
    if (k - 1 > i)
        pathFinder(path, node, choose, num, i, k - 1);
    if (k + 1 < j - 1)
        pathFinder(path, node, choose, num, k + 1, j - 1);
}

int main(int argc, char *argv[]) {
    //////////// read the input file /////////////
    fstream fin(argv[1]);
    fstream fout(argv[2]);
    fin.open(argv[1], ios::in);
    fout.open(argv[2], ios::out);

    //////////// programming assignment part /////////////
    int num;
    fin >> num;
    int *node = new int[num];
    for (int i = 0; i < num / 2; ++i) {
        int t;
        fin >> t;
        fin >> node[t];
        node[node[t]] = t;
    }
    int **table = new int *[num];
    for (int i = 0; i < num; ++i) {
        table[i] = new int[num];
    }
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            table[i][j] = 0;
        }
    }
    int *road = new int[num];
    for (int i = 0; i < num; ++i) road[i] = -1;
    for (int l = 1; l < num; ++l) {
        for (int i = 0; i < num - l; ++i) {
            int j = i + l, k = node[j];
            if (k > j || k < i) {
                table[i][j] = table[i][j - 1];
            } else if (k == i) {
                table[i][j] = table[i + 1][j - 1] + 1;
            } else {
                if (table[i][j - 1] > table[i][k - 1] + 1 + table[k + 1][j - 1]) {
                    table[i][j] = table[i][j - 1];
                } else {
                    table[i][j] = table[i][k - 1] + 1 + table[k + 1][j - 1];
                }
            }
        }
    }
    pathFinder(road, node, table, num, 0, num - 1);
    int count = 0;
    for (int i = 0; i < num; ++i) {
        if (road[i] != -1)
            count++;
        if (road[i] > node[road[i]]) {
            swap(&road[i], &node[road[i]]);
        }
    }

    QuickSort(road, 0, count - 1);
    for (int i = 0; i < count; ++i) {
        fout << road[i] << " " << node[road[i]] << endl;
    }
    fout << table[0][num - 1] << endl;
    return 0;
}
