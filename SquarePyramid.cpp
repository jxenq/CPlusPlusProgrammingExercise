#include <iostream>
#include <iomanip>
#include <cmath>
#define SPACE 12

int Volume(int N, int a) {
    return static_cast<int>(a * a * N / 3);
}
double SlantHeight(int N, int a){
    return sqrt(N  * N + a * a / 4.0);
}

double LSA(int N, int a) {
    return 2.0 * a * sqrt(N  * N + a * a / 4.0);
}

double TSA(int N, int a){
    return LSA(N,a) + a * a;
}

int main() {
    int N,a;
    std::cout << "The program prints the volume, LSA, TSA and slant height of a square pyramid with height h being an odd number ranging from 1 to N and side length a" << std::endl;
    while (true) {
        std::cout << "Enter the value for N:";
        std::cin >> N;

        if (N % 2 != 0) {
            break;
        } else {
            std::cout << "Error: N must be an odd number. Please enter again." << std::endl;
        }
    }
    std::cout << "Enter the length of side a:";
    std::cin >> a;
    std::cout<<std::endl;
    std::cout << std::setw(SPACE) << std::left << "Height"
              << std::setw(SPACE) << std::left << "Volume"
              << std::setw(SPACE + 12) << std::left << "Lateral Surface Area"
              << std::setw(SPACE + 12) << std::left << "Total Surface Area"
              << std::left << "Slant Height"<<std::endl;
    for (int i = 0; i < 84; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
    for(int i = 1; i <= N; i += 2)
    {
        std::cout << std::setw(SPACE) << std::left << i
                  << std::left << Volume(i,a)
                  << std::setw(SPACE + 1 - std::to_string(Volume(i, a)).length()) <<" m\u00B3"
                  << std::left << std::fixed << std::setprecision(3) << LSA(i, a)
                  << std::setw(SPACE + 16 - std::to_string(LSA(i, a)).length()) << " m\u00B2"
                  << std::left << std::fixed << std::setprecision(3) << TSA(i, a)
                  << std::setw(SPACE + 15 - std::to_string(TSA(i, a)).length()) << " m\u00B2"
                  << std::left << std::fixed << std::setprecision(3) << SlantHeight(i, a) <<" m"<< std::endl;
    }
    return 0;
}