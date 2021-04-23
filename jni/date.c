#include <stdio.h>
#include <string.h>
#include <time.h>

void date_help();

int date_main(int argc, char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { date_help(); return 0; }
  else if ( argc > 1 ) { printf("%s: \"%s\" is not a command. Use \"--help\"\n", argv[0], argv[1]); return 1; }

  time_t t;
  time(&t);

  printf("%s", ctime(&t));
  return 0;
}
