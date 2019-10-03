#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function
void swap(int *a, int *b) {
    /* your code here */
    int temp;
    temp= *b;
    *b=*a;
    *a=temp;
}

// BubbleSort function
void bubbleSort(int *a, int n) {
    /* your code here */
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            //if one value is greater than the one following it then they get sent to swap function
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                }
            }
        }
}


int main(int argc, char * argv[]) {
    //check number of arguments
    if(argc != 3){
        cout<<"Usage: ./BubbleSort <seed> <length>\n";
        exit(1);
    }


    // get input: first is random seed, second is vector length
    int seed, length;
    seed=atoi(argv[1]);
    length=atoi(argv[2]);
    srand(seed);

    vector<int> v(length); // vector to be sorted
    vector<int> t(length); // temporary workspace

    // define an integer pointer dynamically allocate an array of integers
    /* your code here */
    int * a=NULL;
    a=new int[length];


    // initialize and print input
    cout << "Unsorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // copy the random list of integers from vector to array
    /* your code here */
    for(int i=0; i<v.size();++i){
        a[i]=v.at(i);
    }

    //unit test for swap function
    int  one=1;
    int  two=2;
    int *test1=&one;
    int *test2=&two;
    cout<<"Unit Test for Swap Function: "<<endl;
    cout<<"before swap  " <<"value 1: "<<*test1<<"  value 2: "<<*test2<<endl;
    swap(*test1,*test2);
    cout<<"after swap  " <<"value 1: "<<*test1<<"  value 2: "<<*test2<<endl;
    assert(*test1 == 2 && *test2 == 1);

    clock_t start_mergeSort = clock();
    // sort vector using mergeSort
    mergeSort(v,t, 0, v.size() - 1);
    clock_t end_mergeSort = clock();

    // check output, make sure vector is sorted after mergeSort
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    clock_t start_bubbleSort = clock();
    // sort array using bubbleSort
    /* your code here */
    bubbleSort(a,length);
    clock_t end_bubbleSort = clock();

    // check output, make sure array is sorted after bubbleSort
    /* your code here */
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }


    // print sorted vector after mergeSort
    cout << "Sorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // print sorted array after bubbleSort
    /* your code here */
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // print elapsed time for mergeSort and bubbleSort
    double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;

    cout <<"Elapsed Time for Merge Sort: "<< elapsed_mergeSort << "  Elapsed Time for Bubble Sort: "<< elapsed_bubbleSort << endl;

    delete [] a;
    *a=NULL;
    return 0;
}

