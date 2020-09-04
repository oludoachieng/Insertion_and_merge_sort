#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <ctime>


using namespace std;
//This part contains the insertion sort where array A and the size of array
//are passed from the main program then sorted and written to output.txt
void Insertion_Sort(int* A, int array_size) {

    int size_of_arr = array_size;
    // A = new int[size_of_arr];
    int val, temp;
    for (int i = 1;i < size_of_arr;i++)
    {
        val = A[i];
        temp = i;
        while (temp > 0 && A[temp - 1] > val)
        {
            A[temp] = A[temp - 1];
            temp = temp - 1;
        }
        A[temp] = val;
    }

}
// this is the merge sort function there is the recursive mergesort and
//merge function to merge left and right arrays
void Merge(int* A, int* L, int left, int* R, int right) {


    int i = 0;
    int j = 0;
    int k = 0;

    while (i < left && j < right)
    {
        if (L[i] < R[j])
            A[k++] = L[i++];

        else
            A[k++] = R[j++];
    }
    while (i < left)
        A[k++] = L[i++];
    while (j < right)
        A[k++] = R[j++];
}


void MergeSort(int* A, int n) {
    int midval, i;
    if (n < 2) return;
    midval = n / 2;
    int* L = new int[midval];
    int* R = new int[n - midval];

    for (i = 0;i < midval;i++) L[i] = A[i];
    for (i = midval;i < n;i++) R[i - midval] = A[i];

    MergeSort(L, midval);
    MergeSort(R, n - midval);
    Merge(A, L, midval, R, n - midval);
    delete[] L;
    delete[] R;
}


//merge sort algorithm
void Reverse_Sort(int* A, int array_size) {

    int size_of_arr = array_size;
    int val, temp;
    for (int i = 1;i < size_of_arr;i++)
    {
        val = A[i];
        temp = i;
        while (temp > 0 && A[temp - 1] < val)
        {
            A[temp] = A[temp - 1];
            temp = temp - 1;
        }
        A[temp] = val;
    }
}
// This is the main program
int main()
{
beginning:


    //RANDOM NUMBER GENERATOR
    int array_size=50;
    
    int high_index = array_size - 1;

    //This section randomly generates values less than 10^6
    //and writes them on the input.txt file
    srand((unsigned)time(0));
    ofstream write_text;
    write_text.open("input.txt");
    for (int m = 0;m < array_size;m++) {
        int random_no = (rand() * rand()) % 1000001;
        write_text << random_no << " ";
    }
    write_text.close();

    cout << endl << "Random array of size " << array_size << " created. " << endl << endl;

    //This part reads the values from the input.txt file and creates an
    //array that we shall sort using our sort algorithms


    int p;
    int* A;
    A = new  int[array_size];
    ifstream op_input;
    op_input.open("input.txt");
    int g = 0;
    while (op_input >> p)
    {
        A[g] = p;
        g++;
    }
    op_input.close();


    char var;
here:
    cout << "Press 1 to sort Array" << endl << endl;
    cout << "Press 2 to Reverse sort Array" << endl << endl;
    cout << "Press 3 to Randomize Array" << endl << endl;
    cout << "Press 4 to exit the program" << endl << endl;
    cin >> var;

    switch (var)
    {
    case '1':
        //pre-sorting input.txt file using insertion sort for best case
    {       cout << "Please wait, pre-sorting the input.txt file..." << endl << endl;
    MergeSort(A, array_size);
    ofstream write_out;
    write_out.open("input.txt");
    for (int r = 0;r < high_index;r++)
    {
        write_out << A[r] << " ";
    }
    write_out.close();
    break;
    }


    case '2':
    {        //Reverse sorting the input.txt file for worst case
        cout << "Please wait, reverse sorting the input.txt file..." << endl << endl;
        Reverse_Sort(A, array_size);
        ofstream write_out2;
        write_out2.open("input.txt");
        for (int h = 0;h < high_index;h++)
        {
            write_out2 << A[h] << " ";
        }
        write_out2.close();
        break;
    }

    case '3':break;
    case '4': {
        delete[] A;
        return 0;
    }
    default:
        goto here;
    }

    char number;
here2:
    cout << "Press 1 for Insertion sort" << endl << endl;
    cout << "Press 2 for Merge sort" << endl << endl;
    cout << "Press 3 to exit" << endl << endl;
    cin >> number;


    switch (number)
    {
    case '1':

    {   cout << "Insertion sort in progress..." << endl << endl;
    //Insertion sort Algorithm, clock for capturing running time.
    int start_s = clock();
    Insertion_Sort(A, array_size);
    int stop_s = clock();
    cout << "Time taken to sort : " << (stop_s - start_s) / double(CLOCKS_PER_SEC) << " seconds." << endl;
    }
    break;

    case '2':
        //Merge sort algorithm, clock for capturing running time.
    {

        cout << "Merge sort in progress..." << endl << endl;
        int start_s2 = clock();
        MergeSort(A, array_size);
        int stop_s2 = clock();
        cout << "Time taken to sort : " << (stop_s2 - start_s2) / double(CLOCKS_PER_SEC) << " seconds." << endl;
    }
    break;

    case '3':
    {
        delete[] A;
        return 0;
    }
    default:
        goto here2;
    }

    //writing the solution to output.txt file

    ofstream write_out;

    write_out.open("output.txt");

    for (int r = 0;r < high_index;r++)
    {
        write_out << A[r] << " ";

    }

    write_out.close();

    char inpt;

    cout << endl << "Press 1 to start again, or any other key then enter to exit." << endl;
    cin >> inpt;
    if (inpt == '1')
    {
        goto beginning;
    }
    else

        delete[] A;
    return 0;
}

