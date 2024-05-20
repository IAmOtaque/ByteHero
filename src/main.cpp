/*  By IAmOtaque
    ByteHero
    Group Reflection, LLC.
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#ifdef _WIN32
#include <conio.h>
#endif

void program_info() {
    std::cout << "ByteHero Jack (0.0.1) by IAmOtaque" << std::endl << std::endl;
}

int main() {
    char filename[100];
    unsigned int neededSize;

    program_info();
    std::cout << "Enter the file name/path: ";
    std::cin >> filename;

    std::cout << "Enter your arbitrary size (in bytes): ";
    std::cin >> neededSize;

    FILE* file = fopen(filename, "rb+");

    if (file == nullptr) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }
    fseek(file, 0, SEEK_END);
    size_t currentSize = ftell(file);
    int difference = neededSize - currentSize;

    if (difference > 0) {
        char nullByte = 0x00;
        for (size_t i = 0; i < difference; i++) {
            fwrite(&nullByte, sizeof(char), 1, file);
        }

        std::cout << "Added " << difference << " null bytes to the file." << std::endl;
    } else {
        std::cout << "The file is already at the needed size or larger." << std::endl;
    }

    fclose(file);

    #ifdef _WIN32
    getch();
    #endif
    return 0;
}