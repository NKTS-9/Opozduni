#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Device.h"

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Keyboard : public Device
{
    public:
        Keyboard();
        Keyboard(string, int, string);
        void setToK(string);
        void show();
    protected:

    private:
        string type_of_keyboard;
};

#endif // KEYBOARD_H
