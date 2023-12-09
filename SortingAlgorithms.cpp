#include <iostream>

using namespace std;

// Function to display the elements of an array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Swapping Function
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int inputKey(){
     cout<<"Please input the value you want to search for: "<<endl;
            int key;
            cin>>key;

    return key;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int size) {
    int temp;
    int change = 0;

    for (int i = 0; i < size - 1; ++i) {
        change = 0;  
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] < arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                change = 1;  
            }
        }

        if (change == 0) {
            
            break;
        }
    }
}


// Function to perform Selection Sort
void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    swap(&array[min_idx], &array[step]);
  }
}

//Function to search for given input in DB
void linearSearch(int array[], int size, int key) {
    for(int i=0; i<size; i++){
        if(array[i] == key){
            cout<<key << " was found at index "<< i << " in the array";
            return;
        }
    }

    cout<< key << " was not found!";
}

//Function to search for given input with Binary Search

void binarySearch(int array[], int size, int key) {
    int low = 0, high = size - 1;
    while(low<=high){
        int mid = low + (high - low) / 2;

        if(array[mid] == key){
            cout<<key<<" was found at index "<<mid<<" in the array";
            return;
        }

        if (array[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
    }

    cout<< key << " was not found in array";
}


// Function to perform Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

       
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

// Function to perform Insertion Sort with Binary Search
void insertionSortWithBinarySearch(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int low = 0, high = i - 1;

        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Shift elements to make space for the key
        for (int j = i - 1; j >= low; --j) {
            arr[j + 1] = arr[j];
        }

        // Insert the key at its correct position
        arr[low] = key;
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int choice;

    do {
        cout << "\nSorting Menu:" << endl;
        cout << "1. Insertion Sort" << endl;
        cout << "2. Insertion Sort with Binary Search" << endl;
        cout << "3. Bubble Sort" << endl;
        cout << "4. Selection Sort" << endl;
        cout << "5. Linear Search" << endl;
        cout << "6. Binary Search" << endl;
        cout << "7. End Program" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            

            case 1:
                insertionSort(arr, n);
                cout << "Sorted array using Insertion Sort: ";
                displayArray(arr, n);
                break;

            case 2:
                insertionSortWithBinarySearch(arr, n);
                cout << "Sorted array using Insertion Sort with Binary Search: ";
                displayArray(arr, n);
                break;
            case 3:
                bubbleSort(arr, n);
                cout << "Sorted array using Bubble Sort: ";
                displayArray(arr, n);
                break;

            case 4:
                selectionSort(arr, n);
                cout << "Sorted array using Bubble Sort: ";
                displayArray(arr, n);
                break;

            case 5:
                linearSearch(arr, n, inputKey());
                break;
            case 6:
                binarySearch(arr, n, inputKey());
                break;
            case 7:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
