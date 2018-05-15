//
//  test_general.cpp
//  test
//
//  Created by Liwen Lin on 7/12/16.
//  Copyright © 2016 Liwen Lin. All rights reserved.
//


#include <stdio.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <memory>
#include "test.hpp"

using namespace std;
using std::cout;
using std::endl;

static int create_string(string *str) {
    str->assign("abc00\00", 7);
    return 0;
}

enum class Color {
    red,
    blue,
    yellow
};

class ATest {
public:
    const static int a;
};
const int ATest::a = 3;

int main(void) {
    shared_ptr<int> sp(new int);
    shared_ptr<int> sp1 = sp;
    shared_ptr<int> sp2 = sp;
    sp1.reset();
    
    
    Data<int> d11;
    d11.d = 4;
    int a[5];
    
    if (-1 > 0U) {
        cout << "what" << endl;
    }
    
    
    Color c = Color::blue;
    int d1 = (int)c;
    cout << d1 << endl;
    
    
    string str;
    create_string(&str);
    
    
    
    vector<int> ve;
    ve.push_back(3);
    ve.push_back(5);
    ve.push_back(7);
    ve.erase(ve.begin()+ve.size()-1, ve.end());
    
    std::unordered_map<std::string,std::string> mymap;
    
    // populating container:
    mymap["U.S."] = "Washington";
    mymap["U.K."] = "London";
    mymap["France"] = "Paris";
    mymap["Russia"] = "Moscow";
    mymap["China"] = "Beijing";
    mymap["Germany"] = "Berlin";
    mymap["Japan"] = "Tokyo";
 
    // show content:
    for ( auto& x: mymap )
        std::cout << x.first << ": " << x.second << std::endl;
    
    
    cout << endl << endl;
    // erase examples:
    mymap.erase ( mymap.begin() );      // erasing by iterator
    mymap.erase ("France");             // erasing by key
    mymap.erase ( mymap.find("Germany"), mymap.end() ); // erasing by range
    
    // show content:
    for ( auto& x: mymap )
        std::cout << x.first << ": " << x.second << std::endl;
    
    
    
    stringstream ss11;
    float f[100];
    f[0] = 3.131;
    f[3] = 323.13;
    ss11.write((char*)f, sizeof(float)*100);
    string st1;
    ss11 >> st1;
    float f1[100];
    memcpy(f1, ss11.str().c_str(), st1.length());
    
    
    int k1 = 19323;
    stringstream ss;
    ss << (&k1);
    string s1 = ss.str();
    void *kp, *kp1;
    ss >> kp >> kp1;
    
    cout << ss.str() << ", " << ss.str().length() << endl;
goto stop;
    char ss1[20];
    memset(ss1, -1, 20);
    sprintf(ss1, "%p", &k1);
    void *d;
    sscanf(ss1, "%p", &d);
    
stop:
    
    
    return 0;
}


