//Piotr Janiszek - 247678
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
void programs(bool init);
void test_ifend(bool init);

struct Pisarz{
    int rok_urodzenia;
    char nazwisko[20];
};

struct Ksiazka{
    char tytul[50];
    int rok_wydania;
    char rodzaj[20];
    Pisarz* autor;
};
Ksiazka ksiazki[10] = {};
void getPisarz(Pisarz* autor){
    cout<<autor->nazwisko<<" urodzony/a w "<<autor->rok_urodzenia<<" roku\n";
}

void getKsiazka(Ksiazka dzielo){
    cout<<"tytul: "<<dzielo.tytul<<" - rok wydania "<<dzielo.rok_wydania<<", autor ";
    getPisarz(dzielo.autor);
}

void Zapisz_Ksiazki(char* nazwisko_autora, Ksiazka* ksiazki) {
    ofstream plik("ksiazki_autora.txt");

    for (int i = 0; i < 10; i++) {
        if (strcmp(ksiazki[i].autor->nazwisko, nazwisko_autora) == 0) {
            plik << ksiazki[i].tytul;
            plik << " ";
            plik << ksiazki[i].rok_wydania;
            plik << " ";
            plik << ksiazki[i].rodzaj;
            plik << endl;
        }
    }

    plik.close();
}

void wypisz(char* rodzaj, Ksiazka* Tab){
    for(int i = 0; i < 10; i++){
        if(strcmp(rodzaj, Tab[i].rodzaj)==0){
            cout<<Tab[i].tytul<<" - ";
            cout<<Tab[i].rok_wydania<<endl;
        }
    }
}

void alfabetycznie(Ksiazka* ksiazki){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 9; j++) {
            if(strcmp(ksiazki[j].autor->nazwisko, ksiazki[j + 1].autor->nazwisko)>0) {
                swap(ksiazki[j], ksiazki[j + 1]);
            }
        }
    }
}

int main()
{
    bool init = false;
    programs(init);

    return 0;
}

void test_ifend(bool init){
    char decision;
    do{
        std::cout<<"Czy zakonczyc dzialanie programu -T/t czy powrocic do menu - N/n?\n";
        std::cin>>decision; std::cout<<"\n";
    }while(!(decision=='T'||decision=='t'||decision=='N'||decision=='n'));

    if(decision=='t'||decision=='T'){
        exit(0);
    }else if(decision=='n'||decision=='N'){
        programs(init);
    }


}void programs(bool init){
    char number;
    std::cout<<"Podaj numer zadania \n";
    std::cout<<"Do wyboru: \n";
    std::cout<<"1. Wypelnienie tablicy danymi z pliku\n";
    std::cout<<"2. Wypisanie na ekran tablicy ksiazek\n";
    std::cout<<"3. Zapis do pliku ksiazek danego autora\n";
    std::cout<<"4. Sortowanie alfabetyczne wedlug autorow i zapis do pliku\n";
    std::cout<<"5. Wypisywanie na ekran ksiazek wybranego rodzaju (zwroc szczegolna uwage przy wpisywaniu na wielkosc znakow, musi sie zgadzac 1:1 z tymi w wypisanej tablicy\n";
    std::cin>>number; std::cout<<"\n";
    switch(number){
        case '1':{ //Zadanie 1
            ifstream plik("ksiazki.txt");
            if (plik.is_open()) {
                for (auto & i : ksiazki) {
                    string tytul;
                    getline(plik, tytul);
                    strcpy(i.tytul, tytul.c_str());

                    plik >> i.rok_wydania;
                    plik >> i.rodzaj;
                    i.autor = new Pisarz;
                    plik >> i.autor->rok_urodzenia;
                    plik >> i.autor->nazwisko;

                    string reszta_wiersza;
                    getline(plik, reszta_wiersza);
                }
                plik.close();
                init = true;
            } else {
                cout << "Nie można otworzyć pliku ksiazki.txt" << endl;
            }
            test_ifend(init);
        }
            break;
        case '2':{ //Zadanie 2
            if(init){
                for(const auto & i : ksiazki){
                    getKsiazka(i);
                }
            } else {
                std::cout<<"Pierw zainicjalizuj tablice - zadanie nr 1\n";
                test_ifend(init);
            }
            test_ifend(init);
        }
            break;
        case '3':{ //Zadanie 3
            if(init){
                char autor[20];
                cout<<"Podaj nazwisko autora, ktorego ksiazki chcesz zapisac do pliku: ";
                cin>>autor;

                Zapisz_Ksiazki(autor, ksiazki);
            } else {
                std::cout<<"Pierw zainicjalizuj tablice - zadanie nr 1\n";
                test_ifend(init);
            }
            test_ifend(init);
        }
            break;
        case '4':{ //Zadanie 4
            if(init){
                alfabetycznie(ksiazki);

                ofstream plik3("alfabetycznie.txt");
                if (plik3.is_open()) {
                    for (auto & i : ksiazki) {
                        plik3<<i.tytul<<" "<<i.rodzaj<<" "<<i.rok_wydania<<" "<<i.autor->rok_urodzenia<<" "<<i.autor->nazwisko<<endl;
                    }
                    plik3.close();
                } else {
                    cout << "Nie można otworzyć pliku ksiazki.txt" << endl;
                }
            } else {
                std::cout<<"Pierw zainicjalizuj tablice - zadanie nr 1\n";
                test_ifend(init);
            }
            test_ifend(init);
        }
            break;
        case '5':{ //Zadanie 5
            if(init){
                cout<<"Podaj rodzaj do wyszukania ksiazek";
                char rodzaj_ksiazki[20];
                cin>>rodzaj_ksiazki;
                wypisz(rodzaj_ksiazki, ksiazki);
            } else {
                std::cout<<"Pierw zainicjalizuj tablice - zadanie nr 1\n";
                test_ifend(init);
            }
            test_ifend(init);
        }
            break;
        default:
            std::cout<<"Podaj wartosc przyporzadkowana do ktoregos zadania\n\n";
            programs(init);
            break;
    }
}