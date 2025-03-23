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
    /*Napisaæ funkcjê:
    obliczaj¹c¹ silniê n! w sposób iteracyjny oraz rekurencyjny,
    obliczaj¹c¹ wartoœæ symbolu Newtona – wykorzystaæ poprzedni¹ funkcjê,
    wyœwietlaj¹c¹ trójk¹t Pascala o podanej liczbie wierszy.*/
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
    /*Zdefiniowaæ dwie zmienne a i b. Napisaæ funkcjê zeruj¹c¹ podane wartoœci i wyœwietlaj¹c¹ je przed i po zerowaniu. Utworzyæ dwie wersjê takiej funkcji, ró¿ni¹ce siê sposobem przekazywania jednego z argumentów:
    przekazaæ argumenty przez wartoœæ,
    jeden z argumentów przekazaæ przez referencjê.
    Wyœwietliæ wartoœci parametrów a i b przed wywo³aniem funkcji, wywo³aæ funkcjê od a i b, wyœwietliæ wartoœci a i b po wywo³aniu funkcji.*/
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
    /*Gracz rzuca dwie koœci. Kiedy koœci zostaj¹ rzucone obliczana jest suma oczek.
    Jeœli przy pierwszym rzucie suma wynosi 7 lub 11 gracz wygrywa. Jeœli suma oczek przy pierwszym rzucie wynosi 2, 3 lub 12 gracz przegrywa.
    Jeœli suma oczek wynosi 4, 5, 6, 8, 9, 10 wtedy suma staje siê „punktami” gracz. Chc¹c wygraæ musi on kontynuowaæ rzucanie koœæmi a¿ do uzyskania „swoich punktów” tzn. do momentu a¿ wyrzuci poprzedni¹ liczbê oczek.
    Gracz przegrywa wyrzucaj¹c 7 przed uzyskaniem „swoich punktów”.
    Napisaæ funkcjê, która symuluje rzut dwiema koœæmi. Gracz ma na pocz¹tku 100 z³, za ka¿d¹ przegran¹ traci 20 z³ a za wygran¹ dostaje 30 z³. Zasymulowaæ 10 rund gry.*/
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
    /*Do przybli¿onego przeliczania daty z kalendarza muzu³mañskiego na gregoriañski s³u¿y formu³a: G=M-M/33+621, gdzie G jest numerem roku gregoriañskiego, M jest numerem roku muzu³mañskiego.
    W celu przeliczenia odwrotnego stosuje siê formu³ê: M=G-621+(G-621)/32. W programie stworzyæ funkcjê void przelicz(int* wskG, int* wskM, bool MtoG), która dzia³a jak nastêpuje:
    jeœli MtoG=true, to funkcja pobiera numer roku muzu³mañskiego (ze zmiennej wskazywanej przez wskM), oblicza numer roku gregoriañskiego i umieszcza wynik w miejscu wskazywanym przez wskG,
    jeœli MtoG=false, to funkcja pobiera numer roku gregoriañskiego (ze zmiennej wskazywanej przez wskG), oblicza numer roku muzu³mañskiego i umieszcza wynik w miejscu wskazywanym przez wskM,
    Program ma pytaæ u¿ytkownika czy chce przeliczyæ datê gregoriañsk¹ na muzu³mañsk¹, czy odwrotnie. Nastêpnie przelicza datê przy pomocy funkcji przelicz. Przy pomocy programu przeliczyæ nastêpuj¹ce daty:

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
    /*Napisz program, który wczytuje liczbê 0 <= n <= 100 000 i wypisuje j¹ w siódemkowym systemie liczbowym. Zadbaj o prawid³owe wypisywanie zera.
    Wskazówka: cyfry ³atwiej generowaæ od najm³odszych, czyli „od koñca”. Ze wzglêdu na ograniczenia n mo¿na jednak a priori oszacowaæ, ile ich bêdzie.
    Alternatywna wskazówka: cia³o funkcji mo¿e zawieraæ wywo³anie jej samej (rekurencjê).*/
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
