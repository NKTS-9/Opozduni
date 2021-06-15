#include "../include/Device.h"

Device::Device()
{
    Device::model = "NoModel";
    Device::prod_year = 0;
}
Device::Device(string m, int py)
{
    Device::model = m;
    Device::prod_year = py;
}
int Device::getPY()
{
    return prod_year;
}
void Device::show()
{
    cout<<model<<"\t"<<prod_year<<endl;
}
void Device::setModel(string var)
{
    model = var;
}
void Device::setPY(int var)
{
    prod_year = var;
}
