#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Dinner{
    string Title;
    string Date;
    int Weight;
    int Price;
};

void reading(Dinner *D, int *n){
    ifstream file("Dinner.txt");
    if(file)
        while(!file.eof()){
            file>>D[*n].Title
                >>D[*n].Date
                >>D[*n].Weight
                >>D[*n].Price;
            (*n)++;
        }
    else
        cout<<"������ �������� �����!\n";
    file.close();
}

void output(Dinner *D, int *n)
{
    float *sr;
    sr = new float;
    *sr=0;
    for (int i=0; i<(*n); i++){
        cout<<i+1<<" "<<D[i].Title<<" "<<D[i].Date<<" "<<D[i].Weight<<" "<<D[i].Price<<endl;
        *sr=*sr+D[i].Price;
    }
    *sr=*sr/(*n);
    cout<<"\n������� ��������� �� ������: "<<*sr<<endl;
    delete sr;
    sr = NULL;
}

void edit(Dinner *D, int *n){
    int *k;
    k= new int;
    int *str;
    str= new int;
    do{
        cout<<"\n������� ����� ������ ��� �������������� (0 ��� ������):\n>> ";
        cin>>*str;
        if((*str)>0 && (*str)<=(*n)){
            (*str)--;
            cout<<"\n1.�������� �����\n2.���� ������������\n3.�����\n4.���� �� ������\n>> ";
            cin>>*k;
            switch(*k){
                case 1:{
                    cout<<"\n������� ��������:\n>> ";
                    cin>>D[*str].Title;
                    break;
                }
                case 2:{
                    cout<<"\n������� ���� ������������:\n>> ";
                    cin>>D[*str].Date;
                    break;
                }
                case 3:{
                    cout<<"\n������� �����:\n>> ";
                    cin>>D[*str].Weight;
                    break;
                }
                case 4:{
                    cout<<"\n������� ���������:\n>> ";
                    cin>>D[*str].Price;
                    break;
                }
                default:{
                    cout<<"\n������!";
                    break;
                }
            }
            (*str)++;
        }
    }while((*str)!=0);
    delete k;
    k = NULL;
    delete str;
    str = NULL;
    cout<<endl;
}

void save(Dinner *D, int *n){
    string name;
    cout<<"\n������� �������� ����� ��� ���������� (�� ����� 10 ��������):\n>> ";
    cin>>name;
    name+=".txt";
    ofstream file(name.c_str());
    for(int i=0; i<*n; i++){
        file << D[i].Title <<" "
             << D[i].Date <<" "
             << D[i].Weight <<" "
             << D[i].Price <<endl;
    }
    file.close();
}

int main(){
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Dinner D[3];
    int n=0;
    reading(D, &n);
    output(D, &n);
    edit(D, &n);
    int *var;
    var = new int;
    output(D, &n);
    do{
        cout<<"\n��������� ���������? (1 - ��, 0 - ���)\n>> ";
        cin>>*var;
        if(*var==1)
            save(D, &n);
    }while((*var!=1)&&(*var!=0));
    delete var;
    var = NULL;
}
