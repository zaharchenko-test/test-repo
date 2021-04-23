#include <stdio.h>
#include <string.h>
#include <unistd.h>

void logname_help();

int logname_main(int argc, char **argv) {

  if (argc > 1 && strcmp(argv[1], "--help") == 0 ) { logname_help(); return 0; }
  else if ( argc > 1 ) { printf("%s: \"%s\" is not a command. Use \"--help\"\n", argv[0], argv[1]); return 1; }

  char *cp;

  cp = getlogin ();
  if (! cp) { printf("%s: no login name.\n", argv[0]); return 1; }

  puts (cp);
  return 0;
}
