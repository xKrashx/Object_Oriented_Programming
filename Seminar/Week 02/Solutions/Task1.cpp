#include <iostream>
#include <cstddef>
#include <fstream>
#include <cstring>
#include <new>

size_t const capacity = 1024;

struct StudentRecord{

	char firstName[capacity];
	char lastName[capacity];
	char fnRaw[capacity];
	char email[capacity];

	int fn;

};

struct StudentCollection{

	StudentRecord *data;
	size_t studentsCount;

};

size_t getLinesCount(std::ifstream &file){

	size_t count = 0;
    char buff[capacity];

	while(!file.eof()){

		file.getline(buff, capacity);
		++count;

	}
	
	file.seekg(0, std::ios::beg);

	return count;

}

void parseField(char * const dest, char const *source){

    size_t index = 0;

	while(source[index] != ',' && source[index] != '\0'){

        dest[index] = source[index];
        index++;

    }

	source += index + 1;
	dest[index] = '\0';

}

void parseFn(StudentRecord &currentStudent){

	if(strlen(currentStudent.fnRaw) < 5) return;
	currentStudent.fn = atoi(currentStudent.fnRaw + 5);

}

void parseStudent(StudentRecord &currentStudent, const char *line){

	parseField(currentStudent.firstName, line);
	parseField(currentStudent.lastName, line);
	parseField(currentStudent.fnRaw, line);
	parseField(currentStudent.email, line);
	parseFn(currentStudent);

}

StudentRecord *find(StudentCollection const &collection, int const fn){

    for(size_t i = 0; i < collection.studentsCount; ++i)
        if(collection.data[i].fn == fn) return collection.data + i;
    return nullptr;

}

void printStudent(const StudentRecord &st){

	std::cout << "First name: " << st.firstName
        << ", second name: " << st.lastName
        << ", number: " << st.fn
        << ", email: " << st.email
        << '\n';

}

void initStudentCollection(StudentCollection &collection, char const * const fileName){
	
	std::ifstream file(fileName);

	if(!file.is_open()){

		std::cout << "Error while reading from file!" << '\n';

		collection.studentsCount = 0;
		collection.data = nullptr;

		return;

	}

	size_t linesCount = getLinesCount(file);
	size_t studentsCount = linesCount - 1;
	
	if(!studentsCount) return;
	
	collection.studentsCount = studentsCount;
	collection.data = new(std::nothrow) StudentRecord[studentsCount];

	if(!collection.data) return;

	char buff[capacity];
	file.getline(buff, capacity); // skip the header

	for(size_t i = 0; i < studentsCount; i++){

		file.getline(buff, capacity);
		parseStudent(collection.data[i], buff);

	}

}

void saveToFile(char const * const fileName, StudentCollection const &collection){

	std::ofstream file(fileName);

	if(!file.is_open()) return;

	file << "Ime, Familiya, Fakulteten nomer, Imeyl adres" << '\n';

	for(int i = 0; i < collection.studentsCount; i++)
	    file << collection.data[i].firstName << ","
            << collection.data[i].lastName << ","
            << collection.data[i].fnRaw << ","
            << collection.data[i].email << '\n';

}

void menu(StudentCollection &collection){

    char command[capacity];
    char name[capacity];
    char str[capacity];
    int fn;

    do{

        std::cin >> command;

        if(!strcmp(command, "save")){

            std::cin >> name;
            saveToFile(name, collection);
            break;

        }

        if(!strcmp(command, "print")){

            std::cin >> fn;
            StudentRecord *query = find(collection, fn);
            if(!query) continue;
            printStudent(*query);

        }

        if(!strcmp(command, "edit")){

            std::cin >> fn >> str;
            StudentRecord *query = find(collection, fn);
            if(!query) continue;
            strcpy(query -> email, str);

        }

    }while(strcmp(command, "save"));

}

int main(){

	char fileName[capacity];

    std::cout << "Open File:\n>";
    std::cin >> fileName;
    std::cin.ignore();
    
	StudentCollection collection;
	initStudentCollection(collection, fileName);

	if(!collection.data){

		std::cout << "Memory error\n";
		return -1;

	}

	if(!collection.studentsCount){

	    std::cout << "Error! No students loaded!" << std::endl;
	    return -1;

	}

    menu(collection);
    
	delete[] collection.data;
	return 0;

}
