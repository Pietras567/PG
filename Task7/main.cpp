#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
//Piotr Janiszek - 247678
const int N = 10;

void input(int Tablica[][N], int size);
void wyswietl(int Tablica[][N], int size);
void suma_wierszy(int Tablica[][N], int size);
void wyswietl_wiersz_max(int Tablica[][N], int size, int wiersz, int maximum);
void transpozycja(int Tablica[][N], int size);
void posortuj_kolumny_mal(int Tablica[][N], int size);
void posortuj_kolumny_ros(int Tablica[][N], int size);
bool sprawdz_symetrie(int Tablica[][N], int size);
void random_array(int** Tab, unsigned int W, unsigned int K);
void wyswietl_niesym(int** Tab, unsigned int W, unsigned int K);
void test_ifend(bool init);
void programs(bool init);

int tablica[N][N] = {};

int main() {
    bool init = false;
    programs(init);
    return 0;
}

void random_array(int** Tab, unsigned int W, unsigned int K){
    srand(time(nullptr));
    for(int i = 0; i<W; i++){
        for(int j = 0; j<K; j++){
            Tab[i][j] = rand() % 20 + 1;
        }
    }


}

void wyswietl_niesym(int** Tab, unsigned int W, unsigned int K){
    for(int i = 0; i < W; i++){
        for(int j = 0; j < K; j++){
            std::cout<<std::setw(4)<<Tab[i][j];
            if(j==K-1)
                std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
}

void input(int Tablica[][N], int size){
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        // Wypełnienie elementów przekątnej głównej tablicy A losowymi wartościami
        Tablica[i][i] = rand() % 10 + 1;

        for (int j = i+1; j < size; j++) {
            // Wypełnienie elementów tablicy A losowymi wartościami
            Tablica[i][j] = rand() % 10 + 1;
            // Symetria względem przekątnej głównej tablicy A
            Tablica[j][i] = Tablica[i][j];
        }
    }

}

void wyswietl(int Tablica[][N], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout<<std::setw(4)<<Tablica[i][j];
            if(j==(size-1))
                std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
}

void suma_wierszy(int Tablica[][N], int size){
    int Suma[10] = {};
    int max = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            Suma[i]+=Tablica[i][j];
        }
        if(Suma[i]>max)
            max=Suma[i];
    }

    for(int i = 0; i < 10; i++){
        if(Suma[i]==max)
            wyswietl_wiersz_max(Tablica, size, i, max);
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}

void wyswietl_wiersz_max(int Tablica[][N], int size, int wiersz, int maximum){
    for(int j = 0; j < size; j++){
        std::cout<<std::setw(4)<<Tablica[wiersz][j];
    }
    std::cout<<" = "<<maximum;
    std::cout<<std::endl;
}

void transpozycja(int Tablica[][N], int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            std::swap(Tablica[i][j], Tablica[j][i]);
        }
    }
}

void posortuj_kolumny_ros(int Tablica[][N], int size){
    for(int j = 0; j < size; j++){
        for(int k = 0; k < size; k++){
            for (int i = 0; i < size - 1; i++){
                if (Tablica[i][j] > Tablica[i + 1][j])
                    std::swap(Tablica[i][j], Tablica[i + 1][j]);
            }
        }
    }
}

void posortuj_kolumny_mal(int Tablica[][N], int size){
    for(int j = 0; j < size; j++){
        for(int k = 0; k < size; k++){
            for (int i = 0; i < size - 1; i++){
                if(Tablica[i][j] < Tablica[i + 1][j])
                    std::swap(Tablica[i][j], Tablica[i + 1][j]);
            }
        }
    }
}

bool sprawdz_symetrie(int Tablica[][N], int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (Tablica[i][j] != Tablica[j][i]) {
                return false;
            }
        }
    }
    return true;
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
}

void programs(bool init){
    char number;
    std::cout<<"Podaj numer zadania \n";
    std::cout<<"Do wyboru: \n";
    std::cout<<"1. Inicjalizacja tablicy oraz jej wypelnienie\n";
    std::cout<<"2. Wiersze/Wiersz z najwieksza suma ich/jego elementow\n";
    std::cout<<"3. Sortowanie tablicy\n";
    std::cout<<"4. Transpozycja tablicy\n";
    std::cout<<"5. Praca na dwuwymiarowej tablicy dynamicznej\n";
    std::cin>>number; std::cout<<"\n";
    switch(number){
        case '1':{ //Zadanie 1
            input(tablica, N);
            wyswietl(tablica, N);
            init = true;
             test_ifend(init);
        }
            break;
        case '2':{ //Zadanie 2
            if(init){
                suma_wierszy(tablica, N);
                test_ifend(init);
            } else {
                std::cout<<"Pierw zainicjalizuj tablice - zadanie nr 1\n";
                test_ifend(init);
            }
        }
            break;
        case '3':{ //Zadanie 3
            if(init){
                char kierunek;
                do {
                    std::cout << "Jak chcesz posortowac kolumny? (1 - rosnaco, 2 - malejaco): ";
                    std::cin >> kierunek;
                }while(!(kierunek=='1'||kierunek=='2'));
                std::cout << "Sprawdzanie symetrii przed sortowaniem: " << sprawdz_symetrie(tablica, N) << std::endl;
                if(kierunek=='1')
                    posortuj_kolumny_ros(tablica, N);
                else if(kierunek=='2')
                    posortuj_kolumny_mal(tablica, N);
                wyswietl(tablica, N);
                std::cout << "Sprawdzanie symetrii po sortowaniu: " << sprawdz_symetrie(tablica, N) << std::endl;
            } else {
                std::cout<<"Pierw zainicjalizuj tablice - zadanie nr 1\n";
                test_ifend(init);
            }
            test_ifend(init);
        }
            break;
        case '4':{ //Zadanie 4
            if(init){
                transpozycja(tablica, N);
                wyswietl(tablica, N);
            } else {
                std::cout<<"Pierw zainicjalizuj tablice - zadanie nr 1\n";
                test_ifend(init);
            }
            test_ifend(init);
        }
            break;
        case '5':{ //Zadanie 5
            unsigned int Wiersze, Kolumny;
            do{std::cout<<"Podaj ilosc wierszy"; std::cin>>Wiersze;}while(Wiersze<=0);
            do{std::cout<<"Podaj ilosc kolumn"; std::cin>>Kolumny;}while(Kolumny<=0);

            int ** Tab7 = new int * [Wiersze];
            for(int i = 0; i<Kolumny; i++){
                Tab7[i] = new int [Kolumny];
            }

            random_array(Tab7, Wiersze, Kolumny);
            wyswietl_niesym(Tab7, Wiersze, Kolumny);

            for(int i = 0; i<Kolumny; i++){
                delete [] Tab7[i];
            }
            delete [] Tab7;
                test_ifend(init);
        }
            break;
        default:
            std::cout<<"Podaj wartosc przyporzadkowana do ktoregos zadania\n\n";
            programs(init);
            break;
    }
}