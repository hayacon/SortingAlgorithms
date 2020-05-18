//
//  Algorithm.cpp
//  SortingAlgorithms
//
//  Created by Hayato Conrad Ishida on 5/8/20.
//  Copyright © 2020 Hayato Conrad Ishida. All rights reserved.
//

#include "Algorithm.hpp"
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>


std::vector<double> Algorithm::bubbleSort(std::vector<double> array, int arraySize)
{
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for(int i = 0; i < arraySize; ++i)
        {
            if(array[i] > array[i + 1])
            {
                std::swap(array[i], array[i+1]);
                swapped = true;
            }
        };

        arraySize = arraySize - 1;
    }

    printArray(array);
    return array;
}

std::vector<double> Algorithm::insertionSort(std::vector<double> array, int arraySize)
{
    for (int i = 0; i < arraySize; ++i) {
        double ins = array[i];
        int j = i - 1;
        while( j >= 0 && ins < array[j])
        {
            array[j+1] = array[j];
            j = j - 1;
        }

        array[j+1] = ins;
    }

    printArray(array);
    return array;
}

std::vector<double> Algorithm::selectionSort(std::vector<double> array, int arraySize)
{
    int min;
    for(int i = 0; i < arraySize; ++i)
    {
        min = posMin(array, i, arraySize);
        std::swap(array[i], array[min]);
    }

    printArray(array);
    return array;
}

// function inside Selection Sirt
int Algorithm::posMin(std::vector<double> array, int i, int arraySize)
{
    int minpos = i;
    for( int i = minpos; i < arraySize; ++i)
    {
        if(array[i]< array[minpos])
        {
            minpos = i;
        }
    }

    return minpos;
}


///
std::vector<double> Algorithm::quickSort(std::vector<double> &array, int left, int right)
{
    if(left < right)
    {
        int pivotInt = partition(array, left, right);
        quickSort(array, left, pivotInt - 1);
        quickSort(array, pivotInt, right);
    }

    printArray(array);
    return array;
}

int Algorithm::partition(std::vector<double> &array, int left, int right)
{
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = array[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(array[i] < pivotValue) {
            i++;
        }
        while(array[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

///
std::vector<double> Algorithm::merge(std::vector<double> left, std::vector<double> right)
{
    std::vector<double> result;
    while ((int)left.size() > 0 || (int)right.size() > 0) {
       if ((int)left.size() > 0 && (int)right.size() > 0) {
          if ((int)left.front() <= (int)right.front()) {
             result.push_back((int)left.front());
             left.erase(left.begin());
          }
    else {
             result.push_back((int)right.front());
             right.erase(right.begin());
          }
       }  else if ((int)left.size() > 0) {
             for (int i = 0; i < (int)left.size(); i++)
                result.push_back(left[i]);
             break;
       }  else if ((int)right.size() > 0) {
             for (int i = 0; i < (int)right.size(); i++)
                result.push_back(right[i]);
             break;
       }
    }

    return result;
}

std::vector<double> Algorithm::mergeSort(std::vector<double> array)
{
    if (array.size() <= 1)
         return array;

      std::vector<double> left, right, result;
      int middle = ((int)array.size()+ 1) / 2;

      for (int i = 0; i < middle; i++) {
         left.push_back(array[i]);
      }

      for (int i = middle; i < (int)array.size(); i++) {
         right.push_back(array[i]);
      }

      left = mergeSort(left);
      right = mergeSort(right);
      result = merge(left, right);

        printArray(result);
      return result;
}

std::vector<double> Algorithm::countingSort(std::vector<double> array)
{
    // initialization
    const double arraySize = array.size();
    int max = 0;
    int pos = 0;
    for(int i = 0; i < arraySize; ++i)
    {
        if(array[i] > max) max = array[i];
    }

    std::vector<double> c;
    std::vector<double> r;
    for(int i = 0; i < arraySize; ++i)
    {
        r.push_back(0);
    }

    for(int i = 0; i < max + 1; ++i)
    {
        c.push_back(0);
    }

    // end of initialization

    // count element
    for(int i = 0; i < arraySize; ++i) c[array[i]] = c[array[i]] + 1;

    // generating sorted array
    for(int i = 0; i < c.size(); ++i)
    {
            while(c[i] != 0)
            {
                r[pos] = i;
                c[i] = c[i] - 1;
                pos += 1;
            }

    }

    printArray(r);
    return r;
}




void Algorithm::printArray(std::vector<double> array)
{
    for (int i = 0; i < array.size(); ++i )
    {
        if(i != array.size() - 1) std::cout << array[i] << ',';
        else std::cout<<array[i] <<std::endl;
    }
}

