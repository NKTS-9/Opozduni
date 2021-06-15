#include <string>
#include <iostream>
#include <stdlib.h>
#include "../include/printer.h"

using namespace std;

Printer::Printer(){
	Printer::state = "No_State";
    Printer::ctp = "No_Connection_Of_PC";
    Printer::format = "No_Format";
    Printer::aoc = 0;
    Printer::black = 0;
    Printer::red = 0;
    Printer::green = 0;
    Printer::blue = 0;
}

Printer::Printer(string st, string ctp, string f, int aoc, int bl, int r, int g, int b){
    Printer::state = st;
    Printer::ctp = ctp;
    Printer::format = f;
    Printer::aoc = aoc;
    Printer::black = bl;
    Printer::red = r;
    Printer::green = g;
    Printer::blue = b;
}

string Printer::get_State(){
    return Printer::state;
}

void Printer::set_State(string val){
    Printer::state = val;
}

string Printer::get_CTP(){
    return Printer::ctp;
}

void Printer::set_CTP(string val){
    Printer::ctp = val;
}

string Printer::get_Format(){
    return Printer::format;
}

void Printer::set_Format(string val){
    Printer::format = val;
}

int Printer::get_AOC(){
    return Printer::aoc;
}

void Printer::set_AOC(int val){
    Printer::aoc = val;
}

int Printer::get_BLACK(){
    return Printer::black;
}

void Printer::set_BLACK(int val){
    Printer::black = val;
}

int Printer::get_RED(){
    return Printer::red;
}

void Printer::set_RED(int val){
    Printer::red = val;
}

int Printer::get_GREEN(){
    return Printer::green;
}

void Printer::set_GREEN(int val){
    Printer::green = val;
}

int Printer::get_BLUE(){
    return Printer::blue;
}

void Printer::set_BLUE(int val){
    Printer::blue = val;
}

//подпрограммы вывода и редактирования

void output(Printer P){
    system("cls");
    cout<<"______________________________________________________________________________________________________________\n";
    cout<<"Состояние\tПодключение_к_компьютеру\tФормат\tКоличество_цветов\tЧерный\tКрасный\tЗеленый\tСиний\n";
    cout<<P.get_State()<<"\t\t";
    if(P.get_State()=="ON"){
        cout<<P.get_CTP()<<"\t\t\t\t"
            <<P.get_Format()<<"\t"
            <<P.get_AOC()<<"\t\t\t"
            <<P.get_BLACK()<<"/500\t";
        if(P.get_AOC()==4)
            cout<<P.get_RED()<<"/500\t"
                <<P.get_GREEN()<<"/500\t"
                <<P.get_BLUE()<<"/500\n";
        else
            cout<<"-\t-\t-\n";
    }
    else
        cout<<"-\t\t\t\t-\t-\t\t\t-\t-\t-\t-\n";
    cout<<"______________________________________________________________________________________________________________\n\n";
}

void change(Printer P){
    int n, ch, fs=1;
    do{
        n=1;
        if(P.get_State()=="ON"){
            cout<<n<<".Выключить принтер\n";
            n++;
            if(P.get_CTP()=="YES"){
                cout<<n<<".Отключить от компьютера\n";
                n++;
                cout<<n<<".Поменять формат\n";
                n++;
                if(P.get_AOC()==1)
                    cout<<n<<".Поменять на цветную печать\n";
                else
                    cout<<n<<".Поменять на черно-белую печать\n";
                n++;
                cout<<n<<".Выполнить печать\n";
            }
            else
                cout<<n<<".Подключиться к компьютеру\n";
        }
        else
            cout<<n<<".Включить принтер\n";
        cout<<"0.Выйти из программы\n";
        cout<<">> ";
        cin>>ch;
        if((ch>0)&&(ch<=n))
        switch(ch){
            case 1:
                if(P.get_State()=="ON")
                    P.set_State("OFF");
                else
                    P.set_State("ON");
                break;
            case 2:
                if(P.get_CTP()=="YES")
                    P.set_CTP("NO");
                else
                    P.set_CTP("YES");
                break;
            case 3:
                if(P.get_Format()=="A4")
                    P.set_Format("A3");
                else
                    P.set_Format("A4");
                break;
            case 4:
                if(P.get_AOC()==1)
                    P.set_AOC(4);
                else
                    P.set_AOC(1);
                break;
            case 5:
                if(P.get_Format()=="A4")
                    fs=1;
                else
                    fs=2;
                if(
                   ((P.get_AOC()==1)&&(P.get_BLACK()>0)&&((P.get_BLACK()-fs)>=0))
                   ||((P.get_AOC()==4)&&(P.get_BLACK()>0)&&(P.get_RED()>0)&&(P.get_GREEN()>0)&&(P.get_BLUE()>0)
                   &&((P.get_BLACK()-fs)>=0)&&((P.get_RED()-fs)>=0)&&((P.get_GREEN()-fs)>=0)&&((P.get_BLUE()-fs)>=0))
                   )
                {
                    if(P.get_AOC()==1)
                        P.set_BLACK(P.get_BLACK()-fs);
                    else
                    {
                        P.set_BLACK(P.get_BLACK()-fs);
                        P.set_RED(P.get_RED()-fs);
                        P.set_GREEN(P.get_GREEN()-fs);
                        P.set_BLUE(P.get_BLUE()-fs);
                    }
                }
                else
                    cout<<"\nПЕЧАТЬ НЕВОЗМОЖНА! ЗАМЕНИТЕ КАРТРИДЖИ!\n";
                break;
        }
        cout<<endl;
        output(P);
    }while(ch!=0);
}
