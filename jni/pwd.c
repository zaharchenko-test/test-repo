#include <stdio.h>
#include <string.h>
#include <unistd.h>

void pwd_help();

int pwd_main(int argc, char **argv) {

  if (argc > 1 && strcmp( argv[1], "--help") == 0 ) { pwd_help(); return 0; }
  else if ( argc > 1 ) { printf("%s: \"%s\" is not a command. Use \"--help\"\n", argv[0], argv[1]); return 1; }

  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  printf("%s\n", cwd);
  return 0;
}
