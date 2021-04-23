#include <stdio.h>
#include <string.h>
#include <unistd.h>

void ln_help();

int ln_main(int argc,char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { ln_help(); return 0; }

  else if (argc == 4) {
    if (strcmp(argv[1], "-s") == 0 && symlink(argv[2], argv[3]) != 0) {
      printf("%s: failed to create symbolic link.\n", argv[0]);
      return 1;
    }
  }
  else if (argc == 3) {
    if (link(argv[1],argv[2]) != 0) {
      printf("%s: failed to create hard link\n", argv[0]);
      return 1;
    }
  }
  else {
    printf("%s: error.\n", argv[0]);
  }
  return 0;
}

