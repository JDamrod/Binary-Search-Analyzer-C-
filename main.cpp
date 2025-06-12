#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;


void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int BinarySearch(int tab[], int length, int s, int &comparisonCount) {
    int left = 0;
    int right = length - 1;
    comparisonCount = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        comparisonCount++;
        if (tab[mid] == s) {
            return mid;
        }

        comparisonCount++;
        if (tab[mid] < s) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


void BubbleSort(int tab[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (tab[j] > tab[j + 1]) {
                swap(tab[j], tab[j + 1]);
            }
        }
    }
}

void GenerateSortedArray(int tab[], int length) {
    for (int i = 0; i < length; i++) {
        bool unique;
        int val;
        do {
            unique = true;
            val = rand() % (length * 10) + 1;
            for (int j = 0; j < i; j++) {
                if (tab[j] == val) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
        tab[i] = val;
    }
    BubbleSort(tab, length);
}

double BinarySearchStatistics(int length, int max) {
    int tab[1000];
    int totalComparisons = 0;

    for (int i = 0; i < max; i++) {
        GenerateSortedArray(tab, length);
        int s = tab[rand() % length];
        int comparisons = 0;
        BinarySearch(tab, length, s, comparisons);
        totalComparisons += comparisons;
    }

    return (double)totalComparisons / max;
}


void TestBinarySearch() {
    ofstream file("binarysearch.dat");

    for (int size = 10; size <= 1000; size += 10) {
        double avg = BinarySearchStatistics(size, 1000);
        file << size << " " << avg << endl;
        cout << "Rozmiar: " << size << ", Srednia liczba porownan: " << avg << endl;
    }

    file.close();
}

int main() {
    srand(time(0));

    cout << "Uruchamiam test wyszukiwania binarnego..." << endl;
    TestBinarySearch();
    cout << "Zakonczono. Wyniki zapisane w binarysearch.dat" << endl;

    return 0;
}
