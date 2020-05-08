//
//  Algoritms.hpp
//  SortingAlgorithms
//
//  Created by Hayato Conrad Ishida on 5/8/20.
//  Copyright © 2020 Hayato Conrad Ishida. All rights reserved.
//

#ifndef Algoritms_hpp
#define Algoritms_hpp

#include <stdio.h>
#pragma once

#endif /* Algoritms_hpp */

#include <vector>


class Algorithm
{
public:
    std::vector<double> bubbleSort(std::vector<double> array);
    std::vector<double> insertionSort(std::vector<double> array);
    std::vector<double> selectionSort(std::vector<double> array);
    std::vector<double> quickSort(std::vector<double> array);
    std::vector<double> mergeSort(std::vector<double> array);

};
