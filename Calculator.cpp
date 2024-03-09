#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// #include <conio.h>


template<typename T>
class Calculator{
    private:
    

    public:
        T add( T a, T b){
            return a + b;
        }

        T sub( T a, T b){
            return a - b;
        }

        T div( T a, T b){
            return a / b;
        }

        T mod( T a, T b){
            return a % b;
        }

        T mul( T a, T b){
            return a * b;
        }

};

int main(){

    double a,b;
    char ch;
    while(true){

        printf("\x1b[2J");
        printf("\x1b[H");
        // printf("\x1b[uANSISYSRC");
        scanf("%lf %c %lf", &a, &ch, &b);
        getchar();

        double ans;
        switch (ch)
        {
        case '+':
            ans = a + b;
            break;
        
        case '-':
            ans = a - b;
            break;

        case '*':
            ans = a * b;
            break;

        case '/':
            ans = a / b;
            break;

        default:
            std::cout  << "Error" << std::endl;
            continue;
        }

        std::cout << "Result: " << ans << "\nPress any key to continue" << std::endl;
        
        std::cin.get();
    }
}