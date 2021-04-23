#include <stdio.h>
#include <string.h>

void yes_help();

int yes_main(int argc, char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { yes_help(); return 0; }

  char **pp;
  argv[0] = (char*)"y";
  if (argv[1]) { ++argv; }

  do {
    pp = argv;
    while (1) {
      fputs(*pp, stdout);
      if (!*++pp) { break; }
      putchar(' ');
    }
  } while (putchar('\n') != EOF);
  return 1;
}
