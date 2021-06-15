#ifndef SCANNER_H
#define SCANNER_H

#include "Device.h"

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Scanner : public Device
{
    public:
        Scanner();
        Scanner(string, int, string, string);
        void setScanForm(string);
        void setToS(string);
        void show();
    private:
        string scan_form;
        string type_of_scanner;
};

#endif // SCANNER_H
