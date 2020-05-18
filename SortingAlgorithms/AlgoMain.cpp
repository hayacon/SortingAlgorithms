//
//  AlgoMain.cpp
//  SortingAlgorithms
//
//  Created by Hayato Conrad Ishida on 5/8/20.
//  Copyright © 2020 Hayato Conrad Ishida. All rights reserved.
//

#include "AlgoMain.hpp"
#include "Algorithm.hpp"
#include <iostream>
#include <vector>

AlgoMain::AlgoMain()
{

};

/** initialize this app*/
void AlgoMain::init()
{
    userMenu(); 
};

void AlgoMain::userMenu()
{
    std::cout << "Sorting ALgorithm Simulator" << std::endl;
    std::cout << "1 : Bubbule Sort" << std::endl;
    std::cout << "2 : Insertion Sort"<<std::endl;
    std::cout << "3 : Selection Sort" << std::endl;
    std::cout << "4 : Quick Sort" <<std::endl;
    std::cout << "5 : Merge Sort" <<std::endl;
    std::cout << "6 : Counting Sort" <<std::endl;
    std::cout << "==============================" << std::endl;
    userInput();
}

void AlgoMain::userInput()
{
    int i;
    std::cout << "Pick an algorithm" <<std::endl;
    std::cin>> i ;
    if(i == 1)
    {
        std::cout << "Bubbule Sort" << std::endl;
        inputArray();
        Algorithm::bubbleSort(array, arraySize);
    }
    else if(i == 2)
    {
        std::cout << "Insertion Sort"<<std::endl;
        inputArray();
        Algorithm::insertionSort(array, arraySize);
    }
    else if(i == 3)
    {
        std::cout << "Selection Sort" << std::endl;
        inputArray();
        Algorithm::selectionSort(array, arraySize);
    }
    else if(i == 4)
    {
        std::cout << "Quick Sort" <<std::endl;
        inputArray();
        Algorithm::quickSort(array, 0, arraySize - 1);
    }
    else if(i == 5)
    {
        std::cout << "Merge Sort" <<std::endl;
        inputArray();
        Algorithm::mergeSort(array);
        
    }else if(i == 6)
    {
        std::cout << "Counting Sort" <<std::endl;
        inputArray();
        Algorithm::countingSort(array);
    }else{
        std::cout << "Invalid input, please try again" <<std::endl;
        userMenu();
    }

}

std::vector<double> AlgoMain::inputArray()
{
    double element;

    std::cout<< "Enter length of array" <<std::endl;
    std::cin >> arraySize;
    std::cout<< "Enter contents of array" <<std::endl;
    for(int i = 0; i < arraySize; ++i)
    {
        std::cout << "element of index " << i << std::endl;
        std::cin>> element;
        array.push_back(element);
    }

    for (int i = 0; i < arraySize; ++i )
    {
        if(i != arraySize - 1) std::cout << array[i] << ',';
        else std::cout<< array[i] <<std::endl;
    }
    return array;
}

