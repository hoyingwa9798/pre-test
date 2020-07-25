#include <iostream> 
#include <string> 
#include <bits/stdc++.h>

  
using namespace std;

int binarySearch(char arr[],int l, int r, char x ){
    while (l <= r) { 
        int m = l + (r - l) / 2; 

        if (arr[m] == x) 
            return m; 
  

        if (arr[m] < x) 
            l = m + 1; 
  

        else
            r = m - 1; 
    } 
  
    return -1;
}

bool isSubset(char array1[],char array2[]){
    int check = 0;
    for (int j = 0;j<sizeof(array2);j++){
        // For every elements in array2, using binary search to search the same element in array1
        int result = binarySearch(array1,0,sizeof(array2)-1,array2[j]);

        if (result != -1){check++;}
    }
    //If array2 is the subset of array1, then all element in array2 should be found in array1. Then check == size of array2
    if (check == sizeof(array2)){return true;}
    else {return false;}
    
}

void merge(char arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    char L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    
    i = 0;  
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(char arr[], int l, int r) 
{ 
    if (l < r) { 
      
        int m = l + (r - l) / 2; 
  
       
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
int main() 

{   
    char array1[] = {'B','C','E','D','A'};
    char array2[] = {'A','Z','C','D'};

    int arr_size = sizeof(array1) ;
    // I want to do the mergeSort to sure that the elements in the array in their right index
    mergeSort(array1, 0, arr_size - 1);

    
    if (isSubset(array1,array2)){cout << "array2 is the subset of array1. ";}
    else {cout << "array2 is not the subset of array1.";}


    return 0; 
} 