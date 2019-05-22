#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

class File
{
public:
	static std::vector<uint8_t> ReadAllBytes(std::string filePath)
	{
		std::ifstream file(filePath, std::ios::in | std::ios::binary | std::ios::ate);
		int fileSize = file.tellg();
		file.seekg(0);
		char* data = new char[fileSize];
		file.read(data, fileSize);
		return std::vector<uint8_t>(data, data + fileSize);
	};

	static void WriteAllBytes(std::string filePath, std::vector<uint8_t> data)
	{
		std::ofstream file(filePath, std::ios::binary);
		file.write((char*)data.data(), data.size());
	};
};