#include <iostream>
#include <cstring>
#include <cstddef>

namespace Students{

	enum class Major : uint8_t{

		CS,
		IS,
		I,
		SI,
		UNKNOWN

	};

	void PrintMajor(Major const major){

        if(major == Major::CS) std::cout << "Computer science\n";
        else if(major == Major::IS) std::cout << "Information systems\n";
        else if(major == Major::I) std::cout << "Informatics\n";
        else if(major == Major::SI) std::cout << "Software engineering\n";
        else if(major == Major::UNKNOWN) std::cout << "Unknown\n";

	}

	struct Student{

		char name[24] = "";
		int fn = -1;
		Major studentMajor = Major::UNKNOWN;

	};

	void print(Student const &st){

		std::cout << "Name: " << st.name << ", fn: " << st.fn << " ";
		PrintMajor(st.studentMajor);
		std::cout << '\n';

	}

}

namespace Group{

	using namespace Students;

	size_t const STUDENTS_COUNT = 4;

	struct StudentGroup{
		Student students[STUDENTS_COUNT];
	};

	enum class SortBy : uint8_t{

		name,
		fn,
		major

	};

	bool compare(Student const &lhs, Student const &rhs, SortBy const sortBy){

		switch (sortBy){

            case SortBy::name:
                return strcmp(lhs.name, rhs.name) < 0;

            case SortBy::fn:
                return lhs.fn < rhs.fn;

            case SortBy::major:
                return lhs.studentMajor < rhs.studentMajor;

            default:
                return false;

		}

	}

	void sortStudentsInUni(StudentGroup &group, SortBy const sortBy){

		for(size_t i = 0; i < STUDENTS_COUNT - 1; i++){

			size_t minIndex = i;
			for(size_t j = i; j < STUDENTS_COUNT; j++)
				if(compare(group.students[j], group.students[minIndex], sortBy))
					minIndex = j;

			if(i != minIndex) std::swap(group.students[i], group.students[minIndex]);

		}

	}

	void printUni(StudentGroup const &group){

		for(size_t i = 0; i < STUDENTS_COUNT; i++)
			print(group.students[i]);

	}

}

int main(){

	using namespace Group;

	StudentGroup uni{ "Ivan Petrov", 434, Major::CS ,
			"Peter Ivanov", 987, Major::SI,
			"Alex Angelov", 12, Major::I  ,
			"Kristian Kasabov", 12, Major::I};

	printUni(uni);
	std::cout << "----------------\n";
	sortStudentsInUni(uni, SortBy::name);
	printUni(uni);
	std::cout << "----------------\n";
	sortStudentsInUni(uni, SortBy::fn);
	printUni(uni);
	std::cout << "----------------\n";

	sortStudentsInUni(uni, SortBy::major);
	printUni(uni);
	std::cout << "----------------\n";

	return 0;

}