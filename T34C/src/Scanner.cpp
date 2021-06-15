#include "../include/Scanner.h"

Scanner::Scanner()
{
    model = "NoModel";
    prod_year = 0;
    scan_form = "NoForm";
    type_of_scanner = "NoType";
}
Scanner::Scanner(string m, int py, string sf, string ts)
{
    model = m;
    prod_year = py;
    scan_form = sf;
    type_of_scanner = ts;
}
void Scanner::setScanForm(string sf)
{
    scan_form = sf;
}
void Scanner::setToS(string ts)
{
    type_of_scanner = ts;
}
void Scanner::show()
{
    cout<<model<<"\t"<<prod_year<<"\t"<<scan_form<<"\t"<<type_of_scanner<<endl;
}
