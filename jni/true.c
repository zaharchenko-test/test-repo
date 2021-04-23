#include <stdio.h>
#include <string.h>

void true_help();

int true_main(int argc, char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { true_help(); }
  return 0;
}
