// C program for insertion sort
#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
cout<<"Sorted array is: "<<endl;
   int i;
   for (i=0; i < n; i++)
     cout<<arr[i]<<endl;

}



/* Driver program to test insertion sort */
int main()
{
    int n,i;
    cout<<"Enter the no of elements you want to sort: "<<endl;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
