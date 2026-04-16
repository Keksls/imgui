#pragma once
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef void(*AssertCallbackFn)(const char* expr, const char* file, int line);

    void SetImGuiAssertCallback(AssertCallbackFn callback);
    void HandleImGuiAssert(const char* expr, const char* file, int line);

#ifdef __cplusplus
}
#endif
