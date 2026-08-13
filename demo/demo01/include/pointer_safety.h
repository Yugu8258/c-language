#pragma once

#include <stdboo.h>

bool is_nullptr(const void *ptr);

#define SAFF_DEREF(ptr, defaultValue) \ (is_nullptr(ptr) ? (log_error("Attempted to dereference a NULL pointer."), defaultValue) : *(ptr))

