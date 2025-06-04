#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static T* Partition(T* start, T* end) {
        int pivot = start[0];
        int i = 1;
        int j = end - start - 1;
        do {
            while (start[i] < pivot) i++;
            while (start[j] > pivot) j--;
            if (i <= j) {
                swap(start[i], start[j]);
            }
        }
        while (i < j);
        swap(start[0], start[j]);
        
        cout << j << " ";
        return &start[j];
    };

public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void selectionSort(T *start, T *end){
        int length = end - start;
        int curr = 0;
        while (curr < length - 1) {
            int min = curr;
            int walker = curr + 1;
            while (walker < length) {
                if (start[walker] < start[min]) {
                    min = walker;
                }
                walker = walker + 1;
            }
            swap(start[curr], start[min]);
            // T temp = start[curr];
            // start[curr] = start[min];
            // start[min] = temp;
            printArray(start, end);
            curr = curr + 1;
        }
    };
    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
        int curr = cur_segment_total + segment_idx;
        while(curr < end - start) {
            T tmp = start[curr];
            int step = curr - segment_idx;
            while(step >= 0 && tmp < start[step]) {
                start[step + segment_idx] = start[step];
                step -= segment_idx;
            }
            start[step+segment_idx] = tmp;
            curr += segment_idx;
        }
    }

    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
        // Note: You must print out the array after sorting segments to check whether your algorithm is true.
        for (int i = 0; i < num_phases - 1; i++) {
            num_segment_list++;
        }
        for (int i = 0; i < num_phases; i++) {
            cout << *num_segment_list << " segments: ";
            int segment = 0;
            while (segment < end - start) {
                sortSegment(start, end, *num_segment_list, segment);
                segment++; 
            }
            num_segment_list--;
            printArray(start, end);
        }
    }

    static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    if (start < end){
        int * pivot = Partition(start, end);
        QuickSort(start, pivot);
        QuickSort(pivot + 1, end);
    }
}
};

int main(){

    int arr[] = {9, 2, 8, 1, 0, -2};
    Sorting<int>::selectionSort(&arr[0], &arr[6]);
    cout << endl;
    /*
    *-2, 0, 8, 1, 2, 9
    *-2, 0, 1, 8, 2, 9
    *-2, 0, 1, 2, 8, 9
    *-2, 0, 1, 2, 8, 9
    */

    int num_segment_list[] = {1, 3, 5};
    int num_phases = 3;
    int array[] = { 10, 9, 8 , 7 , 6, 5, 4, 3, 2, 1 };

    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
    cout << endl;
    // 5 segments: 5 4 3 2 1 10 9 8 7 6
    // 3 segments: 2 1 3 5 4 7 6 8 10 9
    // 1 segments: 1 2 3 4 5 6 7 8 9 10

    int new_array[] = { 3, 5, 7, 10 ,12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19};
    cout << "Index of pivots: ";
    Sorting<int>::QuickSort(&new_array[0], &new_array[20]);
    cout << "\n";
    cout << "Array after sorting: ";
    for (int i : new_array) cout << i << " ";
    }