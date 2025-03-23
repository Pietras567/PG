#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#define N 25 //<----------------------------------------- Tutaj zmiana wielkosci tablic do zadan 1-6
#define G 5
//Piotr Janiszek - 247678 //IDE - CLION
using namespace std;

void mini(int &min_value);
void maxi(int &max_value, int &min_value);
void function1(int Tab[], int mini, int maxi);
void function2(int Tab[]);
void function3(int Tab[]);
struct struct4{
    int max_index;
    int max_value;
};
struct4 function4(const int Tab[]);
double function5(int Tab[]);
int function6(const int Tab1[], const int Tab2[]);
double function7(double Tab[], double x_liczba);
double podaj_x();
void podaj_wsp(double Tab[]);
int main(){
    cout<<"Wielkosc Tablic do zadan mozesz zmienic na gorze kodu strony (w 6 linijce), poprzez zmiane liczby w dyrektywie define\nAktualna ilosc elementow w tablicach: "<<N<<"\nMilego Dnia\n";
    srand(time(NULL));
    //pobranie od uzytkownika wartosci min i max
    int x[N];
    int y[N];
    double a[G];
    int p;
    int k;
    mini(p);
    maxi(k, p);

    //zadanie 1
    cout<<"Zadanie 1 -Tablica x\n";
    function1(&x[N], p, k);
    cout<<"Zadanie 1 -Tablica y\n";
    function1(&y[N], p, k);


    //zadanie 2
    cout<<"Zadanie 2 - Tablica x - Wypisywanie Wartosci\n";
    function2(&x[N]);
    cout<<"Zadanie 2 - Tablica y - Wypisywanie Wartosci\n";
    function2(&y[N]);


    cout<<"Zadanie 3 z Tablica x - Suma Kwadratow miejsc nieparzystych\n";
    function3(&x[N]);

    cout<<"Zadanie 4 z Tablica y - Element Max i jego index\n";
    function4(&y[N]);

    cout<<"Zadanie 5 z Tablica x - Odchylenie standardowe od sredniej arytmetycznej\n";
    function5(&x[N]);

    cout<<"Zadanie 6 z Tablicami x i y - iloczyn skalarny wektorow\n";
    function6(&x[N], &y[N]);

    cout<<"Zadanie 7 z Tablica z - wynik wielomianu dla danego x\n";
    double x_l = podaj_x();
    podaj_wsp(&a[G]);
    function7(&a[G], x_l);
    return 0;
}

void mini(int &min_value){
    cout<<"Podaj wartosc minimalna dla przedzialu zamknietego liczb calkowitych: ";
    cin>>min_value;
}

void maxi(int &max_value, int &min_value){
    do {
        cout << "Podaj wartosc maksymalna dla przedzialu zamknietego liczb calkowitych: ";
        cin >> max_value;
    }while(max_value<min_value);
}

void function1(int Tab[], int mini, int maxi){
    cout<<"Losu Losu \\(^o^)/\n";
    for(int i = 0; i < N; i++){
        Tab[i] = rand()%(maxi-mini+1)+mini;
    }
    cout<<"Wartosci zostaly pomyslnie wygenerowane :)\n";
    cout<<"\n\n";
}

void function2(int Tab[]){
    for(int i = 0; i < N; i++){
        cout<<"Wartosc Tablicy na miejscu "<<i<<" to: "<<Tab[i];
        cout<<"\n";
    }
    cout<<"\n\n";
}

void function3(int Tab[]){
    int suma = 0;
    for(int i = 1; i < N; i+=2){
        cout<<"suma przed: "<<suma<<"\n";
        cout<<"Licze kwadrat dla liczby: "<<Tab[i]<<" i dodaje\n";
        suma+=pow(Tab[i], 2);
    }
    cout<<"Suma kwadratow miejsc nieparzystych tej tablicy to: "<<suma<<"\n";
    cout<<"\n\n";
}


struct4 function4(const int Tab[]){
    struct4 dane{};
    dane.max_index = 0;
    dane.max_value = Tab[0];
    for(int i = 1; i < N; i++){
        if(Tab[i]>=dane.max_value){
            dane.max_index = i;
            dane.max_value = Tab[i];
        }
    }

    cout<<"Max Index wynosi: "<<dane.max_index <<"\n";
    cout<<"Max Wartosc wynosi: "<<dane.max_value<<"\n";
    cout<<"\n\n";
    return dane;
}

double function5(int Tab[]){
    double odchylenie_standard = 0; double sr_arytmetyczna = 0;
    for(int i = 0; i < N; i++){
        sr_arytmetyczna += Tab[i];
    }
    sr_arytmetyczna /= N;
    cout<<"Srednia arytmetyczna wynosi: "<<sr_arytmetyczna<<"\n";
    for(int i = 0; i < N; i++){
        odchylenie_standard+=pow((Tab[i]-sr_arytmetyczna), 2);
    }
    odchylenie_standard /= N;
    cout<<"Wariacja wynosi: "<<odchylenie_standard<<"\n";
    odchylenie_standard = sqrt(odchylenie_standard);
    cout<<"Odchylenie standardowe wynosi: "<<odchylenie_standard<<"\n";
    cout<<"\n\n";
    return odchylenie_standard;
}

int function6(const int Tab1[], const int Tab2[]){
    int iloczyn = 0;
    for(int i = 0; i < N; i++){
        iloczyn += (Tab1[i]*Tab2[i]);
    }
    cout<<"iloczyn wynosi: "<<iloczyn<<"\n";
    cout<<"\n\n";
    return iloczyn;
}

double podaj_x(){
    int x;
    cout<<"Podaj x: ";
    cin>>x;
    cout<<"\n";
    return x;
}

void podaj_wsp(double Tab[]){
    for(int i = 1; i <= G; i++){
        cout<<setw(22)<<"Podaj wspolczynnik nr "<<setw(3)<<i<<setw(3)<<": ";
        cin>>Tab[(i-1)];
    }
}

double function7(double Tab[], double x_liczba){
    cout<<"\n";
    for (int j = 0; j < (G+1)/2; j++)
        swap(Tab[j], Tab[G - j - 1]);

    double w_wielomian = Tab[0];
    for(int i = 1; i <= G-1; i++){
        w_wielomian = w_wielomian*x_liczba+Tab[i];
    }
    cout<<setw(32)<<"Wynik tego wielomianu w punkcie "<<x_liczba<<", to: "<<w_wielomian;
    cout<<"\n\n";
    return w_wielomian;
}



