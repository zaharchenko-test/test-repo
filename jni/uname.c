#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>

void uname_help();

int uname_main(int argc, char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { uname_help(); return 0; }

  struct utsname buffer;

  if (uname(&buffer) < 0) {
    printf("%s: error\n", argv[0]);
    return 1;
  }
  if (argc < 2) {
    printf("%s\n", buffer.sysname);
    return 0;
  }
  else if ( strcmp( argv[1], "-s") == 0 ) {
    printf("%s\n", buffer.sysname);
    return 0;
  }
  else if ( strcmp( argv[1], "-m") == 0 ) {
    printf("%s\n", buffer.machine);
    return 0;
  }
  else if ( strcmp( argv[1], "-v") == 0 ) {
    printf("%s\n", buffer.version);
    return 0;
  }
  else if ( strcmp( argv[1], "-n") == 0 ) {
    printf("%s\n", buffer.nodename);
    return 0;
  }
  else if ( strcmp( argv[1], "-r") == 0 ) {
    printf("%s\n", buffer.release);                                           return 0;
  }
  else if ( strcmp( argv[1], "-a") == 0 ) {
    printf("%s ", buffer.sysname);
    printf("%s ", buffer.nodename);
    printf("%s ", buffer.release);
    printf("%s ", buffer.version);
    printf("%s.\n", buffer.machine);
  }
  else if ( argc > 1 ) { printf("%s: \"%s\" is not a command. Use \"--help\"\n", argv[0], argv[1]); return 1; }
  return 0;
}
