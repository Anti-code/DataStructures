/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mehmet
 *
 * Created on January 27, 2016, 12:48 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int main(int argc, char** argv) {
    int temp,i,j;
    int n=5;
    int a[]={4,2,5,3,1};
    /* advance the position through the entire array */
    /*   (could do j < n-1 because single element is also min element) */
    for (j = 0; j < n-1; j++) {
        /* find the min element in the unsorted a[j .. n-1] */
        /* assume the min is the first element */
        int mindex = j;
        /* test against elements after j to find the smallest */
        for ( i = j+1; i < n; i++) {
            /* if this element is less, then it is the new minimum */
            if (a[i] < a[mindex]) {
                /* found new minimum; remember its index */
                mindex = i;
            }
        }
        if(mindex != j) {
            temp=a[j];
            a[j]=a[mindex];
            a[mindex]=temp;
        }
    }
    for(i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return (EXIT_SUCCESS);
}

