#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

void classAverage();
void gasCalculator();
void tabularOutput();
void squareAsterisks();
int modeloSafeCin();
void binaryToDecimal();
void euler();
void palindrome();
void palindrome2();
void criptography();

int main(){

    int func{0};

    std::cout << "O valor maximo de \"int\" eh: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "O valor minimo de \"int\" eh: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << std::endl;

    
    std::cout << "Tamanho de long double: " << sizeof(long double) << " bytes" << std::endl;
    std::cout << "O valor maximo de \"long double\" eh: " << std::numeric_limits<long double>::max() << std::endl;

    std::cout << "\n\n\n\n";

    std::cout << "Choose a function:\nclassAverage(1);\ngasCalculator(2);\ntabularOutput(3);\nsquareAsterisks(4);\nbinaryToDecimal(5);\neuler(6);\npalindrome(7);\npalindrome2(8);\ncriptography(9);\n";
    while(true){
        if(std::cin >> func){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } else {
            std::cout << "Entrada invalida!\a Por favor tente novamente...";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    switch(func){
        case 1: classAverage(); break;
        case 2: gasCalculator();break;
        case 3: tabularOutput();break;
        case 4: squareAsterisks();break;
        case 5: binaryToDecimal();break;
        case 6: euler();break;
        case 7: palindrome();break;
        case 8: palindrome2();break;
        case 9: criptography(); break;
        default: break;
    }

}

void classAverage(){
    float total{0};
    int gradeCounter{0};
    int gradeCounterHold{0};
    float valueHold{0};

    std::cout << "\nEnter the number of students...";
    std::cin >> gradeCounter;
    
    if(gradeCounter <= 0){
        std::cout << "\nError!\a, invalid number.";
        return;
    }

    gradeCounterHold = gradeCounter;

    while(gradeCounter > 0){
        std::cout << std::endl << "Enter the grade or enter \"-1\" to exit... ";
        std::cin >> valueHold;
        
        if(valueHold == -1){

            if(gradeCounter == gradeCounterHold) {
                std::cout << std::endl << "\aNo grades where entered. Exiting the program...";
                return;
            }

            std::cout << "The total of all " << gradeCounterHold - gradeCounter <<  " grades is: " << total << std::endl;
            std::cout << "The average of the class is: " << total/(gradeCounterHold - gradeCounter);
            return;
        }

        total = total + valueHold;
        gradeCounter = gradeCounter - 1;
    }
    
    std::cout << "\nThe total of all " << gradeCounterHold <<  " grades is: " << total << std::endl;
    std::cout << "The average of the class is: " << total/(gradeCounterHold);

    return;
}

void gasCalculator(){

    double currentKm{0};
    double currentL{0};
    double totalKm{0};
    double totalL{0};

    std::cout << "GAS CALCULATOR\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n\n";

    while(currentKm != -1){
        std::cout << "Enter the number of KM or \"-1\" to exit... ";
        std::cin >>currentKm;

        if(currentKm == -1){
            std::cout << "Exiting the calculator...\n";
            std::cout << "The total Km/L ratio is: ";

            if(currentL == 0){
                std::cout << "0.";
            }

            std::cout << std::setprecision(3) << std::fixed << totalKm/totalL;
            return;
        }

        do{
            std::cout << "Enter the number of Liters used... ";
            std::cin >> currentL;
            if(currentL <= 0){
                std::cout << "Invalid number!\a. Please, Try again...\n";
            }
        } while(currentL <= 0);

        std::cout << "Km per Liter in this trip: ";
        std::cout << currentKm/currentL << "\n";

        totalKm += currentKm;
        totalL += currentL;

        std::cout << "The total Km/L ratio is: " << totalKm/totalL << "\n\n" << std::endl;
    }

    std::cout << "Exiting the calculator...\n";
    std::cout << "The total Km/L ratio is: " << totalKm/totalL;
    
    return;
}

void tabularOutput(){
    int N{0};

    std::cout << "TABULAR OUTPUT\n\n";
    std::cout << "Enter \"N\": ";
    do{
        std::cin >> N;

        if(N <= 0){
            std::cout << "Invalid number!\a Please try again... ";
        }
    } while(N <= 0);

    std::cout << "N\t10*N\t100*N\t1000*N\n\n";
    int i{1};

    while(i <= N){
        std::cout << i << "\t" << i*10 << "  \t" << i*100 << "  \t" << i*1000 << "\n";
        ++i;
    }
    return;
}

void squareAsterisks(){
    int squareSize{0};
    int squareSizeCopy{0};
    int squareSizeCopy2{0};

    std::cout << "\nEnter the size of the square's side: ";
    std::cin >> squareSize;

    std::cout << "\n\n";

    //Full square:
    squareSizeCopy = squareSize;
    squareSizeCopy2 = squareSizeCopy;

    while(squareSizeCopy > 0){

        while(squareSize > 0){
            std::cout << "**";
            --squareSize;
        }

        std::cout << "\n";
        squareSize = squareSizeCopy2;
        --squareSizeCopy;
    }

    std::cout << "\n" << std::endl;

    //Hollow square:
    squareSize = squareSizeCopy2;
    squareSizeCopy = squareSizeCopy2;

    while(squareSize > 0){
        std::cout << "**";
        --squareSize;
    }

    squareSizeCopy -= 2;

    while(squareSizeCopy > 0){
        std::cout << "\n" << "**";
        squareSize = squareSizeCopy2 - 2;

        while(squareSize > 0){
            std::cout << "  ";
            --squareSize;
        }
        std::cout << "**";
        
        --squareSizeCopy;
    }
    
    squareSize = squareSizeCopy2;
    std::cout << "\n";

    while(squareSize > 0){
        std::cout << "**";
        --squareSize;
    }

    return;
}

int modeloSafeCin(){
    int numero{0};

    std::cout << "Digite um numero inteiro";
    while(true){
        if(std::cin >> numero){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return numero;
        } else {
            std::cout << "Entrada invalida!\a Por favor tente novamente...";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return numero;

    /*while(true){
        if(std::cin >> variavel em questao){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } else {
            std::cout << "Entrada invalida!\a Por favor tente novamente...";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }*/

}

void binaryToDecimal(){

    unsigned long long int binaryDecimal{0};
    int potencia{1};
    int digitsB{0};
    int number{0};
    int finalNumber{0};
    
    std::cout << "Enter a binary number: ";

    while(true){
        
        if(std::cin >> binaryDecimal){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        } else {
            std::cout << "Entrada invalida!\a Por favor tente novamente...";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    auto potenciaDez = [](int potencia) -> unsigned long int {
        unsigned long int result{1};
        
        if(potencia < 0){
            std::cout << "\aERROR! negative numbers are not allowed.\n";
            return 0;
        }

        if(potencia == 0){
            return result;
        }

        for(int i = potencia; i > 0; --i){
            result *= 10;
        }
        return result;
    };

    auto digits = [&potenciaDez](int number) -> unsigned int {
        unsigned int result{1};

         if(number < 0){
            std::cout << "\aERROR! negative numbers are not allowed.\n";
            return 0;
        }

        if(number == 0 || number == 1){
            return result;
        }

        for(int i = 1; potenciaDez(i) <= number; i++){
            result = i;
        }
        ++result;

        return result;
    };

    auto potenciaDois = [](int potencia) -> unsigned int {
        unsigned int result{1};
        
        if(potencia < 0){
            std::cout << "\aERROR! negative numbers are not allowed.\n";
            return 0;
        }

        if(potencia == 0){
            return result;
        }

        for(int i = potencia; i > 0; --i){
            result *= 2;
        }
        return result;
    };

    digitsB = digits(binaryDecimal);

    for(int j = 1; j <= digitsB; ++j){

        /*if(potencia == 1){
            number = binaryDecimal%potenciaDez(potencia);
            if(number == 0){
                finalNumber += 0;
            }
            if(number == 1){
                finalNumber += potenciaDois(potencia-1);
            }
            potencia++;
            continue;
        }*/

        number = (binaryDecimal%potenciaDez(potencia) - binaryDecimal%potenciaDez(potencia-1))/(potenciaDez(potencia-1));
        if(number == 0){
            finalNumber += 0;
        }
        if(number == 1){
            finalNumber += potenciaDois(potencia-1);
        }
        potencia++;
    }

    std::cout << "\n\n\nThe binary number converted to decimal is: " << finalNumber;
    //três lambdas... BRUTAL
    return;
}

void euler(){
    //e = 1 + 1/1! + 1/2! + 1/3!...

    int denominator{0};
    long double euler{1};

    std::cout << "Enter a number to estimates Euler's number value \"e\": ";

    while(denominator <= 0){
        while(true){
            if(std::cin >> denominator){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            } else {
                std::cout << "Entrada invalida!\a Por favor tente novamente...";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        if(denominator <= 0){
            std::cout << "Entrada invalida!\a Por favor tente novamente...";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    /* Primeiro teste usando lambda. Basicamente segue a seguinte estrutura: [captura](parametros) -> retorno { corpo }. 
    Função anonima e "descartavel" que vc usa somente no escopo de onde ela foi declarada.*/
    auto factorial = [](int n) -> double {
        double result = n;

        if(n <= 1){
            return result;
        }

        for (int i = (n - 1); i > 1; --i) {
            result *= i;
        }
        return result;
    };

    std::cout << std::setprecision(17) << std::fixed;

    for(int i = 1; i <= denominator; ++i){
        euler += 1.0/factorial(i);
        std::cout << euler << "\n";
    }
    
    std::cout << "\n\neuler's number: " << euler;
    return;
}

void palindrome(){

    int number{0};
    int digits{0};
    int palindrome{0};

    std::cout << "Enter a number and we will return \"true\" if it is PALINDROME and \"false\" otherwise: ";

    while(true){
        if(std::cin >> number){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            } else {
                std::cout << "Entrada invalida!\a Por favor tente novamente...";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
    }
    

    if(number < 0){
        std::cout << "FALSE, the number: " << number << " is not a palindrome.";
        return;
    }
    
    auto digitsLambda = [](int number) -> int{
        int result{1};
        while(number >= 10){
            number /= 10;
            ++result;
        }
        return result;
    };

    auto potenciaDez = [](int potencia) -> unsigned long int {
        unsigned long int result{1};
        
        if(potencia < 0){
            std::cout << "\aERROR! negative numbers are not allowed.\n";
            return 0;
        }

        if(potencia == 0){
            return result;
        }

        for(int i = potencia; i > 0; --i){
            result *= 10;
        }
        return result;
    };

    digits = digitsLambda(number);

    for(int i = 0; i < digits; ++i){
        palindrome += ((number/potenciaDez(i))%10)*potenciaDez((digits - 1) - i); 
    }
      
    if(number == palindrome){
        std::cout << "TRUE, the number " << number << " is a palindrome, and backwards it is show like: " << palindrome;
    }else{
        std::cout << "FALSE, the number: " << number << " is not a palindrome, and backwards it is show like: " << palindrome;
    }

    return;
}

void palindrome2(){
    //Versao muito mais elegante do palindrome()
    int number{0};
    int numberCopy{0};
    int palindrome{0};

    std::cout << "Enter a number and we will return \"true\" if it is PALINDROME and \"false\" otherwise: ";

    while(true){
        if(std::cin >> number){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            } else {
                std::cout << "Entrada invalida!\a Por favor tente novamente...";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
    }

    if(number < 0){
        std::cout << "FALSE! the number: " << number << " is not a palindrome.";
        return;
    }

    numberCopy = number;

    while(numberCopy > 0){
        palindrome = (palindrome*10) + numberCopy%10;

        numberCopy /= 10;
    }

    if(number == palindrome){
        std::cout << "TRUE! the number " << number << " is a palindrome, and backwards it is: " << palindrome;
    }else{
        std::cout << "FALSE! the number: " << number << " is not a palindrome, and backwards it is: " << palindrome;
    }
}

void criptography(){
    int mode{0};
    int number{0};
    int numberCopy{0};
    int encripty{0};
    int encriptyCopy{0};
    int decripty{0};

    char retry{'x'};
    std::cout <<  std::setfill('0');

    std::cout << "                CRIPTOGRAPHY SOFTWARE\n__________________________________________________________________\n\n\n";
    std::cout << "Do you want to encrypt or decrypt a number? Enter \"1\" to encrypt, \"0\" to decrypt and \"-1\" to exit... ";
    do{
        std::cout << "\nEnter \"1\" to encrypt, \"0\" to decrypt and \"-1\" to exit... ";
        while(true){
                if(std::cin >> mode){
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    } else {
                        std::cout << "Entrada invalida!\a Por favor tente novamente...";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
            }

        if(mode == 1){
            do{
                encripty = 0;
                encriptyCopy = 0;
                std::cout << "Enter a four digits number: ";

                while(true){
                    if(std::cin >> number){
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        } else {
                            std::cout << "Entrada invalida!\a Por favor tente novamente...";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                }
                
                if(number == 0){
                    numberCopy = number;

                    encripty = 7777;

                    std::cout << "The encripted number is: " << std::setw(4) << encripty << std::endl;
                    std::cout << "Do you want to encripty another number? Press 'y' for YES and 'n' for NO... ";
                    continue;
                }

                if(number < 10 && number > 0){
                    numberCopy = number;

                    auto potenciaDez = [](int potencia) -> unsigned long int {
                        unsigned long int result{1};
                        
                        if(potencia < 0){
                            std::cout << "\aERROR! negative numbers are not allowed.\n";
                            return 0;
                        }

                        if(potencia == 0){
                            return result;
                        }

                        for(int i = potencia; i > 0; --i){
                            result *= 10;
                        }
                    return result;
                    };

                    encripty += 777;
                    for(int i = 1; i > 0; --i){
                        numberCopy /= potenciaDez(i - 1);
                        numberCopy %= 10;

                        numberCopy += 7;
                        numberCopy %= 10;
                        encripty = (encripty * 10) + numberCopy;

                        numberCopy = number;
                    }

                    numberCopy = encripty;
                    numberCopy /= 10;
                    numberCopy %= 10;
                    encriptyCopy = (encriptyCopy*10) + numberCopy;

                    numberCopy = encripty;
                    numberCopy %= 10;
                    encriptyCopy = (encriptyCopy*10) + numberCopy;

                    numberCopy = encripty;
                    for(int i = 1; i <= 3; ++i){
                        numberCopy /= 10;
                    }
                    encriptyCopy = (encriptyCopy*10) + numberCopy;

                    numberCopy = encripty;
                    for(int i = 1; i <= 2; ++i){
                        numberCopy /= 10;
                    }
                    numberCopy %= 10;
                    encriptyCopy = (encriptyCopy*10) + numberCopy;
                    
                    encripty = encriptyCopy;

                    std::cout << "The encripted number is: " << std::setw(4) << encripty << std::endl;
                    std::cout << "Do you want to encripty another number? Press 'y' for YES and 'n' for NO... ";
                    continue;
                }

                if(number < 100 && number >= 10){
                    numberCopy = number;

                    auto potenciaDez = [](int potencia) -> unsigned long int {
                        unsigned long int result{1};
                        
                        if(potencia < 0){
                            std::cout << "\aERROR! negative numbers are not allowed.\n";
                            return 0;
                        }

                        if(potencia == 0){
                            return result;
                        }

                        for(int i = potencia; i > 0; --i){
                            result *= 10;
                        }
                    return result;
                    };

                    encripty += 77;
                    for(int i = 2; i > 0; --i){
                        numberCopy /= potenciaDez(i - 1);
                        numberCopy %= 10;

                        numberCopy += 7;
                        numberCopy %= 10;
                        encripty = (encripty * 10) + numberCopy;

                        numberCopy = number;
                    }

                    numberCopy = encripty;
                    numberCopy /= 10;
                    numberCopy %= 10;
                    encriptyCopy = (encriptyCopy*10) + numberCopy;

                    numberCopy = encripty;
                    numberCopy %= 10;
                    encriptyCopy = (encriptyCopy*10) + numberCopy;

                    numberCopy = encripty;
                    for(int i = 1; i <= 3; ++i){
                        numberCopy /= 10;
                    }
                    encriptyCopy = (encriptyCopy*10) + numberCopy;

                    numberCopy = encripty;
                    for(int i = 1; i <= 2; ++i){
                        numberCopy /= 10;
                    }
                    numberCopy %= 10;
                    encriptyCopy = (encriptyCopy*10) + numberCopy;
                    
                    encripty = encriptyCopy;

                    std::cout << "The encripted number is: " << std::setw(4) << encripty << std::endl;
                    std::cout << "Do you want to encripty another number? Press 'y' for YES and 'n' for NO... ";
                    continue;
                }

                //excecao de o numero ter o primeiro digito significativo como sendo == 0;
                if(number < 1000 && number >= 100){
                    numberCopy = number;

                    auto potenciaDez = [](int potencia) -> unsigned long int {
                        unsigned long int result{1};
                        
                        if(potencia < 0){
                            std::cout << "\aERROR! negative numbers are not allowed.\n";
                            return 0;
                        }

                        if(potencia == 0){
                            return result;
                        }

                        for(int i = potencia; i > 0; --i){
                            result *= 10;
                        }
                    return result;
                    };

                    encripty += 7;
                    for(int i = 4; i > 0; --i){
                        numberCopy /= potenciaDez(i - 1);
                        numberCopy %= 10;

                        numberCopy += 7;
                        numberCopy %= 10;
                        encripty = (encripty * 10) + numberCopy;

                        numberCopy = number;
                    }

                    numberCopy = encripty;
                    numberCopy /= 10;
                    numberCopy %= 10;
                    encriptyCopy = (encriptyCopy*10) + numberCopy;

                    numberCopy = encripty;
                    numberCopy %= 10;
                    encriptyCopy = (encriptyCopy*10) + numberCopy;

                    numberCopy = encripty;
                    for(int i = 1; i <= 3; ++i){
                        numberCopy /= 10;
                    }
                    encriptyCopy = (encriptyCopy*10) + numberCopy;

                    numberCopy = encripty;
                    for(int i = 1; i <= 2; ++i){
                        numberCopy /= 10;
                    }
                    numberCopy %= 10;
                    encriptyCopy = (encriptyCopy*10) + numberCopy;
                    
                    encripty = encriptyCopy;

                    std::cout << "The encripted number is: " << std::setw(4) << encripty << std::endl;
                    std::cout << "Do you want to encripty another number? Press 'y' for YES and 'n' for NO... ";
                    continue;
                }

                numberCopy = number;

                auto potenciaDez = [](int potencia) -> unsigned long int {
                    unsigned long int result{1};
                    
                    if(potencia < 0){
                        std::cout << "\aERROR! negative numbers are not allowed.\n";
                        return 0;
                    }

                    if(potencia == 0){
                        return result;
                    }

                    for(int i = potencia; i > 0; --i){
                        result *= 10;
                    }
                return result;
                };

                for(int i = 4; i > 0; --i){
                    numberCopy /= potenciaDez(i - 1);
                    numberCopy %= 10;

                    numberCopy += 7;
                    numberCopy %= 10;
                    encripty = (encripty * 10) + numberCopy;

                    numberCopy = number;
                }
                
                numberCopy = encripty;
                numberCopy /= 10;
                numberCopy %= 10;
                encriptyCopy = (encriptyCopy*10) + numberCopy;

                numberCopy = encripty;
                numberCopy %= 10;
                encriptyCopy = (encriptyCopy*10) + numberCopy;

                numberCopy = encripty;
                for(int i = 1; i <= 3; ++i){
                    numberCopy /= 10;
                }
                encriptyCopy = (encriptyCopy*10) + numberCopy;

                numberCopy = encripty;
                for(int i = 1; i <= 2; ++i){
                    numberCopy /= 10;
                }
                numberCopy %= 10;
                encriptyCopy = (encriptyCopy*10) + numberCopy;
                
                encripty = encriptyCopy;

                std::cout << "The encripted number is: " << std::setw(4) << encripty << std::endl;
                std::cout << "Do you want to encripty another number? Press 'y' for YES and 'n' for NO... ";

                while(true){
                    if(std::cin >> retry){
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        } else {
                            std::cout << "Entrada invalida!\a Por favor tente novamente...";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                }
                
                std::cout << "\n\n\n";
            }while(retry == 'y' || retry == 'Y');

        }
        else if(mode == 0){
            do{
                std::cout << "Enter the number to be decripted: ";

                while(true){
                    if(std::cin >> number){
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        } else {
                            std::cout << "Entrada invalida!\a Por favor tente novamente...";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                }
                
                if(number == 0){
                    decripty = 3333;

                    std::cout << "The decripted number is: " << std::setw(4) << decripty << std::endl;

                    std::cout << "Do you want to decripty another number? Press 'y' for YES and 'n' for NO... ";

                    while(true){
                        if(std::cin >> retry){
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        } else {
                            std::cout << "Entrada invalida!\a Por favor tente novamente...";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    
                    std::cout << "\n\n\n";
                    continue;
                }

                if(number < 10 && number >= 0){
                    numberCopy = number;

                    decripty = decripty*10 + 3;

                    number = numberCopy;     
                    number %= 10;

                    if(((number + 10) - 7) < 10 && ((number + 10) - 7) > 0){
                        number += 3;
                    }
                    if(((number + 10) - 7) > 10){
                        number -= 7;
                    }
                    if(number == 0){
                        number = 3;
                    }
                    if(number == 7){
                        number = 0;
                    }

                    decripty = decripty*10 + number;

                    decripty = decripty*10 + 3;

                    decripty = decripty*10 + 3;


                    std::cout << "The decripted number is: " << std::setw(4) << decripty << std::endl ; 

                    std::cout << "Do you want to decripty another number? Press 'y' for YES and 'n' for NO... ";

                    while(true){
                        if(std::cin >> retry){
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        } else {
                            std::cout << "Entrada invalida!\a Por favor tente novamente...";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    
                    std::cout << "\n\n\n";
                    continue;
                }

                if(number < 100 && number >= 10){
                    numberCopy = number;
                    number /= 10;
                    number %= 10;

                    if(((number + 10) - 7) < 10 && ((number + 10) - 7) > 0){
                        number += 3;
                    }
                    if(((number + 10) - 7) > 10){
                        number -= 7;
                    }
                    if(number == 0){
                        number = 3;
                    }
                    if(number == 7){
                        number = 0;
                    }

                    decripty = decripty*10 + number;

                    number = numberCopy;     
                    number %= 10;

                    if(((number + 10) - 7) < 10 && ((number + 10) - 7) > 0){
                        number += 3;
                    }
                    if(((number + 10) - 7) > 10){
                        number -= 7;
                    }
                    if(number == 0){
                        number = 3;
                    }
                    if(number == 7){
                        number = 0;
                    }

                    decripty = decripty*10 + number;

                    decripty = decripty*10 + 3;

                    decripty = decripty*10 + 3;

                    std::cout << "The decripted number is: " << std::setw(4) << decripty << std::endl;

                    std::cout << "Do you want to decripty another number? Press 'y' for YES and 'n' for NO... ";

                    while(true){
                        if(std::cin >> retry){
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        } else {
                            std::cout << "Entrada invalida!\a Por favor tente novamente...";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    
                    std::cout << "\n\n\n";
                    continue;
                }

                //execao caso o number tenha o digito mais significativo == 0;
                if(number < 1000 && number >= 100){
                    numberCopy = number;
                    number /= 10;
                    number %= 10;

                    if(((number + 10) - 7) < 10 && ((number + 10) - 7) > 0){
                        number += 3;
                    }
                    if(((number + 10) - 7) > 10){
                        number -= 7;
                    }
                    if(number == 0){
                        number = 3;
                    }
                    if(number == 7){
                        number = 0;
                    }

                    decripty = decripty*10 + number;

                    number = numberCopy;     
                    number %= 10;

                    if(((number + 10) - 7) < 10 && ((number + 10) - 7) > 0){
                        number += 3;
                    }
                    if(((number + 10) - 7) > 10){
                        number -= 7;
                    }
                    if(number == 0){
                        number = 3;
                    }
                    if(number == 7){
                        number = 0;
                    }

                    decripty = decripty*10 + number;

                    decripty = decripty*10 + 3;

                    number = numberCopy;
                    for(int i = 1; i <= 2; ++i){
                        number /= 10;
                    }
                    number %= 10;
                    if(((number + 10) - 7) < 10 && ((number + 10) - 7) > 0){
                        number += 3;
                    }
                    else if(((number + 10) - 7) > 10){
                        number -= 7;
                    }
                    else if(number == 0){
                        number = 3;
                    }
                    else if(number == 7){
                        number = 0;
                    }

                    decripty = decripty*10 + number;

                    std::cout << "The decripted number is: " << std::setw(4) << decripty << std::endl;

                    std::cout << "Do you want to decripty another number? Press 'y' for YES and 'n' for NO... ";

                    while(true){
                        if(std::cin >> retry){
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        } else {
                            std::cout << "Entrada invalida!\a Por favor tente novamente...";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    
                    std::cout << "\n\n\n";
                    continue;
                }

                decripty = 0;
                numberCopy = number;
                number /= 10;
                number %= 10;

                if(((number + 10) - 7) < 10 && ((number + 10) - 7) > 0){
                    number += 3;
                }
                if(((number + 10) - 7) > 10){
                    number -= 7;
                }
                if(number == 0){
                    number = 3;
                }
                if(number == 7){
                    number = 0;
                }

                decripty = decripty*10 + number;

                number = numberCopy;     
                number %= 10;

                if(((number + 10) - 7) < 10 && ((number + 10) - 7) > 0){
                    number += 3;
                }
                if(((number + 10) - 7) > 10){
                    number -= 7;
                }
                if(number == 0){
                    number = 3;
                }
                if(number == 7){
                    number = 0;
                }

                decripty = decripty*10 + number;

                number = numberCopy;
                for(int i = 1; i <= 3; ++i){
                    number /= 10;
                }
                
                if(((number + 10) - 7) < 10 && ((number + 10) - 7) > 0){
                    number += 3;
                }
                if(((number + 10) - 7) > 10){
                    number -= 7;
                }
                if(number == 0){
                    number = 3;
                }
                if(number == 7){
                    number = 0;
                }

                decripty = decripty*10 + number;

                number = numberCopy;
                for(int i = 1; i <= 2; ++i){
                    number /= 10;
                }
                number%= 10;
                if(((number + 10) - 7) < 10 && ((number + 10) - 7) > 0){
                    number += 3;
                }
                else if(((number + 10) - 7) > 10){
                    number -= 7;
                }
                else if(number == 0){
                    number = 3;
                }
                else if(number == 7){
                    number = 0;
                }

                decripty = decripty*10 + number;

                std::cout << "The decripted number is: " << std::setw(4) << decripty << std::endl;

                std::cout << "Do you want to decripty another number? Press 'y' for YES and 'n' for NO... ";

                    while(true){
                        if(std::cin >> retry){
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        } else {
                            std::cout << "Entrada invalida!\a Por favor tente novamente...";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    
                std::cout << "\n\n\n";
            }while(retry == 'y' || retry == 'Y');

            std::cout << "                CRIPTOGRAPHY SOFTWARE\n__________________________________________________________________\n\n\n";
            std::cout << "Do you want to encrypt or decrypt a number? Press 'y' for YES and 'n' for NO... ";

            while(true){
                if(std::cin >> retry){
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                } else {
                    std::cout << "Entrada invalida!\a Por favor tente novamente...";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }

        }

        std::cout << "                CRIPTOGRAPHY SOFTWARE\n__________________________________________________________________\n\n\n";
        std::cout << "Do you want to encrypt or decrypt a number? Press 'y' for YES and 'n' for NO... ";

            while(true){
                if(std::cin >> retry){
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                } else {
                    std::cout << "Entrada invalida!\a Por favor tente novamente...";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
    }while(retry == 'y' || retry == 'Y');
    std::cout << "\nExiting the program...";
    return;
} 
 