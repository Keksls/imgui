#include "imgui_assert_handler.h"

#include <cstdio>
#include <cstdlib>

static void DefaultAssertCallback(const char* expr, const char* file, int line)
{
    fprintf(stderr, "[IM_ASSERT] %s failed at %s:%d\n", expr, file, line);
    fflush(stderr);
}

static AssertCallbackFn& GetAssertCallback()
{
    static AssertCallbackFn callback = &DefaultAssertCallback;
    return callback;
}

FUGUI_ASSERT_API void HandleImGuiAssert(const char* expr, const char* file, int line)
{
    AssertCallbackFn cb = GetAssertCallback();
    if (cb)
        cb(expr, file, line);
    else
        DefaultAssertCallback(expr, file, line);
}

FUGUI_ASSERT_API void SetImGuiAssertCallback(AssertCallbackFn callback)
{
    GetAssertCallback() = callback;
}
