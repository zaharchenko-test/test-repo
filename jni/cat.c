#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void cat_help();

int cat_main(int argc, char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { cat_help(); return 0; }
  else if ( argc < 2 ) { printf("%s: no argument!. Use \"--help\"\n", argv[0]); return 1; }

  FILE *file;
  int chr, count;

  for(count = 1; count < argc; count++) {
    if((file = fopen(argv[count], "r")) == NULL) {
      fprintf(stderr, "%s: %s : %s\n", argv[0], argv[count],
      strerror(errno));
      continue;
    }
    while((chr = getc(file)) != EOF) {
      fprintf(stdout, "%c", chr);
    }
    fclose(file);
  }
  return 0;
}
