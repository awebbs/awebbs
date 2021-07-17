/**
 *  @author Aaron S. Crandall <crandall@gonzaga.edu>
 *  @copyright 2021
 */

#ifndef __INSTRUMENTED_QUICK_SORT_H
#define __INSTRUMENTED_QUICK_SORT_H

#include "instrumentedSort.h"

class QuickSort: public InstrumentedSort
{

public:
    QuickSort() {
        name = "Quick Sort";
    }

    /**
     *  Place to implement the sorting algorithm
     */
    void doSort(std::vector<int> & vec) override
    {

        // MA TODO: implement quicksort here
        // Don't forget to increment compares and moves when you do them
        quickSort(vec, 0, vec.size()-1);		

    }

    int partition(std::vector<int> &vec, int low, int high) {
    	int midpoint = low + (high-low)/2;
    	int pivot = vec[midpoint];
    	
    	bool done = false;
    	while(!done) {
    		while(++compares && vec[low] < pivot) {
    			low +=1;
    		}
    		while(pivot < vec[high]) {
    			high -= 1;
    		}
    		if(++compares && low >= high) {
    			done = true;
    		}
    		else {
    			int swapVal = vec[low];
    			vec[low] = vec[high];
    			vec[high] = swapVal;
    			low += 1;
    			high -= 1;
    			moves++;
    		}
    	}
    	return high;
   }
	
    void quickSort(std::vector<int> &vec, int low, int high) {

	if(++compares && low >= high) { //zero or sorted one element list
		return;
	}
	int lowEnd = partition(vec, low, high);
	quickSort(vec, low, lowEnd);
	quickSort(vec, lowEnd +1, high);
	

    }
    
};

#endif
