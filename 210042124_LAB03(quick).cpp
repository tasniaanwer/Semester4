 #include<iostream>

using namespace std;

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(array, low, high);

        quicksort(array, low, partitionIndex - 1);
        quicksort(array, partitionIndex + 1, high);
    }
}

int main()
{

    int n;
    cin >> n;
    int inputArray[10];

    for(int i=0; i<n; i++)
    {
        cin >> inputArray[i];
    }

    quicksort(inputArray, 0, n-1);

    cout << "Quicksort: " << endl;
    for(int i=0; i<n; i++)
    {
        cout <<inputArray[i] << " ";
    }


    return 0;

}

