/*
Copyright (c) 2015-2016 Zavod3D graphic engine project. Author: Marat Sungatullin.


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:


The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <stdio.h>
#include <conio.h>
#include <ctime>

#include "dbg/z3ddbg.h"

void goOn()
{
    printf ("Press any key to continue...\n");
    getch();
}




void example01()
{
    // Задаем имя файла как текущее время - такой файл, наверняка, не существует в папке с исполняемым файлом
    std::time_t t = std::time(0);
    char filename[64];
    std::strftime(filename, 64, "%Y-%b-%d[%H-%M-%S]", std::localtime(&t));

    FILE* f = fopen(filename, "r");
    Z3D_ASSERT(f != 0);

    if (f == 0)
    {
        Z3D_ERROR_1ARG(f == 0, "File \"%s\" is not exist", filename, false);
    }
}



void example02()
{

   Z3D_ERROR(Z3D_DEBUG_NOEXP, false);
}



void example03()
{
    const char* filename = 0;

    if (filename == 0)
    {
        Z3D_WARNING_1ARG(filename = 0, "File name is not given", filename);
    }
}



int main(int argc, char** argv)
{

	example01();
    example02();
    example03();

	// quit trigger
	printf("Press any key to quit...");
	getch();
	return 0;
}
