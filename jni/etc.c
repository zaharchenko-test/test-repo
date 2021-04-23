#include "lib/help.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *version = "MultiBox v0.06-zaharchenko multi-call binary.";
char *funcv[] = {"arch","basename","cat","clear","date","hostname","ln","logname","ls","pwd","reset","sh","test","true","uname","whoami","yes"};
int funcc = 17;

void multibox_install(int argc, char **argv) {

  char buffer[BUFSIZ];
  readlink("/proc/self/exe", buffer, BUFSIZ);

  if (argc == 3) {
    for (int i = 0; i < funcc; i++) {
      char buffer[BUFSIZ];
      readlink("/proc/self/exe", buffer, BUFSIZ);
      char *path = strdup(argv[2]);
      int l = strlen(path)-1;
      if (strcmp(&path[l], "/") != 0) {strcat(path, "/");}
      link(buffer ,strcat(path, funcv[i]));
    }
  }
  else if (argc == 4 && strcmp(argv[2], "-s") == 0) {
    for (int i = 0; i < funcc; i++) {
      char buffer[BUFSIZ];
      readlink("/proc/self/exe", buffer, BUFSIZ);
      char *path = strdup(argv[3]);
      int l = strlen(path)-1;
      if (strcmp(&path[l], "/") != 0) {strcat(path, "/");}
      symlink(buffer ,strcat(path, funcv[i]));
    }
  }
  else {
    printf("multibox --install [-s?] [DIR]\n");
  }
}
