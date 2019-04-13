/*
    read_write_numbers.c is a program that reads a file that consist of a 100 random numbers.
    We read the file, count the amount of numbers in the file and display the count to the user.
    Then we sort the numbers using a slection sort and writing the new, sorted list of numbers into 
    a new text file caled sorted_numbers.txt

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

void selection_sort(int a[], int n);
int find_largest(int a[], int n);

int main(){

    int a[MAX_LEN];
    FILE *fp;
    FILE *wfp;
    int count = 0;

    fp = fopen("numbers.txt", "r");
    wfp = fopen("sorted_numbers.txt", "w");
    if(fp == NULL){
        printf("ERROR: Cannot open file\n");
        return 1;
    }

    while(!feof(fp) && !ferror(fp)){
        // Read the next number of file
        if(fscanf(fp, "%d", &a[count]) == 1){
            count++;
        }
    }
    printf("\nThere are %d numbers in the file.\n\n", count);

    // Call selection sort function.
    selection_sort(a, count);

    printf("In ascending order: \n");
    int i;
    for(i = 0; i < count; i++){
        printf("\t%d ", a[i]);
        fprintf(wfp, "%d\n", a[i]);
    }
    printf("\n\nFile sorted_numbers.txt was written\n\n");
    fclose(fp);
    fclose(wfp);
    return 0;
}

// find the index of the largest element in the array
void selection_sort(int a[], int n){

    int largest_index = 0;
    int temp;

    // stop the function if there is only one element
    if(n  == 1){
        return;
    }

    // find the index of the largets elemenet in the array
    // by calling the find_largest function
    // of the array that's passed into the selection_sort function
    largest_index = find_largest(a, n);

    // swap the element at the last posistion in the array
    if(largest_index < n - 1){
        temp  = a[n - 1];
        a[n - 1] = a[largest_index];
        a[largest_index] = temp;
    }
    // call selection_sort function rescursively 
    // to sort the first n - 1 element in the array.
    selection_sort(a, n - 1);
}

// find the index of the largest element in the array
int find_largest(int a[], int n){

    int largest_index = 0;
    int i;

    // to find the largest element we need to compare the first
    // element in the array with the second element in the array
    // if the compared element is of smaller value, then swap them
    for(i = 1; i <  n; i++){
        // a[i] is greater than the current largest element
        // set the largest_index to i
        if(a[i] > a[largest_index]){
            largest_index = i;
        }

    }
    // largest_index holds the largest index in the elements
    return largest_index;
}