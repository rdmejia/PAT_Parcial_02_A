#include "pch.h"

#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

#include "../PAT_Parcial_01_A/Ejercicio02.h"

using ::testing::TestWithParam;
using ::testing::ValuesIn;
using ::std::tuple;
using ::std::vector;
using ::std::string;

namespace P02Tests {
	class E02Tests : public TestWithParam<tuple<string, string, int>> {
	protected:
		Ejercicio02* e02;
		string students;
		string sandwiches;
		int expected;

		void SetUp() override {
			e02 = new Ejercicio02();
			std::tie(students, sandwiches, expected) = GetParam();
		}

		void TearDown() override {
			delete e02;
			e02 = nullptr;
		}
	
	public:
		static vector<tuple<string, string, int>> ReadParams() {
			vector<tuple<string, string, int>> params;

			std::ifstream paramsFile("e02.csv");
			string line;

			while (std::getline(paramsFile, line)) {
				std::stringstream strStream(line);

				string students;
				std::getline(strStream, students, ',');

				string sandwiches;
				std::getline(strStream, sandwiches, ',');

				string expectedString;
				std::getline(strStream, expectedString, ',');
				int expected = std::stoi(expectedString);

				params.push_back(tuple<string, string, int>(students, sandwiches, expected));
			}

			return params;
		}
	};

	TEST_P(E02Tests, E02NotEatingLunch) {
		vector<char> _students(students.begin(), students.end());
		vector<char> _sandwiches(sandwiches.begin(), sandwiches.end());

		int actual = e02->countStudents(&_students, &_sandwiches);

		EXPECT_EQ(expected, actual) << "La cantidad de estudiantes no es la esperada. Se esperaba [" << expected << "], pero se obtubo [" << actual << "].";
	}

	INSTANTIATE_TEST_CASE_P(E02NotAbleToEatLunch, E02Tests, ValuesIn(E02Tests::ReadParams()));
}