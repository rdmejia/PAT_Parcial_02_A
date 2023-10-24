#include "Ejercicio02.h"

int Ejercicio02::countStudents(vector<char>* students, vector<char>* sandwiches)
{
    int studentsWithoutPreferredSandwich = 0;x

    for (int i = 0; i < students->size(); ++i) {
        char preferredSandwich = (*students)[i];
        bool foundPreferredSandwich = false;

        for (int j = 0; j < sandwichesLeft; ++j) 
        {
            if ((*sandwiches)[j] == preferredSandwich) 
            {
                sandwichesLeft--;
                (*sandwiches).erase((*sandwiches).begin() + j);
                foundPreferredSandwich = true;
                break;
            }
        }

        if (!foundPreferredSandwich) {
            studentsWithoutPreferredSandwich = students->size() - i;
            break;
        }
    }

    return studentsWithoutPreferredSandwich;
}

