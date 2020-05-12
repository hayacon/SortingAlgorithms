//
//  Algorithm.hpp
//  SortingAlgorithms
//
//  Created by Hayato Conrad Ishida on 5/8/20.
//  Copyright © 2020 Hayato Conrad Ishida. All rights reserved.
//

#ifndef Algorithm_hpp
#define Algorithm_hpp

#include <stdio.h>
#pragma once

#endif /* Algorithm_hpp */

#include <vector>


class Algorithm
{
public:
    static std::vector<double> bubbleSort(std::vector<double> array, int arraySize);
    static std::vector<double> insertionSort(std::vector<double> array, int arraySize);
    static std::vector<double> selectionSort(std::vector<double> array, int arraySize);
    static std::vector<double> quickSort(std::vector<double> &array, int left, int right);
    static std::vector<double> mergeSort(std::vector<double> array);

private:
    static void printArray(std::vector<double> array);
    static int posMin(std::vector<double> array, int i, int arraySize);
    static int partition(std::vector<double> &array, int left, int right);
    static std::vector<double> merge(std::vector<double> left, std::vector<double> right );


};
