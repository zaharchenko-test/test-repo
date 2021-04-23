#include "lib/multibox.h"
#include <stdio.h>
#include <string.h>

int multibox(int argc, char **argv, char *func_name) {

  if (argc < 1) { printf("%s: error.\n", func_name); return 1; }

  else if ( strcmp( func_name, "arch") == 0 ) { return arch_main(argc, argv); }
  else if ( strcmp( func_name, "basename") == 0 ) { return basename_main(argc, argv); }
  else if ( strcmp( func_name, "cat") == 0 ) { return cat_main(argc, argv); }
  else if ( strcmp( func_name, "clear") == 0 ) { return clear_main(argc, argv); }
  else if ( strcmp( func_name, "date") == 0 ) { return date_main(argc, argv); }
  else if ( strcmp( func_name, "hostname") == 0 ) { return hostname_main(argc, argv); }
  else if ( strcmp( func_name, "ln") == 0 ) { return ln_main(argc, argv); }
  else if ( strcmp( func_name, "logname") == 0 ) { return logname_main(argc, argv); }
  else if ( strcmp( func_name, "ls") == 0 ) { return ls_main(argc, argv); }
  else if ( strcmp( func_name, "pwd") == 0 ) { return pwd_main(argc, argv); }
  else if ( strcmp( func_name, "reset") == 0 ) { return reset_main(argc, argv); }
  else if ( strcmp( func_name, "sh") == 0 ) { return sh_main(argc, argv); }
  else if ( strcmp( func_name, "test") == 0 ) { return test_main(argc, argv); }
  else if ( strcmp( func_name, "true") == 0 ) { return true_main(argc, argv); }
  else if ( strcmp( func_name, "uname") == 0 ) { return uname_main(argc, argv); }
  else if ( strcmp( func_name, "whoami") == 0 ) { return whoami_main(argc, argv); }
  else if ( strcmp( func_name, "yes") == 0 ) { return yes_main(argc, argv); }

  else { printf("%s: not a function.\n", func_name); }
  return 1;
}
