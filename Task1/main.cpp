//Piotr Adam Janiszek - 247678 //IDE - CLION
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
void wybor(char &number);
void koniec(char &number);
void programy(char &number);

int main()
{
    char number;
    wybor(number);

    return 0;
}

void wybor(char &number) {
    std::cout << "1. Przeliczanie radianow na stopnie." << std::endl;
    std::cout << "2. obliczanie sumy, srefniej arytmetycznej i harmonicznej podanych 3 liczb." << std::endl;
    std::cout << "3. Obliczanie objetosci kuli i stozka." << std::endl;
    std::cout << "4. Sprawdzenie, czy rok jest przestepny" << std::endl;
    std::cout << "5. Obliczanie rozwiazan rownanie kwadratowego" << std::endl;
    std::cout << "Podaj numer zadania z zakresu <1; 5>, tylko liczby calkowite, zadnych literek czy ulamkow" << std::endl;
    std::cin >> number;
    std::cout << std::endl;
    programy(number);
}

void koniec(char &number){
    char option;
    do{
        std::cout<<"Czy zakonczyc dzialanie programu? t/T dla Tak, n/N dla nie: ";
        std::cin>>option;
    }while(!option=='t'||!option=='T'||!option=='n'||!option=='N');


    if(option=='N'||option=='n'){
        wybor(number);
    } else if(option=='T'||option=='t'){
        exit('Koniec zarzadzony przez uzytkownika');
    }
}

void programy(char &number){
    switch(number){
        case '1':{
            /*Napisz program przeliczajacy podana przez uzytkownika wielkosæ kata wyrazona w stopniach na radiany i wyswietlajacy ja na ekranie.*/
            double kat;
            std::cout<<"Podaj wielkosc kata wyrazona w stopniach"<<std::endl;
            std::cin>>kat;
            kat=kat*M_PI/180.0;
            std::cout<<"Podany kat w radianach wynosi "<<kat<<std::endl;
            koniec(number);
        }
            break;
        case '2':{
            /*Napisz program, ktory wczytuje trzy liczby calkowite, oblicza ich sume, srednia arytmetyczna i srednia harmoniczna oraz wyswietla je na ekranie.*/
            double number1, number2, number3;
            std::cout<<"Podaj trzy liczby calkowite"<<std::endl;
            std::cout<<"Liczba pierwsza: "; std::cin>>number1; std::cout<<std::endl;
            std::cout<<"Liczba druga: "; std::cin>>number2; std::cout<<std::endl;
            std::cout<<"Liczba trzecia: "; std::cin>>number3; std::cout<<std::endl;
            double suma = (number1 + number2 + number3);
            double sr_ar = (number1 + number2 + number3)/3.0;
            double sr_har = 3/(1.0/number1 + 1.0/number2 + 1.0/number3);
            std::cout<<"Suma podanych liczb wynosi "<<suma<<", srednia arytmetyczna "<<sr_ar<<", zas srednia harmoniczna "<<sr_har<<std::endl;
            koniec(number);
        }
            break;
        case '3':
        {
            /*Napisz program obliczajacy i wyswietlajacy na ekranie objetosæ kuli oraz stozka. Promien kuli/stozka oraz wysokosæ stozka nalezy wczytaæ z klawiatury.*/
            double r_kuli, r_stozka, h_stozka;
            std::cout<<"Podaj promien dla kuli: "<<std::endl; std::cin>>r_kuli;
            std::cout<<"Podaj promien dla stozka: "<<std::endl; std::cin>>r_stozka;
            std::cout<<"Podaj wysokosc dla stozka: "<<std::endl; std::cin>>h_stozka;
            std::cout<<"Objetosæ kuli wynosi: "<<(4.0/3.0*pow(r_kuli, 3)* M_PI); std::cout<<std::endl;
            std::cout<<"Objetosæ stozka wynosi: "<<(1.0/3.0* M_PI*pow(r_stozka, 2)*h_stozka); std::cout<<std::endl;
            koniec(number);
        }
            break;
        case '4':{
            /*Rok jest przestepny, jesli spelniony jest jeden z ponizszych warunkow: • Jest podzielny przez 4 i jednoczesnie nie jest podzielny przez 100 •
             * Jest podzielny przez 400 Napisz program, ktory wczytuje podany przez uzytkownika rok i wyswietla komunikat, czy rok jest przestepny.
             * Program powinien sprawdziæ, czy podana przez uzytkownika wartosæ jest dodatnia.*/
            int rok;
            do{std::cout<<"Podaj rok do sprawdzenia: "; std::cin>>rok; std::cout<<std::endl;}
            while(rok<=0);
            if(((rok%4==0)&&!(rok%100==0))||(rok%400==0)){
                std::cout<<"Podany rok - "<<rok<<" - jest przestepny "; std::cout<<std::endl;
            } else {
                std::cout<<"Podany rok - "<<rok<<" - nie jest przestepny "; std::cout<<std::endl;
            }
            koniec(number);
        }
            break;
        case '5':{
            /*Napisz program wczytujacy wartosci wspolczynnikow a, b i c i rozwiazujacy rownanie ax2 + bx + c = 0.
             * Uwzglednij przypadek, gdy dla a = 0 rownanie jest liniowe.*/
            double a, b, c;
            do {
                std::cout << "Podaj wspolczynnik a: ";
                std::cin >> a;
                std::cout << std::endl;
                std::cout << "Podaj wspolczynnik b: ";
                std::cin >> b;
                std::cout << std::endl;
                std::cout << "Podaj wspolczynnik c: ";
                std::cin >> c;
                std::cout << std::endl;
                if(a==0&&b==0&&!c==0) std::cout<<"Przystopuj kolego, bo doprowadzisz do sprzecznosci\n";
                if(a==0&&b==0&&c==0) std::cout<<"Nieoznaczonego rownania 0=0, to my nie chcemy\n";
            }
            while(a==0&&b==0||a==0&&b==0&&c==0);

            if(a==0){
                double x;
                x = -c/b;
                std::cout<<"Podane rownanie jest liniowe ze wzgledu na wspolczynnik a rowny 0, a jego rozwiazanie to: "<<x<<std::endl;
            } else {
                double delta;
                delta = pow(b, 2.0)-4.0*a*c;
                std::cout<<"Delta z rownania wynosi: "<<delta<<std::endl;
                if(delta>0){
                    double x1, x2, pierw_z_delty;
                    pierw_z_delty = sqrt(delta);
                    x1 = ((-1)*b - pierw_z_delty)/(2*a);
                    x2 = ((-1)*b + pierw_z_delty)/(2*a);
                    std::cout<<"Rozwiazaniami podanego rowniania w zbiorze liczb rzeczywistych sa wartosci: "<<x1<<" oraz "<<x2<<std::endl;
                } else if(delta==0){
                    double x;
                    x = -b/(2*a);
                    std::cout<<"Rozwiazaniami podanego rowniania w zbiorze liczb rzeczywistych jest wartosc: "<<x<<std::endl;
                } else if(delta<0){
                    std::cout<<"Podane rownanie nie ma rozwiazan w zbiorze liczb rzeczywistych"<<std::endl;
                }

            }
            koniec(number);
        }
            break;
        default:
            std::cout<<"Podaj poprawna wartosc liczbowa"<<std::endl;
            wybor(number);
            break;
    }
}

