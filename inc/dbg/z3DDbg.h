
#ifndef Z3DDBG_H_
#define Z3DDBG_H_

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


/**
    @defgroup Z3DDEBUG Error handling and debug utilits

Short manual

Debug mode is active when Z3D_DEBUG macro is defined.

Use Z3D_ASSERT(exp) for asserts.

Use Z3D_ERROR(exp, q).
 - If no expression is required pass Z3D_DEBUG_NOEXP through the 'exp'.
 - For aborting an application pass true through the 'q'.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>



// Breakpoint
#ifdef Z3D_DEBUG

    #ifdef _MSC_VER
        #define Z3D_DEBUG_BP() do{__asm int 3;} while (0)
    #endif // _MSC_VER

    #ifdef __GNUC__
        #define Z3D_DEBUG_BP() do{__asm__ ("int $3\n\t");}while (0)
    #endif // __GNUC__

#else
    #define Z3D_DEBUG_BP(skip)
#endif //Z3D_DEBUG


/**
	@brief assert
	@ingroup Z3DDEBUG
*/
#ifdef Z3D_DEBUG
    #define Z3D_ASSERT(exp)                                                                 \
    {                                                                                       \
        if (!(exp))                                                                         \
        {                                                                                   \
            z3D::DebugTool::Print(z3D::DebugTool::kAssert, __FILE__, __LINE__, #exp, "\n");   \
            z3D::DebugTool::Log(z3D::DebugTool::kAssert, __FILE__, __LINE__, #exp, "\n");     \
            Z3D_DEBUG_BP();                                                                 \
        }                                                                                   \
    }
#else
    #define Z3D_ASSERT(exp)
#endif // Z3D_DEBUG



#define Z3D_DEBUG_NOEXP "NOEXP"



/**
    @brief error handling.
    @ingroup Z3DDEBUG
    @param exp expression with error.
    @param q if true abort the application.
    @date 2015-12-26
*/
#define Z3D_ERROR(exp, q)                                                   \
{                                                                           \
    z3D::DebugTool::Print(z3D::DebugTool::kError,                           \
                          __FILE__, __LINE__,                               \
                          #exp,                                             \
                          "\n");                                            \
    z3D::DebugTool::Log(z3D::DebugTool::kError,                             \
                         __FILE__, __LINE__,                                \
                        #exp,                                               \
                        "\n");                                              \
    if ((q)) exit (EXIT_FAILURE);                                           \
                                                                            \
}



/**
    @brief error handling with user message.
    @ingroup Z3DDEBUG
    @param exp expression with error.
    @param fmt user message format string.
    @param q if true abort the application.
    @date 2015-12-26
*/
#define Z3D_ERROR_NOARG(exp, fmt, q)                                        \
{                                                                           \
    z3D::DebugTool::Print(z3D::DebugTool::kError,                           \
                          __FILE__, __LINE__,                               \
                          #exp,                                             \
                          "\n"                                              \
                          fmt);                                             \
    z3D::DebugTool::Log(z3D::DebugTool::kError,                             \
                        __FILE__, __LINE__,                                 \
                        #exp,                                               \
                        "\n"                                                \
                        fmt);                                               \
    if ((q)) exit (EXIT_FAILURE);                                           \
                                                                            \
}



/**
    @brief error handling with user message (1 arg).
    @ingroup Z3DDEBUG
    @param exp expression with error.
    @param fmt user message format string.
    @param arg1 1st argument of user message.
    @param q if true abort the application.
    @date 2015-12-26
*/
#define Z3D_ERROR_1ARG(exp, fmt, arg1, q)                                   \
{                                                                           \
    z3D::DebugTool::Print(z3D::DebugTool::kError,                           \
                          __FILE__, __LINE__,                               \
                          #exp,                                             \
                          "\n"                                              \
                          fmt,                                              \
                          (arg1) );                                         \
    z3D::DebugTool::Log(z3D::DebugTool::kError,                             \
                        __FILE__, __LINE__,                                 \
                        #exp,                                               \
                        "\n"                                                \
                        fmt,                                                \
                        (arg1) );                                           \
    if ((q)) exit (EXIT_FAILURE);                                           \
                                                                            \
}



/**
    @brief error handling with user message (2 args).
    @ingroup Z3DDEBUG
    @param exp expression with error.
    @param fmt user message format string.
    @param arg1 1st argument of user message.
    @param arg2 2nd argument of user message.
    @param q if true abort the application.
    @date 2015-12-26
*/
#define Z3D_ERROR_2ARG(exp, fmt, arg1, arg2, q)                             \
{                                                                           \
    z3D::DebugTool::Print(z3D::DebugTool::kError,                           \
                          __FILE__, __LINE__,                               \
                          #exp,                                             \
                          "\n"                                              \
                          fmt,                                              \
                          (ar1), (arg2) );                                  \
    z3D::DebugTool::Log(z3D::DebugTool::kError,                             \
                        __FILE__, __LINE__,                                 \
                        #exp,                                               \
                        "\n"                                                \
                        fmt,                                                \
                        (arg1), (arg2) );                                   \
    if ((q)) exit (EXIT_FAILURE);                                           \
                                                                            \
}



/**
    @brief warning outputs.
    @ingroup Z3DDEBUG
    @param exp expression.
    @date 2015-12-26
*/
#define Z3D_WARNING(exp)                                                    \
{                                                                           \
    z3D::DebugTool::Print(z3D::DebugTool::kWarning,                         \
                          __FILE__, __LINE__,                               \
                          #exp,                                             \
                          "\n");                                            \
    z3D::DebugTool::Log(z3D::DebugTool::kWarning,                           \
                         __FILE__, __LINE__,                                \
                        #exp,                                               \
                        "\n");                                              \
}



/**
    @brief warning outputs with user message.
    @ingroup Z3DDEBUG
    @param exp expression.
    @param fmt user message format string.
    @date 2015-12-26
*/
#define Z3D_WARNING_NOARG(exp, fmt)                                         \
{                                                                           \
    z3D::DebugTool::Print(z3D::DebugTool::kWarning,                         \
                          __FILE__, __LINE__,                               \
                          #exp,                                             \
                          "\n"                                              \
                          fmt);                                             \
    z3D::DebugTool::Log(z3D::DebugTool::kWarning,                           \
                        __FILE__, __LINE__,                                 \
                        #exp,                                               \
                        "\n"                                                \
                        fmt);                                               \
}



/**
    @brief warning outputs with user message (1 arg).
    @ingroup Z3DDEBUG
    @param exp expression.
    @param fmt user message format string.
    @param arg1  1st argument of user message.
    @date 2015-12-26
*/
#define Z3D_WARNING_1ARG(exp, fmt, arg1)                                    \
{                                                                           \
    z3D::DebugTool::Print(z3D::DebugTool::kWarning,                         \
                          __FILE__, __LINE__,                               \
                          #exp,                                             \
                          "\n"                                              \
                          fmt,                                              \
                          (arg1) );                                         \
    z3D::DebugTool::Log(z3D::DebugTool::kWarning,                           \
                        __FILE__, __LINE__,                                 \
                        #exp,                                               \
                        "\n"                                                \
                        fmt,                                                \
                        (arg1) );                                           \
}



/**
    @brief warning outputs (2 args).
    @ingroup Z3DDEBUG
    @param exp expression.
    @param fmt user message format string.
    @param arg1 1st argument of user message.
    @param arg2 2nd argument of user message.
    @date 2015-12-26
*/
#define Z3D_WARNING_2ARG(exp, fmt, arg1, arg2)                              \
{                                                                           \
    z3D::DebugTool::Print(z3D::DebugTool::kWarning,                         \
                          __FILE__, __LINE__,                               \
                          #exp,                                             \
                          "\n"                                              \
                          fmt,                                              \
                          (ar1), (arg2) );                                  \
    z3D::DebugTool::Log(z3D::DebugTool::kWarning,                           \
                        __FILE__, __LINE__,                                 \
                        #exp,                                               \
                        "\n"                                                \
                        fmt,                                                \
                        (arg1), (arg2) );                                   \
}



namespace z3D
{

/*
Отладочный инструмент.
Функции Log и Print практически идентичны. Разница только в том, что
Log пишет в файл, а Print производит печать в консоль.
*/
class DebugTool
{
    // Запрещаем создание экземпляра
    DebugTool();

public:
    // Тип события
    enum eMsgType
    {
        // Просто текст
        kNone,

        // Ошибка
        kError,

        // Нарушение утверждения
        kAssert,

        // Предупреждение
        kWarning
    };


    /*
    Назначение: запись сообщения в файл лога.
    Параметры msgType:          тип сообщения.
        filename:               имя файла, связанного с сообщением.
        nLine:                  номер строки в файле, связанной с сообщением.
        exp:                    строка выражения.
        fmt:                    строка формата, после которой могут идти сообщения.
    Примечания: для простых сообщений (тип kNone) параметры filename, nLine, exp
                игнорируются (можно передать нули). Для сообщений об ошибках и т.п. через
                filename передается имя файла с ошибкой, nLine - номер строки с ошибкой,
                exp - выражение с ошибкой.
    Создан: 2015-12-10.
    */
    static inline
    void Log(eMsgType msgType,
                        const char* filename,
                        int nLine,
                        const char* exp,
                        const char* fmt, ...)
    {
        char typeStrHeader[32];
        char typeStrFooter[32];

        if (msgType == kError)
        {
            sprintf(typeStrHeader, "Error");
            sprintf(typeStrFooter, "found in file");
        }
        else if (msgType == kAssert)
        {
            sprintf(typeStrHeader, "Assert");
            sprintf(typeStrFooter, "failed in file");
        }
        else if (msgType == kWarning)
        {
            sprintf(typeStrHeader, "Warning");
            sprintf(typeStrFooter, "reported on file");
        }
        static bool fLog = false;
        static FILE* f;
        static const char* logfilename = "z3DLibDebugLog.txt";
        if (!fLog)
        {
            // Попытка открыть файл лога для чтения
            f = fopen(logfilename, "r");
            if (f != 0)
            {
                // Удаляем файл, если он существует
                fclose(f);
                remove(logfilename);
            }
            fLog = true;
        }
        // Пишем в лог
        //
        f = fopen(logfilename, "a");
        if (f == 0) return;

        if (msgType != kNone)
        {
            fprintf(f, "%s (%s) %s \"%s\"(%d)\n    Details: ",
                typeStrHeader,
                exp,
                typeStrFooter,
                filename,
                nLine);
        }

        va_list ptr;
        va_start(ptr, fmt);
        vfprintf(f, fmt, ptr);
        va_end(ptr);

        fprintf(f, "\n");
        fclose(f);

    }



    /*
    Назначение: вывод в консоль сообщения.
    Параметры msgType:          тип сообщения.
        filename:               имя файла, связанного с сообщением.
        nLine:                  номер строки в файле, связанной с сообщением.
        exp:                    строка выражения.
        fmt:                    строка формата, после которой могут идти сообщения.
    Примечания: для простых сообщений (тип kNone) параметры filename, nLine, exp
                игнорируются (можно передать нули). Для сообщений об ошибках и т.п. через
                filename передается имя файла с ошибкой, nLine - номер строки с ошибкой,
                exp - выражение с ошибкой.
    Создан: 2015-12-10.
    */
    static inline
    void Print(eMsgType msgType,
                        const char* filename,
                        int nLine,
                        const char* exp,
                        const char* fmt, ...)
    {
        char typeStrHeader[32];
        char typeStrFooter[32];

        if (msgType == kError)
        {
            sprintf(typeStrHeader, "Error");
            sprintf(typeStrFooter, "found in file");
        }
        else if (msgType == kAssert)
        {
            sprintf(typeStrHeader, "Assert");
            sprintf(typeStrFooter, "failed in file");
        }
        else if (msgType == kWarning)
        {
            sprintf(typeStrHeader, "Warning");
            sprintf(typeStrFooter, "reported on file");
        }

        if (msgType != kNone)
        {
            printf("%s (%s) %s \"%s\"(%d)\n    Details: ",
                typeStrHeader,
                exp,
                typeStrFooter,
                filename,
                nLine);
        }

        va_list ptr;
        va_start(ptr, fmt);
        vprintf(fmt, ptr);
        va_end(ptr);
        printf ("\n");

    }

};



} // end of z3D



#endif // Z3DDBG_H_


