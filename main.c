#include "includes.h"

int main(int argc, char const *argv[])
{

    isFileExist("Hello.txt");

    printDivision(25, 0);

    //ctrl_c_handler(); //EX-4

    printf("\n\n");

    printFirstNotEqualRowInTwoFiles("file1.txt", "file2.txt"); // EX-5

    //timeLoop();


    return 0;
}
