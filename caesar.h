// Encrypt/decrypt given strings with caesar cipher
#ifndef CAESAR_H
#define CAESAR_H

#include <iostream>
#include <ctype.h>
#include <string>

const int ALPHABET_SIZE = 26;

int string_to_key(const char* k)
{
    int key = atoi(k);
    return  (key < 0) ? (ALPHABET_SIZE + key) : key;
}

int reversed_key(int key) {
    return ALPHABET_SIZE - key;
}

std::string encrypt(std::string text, int key)
{
    // encrypt alphabetical characters, but leave the other chars (i.e. ',', '*', '!' etc)
    std::string encrypted;

    for (int i = 0; i < text.size(); i++)
    {
        if (isupper(text[i]))
            encrypted += char(int(text[i] + key - 65) % ALPHABET_SIZE + 65);
        else if (islower(text[i]))
            encrypted += char(int(text[i] + key - 97) % ALPHABET_SIZE + 97);
        else
            encrypted += text[i];
    }

    return encrypted;
}

std::string decrypt(std::string text, int key)
{
    return encrypt(text, reversed_key(key));
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

bool is_valid_key(std::string k)
{
    return is_number(k) || (k[0] == '-' && is_number(k.substr(1, k.size() - 1)));
}

#endif
