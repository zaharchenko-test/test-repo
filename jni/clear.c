#include <stdio.h>
#include <string.h>

void clear_help();

int clear_main(int argc, char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { clear_help(); return 0; }
  else if ( argc > 1 ) { printf("%s: \"%s\" is not a command. Use \"--help\"\n", argv[0], argv[1]); return 1; }

  printf("\033c");
  printf("\033[H\033[J");
  return 0;
}
