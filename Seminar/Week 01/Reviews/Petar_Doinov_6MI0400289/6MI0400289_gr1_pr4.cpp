#include <iostream>

struct student {
	unsigned int stNumber;
	unsigned int course : 3;
	float grade;
};

struct group {
	unsigned int N = 0;
	student* arr;
	float avGrade = 0;
};

// Същите забележки за входа както на другите задачи.
float validFloat() {
	float temp = -1000;
	do {
		char c = std::cin.peek();
		while (c != '-' && (c < '0' || c > '9')) {
			std::cin.ignore();
			c = std::cin.peek();
		}
		c = getchar();
		if (c == '-') {
			c = std::cin.peek();
			if (c < '0' || c > '9') {
				continue;
			}
		}
		std::cin.unget();
		std::cin >> temp;
		//std::cout << temp << std::endl;
	} while (false);
	return temp;
}

void initStudent(student& st) {
	float temp = 0;
	do {
		temp = validFloat();
		if (temp < 10000 || temp > 100000) {
			std::cout << "Invalid Student Number. Please enter a number between 10000 and 100000." << std::endl;
		}
	} while (temp < 10000 || temp > 100000);
	st.stNumber = temp;

	do {
		temp = validFloat();
		if (temp < 1 || temp > 4) {
			std::cout << "Invalid course. Please enter a number between 1 and 4." << std::endl;
		}
	} while (temp < 1 || temp > 4);
	st.course = temp;

	do {
		temp = validFloat();
		if (temp < 2 || temp > 6) {
			std::cout << "Invalid grade. Please enter a number between 2 and 6." << std::endl;
		}
	} while (temp < 2 || temp > 6);
	st.grade = temp;
}

void printStudent(student& st) {
	std::cout << st.stNumber << " " << st.course << " " << st.grade << std::endl;
}

bool readGroup(group& team) {
	unsigned int temp = 0;
	do {
		temp = validFloat();
		if (temp < 1 || temp > 500) {
			std::cout << "Invalid group size. Please enter a number between 1 and 500." << std::endl;
		}
	} while (temp < 1 || temp > 500);
	team.N = temp;

	student* gr = new(std::nothrow) student[temp];
	if (!gr) {
		return false;
	}
	for (int i = 0; i < temp; i++) {
		initStudent(gr[i]);
		team.avGrade += gr[i].grade;
	}
	team.avGrade /= temp;
	team.arr = gr;
}

void printGroup(group& team) {
	for (int i = 0; i < team.N; i++) {
		printStudent(team.arr[i]);
	}
	std::cout << team.avGrade << std::endl;
}

unsigned int passed(group& team, float minSuccess) {
	unsigned int counter = 0;
	for (int i = 0; i < team.N; i++) {
		if (team.arr[i].grade >= minSuccess) {
			counter++;
		}
	}
	return counter;
}

int main() {
	group group;
	readGroup(group);
	//printGroup(group);
	float minSuccess = validFloat();
	std::cout << group.avGrade << " " << passed(group, minSuccess);
	delete[] group.arr;
}