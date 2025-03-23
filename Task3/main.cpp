#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <cstdio>
#include <string>
//247678 - Piotr Janiszek //IDE - CLION

void choose(char &number);
void programs(char &number);
void test_ifend();

int main()
{
    char number;
    choose(number);
    return 0;
}

void choose(char &number){
    std::cout<<"Podaj numer zadania \n";
    std::cout<<"Do wyboru: \n";
    std::cout<<"1. Obliczanie pol figur\n";
    std::cout<<"2. Obliczanie sinusa z podanego kata\n";
    std::cout<<"3. Tabele z wartosciami funkcji trygonometrycznych\n";
    std::cout<<"4. Sprawdzenie liczb, czy tworza trojke pitagorejska\n";
    std::cout<<"5. Najwiekszy wspolny dzielnik dwoch liczb naturalnych\n";
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
        programs(number);
    }
}

void programs(char &number) {
    switch (number) {
        case '1': { //Zadanie 1
            /*Napisać program który pobiera od użytkownika z klawiatury zmienną typu char. Następnie: - jeśli podano 'p' lub 'P'
             * komputer oblicza pole prostokąta o parametrach podanych przez użytkownika, - jeśli podano 't' lub 'T' komputer oblicza pole
             * trójkąta o parametrach podanych przez użytkownika, - jeśli podano 'k' lub 'K' komputer oblicza pole koła o parametrach podanych przez
             * użytkownika*/
            char figura;
            do{
                std::cout<<"Podaj ktorej figury pole chcesz obliczyc (p/P- prostokat, t/T - trojkat, k/K - Kolo): "; std::cin>>figura;
            }while(!(figura=='p'||figura=='P'||figura=='t'||figura=='T'||figura=='k'||figura=='K'));
            if(figura=='p'||figura=='P'){
                double pole, bok_a, bok_b;
                std::cout<<"Podaj bok a: "; std::cin>>bok_a;
                std::cout<<"Podaj bok b: "; std::cin>>bok_b;
                pole = bok_a * bok_b;
                std::cout<<"Pole prostokata o podanych wymiarach wynosi: "<<pole;
                std::cout<<"\n";
            } else if(figura=='t'||figura=='T'){
                double pole, podstawa, wysokosc;
                std::cout<<"Podaj podstawe: "; std::cin>>podstawa;
                std::cout<<"Podaj wysokosc: "; std::cin>>wysokosc;
                pole = ((podstawa * wysokosc)/2);
                std::cout<<"Pole trojkata o podanych wymiarach wynosi: "<<pole;
                std::cout<<"\n";

            } else if(figura=='k'||figura=='K'){
                double pole, promien;
                std::cout<<"Podaj promien: "; std::cin>>promien;
                pole = (pow(promien, 2) * M_PI);
                std::cout<<"Pole kola o podanych wymiarach wynosi: "<<pole;
                std::cout<<"\n";
            }

            test_ifend();
        }
            break;
        case '2': { //Zadanie 2
            /*Napisać program który pobiera od użytkownika liczbę typu double oraz zmienną typu char.
             * Następnie program oblicza sinus kąta, którego wartość podana została w zmiennej typu double, przy czym: –
             * jeśli w zmiennej typu char użytkownik wpisał 'r' lub 'R' to zakładamy, że kąt został podany w radianach, –
             * jeśli w zmiennej typu char użytkownik wpisał 's' lub 'S” to zakładamy, że kąt został podany w stopniach,
             * Program należy napisać jak najprościej, używając instrukcji switch. Funkcji sin() należy użyć w kodzie tylko jeden raz,
             * wewnątrz instrukcji switch.*/
             double number2; char test;
             do{
                std::cout<<"Podaj liczbe do obliczen\n";
                std::cin>>number2;
                std::cout<<"\n";
             }while(number2<0);
             do{
                std::cout<<"Podana liczba zostala podana w stopniach - 'S'/'s' czy radianach - 'R'/'r'";
                std::cin>>test;
                std::cout<<"\n";
             }while(!(test=='r'||test=='R'||test=='s'||test=='S'));
			 switch(test){
				 case 's':{
					double sin_wynik = sin((number2*M_PI)/180);
					std::cout<<"Wartosc sinusa z podanego kata wynosi: "<<sin_wynik;
					std::cout<<"\n";
				 }
				 break;
                 case 'S':{
                     double sin_wynik = sin((number2*M_PI)/180);
                     std::cout<<"Wartosc sinusa z podanego kata wynosi: "<<sin_wynik;
                     std::cout<<"\n";
                 }
                 break;
                 case 'R':{
					double sin_wynik = sin(number2);
					std::cout<<"Wartosc sinusa z podanego kata wynosi: "<<sin_wynik;
					std::cout<<"\n";
				 }
                 break;
                 case 'r':{
                     double sin_wynik = sin(number2);
                     std::cout<<"Wartosc sinusa z podanego kata wynosi: "<<sin_wynik;
                     std::cout<<"\n";
                 }
				 break;
			 }
            test_ifend();
        }
            break;
        case '3': { //Zadanie 3
            /*Napisać program wyświetlający na konsoli tablicę z wartościami funkcji trygonometrycznych sin, cos, tg, ctg,
             * w zakresie kątów od 0 do 90 stopni, co 15 stopni. W wersji bardziej rozbudowanej użytkownik może podać na początku co ile stopni mają
             * być liczone wartości.*/
            float odstep;
            std::cout<<"Podaj, co ile stopni maja byc liczone wartosci trygonometryczne (zaczynajac od zera): "; std::cin>>odstep;
            for(float i = 0; i<=90; i+=odstep){
                std::cout<<"Sinus z "<<i<<" stopni wynosi: "<<sin((i*M_PI)/180)<<"\n";
            }
            std::cout<<"\n";
            for(float i = 0; i<=90; i+=odstep){
                if(i==90){
                    std::cout<<"Cosinus z "<<i<<" stopni wynosi: "<<0<<"\n";
                }
                else{
                    std::cout<<"Cosinus z "<<i<<" stopni wynosi: "<<cos((i*M_PI)/180)<<"\n";
                }
            }
            std::cout<<"\n";
            for(float i = 0; i<=90; i+=odstep){
                if(i==90){
                    std::cout<<"Tangens z "<<i<<" stopni nie istnieje \n";
                } else {
                    std::cout << "Tangens z " << i << " stopni wynosi: " << tan((i * M_PI) / 180) << "\n";
                }
            }
            std::cout<<"\n";
            for(float i = 0; i<=90; i+=odstep){
                if(i==0){
                    std::cout<<"Cotangens z "<<i<<" stopni nie istnieje \n";
                } else if(i==90){
                    std::cout<<"Cotangens z "<<i<<" stopni wynosi: "<<0<<"\n";
                } else {
                    std::cout << "Cotangens z " << i << " stopni wynosi: " << (1 / tan((i * M_PI) / 180)) << "\n";
                }
            }
            std::cout<<"\n";
            test_ifend();
        }
            break;
        case '4': { //Zadanie 4
            /*Napisać funkcję przyjmującą trzy parametry a, b, c, będące liczbami całkowitymi. Funkcja zwraca wartość jeden,
             * jeśli podane liczby są liczbami pitagorejskimi oraz zero w przeciwnym wypadku.*/
             int a, b, c, d; //d - zmienna przechowujaca wynik
             do{std::cout<<"Podaj a: "; std::cin>>a;}while(a<0);
             do{std::cout<<"Podaj b: "; std::cin>>b;}while(b<0);
             do{std::cout<<"Podaj c: "; std::cin>>c;}while(c<0);
             if(a>b&&a>c){
                if(pow(a, 2)==(pow(b, 2) + pow(c, 2))){
                    d = 1;
                    std::cout<<"Podane liczby tworza trojke pitagorejska - "<<d;
                    std::cout<<"\n";
                } else {
                    d = 0;
                    std::cout<<"Podane liczby nie tworza trojki pitagorejskiej - "<<d;
                    std::cout<<"\n";
                }
             }
             if(b>c&&b>a){
                if(pow(b, 2)==(pow(a, 2) + pow(c, 2))){
                    d = 1;
                    std::cout<<"Podane liczby tworza trojke pitagorejska - "<<d;
                    std::cout<<"\n";
                } else {
                    d = 0;
                    std::cout<<"Podane liczby nie tworzą trojki pitagorejskiej - "<<d;
                    std::cout<<"\n";
                }
             }
             if(c>a&&c>b){
                if(pow(c, 2)==(pow(b, 2) + pow(a, 2))){
                    d = 1;
                    std::cout<<"Podane liczby tworza trojke pitagorejska - "<<d;
                    std::cout<<"\n";
                } else {
                    d = 0;
                    std::cout<<"Podane liczby nie tworza trojki pitagorejskiej - "<<d;
                    std::cout<<"\n";
                }
             }
            std::cout<<d<<"\n";
            test_ifend();
        }
            break;
        case '5': { //Zadanie 5
            /*Napisać funkcję zwracającą największy wspólny dzielnik dwóch liczb naturalnych przekazywanych przez parametr.*/
            unsigned int number1, number2;
            std::cout << "Wprowadz liczbe nr 1: \n";
            std::cin >> number1;
            std::cout << "Wprowadz liczbe nr 2: \n";
            std::cin >> number2;
            int i;
            if (number1 <= number2) {
                i = number1;
                for (i; i > 0; i--) {
                    if (number1 % i == 0 && number2 % i == 0) {
                        std::cout << "Największy wspólny dzielnik to: " << i;
                        break;
                    }
                    break;
                }
            } else if (number1 >= number2) {
                i = number2;
                for (i; i > 0; i--) {
                    if (number1 % i == 0 && number2 % i == 0) {
                        std::cout << "Najwiekszy wspolny dzielnik to: " << i<<"\n";
                        break;
                    }
                    break;
                }

                test_ifend();
            }
            break;
            default:
                std::cout << "Podaj wartosc przyporzadkowana do ktoregos zadania\n\n";
            choose(number);
            break;
        }
    }
}
