#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "caesar.h"
#include "fcaesar.h"

void prompt_usage()
{
    std::cout << "Usage: ./substitution command[decrypt/encrypt] key file[OPTIONAL]\n";
}

void do_command(std::string command, int key, std::string inputPath, std::string outputPath="")
{
    if (command == "encrypt")
    {
        encrypt_file(key, inputPath, outputPath);
    }
    else if (command == "decrypt")
    {
        decrypt_file(key, inputPath, outputPath);
    }
}

int main(int argc, char* argv[])
{
    if (argv[1] == "help")
    {
        prompt_usage();
        return 0;
    }
    // check if arguments have been given
    if (argc < 4 || (argc == 4 && is_number(argv[1])))
    {
        prompt_usage();
        return 1;
    }

    std::string command;
    try {
        // check if command is valid
        if (strcmp(argv[1], "encrypt") == 0 || strcmp(argv[1], "decrypt") == 0)
            command = argv[1];
        else
            throw("Not a valid command");
    }
    catch(char const* exp)
    {
        std::cout << exp << std::endl;
        return 2;
    }

    // check if key is valid
    if (!is_valid_key(argv[2]))
    {
        std::cout << "Not a valid key!\n";
        return 3;
    }
    int key = string_to_key(argv[2]);

    try {
        if (argc == 4)
            do_command(argv[1], key, argv[3]);
        else
            do_command(argv[1], key, argv[3], argv[4]);
    }
    catch (char const* exp)
    {
        std::cout << exp << std::endl;
        return 5;
    }

    return 0;
}
