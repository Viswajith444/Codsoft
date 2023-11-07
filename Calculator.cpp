#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// #include <conio.h>


class Calculator{
    private:
    

    public:
        template<typename T>
        T add( T a, T b){
            return a + b;
        }

        template<typename T>
        T sub( T a, T b){
            return a - b;
        }

        template<typename T>
        T div( T a, T b){
            return a / b;
        }

        template<typename T>
        T mod( T a, T b){
            return a % b;
        }

        template<typename T>
        T mul( T a, T b){
            return a * b;
        }

};

int main(){

    double a,b;
    char ch;
    while(true){

        printf("\x1b[2J");
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
            std::cout  << "Shame on u" << std::endl;
            continue;
        }

        std::cout << "Result: " << ans << "\nPress any key to continue" << std::endl;
        
        std::cin.get();
    }
}