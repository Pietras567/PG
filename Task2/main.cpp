//Piotr Janiszek - 247678 //IDE - CLION
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <cstdio>
#include <string>


void choose(char &number);
void programs(char &number);
void test_ifend();
int silnia(int liczba);

int main()
{
    char number;
    choose(number);
    return 0;
}

void choose(char &number){
    std::cout<<"Podaj numer zadania \n";
    std::cout<<"Do wyboru: \n";
    std::cout<<"1. Dzialania na pobranej wartosci n\n";
    std::cout<<"2. Rysowanie choinek w roznych wariacjach\n";
    std::cout<<"3. Dzialanie eps(x)\n";
    std::cout<<"4. Suma dzialania, wykonywujaca sie podana liczba razy\n";
    std::cout<<"5. Dzielniki podanej liczby i weryfikacja tego, czy jest liczba pierwsza\n";
    std::cin>>number; std::cout<<"\n";
    programs(number);
}

void test_ifend(){
    char number; char decision;
    do{
        std::cout<<"Czy zakonczyc dzialanie programu? W przeciwnym razie powrocisz do wyboru programu.\n";
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
            /*Napisz program pobieraj�cy od u�ytkownika liczb� int n. Nast�pnie wy�wietlaj�cy na konsoli:
            � wszystkie liczby od 1 do n,
            � wszystkie liczby od n do 1 (tzn w odwrotnej kolejno�ci),
            � wszystkie liczby nieparzyste mniejsze od n,
            � wszystkie liczby parzyste mniejsze od n, daj�ce przy dzieleniu przez 3 reszt� 2,
            � wszystkie wielokrotno�ci liczby 5 mniejsze od n,
            � wszystkie ma�e litery alfabetu od 'a' do 'z'.*/
            int n;
            std::cout<<"Wprowadz liczbe do wykorzystania\n";

            std::cin>>n;


            std::cout<<"1.1 Wyswietlanie liczb od 1 do "<<n<<"\n\n";
            for(int i=1; i<=n; i++){
                std::cout<<i<<"\n";
            }

            std::cout<<"\n";
            std::cout<<"1.2 Wyswietlanie liczb od "<<n<<" do 1\n\n";
            for(int i=n; i>=1; i--){
                std::cout<<i<<"\n";
            }

            std::cout<<"\n";
            std::cout<<"1.3 Wyswietlanie liczb nieparzystych mniejszych od "<<n<<"\n\n";
            for(int i=1; i<n; i++){
                if(i%2==1)
                std::cout<<i<<"\n";
            }

            std::cout<<"\n";
            std::cout<<"1.4 Wyswietlanie liczb parzystych mniejszych od "<<n<<" oraz dajace przy dzieleniu przez 3 reszte 2"<<"\n\n";
            for(int i=1; i<n; i++){
                if(i%2==0&&i%3==2)
                std::cout<<i<<"\n";
            }

            std::cout<<"\n";
            std::cout<<"1.5 Wyswietlanie wszystkich wielokrotnosci liczby 5 mniejszych od "<<n<<"\n\n";
            for(int i=1; i<n; i++){
                if(i%5==0)
                std::cout<<i<<"\n";
            }

            std::cout<<"\n";
            std::cout<<"1.6 Wyswietlanie malych liter alfabetu lacinskiego od a do z"<<n<<"\n\n";
            for(char i=97; i<123; i++){
                std::cout<<i<<"\n";
            }
            test_ifend();
        }
        break;
        case '2':{ //Zadanie 2
            int stars, wiersz, ostatni;
            std::cout<<"Wprowadz liczbe gwiazdek"<<"\n";
            std::cin>>stars; std::cout<<"\n";
            int stars_const = stars;

            std::cout<<"\nChoinka numer 1\n";
            for(int i=1; stars>0; i++){
                int j = 1;
                if(stars<=i&&stars>0){
                    ostatni=stars; wiersz=i;
                }
                for(; j<=i; j++){
                    if(stars>0){
                        std::cout<<"*";
                        stars=stars-1;
                    }
                }
                std::cout<<"\n";
            }

            std::cout<<"\nChoinka numer 2\n";
            stars = stars_const;
            for (int p = 0; p < ostatni; p++) { std::cout << "*"; }
            stars -= ostatni; std::cout<<"\n";

            for(int i=wiersz; stars>0; i--){
                if(stars>0){
                    int j = 1;
                    for(; j<i; j++){
                        std::cout<<"*";
                        stars=stars-1;
                    }
                }
                std::cout<<"\n";
            }

            std::cout<<"\nChoinka numer 3\n";
            stars = stars_const;
            for(int k = ostatni; k<wiersz; k++) { std::cout << " "; }
            for (int p = 0; p < ostatni; p++) { std::cout << "*"; }
            stars-=ostatni; std::cout<<"\n";

            for(int i=wiersz; stars>0; i--){
                if(stars>0){
                    for(int k = i; k<=wiersz; k++){
                        std::cout << " ";
                    }
                    int j = 1;
                    for(; j<i; j++){
                        std::cout<<"*";
                        stars=stars-1;
                    }
                    std::cout<<"\n";
                }
            }

            std::cout<<"\nChoinka numer 4\n";
            stars = stars_const;

            for(int i=1; stars>0; i++){
                if(stars>0){
                    for(int k = i; k<wiersz; k++){
                        std::cout << " ";
                    }
                    int j = 1;
                    for(; j<=i; j++){
                        std::cout<<"*";
                        stars=stars-1;
                        if(stars==0) break;
                    }
                    std::cout<<"\n";
                }
            }


            std::cout<<"\nChoinka numer 5\n";
            stars = stars_const;
            int j=0; int pozostalo;
            for(int i=1; stars>0; i+=2){
                if(stars>0){
                    if(stars<=i){
                        wiersz = (j+1);
                        ostatni = i;
                        pozostalo = stars;
                        stars=0;
                        j++;
                    } else {
                        stars-=i;
                        j++;
                    }
                }
            }

            stars = stars_const;
            int counter = 1;
            for(int k = 0; k<wiersz; k++){
                if(stars>0){
                    for(int d = 1; ((ostatni/2)-(counter/2))>=d; d++) {
                        std::cout <<" ";
                    }
                    if(stars<=counter){
                        for(int p = stars;p>0;p--) {
                            std::cout << "*";
                            stars=0;
                        }
                    }else{
                        for(int p = 1;p<=counter;p++) {
                            std::cout << "*";
                        }
                    }
                    for(int d = 1; ((ostatni/2)-(counter/2))>=d; d++) {
                        std::cout <<" ";
                    }
                    stars -= counter;
                    std::cout<<"\n";
                    counter += 2;
                }
            }


            std::cout<<"\nChoinka numer 6\n";
            stars = stars_const;
            int counter2 = ostatni;
            for(int k = wiersz; k>0; k--){
                if(stars>0){
                    for(int d = ostatni; ((ostatni/2)+(counter2/2))<=d; d--) {
                        std::cout <<" ";
                    }
                    if(k == wiersz){
                        for(int p = pozostalo;p>0;p--){
                            std::cout << "*";
                        }
                        stars-=pozostalo;
                        counter2 -= 2;
                    }
                    if(k != wiersz){
                        for(int p = counter2;p>0;p--) {
                            std::cout << "*";
                        }
                        stars -= counter2;
                        counter2 -= 2;
                    }
                    for(int d = ostatni; ((ostatni/2)+(counter2/2))<=d; d--) {
                        std::cout <<" ";
                    }
                    std::cout<<"\n";
                }
            }

            test_ifend();
        }
        break;
        case '3':{ //Zadanie 3
            int x;
            double eps, silnia=1.0, potega, q, exp = 1.0;

            do{
                std::cout<<"Podaj x: "; std::cin>>x;
            }while(!(x>0));


            do{
                std::cout<<"Podaj eps: "; std::cin>>eps;
            }while(!(eps>0));

            int i = 1;

            do{
                silnia*=i;
                potega=pow(x,i);
                q=((potega)/(silnia));
                exp+=q;
                i++;
            }while(q>eps);
            std::cout<<std::endl;
            std::cout<<"exp("<<x<<") = "<<exp<<"\n";

            test_ifend();
        }
        break;
        case '4':{ //Zadanie 4
            int N; double x; double y = 0; int fac;
            std::cout<<"Podaj liczbe iteracji: "; std::cin>>N;
            std::cout<<"Podaj wartosc x: "; std::cin>>x;
            for(int i=1; i<=N; i++){
                fac = silnia(i);
                y += ((pow(x, i))/fac);
            }
            std::cout<<"Wynik tego dzialania to: "<<y<<"\n";
            test_ifend();
        }
        break;
        case '5':{ //Zadanie 5
            /*Napisz program który pobiera od użytkownika liczbę całkowitą, następnie wypisuje na ekranie jej wszystkie podzielniki.
             * Na końcu generuje komunikat czy podana przez użytkownika liczba jest liczbą pierwszą. Program ma działać „w kółko”, tzn. na końcu program
             * pyta użytkownika czy chce wyjść z programu i w zależności od jego decyzji program jest przerywany lub wraca do początku.*/
            char test_ifend5;
            do {
                int n; int k = 0;
                std::cout << "Podaj liczbe calkowita: ";
                std::cin >> n;
                for (int i = 1; i <= n; i++) {
                    if (n % i == 0) {
                        std::cout << "Podzielnikiem liczny " << n << " jest: " << i << "\n";
                        k += 1;
                    }
                }

                if (k <= 2 && n!=1) {
                    std::cout << "Liczba " << n << " jest liczba pierwsza\n";
                } else {
                    std::cout << "Liczba " << n << " nie jest liczba pierwsza\n";
                }

                std::cout<<"Czy chcesz wprowadzic i sprawdic kolejna liczbe? Podaj 't' lub 'T' dla Tak, w przeciwnym razie przejdziesz do dalszej czesci programu: \n";
                std::cin>>test_ifend5;
            }while(test_ifend5=='T'||test_ifend5=='t');

            test_ifend();
        }
        break;
        default:
            std::cout<<"Podaj wartosc przyporzadkowana do ktoregos zadania\n\n";
            choose(number);
        break;
    }
}

int silnia(int liczba){
    int silnia_wynik=1;
    for(int i = liczba; liczba > 0; liczba--){
        silnia_wynik*=liczba;
    }
    return silnia_wynik;
}
