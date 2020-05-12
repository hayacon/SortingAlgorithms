//
//  AlgoMain.hpp
//  SortingAlgorithms
//
//  Created by Hayato Conrad Ishida on 5/8/20.
//  Copyright © 2020 Hayato Conrad Ishida. All rights reserved.
//

#ifndef AlgoMain_hpp
#define AlgoMain_hpp

#include <stdio.h>
#pragma once
#include <vector>

#endif /* AlgoMain_hpp */

class AlgoMain
{
public:
    AlgoMain();
    void init();
    void userMenu();
    void userInput();
    std::vector<double> inputArray();

private:
    int arraySize;
    std::vector<double> array;
     
};
