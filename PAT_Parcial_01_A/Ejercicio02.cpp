#include "Ejercicio02.h"

int Ejercicio02::countStudents(vector<char>* students, vector<char>* sandwiches)
{
    int studentIndex = 0; 
    int sandwichIndex = 0; 
    int studentsLeft = students->size(); 

    while (sandwichIndex < sandwiches->size() && studentsLeft > 0)
    {
        if ((*students)[studentIndex] == (*sandwiches)[sandwichIndex]) 
        {
            studentIndex++;
            sandwichIndex++;
            studentsLeft--;
        } else 
        {
            studentIndex++;
            
            if (studentIndex >= students->size()) 
            {
                studentIndex = 0;
            }
        }
    }

    return studentsLeft;
}
