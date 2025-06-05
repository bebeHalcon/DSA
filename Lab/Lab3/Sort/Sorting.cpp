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

    static void merge(T* left, T* middle, T* right){
    /*TODO*/
    //Sorting::printArray(left, right);
        int leftSize = middle - left + 1; // Length of left subarray
        int rightSize = right - middle;    // Length of right subarray

        // Create temporary arrays for left and right subarrays
        T* leftTemp = new T[leftSize];
        T* rightTemp = new T[rightSize];

        // Copy data into temporary arrays
        for (int i = 0; i < leftSize; i++)
            leftTemp[i] = left[i];
        for (int i = 0; i < rightSize; i++)
            rightTemp[i] = middle[1 + i];

        // Merge the temporary arrays back into the original array
        int i = 0, j = 0, k = 0;
        while (i < leftSize && j < rightSize) {
            if (leftTemp[i] <= rightTemp[j]) {
                left[k++] = leftTemp[i++];
            } else {
                left[k++] = rightTemp[j++];
            }
        }

        // Copy the remaining elements of leftTemp, if any
        while (i < leftSize) {
            left[k++] = leftTemp[i++];
        }

        // Copy the remaining elements of rightTemp, if any
        while (j < rightSize) {
            left[k++] = rightTemp[j++];
        }

        // Deallocate temporary arrays
        delete[] leftTemp;
        delete[] rightTemp;
        
        // Print the array after the merge
        Sorting::printArray(left, right + 1);
    }
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

    static void mergeSort(T* start, T* end){
        /*TODO*/
        if (start < end) {
            // Calculate the middle point
            T* middle = start + (end - start) / 2;

            // Recursively sort the first and second halves
            mergeSort(start, middle);
            mergeSort(middle + 1, end);

            // Merge the sorted halves
            merge(start, middle, end);
        }
    }

    static void InsertionSort(T* start, T* end) {
        // TODO
        for(T *i = start; i <= end; i++){
            T ai = *i;
            T *j = i - 1;
            while(j >= start && *j > ai){
                *(j + 1) = *j;
                j--;
            }
            *(j+1) = ai;
        }
    }

    static void TimSort(T* start, T* end, int min_size) {
        // TODO
        // You must print out the array after using insertion sort and every time calling method merge.
        int n = end - start;
        for(int i = 0; i < n; i += min_size) {
            InsertionSort(start + i, start + min(i + min_size - 1, n - 1));
        }
        cout << "Insertion Sort: ";
        printArray(start, end);
        int cnt = 0;
        for (int size = min_size; size < n; size = 2 * size) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right =min((left + 2 * size - 1), (n - 1));
                if (mid < right){
                    merge(start + left, start + mid,start + right);
                }
                cnt++;
                cout << "Merge " << cnt << ": ";
                printArray(start, end);
            }
        }
    }

    static void heapify(T* start, int size, int i)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < size && start[left] > start[largest])
            largest = left;
        if (right < size && start[right] > start[largest])
            largest = right;
            
        if (largest != i) 
        {
            swap(start[i], start[largest]);
            heapify(start, size, largest);
        }
    }

    static void heapSort(T* start, T* end){
        //TODO
        int size = end - start;
        for (int i = size/2 - 1; i >= 0; i--)
            heapify(start, size, i);
        for (int i = size - 1; i >= 0; i--) 
        {
            swap(start[0], start[i]);
            heapify(start, i, 0);
        }
        Sorting<T>::printArray(start,end);
    }
};

int main(){

    int select_arr[] = {9, 2, 8, 1, 0, -2};
    cout << "Selection Sort" << endl;
    Sorting<int>::selectionSort(&select_arr[0], &select_arr[6]);
    cout << endl;
    /*
    *-2, 0, 8, 1, 2, 9
    *-2, 0, 1, 8, 2, 9
    *-2, 0, 1, 2, 8, 9
    *-2, 0, 1, 2, 8, 9
    */

    int num_segment_list[] = {1, 3, 5};
    int num_phases = 3;
    int shell_array[] = { 10, 9, 8 , 7 , 6, 5, 4, 3, 2, 1 };

    cout << "Shell Sort" << endl;
    Sorting<int>::ShellSort(&shell_array[0], &shell_array[10], &num_segment_list[0], num_phases);
    cout << endl;

    // 5 segments: 5 4 3 2 1 10 9 8 7 6
    // 3 segments: 2 1 3 5 4 7 6 8 10 9
    // 1 segments: 1 2 3 4 5 6 7 8 9 10

    cout << "Quick Sort" << endl;
    int quick_array[] = { 3, 5, 7, 10 ,12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19};
    cout << "Index of pivots: ";
    Sorting<int>::QuickSort(&quick_array[0], &quick_array[20]);
    cout << "\n";
    cout << "Array after sorting: ";
    for (int i : quick_array) cout << i << " ";
    cout << endl << endl;

    // Index of pivots: 2 0 0 6 1 0 2 1 0 0 2 1 0 0 0 0 0 0 1 0
    // Array after sorting: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

    cout << "Merge Sort" << endl;
    int merge_arr[] = {0,2,4,3,1,4};
    Sorting<int>::mergeSort(&merge_arr[0], &merge_arr[5]);
    cout << endl;

    // 0, 2
    // 0, 2, 4
    // 1, 3
    // 1, 3, 4
    // 0, 1, 2, 3, 4, 4

    // cout << "Insertion Sort" << endl;
    int insertion_array[] = {12, 13, 14, 15, 1, 2, 9, 6, 4, 7, 10, 8, 5, 3 ,0};
    int min_size = 4;
    Sorting<int>::TimSort(&insertion_array[0], &insertion_array[15], min_size);
    cout << endl;
    // Insertion Sort: 12, 13, 14, 15, 1, 2, 6, 9, 4, 7, 8, 10, 0, 3, 5
    // 1, 2, 6, 9, 12, 13, 14, 15
    // Merge 1: 1, 2, 6, 9, 12, 13, 14, 15, 4, 7, 8, 10, 0, 3, 5
    // 0, 3, 4, 5, 7, 8, 10
    // Merge 2: 1, 2, 6, 9, 12, 13, 14, 15, 0, 3, 4, 5, 7, 8, 10
    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15
    // Merge 3: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15

    cout << "Heap Sort\n";
    int arr[4]={-1,0,2,3};
    Sorting<int>::heapSort(&arr[0],&arr[4]);
}