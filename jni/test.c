#include <stdio.h>
#include <string.h>

void test_help();

int test_main(int argc, char **argv) {

  if (argc > 1 && strcmp(argv[1], "--help") == 0 ) { test_help(); return 0; }

  printf("argc : [%d]\n", argc);

  for (int i = 0; i < argc; i++) {
    printf("%d : \"%s\"\n", i, argv[i]);
  }
  return 0;
}
