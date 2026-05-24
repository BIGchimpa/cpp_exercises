#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <windows.h>

int primeNumber(int n);
double squareRoot(int num);

int main(){

    SetConsoleOutputCP(CP_UTF8);

    int Nprime{0};

    while(true){
        std::cout << "Enter a number, and the return value will be the prime that ocupies that position... ";
        std::cin >> Nprime;
        if(Nprime >= 1){
            break;
        } else {
            std::cout << "ERROR!\a invalid number. Try again...❌" << std::endl;
        }
    }
    std::cout << "The prime number that ocupies the " << Nprime << "° position is: " << primeNumber(Nprime) << std::endl;
}

int primeNumber(int n){
    int primeQuant{1};
    int num{1};
    int numC{0};
    int aux{2};
    double root{0};

    while(primeQuant <= n){
        
        root = squareRoot(num);
        while(aux <= root){
            if((num%aux) == 0){
                break;
            } else {
                ++aux;
            }
        }

        if(aux > root){
            ++primeQuant;
            numC = num;
        }
        ++(++num);
        aux = 2;
    }

    return numC;
}

double squareRoot(int num){

    double square{1};
    double antSquare{1};
    double aux{0};
    short int precision{0};

    if(num == 1){
        return 1;
    }
    if(num == 0){
        return 0;
    }
    if(num < 0){
        std::cout << "\nERRO!\a número inválido.";
        return 0;
    }

    while((square*square) < num){
        ++square;
    }

    if(square == num){
        return square;
    }

    antSquare = (square - 1);

    for(precision = 54; precision > 0; --precision){

        square = (antSquare + square)/2;

        if((square*square) > num){
            ;
        } else if((square*square) < num){
            aux = square;
            square += (square - antSquare);
            antSquare = aux;
        } else if((square*square) == num){
            return square;
        }

    }

    return square;

}