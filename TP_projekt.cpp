#include <iostream>
#include <string>
#include <locale.h>
#include "NormalizeSets.h"
#include "SolveSets.h"

bool CheckRquanationCorrectness(std::string eq);

int main()
{
    setlocale(LC_CTYPE, "Polish");
    std::cout << "Kalkulator układów równań z trzema niewiadomymi. \n";
    std::cout << "Autor: Dawid Labuda 160422 \n\n";

    std::string equanations[3];
    std::string equanationsStrings[] = { "pierwsze", "drugie", "trzecie" };

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Proszę wprowadzić " << equanationsStrings[i] << " równianie (niewiadome: x,y,z). \n";
        std::getline(std::cin, equanations[i]);

        if (!CheckRquanationCorrectness(equanations[i]))
        {
            do
            {
                std::cout << "Wprowadzono nieprawidłowe równanie. Ponów próbę. \n";
                std::getline(std::cin, equanations[i]);
            } while (!CheckRquanationCorrectness(equanations[i]));
        }
    }
    std::cout << "\n\n";
    NormalizeSets normalize(equanations[0], equanations[1], equanations[2]);

    std::vector<std::vector<int>> normalized = normalize.GetNormalized();

    SolveSets solve(normalized);
    
    std::string determination = solve.GetDetermination();

    if (determination == "contradictory")
        std::cout << "Układ jest sprzeczny. Brak rozwiązań.\n";
    else if (determination == "indeterminate")
        std::cout << "Układ jest nieoznaczony. Posiada nieskończenie wiele rozwiązań.\n";
    else
    {
        std::vector<double> res = solve.GetResoultion();
        std::cout << "Układ jest oznaczony. Rozwiązania: \n";
        std::cout << "x: " << res[0] << "\ny: " << res[1] << "\nz: " << res[2] << "\n";
    }
   
    std::string xx;
    std::cin >> xx;
}


bool CheckRquanationCorrectness(std::string eq)
{
    int equalNumber = 0;
    char allowedChars[] = { '+', '-', '=', ' ', 'x', 'y', 'z' };
    for (int i = 0; i < eq.length(); i++)
    {
        char* found = std::find(std::begin(allowedChars), std::end(allowedChars), eq[i]);
        // When the element is not found, std::find returns the end of the range
        if (!isdigit(eq[i]) && found == std::end(allowedChars))
            return false;

        if (eq[i] == '=')
            equalNumber++;
    }

    if (eq.find('x') == std::string::npos && eq.find('y') == std::string::npos && eq.find('y') == std::string::npos)
        return false;

    if (eq.length() < 3)
        return false;

    if (equalNumber != 1)
        return false;

    return true;
}
