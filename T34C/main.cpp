#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "include/Device.h"
#include "include/Keyboard.h"
#include "include/Scanner.h"
#include <stdlib.h>

using namespace std;

void output(Device* ps[]); //���������
void edit(Device* ps[], Keyboard k1, Keyboard k2, Scanner s1, Scanner s2);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Keyboard k1("Samsung", 2008, "������������");
    Keyboard k2("Genius", 2017, "����������");
    Scanner s1("HP", 2013, "A4", "����������");
    Scanner s2("Samsung", 2010, "A3", "���������");
    Device* ps[4]; // ������ ���������� �� ������� �����
    //���������� ������� ������ ����� � ����� �������
    ps[0]=&k1;
    ps[1]=&k2;
    ps[2]=&s1;
    ps[3]=&s2;

    output(ps);

    edit(ps, k1,k2,s1,s2);
}

void output(Device* ps[])
{
    system("cls");
    //����� ������ � ������� ������� ����������
    cout<<"�\t������\t���\t������\t���\n";
    for(int i=0; i<4; i++)
    {
        cout<<i+1<<"\t";
        ps[i]->show();
    }
    int avr=0;
    //������ �������� ����� ������������
    for(int i=0; i<4; i++)
    {
        avr += 2020 - (*(ps+i))->getPY();
    }
    avr /= 4;
    cout << "\n������� ���� ������������:  " << avr << endl;
}

void edit(Device* ps[], Keyboard k1, Keyboard k2, Scanner s1, Scanner s2)
{
    int k, str;
    string str_buf;
    int int_buf;
    do{
        int n=3;
        cout<<"\n������� ����� ������ ��� �������������� (0 - �����):\n>> ";
        cin>>str;
        if(str>0 && str<=4){
            str--;
            cout<<"\n1.������\n2.���\n";
            if(str>1){
                cout<<n<<".������\n";
                n++;
            }
            cout<<n<<".���\n>> ";
            cin>>k;
            switch(k){
                case 1:{
                    cout<<"\n������� ����� ������:\n>> ";
                    cin>>str_buf;
                    (*(ps+str))->setModel(str_buf);
                    break;
                }
                case 2:{
                    cout<<"\n������� ����� ���:\n>> ";
                    cin>>int_buf;
                    (*(ps+str))->setPY(int_buf);
                    break;
                }
                case 3:{
                    if(str+1==1)
                    {
                        cout<<"\n������� ����� ���:\n>> ";
                        cin>>str_buf;
                        k1.setToK(str_buf);
                        ps[0]=&k1;
                    }
                    if(str+1==2)
                    {
                        cout<<"\n������� ����� ���:\n>> ";
                        cin>>str_buf;
                        k2.setToK(str_buf);
                        ps[1]=&k2;
                    }
                    if(str+1==3)
                    {
                        cout<<"\n������� ����� ������:\n>> ";
                        cin>>str_buf;
                        s1.setScanForm(str_buf);
                        ps[2]=&s1;
                    }
                    if(str+1==4)
                    {
                        cout<<"\n������� ����� ������:\n>> ";
                        cin>>str_buf;
                        s2.setScanForm(str_buf);
                        ps[3]=&s2;
                    }
                    break;
                }
                case 4:{
                    if(str+1==3)
                    {
                        cout<<"\n������� ����� ���:\n>> ";
                        cin>>str_buf;
                        s1.setToS(str_buf);
                        ps[2]=&s1;
                    }
                    if(str+1==4)
                    {
                        cout<<"\n������� ����� ���:\n>> ";
                        cin>>str_buf;
                        s2.setToS(str_buf);
                        ps[3]=&s2;
                    }
                    break;
                }
                default:{
                    cout<<"\n������!";
                    break;
                }
            }
            str++;
        }
        output(ps);
    }while(str!=0);
}
