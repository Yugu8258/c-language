#include "pointer_safety.h"
#include "error_handling.h"
#include <stdlib.h>

bool is_nullptr(const void *ptr)
{
    if (ptr == NULL)
    {
        log_error("Detected a NULL pointer.");
        return true;
    }

    return false;
}

