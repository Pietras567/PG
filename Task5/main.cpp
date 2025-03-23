#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;
//Piotr Janiszek - 247678 //IDE - CLION
void zad1(int tab[]);
void zad2(int tab[]);
void zad3(int tab[]);
void zad4(int tab[]);
void zad5(int tab[], int tab_much[]);
void zad6(int tab[], int tab_much[]);
void zad7(int tab[], int tab_much[]);
int main()
{
    /*Grup� 100 student�w Informatyki poproszono o ocen� praktyk odbytych w firmie XXX. Ka�dy student m�g� przyzna� ocen� od 0 do 10. Zadeklarowa� N �elementow� np.100-elementow� tablic� student typu int.
    1. Wylosowa� elementy tej tablicy z przedzia�u <0, 10>.

    2. Wypisa� wylosowan� tablic�.

    3. Obliczy� �redni� ocen�, kt�r� dali studenci.

    4. Obliczy� median� (�rodkowa warto�� w posortowanej tablicy, w przypadku parzystej liczby element�w tablicy jest to �rednia dw�ch �rodkowych warto�ci).

    5. Obliczy� ile student�w przyzna�o ka�d� z ocen. W tym celu zadeklarowa� 11 -to elementow� tablic� ocena, i-ty element tej tablicy zawiera ilo�� student�w kt�rzy dali t� ocen�.

    6. Obliczy� kt�r� ocen� studenci przyznali najwi�ksz� ilo�� razy. Je�eli by�o kilka takich ocen wypisa� wszystkie.

    7. Narysowa� histogram z�o�ony z '*' (Histogram pokazuje liczebno�ci poszczeg�lnych grup).*/
    int student[100];
    int tab_howmuch[11];
    zad1(&student[100]);
    zad2(&student[100]);
    zad3(&student[100]);
    zad4(&student[100]);
    zad5(&student[100], &tab_howmuch[11]);
    zad6(&student[100], &tab_howmuch[11]);
    zad7(&student[100], &tab_howmuch[11]);

    return 0;
}

void zad1(int tab[]){
    cout<<"Zadanie 1\n";
    srand (time(NULL));
    for(int i=0; i<100; i++){
        tab[i]=rand()%11;
    }
    cout<<"Wartosci Tablicy zostaly pomyslnie wygenerowane pseudolosowo :) \n\n\n";
}

void zad2(int tab[]){
    cout<<"Zadanie 2\n";
    for(int i=0; i<100; i++){
        cout<<"Ocena Studenta nr "<<i+1<<": "<<tab[i]<<"\n";
    }
    cout<<"\n\n\n";
}

void zad3(int tab[]){
    cout<<"Zadanie 3\n";
    int suma = 0;
    for(int i=0; i<100; i++){
        suma+=tab[i];
    }
    cout<<"Suma ocen wynosi: "<<suma<<"\n";
    double srednia = (suma/100.0);
    cout<<"Srednia ocen wynosi: "<<srednia<<"\n";
    cout<<"\n\n\n";
}

void zad4(int tab[]){
    cout<<"Zadanie 4\n";
    for(int i=100; i>0; i--){
        for(int j=0; j<100; j++){
            if(tab[j]>tab[j+1]){
                swap(tab[j], tab[j+1]);
            }
        }
    }

    for(int i=0; i<100; i++){
        cout<<"Ocena na miejscu nr "<<i+1<<": "<<tab[i]<<"\n";
    }

    double mediana = (tab[49]+tab[50])/2.0;
    cout<<"Mediana posortowanej tablicy wynosi: "<<mediana<<"\n";
    cout<<"\n\n\n";
}

void zad5(int tab[], int tab_much[]){
    cout<<"Zadanie 5\n";
    int Mr_buffor;
    for(int i=0; i<11; i++)tab_much[i]=0;

    for(int i=0; i<100; i++){
        Mr_buffor=tab[i];
        tab_much[Mr_buffor]+=1;
    }

    int suma_kontrolna = 0;
    for(int i=0; i<11; i++){
            cout<<"Ocene "<<i<<" przyznalo sobie: "<<tab_much[i]<<" uczniow"<<"\n";
            suma_kontrolna+=tab_much[i];
    }
    cout<<"Suma kontrolna wynosi: "<<suma_kontrolna<<"\n";
    cout<<"\n\n\n";
}

void zad6(int tab[], int tab_much[]){
    cout<<"Zadanie 6\n";
    int max = tab_much[0];
    for(int i=0; i<10; i++){
        if(tab_much[i+1]>max){
            max=(tab_much[i+1]);
        }
    }

    for(int i=0; i<11; i++){
        if(tab_much[i]==max){
            cout<<"Najwieksza liczbe razy wylosowano ocene: "<<i<<"\n";
        }
    }
    cout<<"\n\n\n";
}

void zad7(int tab[], int tab_much[]){
    string axis1 = "Ocena";
    string axis2 = "Liczba Ocen";
    for(int i = 0; i<=10; i++){
        cout<<setw(5)<<axis1<<setw(1)<<" "<<setw(2)<<i<<setw(2)<<": ";
        for(int j = tab_much[i]; j>0; j--){
            cout<<"*";
        }
        cout<<"\n";
    }
    cout<<setw(15)<<axis2;
    cout<<"\n\n\n";
}

