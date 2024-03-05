#pragma once

#ifdef _WIN32
#define DLLExport __declspec(dllexport)
#else
#define DLLExport
#endif

extern "C"{
    DLLExport void func();
}