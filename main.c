#include <stdlib.h>

#include "st.h"
#ifdef _WIN32
#include <io.h>
#define F_OK 0
#else
#include <unistd.h>
#endif

float strtof(const char *str, char **endptr) {
  return (float) strtod(str, endptr);
}


static const char *const bootstrap[] = {
					"bootstrap/basic.st",
					"bootstrap/mag.st",
					"bootstrap/collect.st",
					"bootstrap/file.st",
					"bootstrap/mult.st",
					"bootstrap/tty.st",
};


int main(int argc, char **argv) {
	if(access("systemImage", F_OK)!=-1) {
		return st_main();
	} else {
		st_initial_main(6, bootstrap);
	}
}
