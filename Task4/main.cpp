#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
//Piotr Janiszek - 247678 //IDE - CLION

void choose(char &number);
void programs(char &number);
void test_ifend();
void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
double zad1_rekurencja(double number_rek, double silnia_rek, double i_rek);
void przelicz(int *wskG, int *wskM, bool MtoG);

int main()
{
    char number;
    choose(number);
    return 0;
}

void choose(char &number){
    std::cout<<"Podaj numer zadania \n";
    std::cout<<"Do wyboru: \n";
    std::cout<<"1. Silnia i trojkat pascala\n";
    std::cout<<"2. Zerowanie zmiennych\n";
    std::cout<<"3. Gra Hazardowa\n";
    std::cout<<"4. Przeliczanie kalendarzy\n";
    std::cout<<"5. Przeliczanie liczby z systemu dziesiatkowego na siodemkowy\n";
    std::cin>>number; std::cout<<"\n";
    programs(number);
}

void test_ifend(){
    char number; char decision;
    do{
        std::cout<<"Czy zakonczyc dzialanie programu? W przeciwnym wypadku wrocisz do menu.\n";
        std::cout<<"T/t dla Tak, N/n dla nie\n";
        std::cin>>decision; std::cout<<"\n";
    }while(!(decision=='T'||decision=='t'||decision=='N'||decision=='n'));

    if(decision=='t'||decision=='T'){
        exit(0);
    }else if(decision=='n'||decision=='N'){
        programs(number);
    }
}

void programs(char &number){
    switch(number){
        case '1':{ //Zadanie 1
            zad1();
            test_ifend();
        }
            break;
        case '2':{ //Zadanie 2
            zad2();
            test_ifend();
        }
            break;
        case '3':{ //Zadanie 3
            zad3();
            test_ifend();
        }
            break;
        case '4':{ //Zadanie 4
            zad4();
            test_ifend();
        }
            break;
        case '5':{ //Zadanie 5
            zad5();
            test_ifend();
        }
            break;
        default:
            std::cout<<"Podaj wartosc przyporzadkowana do ktoregos zadania\n\n";
            choose(number);
            break;
    }
}
int Wartosc_Tego_Pola(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    else
        return (Wartosc_Tego_Pola(n - 1, k - 1) + Wartosc_Tego_Pola(n - 1, k));
}

void zad1(){
    /*Napisa� funkcj�:
    obliczaj�c� silni� n! w spos�b iteracyjny oraz rekurencyjny,
    obliczaj�c� warto�� symbolu Newtona � wykorzysta� poprzedni� funkcj�,
    wy�wietlaj�c� tr�jk�t Pascala o podanej liczbie wierszy.*/
    int number, rows;
    double silnia = 1;
    do{std::cout<<"Podaj liczbe do obliczenia silni\n"; std::cin>>number;}while(number<0);
    do{std::cout<<"Podaj liczbe wierszy do wyswietlenia trojkata pascala - Max 19\n"; std::cin>>rows;}while(rows<1);

    //sposob iteracyjny
    for(int i=1; i<=number; i++){
        silnia*=i;
    }
    std::cout<<"Wynik silni z liczby "<<number<<" dzialaniem iteracyjnym, to: "<<silnia<<"\n";

    std::cout<<"Wynik silni z liczby "<<number<<" dzialaniem rekurencyjnym, to: "<<zad1_rekurencja(number, 1, 1)<<"\n";




    std::cout<<"\nTrojkat Pascala\n";

    for(int n = 0; n<rows; n++){
        std::cout << std::setw(2) << n << std::setw(3 * (rows - n)) << "";
        for (int k = 0; k <= n; k++)
            std::cout << std::setw(6) << Wartosc_Tego_Pola(n, k);
        std::cout << std::endl;
    }
}

double zad1_rekurencja(double number_rek, double silnia_rek, double i_rek){
    if(i_rek>number_rek){
        return silnia_rek;
    } else if(i_rek<=number_rek){
        silnia_rek*=i_rek;
        i_rek++;
        zad1_rekurencja(number_rek, silnia_rek, i_rek);
    }
}

int zad2_1(int c){
    c = 0;
    return c;
}

int zad2_2(int* c){
    *c = 0;
    return *c;
}


void zad2(){
    /*Zdefiniowa� dwie zmienne a i b. Napisa� funkcj� zeruj�c� podane warto�ci i wy�wietlaj�c� je przed i po zerowaniu. Utworzy� dwie wersj� takiej funkcji, r�ni�ce si� sposobem przekazywania jednego z argument�w:
    przekaza� argumenty przez warto��,
    jeden z argument�w przekaza� przez referencj�.
    Wy�wietli� warto�ci parametr�w a i b przed wywo�aniem funkcji, wywo�a� funkcj� od a i b, wy�wietli� warto�ci a i b po wywo�aniu funkcji.*/
    int a, b;
    std::cout<<"Podaj wartosc dla zmiennej a: "; std::cin>>a; int c = a;
    std::cout<<"Podaj wartosc dla zmiennej b: "; std::cin>>b; int d = b;

    std::cout<<"Wartosc zmiennej a przed operacja zerowania: "<<a<<"\n";
    std::cout<<"Wartosc zmiennej b przed operacja zerowania: "<<b<<"\n\n";

    zad2_1(a);
    zad2_1(b);

    std::cout<<"Wartosc zmiennej a po operacji zerowania: "<<a<<"\n";
    std::cout<<"Wartosc zmiennej b po operacji zerowania: "<<b<<"\n\n";

    std::cout<<"Wartosc zmiennej a przed operacja zerowania przez referencje: "<<a<<"\n";
    std::cout<<"Wartosc zmiennej b przed operacja zerowania przez referencje: "<<b<<"\n\n";

    zad2_2(&a);
    zad2_2(&b);

    std::cout<<"Wartosc zmiennej a po operacji zerowania przez referencje: "<<a<<"\n";
    std::cout<<"Wartosc zmiennej b po operacji zerowania przez referencje: "<<b<<"\n\n";

    a = c;
    b = d;

    std::cout<<"Wartosc zmiennej a przed operacja zerowania: "<<a<<"\n";
    std::cout<<"Wartosc zmiennej b przed operacja zerowania przez referencje: "<<b<<"\n\n";

    zad2_1(a);
    zad2_2(&b);

    std::cout<<"Wartosc zmiennej a po operacji zerowania: "<<a<<"\n";
    std::cout<<"Wartosc zmiennej b po operacji zerowania przez referencje: "<<b<<"\n\n";
}


void zad3(){
    /*Gracz rzuca dwie ko�ci. Kiedy ko�ci zostaj� rzucone obliczana jest suma oczek.
    Je�li przy pierwszym rzucie suma wynosi 7 lub 11 gracz wygrywa. Je�li suma oczek przy pierwszym rzucie wynosi 2, 3 lub 12 gracz przegrywa.
    Je�li suma oczek wynosi 4, 5, 6, 8, 9, 10 wtedy suma staje si� �punktami� gracz. Chc�c wygra� musi on kontynuowa� rzucanie ko��mi a� do uzyskania �swoich punkt�w� tzn. do momentu a� wyrzuci poprzedni� liczb� oczek.
    Gracz przegrywa wyrzucaj�c 7 przed uzyskaniem �swoich punkt�w�.
    Napisa� funkcj�, kt�ra symuluje rzut dwiema ko��mi. Gracz ma na pocz�tku 100 z�, za ka�d� przegran� traci 20 z� a za wygran� dostaje 30 z�. Zasymulowa� 10 rund gry.*/
    int a, b;
    int iteration = 1;
    srand(time(NULL));
    int money = 100;
    a = rand()%6 + 1;
    b = rand()%6 + 1;
    int c = a + b;
    std::cout<<"Proba numer: "<<iteration<< "\n";
    std::cout<<"Wylosowano wartosci: "<<a<<", "<<b<<", co daje razem: "<<(a+b)<< "\n";

    if ((a + b) == 7 || (a + b) == 11) {
        std::cout << "Brawo, wygrales! Wylosowales sume: " << (a + b) << "\n";
        money += 30;
        std::cout<<"Twoj stan konta wynosi: "<<money<< "\n";
        test_ifend();
    } else if ((a + b) == 2 || (a + b) == 3 || (a + b) == 12) {
        std::cout << "Coz, przegrales, moze nastepnym razem Ci sie uda :( Wylosowales sume: " << (a + b) << "\n";
        money -= 20;
        std::cout<<"Twoj stan konta wynosi: "<<money<< "\n";
        test_ifend();
    } else {
        do {
            iteration++;
            std::cout<<"Proba numer: "<<iteration<< "\n";
            a = rand() % 6 + 1;
            b = rand() % 6 + 1;
            std::cout << "Wylosowano wartosci: " << a << ", " << b << ", co daje razem: " << (a + b) << "\n";
            if ((a + b == c)) {
                std::cout << "Brawo, wygrales! Wylosowales sume: " << (a + b) << "\n";
                money += 30;
                std::cout << "Twoj stan konta wynosi: " << money << "\n";
                test_ifend();
            } else if ((a + b) == 7) {
                std::cout << "Coz, przegrales, moze nastepnym razem Ci sie uda :( Wylosowales sume: " << (a + b)
                          << "\n";
                money -= 20;
                std::cout << "Twoj stan konta wynosi: " << money << "\n";
                test_ifend();
            }
        } while (iteration < 10);
        std::cout << "Twoj stan konta wynosi niezmiennie: " << money << "\n";
    }
}
void zad4(){
    /*Do przybli�onego przeliczania daty z kalendarza muzu�ma�skiego na gregoria�ski s�u�y formu�a: G=M-M/33+621, gdzie G jest numerem roku gregoria�skiego, M jest numerem roku muzu�ma�skiego.
    W celu przeliczenia odwrotnego stosuje si� formu��: M=G-621+(G-621)/32. W programie stworzy� funkcj� void przelicz(int* wskG, int* wskM, bool MtoG), kt�ra dzia�a jak nast�puje:
    je�li MtoG=true, to funkcja pobiera numer roku muzu�ma�skiego (ze zmiennej wskazywanej przez wskM), oblicza numer roku gregoria�skiego i umieszcza wynik w miejscu wskazywanym przez wskG,
    je�li MtoG=false, to funkcja pobiera numer roku gregoria�skiego (ze zmiennej wskazywanej przez wskG), oblicza numer roku muzu�ma�skiego i umieszcza wynik w miejscu wskazywanym przez wskM,
    Program ma pyta� u�ytkownika czy chce przeliczy� dat� gregoria�sk� na muzu�ma�sk�, czy odwrotnie. Nast�pnie przelicza dat� przy pomocy funkcji przelicz. Przy pomocy programu przeliczy� nast�puj�ce daty:

    M=170A.H., G=?
    G=1258A.D., M=?*/
    int rok, rokG, rokM; bool MtoG;
    do{
        std::cout<<"Czy dany rok zostal podany w systemie gregorianskim '0' czy muzulmanskim '1': ";
        std::cin>>MtoG;
    }while(!(MtoG==0||MtoG==1));
    std::cout<<"Podaj rok do przeliczenia: "; std::cin>>rok;

    if(MtoG==false){
        int rokG = rok;
        przelicz(&rokG, &rokM, MtoG);
    }else if(MtoG==true){
        int rokM = rok;
        przelicz(&rokG, &rokM, MtoG);
    }
}

void przelicz(int* wskG, int* wskM, bool MtoG){
    if(MtoG==false){
        *wskM = *wskG - 621 + (*wskG - 621) / 32;
        std::cout << "data muzulmanska z tego roku to: " << *wskM<< "\n";
    }else if(MtoG==true){
        *wskG = *wskM - *wskM / 33 + 621;
        std::cout << "data gregorianska z tego roku to: " << *wskG<< "\n";
    }
}
void zad5(){
    /*Napisz program, kt�ry wczytuje liczb� 0 <= n <= 100 000 i wypisuje j� w si�demkowym systemie liczbowym. Zadbaj o prawid�owe wypisywanie zera.
    Wskaz�wka: cyfry �atwiej generowa� od najm�odszych, czyli �od ko�ca�. Ze wzgl�du na ograniczenia n mo�na jednak a priori oszacowa�, ile ich b�dzie.
    Alternatywna wskaz�wka: cia�o funkcji mo�e zawiera� wywo�anie jej samej (rekurencj�).*/
    int number;
    do{
        std::cout<<"Wprowadz liczbe calkowita z zakresu <0, 100 000>, a ja przelicze ja(komputer) na system siodemkowy: "<< "\n";
        std::cin>>number;
    }while(number>100000||number<0);
    int TabMax[6];
    for(int i=0; i<8; i++)TabMax[i]=0;


    for(int i = 5; i>=0; i--){
        TabMax[i]=(number%7);
        number=number/7;
    }

    std::cout<<"Podana liczba w systemie siodemkowym to: ";
    for(int i = 0; i<=5; i++){
        std::cout<<" "<<TabMax[i];
    }

    std::cout<<"\n";
}
