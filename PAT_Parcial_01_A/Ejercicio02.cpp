#include "Ejercicio02.h"

int Ejercicio02::countStudents(vector<char>* students, vector<char>* sandwiches)
{
    if (students->empty() || sandwiches->empty())
    {
		return students->size();
	}
	int i = 0;
	int j = 0;
	while (i < students->size() && j < sandwiches->size())
    {
		if (students->at(i) == sandwiches->at(j))
        {
			students->erase(students->begin() + i);
			sandwiches->erase(sandwiches->begin() + j);
			i = 0;
			j = 0;
		}
		else {
			i++;
		}
	}
	return students->size();
}

