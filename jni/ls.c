#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>
#include <libgen.h>
#include <sys/types.h>
#include <grp.h>
#include <string.h>

void print_long(char *dir_arg, struct dirent *dir_entry);
void flag_handler(char *dir_arg, struct dirent *dir_entry, int flag_all, int flag_long);
void print_args(char *dir_arg, char *file, int flag_all, int flag_long, int flag_file);
void ls_help();

int ls_main(int argc, char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { ls_help(); return 0; }

  int flag_long = 0;
  int flag_all = 0;
  int flag_file = 0;

  int opt;
  while ((opt = getopt(argc, argv, "al")) != -1) {
    switch (opt) {
      case 'l':
        flag_long = 1;
        break;
      case 'a':
        flag_all = 1;
        break;
      default:
        exit(EXIT_FAILURE);
    }
  }

  if (optind == argc) {
    print_args(".", "NULL", flag_all, flag_long, flag_file);
  }else {
    while (optind < argc) {
      struct stat argbuf;
      char *arg = argv[optind];
      if ((stat(arg, &argbuf)) == -1) {
        printf("%s: cannot access '%s': No such file or directory\n", argv[0], argv[optind]);
      }else {
        if(S_ISREG(argbuf.st_mode)) {
          flag_file = 1;
          print_args(".", arg, flag_all, flag_long, flag_file);
        }
        if(S_ISDIR(argbuf.st_mode)) {
           printf("%s:\n", arg);
           print_args(arg, "NULL", flag_all, flag_long, flag_file);
        }
        flag_file = 0;
        if(optind < argc-1) {
          printf("\n");
        }
      }
      optind ++;
    }
  }
  return 0;
}

void print_long(char *dir_arg, struct dirent *dir_entry) {
  struct stat statbuf;
  char fp[1024];
  sprintf(fp, "%s/%s", dir_arg, dir_entry->d_name);

  if(stat(fp, &statbuf) == -1) {
    perror("stat");
    return;
  }

  printf((S_ISDIR(statbuf.st_mode)) ? "d" : "-");
  printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
  printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
  printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
  printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
  printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
  printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
  printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
  printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
  printf((statbuf.st_mode & S_IXOTH) ? "x " : "- ");
int app1 = statbuf.st_nlink;
int app2 = statbuf.st_size;
  printf("%d ", app1);


  struct passwd *pw;
  struct group *gid;
  pw = getpwuid(statbuf.st_uid);
  if(pw == NULL) {
    perror("getpwuid");
    printf("%d ", statbuf.st_uid);
  }else {
    printf("%s ", pw->pw_name); 
  }
  gid = getgrgid(statbuf.st_gid);
  if(gid == NULL) {
    perror("getpwuid"); 
    printf("%d ", statbuf.st_gid); 
  }else  {
    printf("%s ", gid->gr_name); 
  }

  printf("%d ", app2);

  struct tm *tmp;
  char outstr[200];
  time_t t = statbuf.st_mtime;
  tmp = localtime(&t);   
  if(tmp == NULL) {
    perror("localtime"); 
    exit(EXIT_FAILURE);
  } 
  strftime(outstr, sizeof(outstr), "%b %d %R", tmp); 
  printf("%s ", outstr);

  printf("%s\n", dir_entry->d_name); 
}


void flag_handler(char *dir_arg, struct dirent *dir_entry, int flag_all, int flag_long) {
  if(flag_all == 0){
    if(dir_entry->d_name[0] == '.') {
      return; 
    } 
  }
  if(flag_long == 0) {
    printf("%s \n", dir_entry->d_name);
  }else { 
    print_long(dir_arg, dir_entry);
  }
}


void print_args(char *dir_arg, char *file, int flag_all, int flag_long, int flag_file) {

  DIR *dir = opendir(dir_arg);
  if(dir == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }

  struct dirent *dir_entry;
  errno = 0;
  while((dir_entry = readdir(dir))!= NULL) { 
    if(flag_file == 1) {
      if(strcmp(dir_entry->d_name, file) == 0) {
        flag_handler(dir_arg, dir_entry, flag_all, flag_long);
      }
      }else {
        flag_handler(dir_arg, dir_entry, flag_all, flag_long); 
      }
    }
    if((dir_entry == NULL) && (errno != 0)) {
      exit(EXIT_FAILURE);
    }
  closedir(dir);
}
