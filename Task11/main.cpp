#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <cstdint>
//Piotr Janiszek - 247678
using namespace std;
void test_ifend();
void programs();
void wlacz_bit(unsigned int &wektor, int pozycja)
{
    wektor |= (1 << pozycja);
}

void wylacz_bit(unsigned int &wektor, int pozycja)
{
    wektor &= ~(1 << pozycja);
}

void zmien_bit(unsigned int &wektor, int pozycja)
{
    wektor ^= (1 << pozycja);
}

bool bit_wylaczony(unsigned int wektor, int pozycja)
{
    return !(wektor & (1 << pozycja));
}

int encode(const char* input) {
    int output = 0;
    for (int i = 0; i < 4; i++) {
        output |= (input[i] & 0xff) << (i * 8);
    }
    return output;
}

void decode(int input, char* output) {
    for (int i = 0; i < 4; i++) {
        output[i] = (input >> (i * 8)) & 0xff;
    }
}

void encrypt_file_xor(const std::string& input_file, const std::string& output_file, const std::string& key) {
    std::ifstream input(input_file, std::ios::binary);
    std::ofstream output(output_file, std::ios::binary);
    std::size_t key_pos = 0;

    char input_char;
    while (input.get(input_char)) {
        output.put(input_char ^ key[key_pos]);
        key_pos = (key_pos + 1) % key.length();
    }
}



int main()
{
    programs();
    return 0;
}



void test_ifend(){
    char decision;
    do{
        std::cout<<"Czy zakonczyc dzialanie programu -T/t czy powrocic do menu - N/n?\n";
        std::cin>>decision; std::cout<<"\n";
    }while(!(decision=='T'||decision=='t'||decision=='N'||decision=='n'));

    if(decision=='t'||decision=='T'){
        exit(0);
    }else if(decision=='n'||decision=='N'){
        programs();
    }


}void programs(){
    char number;
    std::cout<<"Podaj numer zadania \n";
    std::cout<<"Do wyboru: \n";
    std::cout<<"1. Operacja bitowe na wektorze\n";
    std::cout<<"2. Kodowanie i rozkodowanie tablicy znakowej z 4 elementami\n";
    std::cout<<"3. Szyfrowanie pliku wedlug podanego klucza\n";
    std::cin>>number; std::cout<<"\n";
    switch(number){
        case '1':{ //Zadanie 1
            unsigned int dane;
            cout<<"Podaj wartosc unsigned int dla wektora";
            while(!(cin>>dane)){
                cout<<"Podaj wartosc typu unsigned int dla wektora";
                cin.clear();
                cin.ignore();
            }
            char wybor;
            do{
                cout<<"Podaj co chcesz zrobic z wektorem: \n";
                cout<<"1: Wlaczyc dany bit\n";
                cout<<"2: Wylaczyc dany bit\n";
                cout<<"3: Zmienic dany bit na przeciwny\n";
                cout<<"4: Sprawdzic czy dany bit jest wylaczony\n";
                cin>>wybor;
            }while(!(wybor=='1'||wybor=='2'||wybor=='3'||wybor=='4'));

            int poz;
            do {
                cout << "Podaj pozycja bitu w zmiennej typu unsigned int <0-31>: \n";
                cin >> poz;
            } while (poz>31&&poz<0);
            if(wybor=='1'){
                wlacz_bit(dane, poz);
                cout << "Po zmianie: ";
                cout << dane << std::endl;
            } else if(wybor=='2'){
                wylacz_bit(dane, poz);
                cout << "Po zmianie: ";
                cout << dane << std::endl;
            } else if(wybor=='3'){
                zmien_bit(dane, poz);
                cout << "Po zmianie: ";
                cout << dane << std::endl;
            } else if(wybor=='4'){
                if(bit_wylaczony(dane, poz)==1) {
                    cout << "Na pozycji: " << poz << " znajduje sie wartosc 0" << std::endl;
                }else if(bit_wylaczony(dane, poz)==0) {
                    cout << "Na pozycji: " << poz << " znajduje sie wartosc 1" << std::endl;
                }
            }
            test_ifend();
        }
            break;
        case '2':{ //Zadanie 2
            char input[5];
            for(int i = 0; i < 4; i++){
                cout<<"Podaj znak do zakodowania: \n";
                cin>>input[i];
            }

            int encoded = encode(input);
            char output[5];
            decode(encoded, output);
            cout << "Input: " << input << endl;
            cout << "Encoded: " << encoded << endl;
            cout << "Decoded: " << output << endl;

            test_ifend();
        }
            break;
        case '3':{ //Zadanie 3
            string key;
            cout<<"Podaj klucz: ";
            cin>>key;
            encrypt_file_xor("input.txt", "output.txt", key);
            test_ifend();
        }
            break;
        default:
            std::cout<<"Podaj wartosc przyporzadkowana do ktoregos zadania\n\n";
            programs();
            break;
    }
}