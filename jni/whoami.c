#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

void whoami_help();

int whoami_main(int argc, char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { whoami_help(); return 0; }
  else if ( argc > 1 ) { printf("%s: \"%s\" is not a command. Use \"--help\"\n", argv[0], argv[1]); return 1; }

  register struct passwd *pw;
  register uid_t uid;

  uid = geteuid();
  pw = getpwuid(uid);

    if (pw) {
      puts(pw->pw_name);
      return 0;
    }

  fprintf(stderr,"%s: cannot find username for UID %u\n", argv[0], (unsigned) uid);
  return 1;
}
