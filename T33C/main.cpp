#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "include/printer.h"

using namespace std;

void output(Printer P);
void change(Printer P);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    //Printer P;
    string state_buf;
    string ctp_buf;
    string format_buf;
    int aoc_buf;
    int black_buf;
    int red_buf;
    int green_buf;
    int blue_buf;
    ifstream fl("files//printer.txt");
    if(fl)
    {
        fl  >> state_buf
            >> ctp_buf
            >> format_buf
            >> aoc_buf
            >> black_buf
            >> red_buf
            >> green_buf
            >> blue_buf;

        Printer P(state_buf, ctp_buf, format_buf, aoc_buf, black_buf, red_buf, green_buf, blue_buf);
        output(P);
        change(P);
    }
    else
        cout<<"Ошибка открытия файла!\n";
    fl.close();
}
