#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool pesquisaChar(string, char);
string removeDuplicados(string);

int main()
{
    int numTestes;
    cin >> numTestes;
    getchar(); // remove erro ao usar getline depois de cin

    for (int i = 0; i < numTestes; i++)
    {
        string dieta, cafe, almoco;

        getline(cin, dieta);
        sort(dieta.begin(), dieta.end());
        dieta = removeDuplicados(dieta);

        getline(cin, cafe);
        getline(cin, almoco);

        string jaComeu = cafe + almoco;
        bool cheater = false;

        for (int j = 0; jaComeu[j]; ++j)
        {
            if (!pesquisaChar(dieta, jaComeu[j]))
            {
                cheater = true;
                break;
            }
            else
                dieta.erase(remove(dieta.begin(), dieta.end(), jaComeu[j]), dieta.end());
        }

        if (cheater)
            cout << "CHEATER" << endl;
        else
            cout << dieta << endl;
    }

    return 0;
}

bool pesquisaChar(string str, char caractere)
{
    bool encontrou = false;
    int i = 0;

    while (!encontrou && i < str.length())
    {
        if (str[i] == caractere)
            encontrou = true;
        else
            i++;
    }

    return encontrou;
}

string removeDuplicados(string str)
{
    string newStr = "";
    bool jaTem;

    for (int i = 0; str[i]; ++i)
    {
        jaTem = false;

        for (int j = 0; newStr[j]; ++j)
        {
            if (str[i] == newStr[j])
            {
                jaTem = true;
                break;
            }
        }

        if (!jaTem)
            newStr += str[i];
    }

    return newStr;
}