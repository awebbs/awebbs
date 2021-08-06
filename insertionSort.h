/**
 *  @author Aaron S. Crandall <crandall@gonzaga.edu>
 *  @author Student: Amber Paige Webber
 *  @copyright 2021
 */

#ifndef __INSTRUMENTED_INSERTION_SORT_H
#define __INSTRUMENTED_INSERTION_SORT_H

#include "instrumentedSort.h"

class InsertionSort: public InstrumentedSort
{

public:
    InsertionSort() {
        name = "Insertion Sort";
    }

    /**
     *  Place to implement the sorting algorithm
     */
    void doSort(std::vector<int> & vec) override
    {
        // MA TODO: implement insertion sort here
        // Don't forget to increment compares and moves when you do the
  
        int j = 0;
        int swapVal = 0;

        	for(size_t i = 1; i < vec.size(); ++i) {	
        		j = i;
        		while(++compares && j > 0 && vec[j] < vec[j -1]) {
        				moves++;
        				swapVal = vec[j];
        				vec[j] = vec[j-1];
        				vec[j-1] = swapVal;
        				--j;
        		}
        	}	
    }	
};

#endif
