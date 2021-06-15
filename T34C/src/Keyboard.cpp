#include "../include/Keyboard.h"

Keyboard::Keyboard()
{
    model = "NoModel";
    prod_year = 0;
    type_of_keyboard = "NoType";
}
Keyboard::Keyboard(string m, int py, string t)
{
    model = m;
    prod_year = py;
    type_of_keyboard = t;
}
void Keyboard::setToK(string t)
{
    type_of_keyboard = t;
}
void Keyboard::show()
{
    cout<<model<<"\t"<<prod_year<<"\t\t"<<type_of_keyboard<<endl;
}
