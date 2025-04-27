#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "usage : " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty())
	{
		std::cerr << "s1 is empty" << std::endl;
		return (1);
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cerr << "Error opening file: " << filename << std::endl;
		return 1;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cerr << "Error creating output file: " << filename + ".replace" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos,s2);
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}