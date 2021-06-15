#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Device
{
    public:
        Device();
        Device(string, int);
        void setModel(string);
        int getPY();
        int getCoY();
        void setPY(int);
        virtual void show();
    protected:
        string model;
        int prod_year;
    private:
};

#endif // DEVICE_H
