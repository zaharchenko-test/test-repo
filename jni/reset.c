#include <stdio.h>
#include <string.h>

void reset_help();

int reset_main(int argc, char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { reset_help(); return 0; }
  else if ( argc > 1 ) { printf("%s: \"%s\" is not a command. Use \"--help\"\n", argv[0], argv[1]); return 1; }

  printf("\033c\033(B\033[m\033[J\033[?25h");
  return 0;
}
