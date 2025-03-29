// Created: 2018-02-01 16:00:00
// Last modified: 2018-02-01 16:00:00
//#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <iostream>
#include "Bitmap.h"

#define UNUSED(x) ((void)(x))

using namespace std;
using namespace caveofprogramming;

int main() {
    Bitmap bitmap(800, 600);

    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

    
    printf("Hello, World!\n");
    FILE* file = fopen("log.txt", "w");
    const char* text = "Hello, World!";
    size_t bytesWritten = fwrite(text, 1, strlen(text), file);
    printf("Bytes written: %zu\n", bytesWritten);
    fclose(file);
    

    UNUSED(getchar());
    return 0;
}
