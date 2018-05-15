//
//  test.cpp
//  test
//
//  Created by Liwen Lin on 4/7/16.
//  Copyright © 2016 Liwen Lin. All rights reserved.
//

#include "test.hpp"


int * Data1::p;

template <typename T>
OperatorTest& OperatorTest::operator<<(T data) {
    this->ss << data;
    int k = aaa+5;
    return *this;
}

void instantiate_ot()
{
    OperatorTest ot;
    ot << 3 << "dfasd";
}


static void fun1() {
    return;
}
