#include <stdio.h>
#include <string.h>
#include <libgen.h>

void basename_help();

int basename_main(int argc, char **argv) {

  if (argc > 1 && strcmp(argv[1], "--help") == 0 ) { basename_help(); return 0; }

  printf("%s\n", basename(argv[1]));
  return 0;
}
