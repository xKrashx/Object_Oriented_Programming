<h1>File Streams:</h1>

<h3>Type of streams for files</h3>
	
	std::ofstream - This data type represents the output file stream and is used to create files and to write 
	           information to files.

	std::ifstream - This data type represents the input file stream and is used to read information from files.

	std::fstream  - This data type represents the file stream generally, and has the capabilities of both 
	           ofstream and ifstream which means it can create files, write information to files, and read 
	           information from files.


<h3>Type of flags</h3>

	std::ios::app   - Append mode. All output to that file to be appended to the end.
	std::ios::ate   - Open a file for output and move the read/write control to the end of the file.
	std::ios::in    - Open a file for reading.
	std::ios::out   - Open a file for writing.
	std::ios::trunc - If the file already exists, its contents will be truncated before opening the file.
    std::ios::binary - Open a binary file

<h3>read & write BINARY</h3>

	std::ofstream outFile("<filename>", std::ios::binary);

	outFile.write((const char*)<address_of_object_to_write>, sizeof(<object_type>));

	outFile.seekp(<bytes>); //beg, end, cur  - sets the position where the next character is to be inserted
	outFile.tellp(); - gets the position from the beginning of the file

	std::ifstream inFile("<filename>", std::ios::binary);

	inFile.seekg(<bytes>); //beg, end, cur - sets the position where the next character is to be read
	inFile.tellg(); - gets the position from the beginning of the file

	inFile.read((char*)<address_of_object_to_read>, sizeof(<object_type>));