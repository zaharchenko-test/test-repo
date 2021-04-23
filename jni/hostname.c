#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>

void hostname_help();

int hostname_main(int argc, char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { hostname_help(); return 0; }
  else if ( argc > 1 ) { printf("%s: \"%s\" is not a command. Use \"--help\"\n", argv[0], argv[1]); return 1; }

  struct utsname buffer;

  if (uname(&buffer) < 0) {
    printf("%s: error\n", argv[0]);
    return 1;
  }else {
    printf("%s\n", buffer.nodename);
  }
  return 0;
}
