//
//  test_builder.cpp
//  test
//
//  Created by Liwen Lin on 5/5/17.
//  Copyright © 2017 Liwen Lin. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Vehicle {
public:
    Vehicle() {
        m_name = "unknown";
    }
    
    virtual void set_wheel(int n) {
        m_wheel = n;
        cout << m_name << " set wheel: " << m_wheel << endl;
    }
    
    virtual void set_door(int n) {
        m_door = n;
        cout << m_name << " set door: " << m_door << endl;
    }
    
    virtual void set_engine(string engine) {
        m_engine = engine;
        cout << m_name << " set engine: " << engine << endl;
    }

protected:
    string m_name;
    
private:
    int m_wheel;
    int m_door;
    string m_engine;
};

class Bike: public Vehicle {
public:
    Bike() {
        m_name = "bike";
    }
    
};

class Car: public Vehicle {
public:
    Car() {
        m_name = "car";
    }
    
};

class VehicleBuilder {
public:
    virtual void build_vehicle() = 0;
    
    virtual void build_door() = 0;
    
    virtual void build_wheel() = 0;
    
    virtual void build_engine() = 0;
    
    Vehicle* get_vehicle() { return m_vehicle; }
    
protected:
    Vehicle *m_vehicle;
};

class BikeBuilder : public VehicleBuilder {
public:
    virtual void build_vehicle() {
        m_vehicle = new Bike;
    }
    
    virtual void build_door() {
        m_vehicle->set_door(0);
    }
    
    virtual void build_wheel() {
        m_vehicle->set_wheel(2);
    }
    
    virtual void build_engine() {
        m_vehicle->set_engine("human power");
    }
};

class CarBuilder : public VehicleBuilder {
public:
    virtual void build_vehicle() {
        m_vehicle = new Car;
    }
    
    virtual void build_door() {
        m_vehicle->set_door(4);
    }
    
    virtual void build_wheel() {
        m_vehicle->set_wheel(4);
    }
    
    virtual void build_engine() {
        m_vehicle->set_engine("Tesla EV");
    }
};

class VehicleManufactory {
 public:
    Vehicle* build_vehicle(VehicleBuilder* vb) {
        vb->build_vehicle();
        vb->build_door();
        vb->build_wheel();
        vb->build_engine();
        return vb->get_vehicle();
    }
};

int main(int argc, char *argv[]) {
    VehicleManufactory vm;
    BikeBuilder bb;
    CarBuilder cb;
    Vehicle *v1 = vm.build_vehicle(&bb);
    Vehicle *v2 = vm.build_vehicle(&cb);
    
    delete v1;
    delete v2;
    
    return 0;
}


