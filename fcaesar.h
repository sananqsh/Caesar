// Encrypt/decrypt given text files with caesar cipher
// Requires caesar.h (if caesar.h is missing, you can get it from: https://github.com/sananqsh/Caesar)
#ifndef F_CAESAR_H
#define F_CAESAR_H

#include <fstream>

#include "caesar.h"

const std::string DEFAULT_OUTPATH = "output.txt";

void encrypt_file(int key, std::string inputPath, std::string outputPath="")
{
    std::ifstream inputFile(inputPath);
    if (!inputFile.good())
    {
        throw("Could not open file.");
    }

    if (inputPath == outputPath || (outputPath == "" && inputPath == DEFAULT_OUTPATH))
    {
        char const* exp = "Input and output files can`t be the same(consider default output path in fcaesar.h)!";
        throw(exp);
    }

    if (outputPath == "")
    {
        outputPath = DEFAULT_OUTPATH;
    }

    std::ofstream outputFile(outputPath, std::ios::out);

    std::string line;
    while(getline(inputFile, line))
    {
        outputFile << encrypt(line, key) << std::endl;
    }

    outputFile.close();
    inputFile.close();
}

void decrypt_file(int key, std::string inputPath, std::string outputPath="")
{
    encrypt_file(reversed_key(key), inputPath, outputPath);
}

#endif
