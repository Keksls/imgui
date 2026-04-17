#pragma once
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define FUGUI_ASSERT_API extern "C" __declspec(dllexport)
#else
#define FUGUI_ASSERT_API extern "C"
#endif

typedef void(*AssertCallbackFn)(const char* expr, const char* file, int line);

FUGUI_ASSERT_API void SetImGuiAssertCallback(AssertCallbackFn callback);
FUGUI_ASSERT_API void HandleImGuiAssert(const char* expr, const char* file, int line);
