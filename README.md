# Caesar
Encrypt/Decrypt strings of text or text files with Caesar cryptosystem

# Usage
Say I need my text file `plaintext.txt` encrypted with Caesar cryptosystem and `key = 13`

All I need to do is to
  - compile `caesar_driver.cpp` and 
  - enter the following in terminal: `./a.out encrypt 13 plaintext.txt`

If I want my result file to have a specific name, I enter its name in the end:
   
   - `./a.out encrypt 13 plaintext.txt myEncryptedText.txt`

> *Be careful not to name the input file same as the default output file name(i.e. `output.txt`).*

> `caesar_driver.cpp` only encrypts/decrypts text files but feel free to write another driver code to work specifically on strings, only requiring `caesar.h`
