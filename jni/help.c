#include "lib/help.h"
#include <stdio.h>

void multibox_help();
void multibox_list();
void multibox_version();

void multibox_help() {
  printf("Usage: multibox [function [arguments]...\n   --install   -- create links.\n   --version   -- display the current version.\n   --list   -- display all available functions in a list.\n   --help   -- display the current message.\n\nAll functions:\n      ");
  for ( int i = 0; i < funcc; i++ ) { printf("%s, ", funcv[i]); }
  printf("\n");
}

void multibox_version() {
  printf("%s\n", version);
}

void multibox_list() {
  for ( int i = 0; i < funcc; i++ ) { printf("%s\n", funcv[i]); }
}

void arch_help() {
  printf("Usage: arch\nDisplay system architecture.\n");
}

void basename_help() {
  printf("Usage: basename\nStrip directory path from FILE.\n");
}

void cat_help() {
  printf("Usage: cat [filename]\nPrint FILEs to stdout.\n");
}

void clear_help() {
  printf("Usage: clear\nClear screen.\n");
}

void date_help() {
  printf("Usage: date\nDisplay the current date and time.\n");
}

void hostname_help() {
  printf("Usage: hostname\nDisplay hostname or domain name.\n");
}

void ln_help() {
  printf("Usage: ln [-s?] [file] [link]\n   -s   -- symbol link\n");
}

void logname_help() {
  printf("Usage: logname\nDisplay the name of the current user.\n");
}

void ls_help() {
  printf("Usage: ls [-arg] [path]\nDisplay list directory contents.\n   -l   -- use a long listing format.\n   -a   -- show all.\n");
}

void pwd_help() {
  printf("Usage: pwd\nDisplay the full filename of the current working directory.\n");
}

void reset_help() {
  printf("Usage: reset\nReset the screen.\n");
}

void sh_help() {
  printf("Usage: sh\nMinimal shell interpreter.\n");
}

void test_help() {
  printf("Usage: test [arguments]...\nDisplay all argc && argv.\n");
}

void true_help() {
  printf("Usage: true\nAlredy return true.\n");
}

void uname_help() {
  printf("Usage: uname [-arg]\nDisplay system information.\n   -a   -- Print all\n   -m   -- The machine (hardware) type\n   -n   -- Hostname\n   -r   -- Kernel release\n   -s   -- Kernel name (default)\n   -v   -- Kernel version\n");
}

void whoami_help() {
  printf("Usage: whoami\nDisplay the user name associated with the current user ID.\n");
}

void yes_help() {
  printf("Usage: yes [strings]\nRepeatedly output a line with all specified STRING(s).\n");
}
