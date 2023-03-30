# include <iostream>
# include <ctime>
using namespace std;


void swap(int *a,int *b){ // swapping two elements
    int temp = *a;
    *a=*b;
    *b = temp;
}

int partition (int arr[], int start, int end){ // quick sort is a divide and conquer algorithm
    int x = arr[end];                      // function to divide array into parts
    int i = start - 1;
    for (int j = start; j <= end- 1; j++){
    if (arr[j] <= x){
        i++;
        swap (&arr[i], &arr[j]);
    }
    }
    swap (&arr[i + 1], &arr[end]);
    return (i + 1);
    }


void quickiterative(int arr[], int start, int end) {
    int stack[end - start + 1];  // create a stack of size equal to the array
    int top = -1;  // initialize top of stack

    // push initial values of low and high to stack
    stack[++top] = start;
    stack[++top] = end;

    // keep popping from stack until it is empty
    while (top >= 0) {
        // pop high and low
        end = stack[top--];
        start = stack[top--];

        // set pivot element at its correct position
        int pivot = partition(arr, start, end);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (pivot - 1 > start) {
            stack[++top] = start;
            stack[++top] = pivot - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (pivot + 1 < end) {
            stack[++top] = pivot + 1;
            stack[++top] = end;
        }
    }
}



int main(){
    int size;       // get the size of array as user input
    cin>>size;
    clock_t start,end;

    int arr[size];
    for(int index=0;index<size;index++){ // creating a random array
        arr[index]=rand()%10000;
    }
    start=clock();  // start the clock
    quickiterative(int arr[], 0, size-1);

    end =clock();  // end the clock

    double time =(double)(end-start)/CLOCKS_PER_SEC;
    cout<< time;
}
















    end =clock();
    double time =(double)(end-start)/CLOCKS_PER_SEC;
    cout<< time;



}