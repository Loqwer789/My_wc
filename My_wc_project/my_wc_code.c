#include <stdio.h>
#include<string>
#include<fstream>
#include<sstream>

static int  l_result(const std::string& f_file)
{
	int counter = 0;
	std::ifstream file(f_file);
	std::string read;

	while (std::getline(file,read))
	{
		counter++;

	}
	file.close();
	return counter;
}	

static int b_result(const std::string& f_file)
{
	std::ifstream file(f_file, std::ios::binary);
	file.seekg(0, std::ios::end);
	int counter = file.tellg();
	file.close();
	return counter;
}

static int w_result(const std::string& f_file)
{
	int counter = 0;
	std::ifstream file(f_file);
	std::string read;

	while (file >> read)
	{
		counter++;
	}
	file.close();

	return counter;
}	


int main(int argc, char* argv[])
{

	std::string flag = argv[1]; 
	std::string file = argv[2]; 

int result = 0;

	if (flag == "-b")
		
	{
		result = b_result(file);
		printf("Bites: %d\n", result);	
		return 0;
	}	
	else if (flag == "-w" ) 
	{
		result = w_result(file);
		printf("Words: %d\n", result);
		return 0;
	}
	else if (flag == "-l")
	{
		result = l_result(file);
		printf("Lines: %d\n", result);
		return 0 ;
	}	

	printf("empty - no flag");
	

return 0;
}	
