#include <string.h>
#include <libgen.h>

int multibox(int argc, char **argv, char *func_name);
void multibox_install(int argc, char **argv);

void multibox_help();
void multibox_list();
void multibox_version();

int main(int argc, char **argv) {

  char *func_name = basename(argv[0]);
  int multi_name = strncmp(func_name, "multibox", 8);

  if (multi_name == 0 && argc < 2) {
    multibox_help();
    return 0;
  }
  else if (argc > 1 && multi_name == 0 && (strcmp(argv[1], "--help") == 0)) {
    multibox_help();
    return 0;
  }
  else if (argc > 1 && multi_name == 0 && (strcmp(argv[1], "--version") == 0)) {
    multibox_version();
    return 0;
  }
  else if (argc > 1 && multi_name == 0 && (strcmp(argv[1], "--list") == 0)) {
    multibox_list();
    return 0;
  }
  else if (argc > 1 && multi_name == 0 && (strcmp(argv[1], "--install") == 0)) {
    multibox_install(argc, argv);
    return 0;
  }
  else if (argc > 1 && multi_name == 0) {
    func_name = argv[1];
    argv[0] = NULL;
    argc--;
    argv++;
    return multibox(argc, argv, func_name);
  }

  else { return multibox(argc, argv, func_name); }
}
