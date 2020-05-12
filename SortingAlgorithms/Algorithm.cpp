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
std::vector<double> Algorithm::quickSort(std::vector<double> array, int low, int high)
{
    return array;
}

int Algorithm::partition(std::vector<double> array, int low, int high)
{
    int i;
    return i;
}

///

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

void Algorithm::printArray(std::vector<double> array)
{
    for (int i = 0; i < array.size(); ++i )
    {
        if(i != array.size() - 1) std::cout << array[i] << ',';
        else std::cout<<array[i] <<std::endl;
    }
}

