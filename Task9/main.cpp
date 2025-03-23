#include <iostream>
#include <fstream>
#include <string>
void choose(char &number);
void programs(char &number);
void test_ifend();
//Piotr Janiszek - 247678
using namespace std;

struct osoba{
    char imie[10];
    char nazwisko[20];
    int wiek;
};

struct pies{
    char imie[10];
    int wiek;
    double masa;
};

struct Pisarz{
    int rok_urodzenia;
    char imie[12];
    char nazwisko[20];
};

struct Ksiazka{
    char tytul[20];
    int rok_wydania;
    Pisarz* autor;
};

pies get1(pies piesek){
    cout<<"\n\n";
    cout<<"Pies "<<piesek.imie<<" ma "<<piesek.wiek<<" lat i wazy "<<piesek.masa<<" kg\n\n";
    return piesek;
}

pies set1(){
    pies piesek;
    cout<<"\n\n";
    cout << "Podak imie dla psa\n";
    cin >> piesek.imie;

    cout << "Podak wiek dla psa\n";
    cin >> piesek.wiek;

    cout << "Podak mase dla psa\n";
    cin >> piesek.masa;

    return piesek;
}

pies set2(char imie[10], int wiek, double masa){
    pies doggo;
    cout<<"\n\n";
    for(int i=0; i<10; i++)
    doggo.imie[i] = imie[i];

    doggo.wiek = wiek;

    doggo.masa = masa;

    return doggo;
}

void getPisarz(Pisarz Artysta){
    cout<<Artysta.imie<<" "<<Artysta.nazwisko<<" urodzony/urodzona w "<<Artysta.rok_urodzenia<<" roku "<<"\n";
}

void getKsiazka(Ksiazka Dzielo){
    cout<<"Ksiazka "<<Dzielo.tytul<<" wydana w roku "<<Dzielo.rok_wydania<<" przez: ";
    getPisarz(*Dzielo.autor);
}

int main(){
    char number;
    choose(number);


    return 0;
}

void choose(char &number){
    std::cout<<"Podaj numer zadania \n";
    std::cout<<"Do wyboru: \n";
    std::cout<<"1. Struktura dla danych personalnych wybranej osoby\n";
    std::cout<<"2. struktura, wprowadzanie danych do obiektow struktury, zapis do pliku elementow struktury na przykladzie pupili\n";
    std::cout<<"3. Pisarze i ich ksiazki z uzyciem struktur\n";
    std::cin>>number; std::cout<<"\n";
    programs(number);
}

void test_ifend(){
    char number; char decision;
    do{
        std::cout<<"Czy zakonczyc dzialanie programu czy powrocic do poczatku?\n";
        std::cout<<"T/t dla Tak, N/n dla nie\n";
        std::cin>>decision; std::cout<<"\n";
    }while(!(decision=='T'||decision=='t'||decision=='N'||decision=='n'));

    if(decision=='t'||decision=='T'){
        exit(0);
    }else if(decision=='n'||decision=='N'){
        choose(number);
    }
}

void programs(char &number){
    switch(number){
        case '1':{ //Zadanie 1
            osoba persona;
            cout << "Podak imie dla osoby\n";
            cin >> persona.imie;

            cout << "Podak nazwisko dla osoby\n";
            cin >> persona.nazwisko;

            cout << "Podak wiek dla osoby\n";
            cin >> persona.wiek;


            cout<<"Dane personalne wprowadzonej osoby: \n";
            cout<<"\nImie: "<<persona.imie<<"\nNazwisko: "<<persona.nazwisko<<"\nWiek: "<<persona.wiek<<"\n";
            cout<<"\n\n";

            test_ifend();
        }
            break;
        case '2':{ //Zadanie 2
            pies pupile[3];
            pupile[0]=set1();
            pupile[1]=set2("Azor", 12, 23);
            pupile[2]=set2("Rex", 6, 16);

            for(auto & i : pupile)
                get1(i);

            ofstream plik("imiona.txt");
            if(plik.is_open()){
                std::cout << "Uzyskano autoryzowany dostep do pliku!" << endl;
                for(int i = 0; i < 3; i++){
                    plik << pupile[i].imie << endl;
                }
                plik.close();
            }else std::cout << "Dostep do pliku zostal zabroniony!" << endl;

            test_ifend();
        }
            break;
        case '3':{ //Zadanie 3
            Pisarz Autorzy[3] = {{1957, "Adam", "Nawalka"}, {1798, "Adam", "Mickiewicz"}, {1977, "Adam", "Malysz"}};

            Ksiazka Ksiegi[4] = {{"Laga na Lewego", 2017, &Autorzy[0]}, {"Dziady Czesc 2", 1823, &Autorzy[1]}, {"Skoki od podszewki", 2012, &Autorzy[2]}, {"Pan Tadeusz",1834, &Autorzy[1]}};

            std::cout << "Autorzy:" << std::endl;
            for (int i = 0; i < 3; i++) {
                getPisarz(Autorzy[i]);
            }

            std::cout << "Ksiazki:" << std::endl;
            for (int i = 0; i < 4; i++) {
                getKsiazka(Ksiegi[i]);
            }

            test_ifend();
        }
            break;
        default:
            std::cout<<"Podaj wartosc przyporzadkowana do ktoregos zadania\n\n";
            choose(number);
            break;
    }
}