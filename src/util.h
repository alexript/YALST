
#ifndef __UTIL_H
#define __UTIL_H

#include <string.h>
#include <stdlib.h>

#include "tty.h"

static inline boolean streq(const char *a, const char *b) {
    return strcmp(a,b) == 0;
} 

// Call calloc(), failing on error.
static inline void *ck_calloc(size_t count, size_t size) {
  if(count==0)count++; // TODO: check and fix. count should not be 0, from my point of view
    void *result = calloc(count, size);
    if (!result) {
      char buf[100];
      sprintf(buf, "Memory error: calloc(%d, %d) failed.",count, size);
      sysError(buf,"");
    }
    return result;
}

// This is wrong (assumes 16-bit int) but I'm keeping it for now until
// I get a better set of tests.
static inline int longCanBeInt(long l) {
    return l >= OBJINT_MIN && l <= OBJINT_MAX;
}

#endif
