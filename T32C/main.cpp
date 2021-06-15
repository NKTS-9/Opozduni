#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

class Dinner
{
    public:
        Dinner();
        Dinner(string, string, int, int);

        string get_Title();
        void set_Title(string val);

        string get_Date();
        void set_Date(string val);

        int get_Weight();
        void set_Weight(int val);

        int get_Price();
        void set_Price(int val);

    private:
        string Title;
        string Date;
        int Weight;
        int Price;

};

Dinner::Dinner(){
	Title = "NoTitle";
    Date = "00.00.0000";
    Weight = 0;
    Price = 0;
}

Dinner::Dinner(string t, string d, int w, int p){
    Title = t;
    Date = d;
    Weight = w;
    Price = p;
}

string Dinner::get_Title(){
    return Title;
}

void Dinner::set_Title(string val){
    Title = val;
}

string Dinner::get_Date()
{
    return Date;
}

void Dinner::set_Date(string val){
    Date = val;
}

int Dinner::get_Weight(){
    return Weight;
}

void Dinner::set_Weight(int val){
    Weight = val;
}

int Dinner::get_Price(){
    return Price;
}

void Dinner::set_Price(int val){
    Price = val;
}

//подпрограммы вывода и редактирования

void output(Dinner *D, int *n){
    system("cls");
    float *sr;
    sr = new float;
    *sr=0;
    for (int i=0; i<(*n); i++){
        cout<<i+1<<" "<<D[i].get_Title()<<" "<<D[i].get_Date()<<" "<<D[i].get_Weight()<<" "<<D[i].get_Price()<<endl;
        *sr=*sr+D[i].get_Price();
    }
    *sr=*sr/(*n);
    cout<<"\nСредняя стоймость за порцию: "<<*sr<<endl;
    delete sr;
    sr = NULL;}

void change(Dinner *D, int *n){
int *k;
    k= new int;
    int *str;
    str= new int;
    do{
        cout<<"\nВведите номер строки для редактирования (0 для выхода):\n>> ";
        cin>>*str;
        if((*str)>0 && (*str)<=(*n)){
            (*str)--;
            cout<<"\n1.Название блюда\n2.Дата изготовления\n3.Масса\n4.Цена за порцию\n>> ";
            cin>>*k;
            switch(*k){
                case 1:{
                    string buf;
                    cout<<"\nВведите Название:\n>> ";
                    cin>>buf;
                    D[*str].set_Title(buf);
                    break;
                }
                case 2:{
                    string buf;
                    cout<<"\nВведите Дата изготовления:\n>> ";
                    cin>>buf;
                    D[*str].set_Date(buf);
                    break;
                }
                case 3:{
                    int buf;
                    cout<<"\nВведите Масса:\n>> ";
                    cin>>buf;
                    D[*str].set_Weight(buf);
                    break;
                }
                case 4:{
                    int buf;
                    cout<<"\nВведите Стоимость:\n>> ";
                    cin>>buf;
                    D[*str].set_Price(buf);
                    break;
                }
                default:{
                    cout<<"\nОшибка!";
                    break;
                }
            }
            (*str)++;
        }
        system("cls");
        if((*str)!=0)
            output(D, n);
    }while((*str)!=0);
    delete k;
    k = NULL;
    delete str;
    str = NULL;
    cout<<endl;
}

int main(){
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout<<"Объект по умолчанию\n\n";
    Dinner a;
    cout<<a.get_Title()<<" "<<a.get_Date()<<" "<<a.get_Weight()<<" "<<a.get_Price()<<endl<<endl;
    system("pause");
    cout<<"\nОбъект с параметрами\n\n";
    Dinner b("Салат", "13.05.2021", 120, 36);
    cout<<b.get_Title()<<" "<<b.get_Date()<<" "<<b.get_Weight()<<" "<<b.get_Price()<<endl<<endl;
    system("pause");

    string t_buf, d_buf;
    int w_buf, p_buf;
    int n=0;
    ifstream file("Dinner.txt");
    if(file){
        while(!file.eof()){
            file>>t_buf>>d_buf>>w_buf>>p_buf;
            n++;
        }
        file.seekg(0); //переместиться к началу файла
        Dinner D[n];
        for(int i=0; i<n; i++){
            file>>t_buf>>d_buf>>w_buf>>p_buf;
            D[i].set_Title(t_buf);
            D[i].set_Date(d_buf);
            D[i].set_Weight(w_buf);
            D[i].set_Price(p_buf);
        }
        output(D, &n);
        change(D, &n);
    }
    else
        cout<<"Ошибка открытия файла!\n";
    file.close();
}

