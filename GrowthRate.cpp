#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <locale>
#include<sstream>

using namespace std;

std::string Ranking(double GrowthRate)
{
    if(GrowthRate > 0.25)
        return "Exceptional";
    else if(GrowthRate > 0)
        return "Good";
    else
        return "Poor";
}

int main() {
    int a,n;
    std::cout << "Enter the number of countries: ";
    std::cin >> a;
    std::cout << "Enter the number of years: ";
    std::cin >> n;
    long int GDP[a][n + 1];
    double GR[a][n];
    double value[a];
    std::string CountryName[a];
    for(int i = 0; i < a; i++)
    {
        std::cout << "Enter the name of country " << i + 1<< ": ";
        std::cin >> CountryName[i];
        std::cout << std::endl;
        std::cout << "Country " << CountryName[i] << std::endl;
        for(int j = 0; j < 43; j++)
            std::cout << "-";
        std::cout << std::endl;
        std::cout << "Enter the beginning GDP value: ";
        std::cin >> GDP[i][0];
        for(int year = 1; year <= n; year++)
        {
            std::cout << "Enter the end of year " << year << " GDP value: ";
            std::cin >> GDP[i][year];
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < a; i++)
    {
        std::cout << "                      Country " << CountryName[i] << std::endl;
        for(int j = 0; j < 60; j++)
            std::cout << "-";
        std::cout << std::endl;
        std::cout << "Year |         GDP Value     |    Growth Rate    |   Ranking" << std::endl;
        for(int j = 0; j < 60; j++)
            std::cout << "-";
        std::cout << std::endl;
        GR[i][0] = 0;
        for(int year = 1; year <= n; year++) {
                GR[i][year] = static_cast<double>(GDP[i][year] - GDP[i][year - 1]) / GDP[i][year - 1];
                GR[i][0] += GR[i][year];
                std::cout << std::setw(5) << std::left << year;
                std::cout << std::setw(7) << std::left << "|";
                std::cout << "$";
                std::string str;
                str = to_string(GDP[i][year]);
                size_t len = str.length();
                for(int index = (int) len-3; index > 0; index -= 3)
                    str.insert(index, ",");
                str += ".00";
                std::cout << std::setw(16) << str;
                std::cout.imbue(std::locale());
                std::cout << std::setw(7) << std::left << "|";
                std::cout << std::fixed << std::setprecision(2) << GR[i][year] * 100;
                std::cout << std::setw(17 - std::to_string(GR[i][year] * 100).length()) << "%";
                std::cout << std::setw(4) << "|";
                std::cout << Ranking(GR[i][year]);
                std::cout << std::endl;
        }
        std::cout << "Average Annual Growth Rate: " << (GR[i][0] / static_cast<double>(n) * 100) << "%" << std::endl;
        std::cout << "Compound Annual Growth Rate: " << (pow((static_cast<double>(GDP[i][n]) / static_cast<double>(GDP[i][0])),1.0/n) - 1) * 100 << "%" << std::endl;
        value[i] = 0;
        double mean = static_cast<double>(GR[i][0]) / static_cast<double>(n);
        for(int j = 1; j <= n; j++)
        {
            value[i] += (GR[i][j] - mean) * (GR[i][j] - mean);
        }
        value[i]  = sqrt(value[i] / static_cast<double>(n - 1));
        value[i] *= 100;
        std::cout << "Standard Deviation: ";
        std::cout << std::fixed << std::setprecision(3) << value[i];
        std::cout << std::endl << std::endl;
    }
    int max = 0;
    int min = 0;
    for (int i = 0; i < a; i++) {
        if (value[i] > value[max]) {
            max = i;
        }
        if (value[i] < value[min]) {
            min = i;
        }
    }
    if(max - min < 25)
        std::cout << "The Country " << CountryName[min] << "'s economy is most stable";
    if(max - min > 25)
        std::cout << "The Country " << CountryName[max] << "'s economy is least risky";
    return 0;
}
