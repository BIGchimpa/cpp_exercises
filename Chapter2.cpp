#include <iostream>
#include <string>

void sumTwoIntegers();
void stringTestDrive();
void productOfThreeIntegers();
void arithmeticTwoNumbers();
void isMultiple();
void digitsOfAnInteger();


int main(){

    int functionSelection{0};

    std::cout << "Select a function...\ndigitsOfAnInteger(1); \nisMultiple(2); \narithmeticTwoNumbers(3); \nstringTestDrive(4); \nproductOfThreeIntegers(5); \nsumTwoIntegers(6);... ";
    std::cin >> functionSelection;

    switch(functionSelection){
        case 1: std::cout << "\n\n\n"; digitsOfAnInteger(); break;
        case 2: std::cout << "\n\n\n"; isMultiple(); break;
        case 3: std::cout << "\n\n\n"; arithmeticTwoNumbers(); break; 
        case 4: std::cout << "\n\n\n"; stringTestDrive(); break;
        case 5: std::cout << "\n\n\n"; productOfThreeIntegers(); break; 
        case 6: std::cout << "\n\n\n"; sumTwoIntegers(); break;
        default: std::cout << "Invalid number! \a"; break;
    }

} 


void sumTwoIntegers(){
    int num1{0};
    int num2{0};
    int sum{0};

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    sum = num1 + num2;

    std::cout << "\nThe sum of the two given numbers is: " << sum << "\n";
    std::cout << "The sum of the two given numbers is: " << num1 + num2; 

    return;
}

void stringTestDrive(){
    std::string s1{"Happy"};
    std::string s2{" birthday!"};
    std::string s3;

    std::cout << "s1: \"" << s1 << "\"; length: " << s1.length()
    << "\ns2: \"" << s2 << "\"; length: " << s2.length()
    << "\ns3: \"" << s3 << "\"; length: " << s3.length() << "\n";

    if(s3.empty()){
        std::cout << "s3 string is empty, assigning s1 + s2 to s3... \n";
        s3 = s1 + s2;
        std::cout << "s3: " << s3 << "\n";
    }

    std::cout << std::boolalpha;

    std::cout << "s1 starts with \"Ha\": " << s1.starts_with("Ha") << "\n";
    std::cout << "s2 starts with \"Ha\": " << s2.starts_with("Ha") << "\n";
    std::cout << "s2 ends with \"ay!\": " << s2.ends_with("ay!") << "\n";

    return;
}

void productOfThreeIntegers(){
    int x{0};
    int y{0};
    int z{0};
    int result{0};

    std::cout << "Enter three numbers (): ";
    std::cin >> x >> y >> z;
    result = x * y * z;

    std::cout << " \nThe product is: " << result;

    return;
}

void arithmeticTwoNumbers(){
    int num1{0};
    int num2{0};
    
    std::cout << "Please enter two numbers:\n";
    std:: cin >> num1 >> num2;

    std::cout << "The sum is: " << num1 + num2 
    << "\nThe diference is: " << num1 - num2 
    << "\nThe product is: " << num1 * num2 
    << "\nThe quocient is: " << num1/num2;

    return;
}

void isMultiple(){
    int num1{0};
    int num2{0};
    
    std::cout << "Please enter two numbers, and we will return if they are multiple of each other or no:\n";
    std:: cin >> num1 >> num2;

    if(num1%num2 == 0){ 
        std::cout << num1 << " is a multiple of " << num2;
    }

    if(num2%num1 == 0){
        std::cout << num2 << " is a multiple of " << num1;
    }

    if(num1%num2 != 0 && num2%num1 != 0){
        std::cout << "They are not multiple of each other\n";
    }
    return;
}

void digitsOfAnInteger(){
    int number{0};

    std::cout << "Enter a five digits number: ";
    std::cin >> number;

    if(number > 99999){
        std::cout << "\a ERROR! Invalid number.";
        return;
    }

    std::cout << (number%100000 - number%10000)/10000 
    << "  " << (number%10000 - number%1000)/1000 
    << "  " << (number%1000 - number%100)/100 
    << "  " << (number%100 - number%10)/10 
    << "  " << number%10;

    return;
}