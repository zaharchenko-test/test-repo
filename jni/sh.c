#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>


#define BUFFER 300

static char command[BUFFER];
static char copy[BUFFER];
static char *token;
static struct stat file_stat;

void change_directory();
void run_time();
void redirect_output(char flag);
void run_program();

void sh_help();

int sh_main(int argc, char **argv) {

  if ( argc > 1 && strcmp( argv[1], "--help") == 0 ) { sh_help(); return 0; }

  char *redirect_pos;
  char* username;

  username = getlogin();

  stat(__FILE__, &file_stat);

  while(1){
    printf("%s $ ", username);

    fgets(command, sizeof command, stdin);

    strcpy(copy, command);

    token = strtok(command, " \t\n()<>|&;");

    if(!token){
      continue;
    }

    else if(strcmp(token, "exit") == 0) {
      printf("logout.\n");
      exit(0);
    }

    else if(strcmp(token, "cd") == 0) {
      change_directory();
    }

    else if(strcmp(token, "time") == 0) {
      run_time();
    }

    else if((redirect_pos = strchr(copy, '>'))) {

      if ( *(redirect_pos + 1) == '>') {
        redirect_output('a');
      }
      else {
        redirect_output('w');
      }
    }

    else {
      run_program();
    }
  }

  return 0;
}

void change_directory() {
  char *home;
  home = getenv("HOME");

  token = strtok(NULL, " \t\n()<>|&;");

  if (token == NULL) {
    if (home == NULL) {
      printf("HOME environment variable not set. Home directory commands will not work.\n");
      return;
    }
    if(chdir(home) == -1) {
      perror("Error");
    }
    return;
  }
  if (token[0] == '~') {
    if (home == NULL) {
      printf("HOME environment variable not set. Home directory commands will not work.\n");
      return;
    }
    char relative[400];
    strcpy(relative, home);
    token = strcat(relative, &token[1]);
  }
  if(chdir(token) == -1) {
    perror("Error");
  }
}

void run_time() {
  struct tms start_time;
  struct tms end_time;
  long double clktck;

  if (times(&start_time) == -1) {
    perror("Error");
    return;
  }

  token = strtok(NULL, " \t\n()<>|&;");
  run_program();

  if (times(&end_time) == -1) {
    perror("Error");
    return;
  }

  clktck = sysconf(_SC_CLK_TCK);

  printf("\nuser\t%.3lfs", (end_time.tms_cutime - start_time.tms_cutime) / (double)clktck);
  printf("\nsys\t%.3lfs\n", (end_time.tms_cstime - start_time.tms_cstime) / (double)clktck);
}

void redirect_output(char flag) {
  pid_t pid;
  char *args[BUFFER];
  int arg_num;
  FILE* fp;
  int status;

  status = 0;
  arg_num = 0;
  pid = fork();

  if(pid == -1) {
    perror("Error");
    exit(EXIT_FAILURE);
  }
  else if(pid == 0) {
    args[arg_num] = token;

    while(token != NULL) {
      token = strtok(NULL, " \t\n()<>|&;");
      arg_num++;
      args[arg_num] = token;
    }

    fp = freopen(args[arg_num - 1], &flag, stdout);
    if (fp == NULL) {
      perror("Error");
      return;
    }
    args[arg_num - 1] = NULL;

    if((execvp(args[0], args) == -1)) {
      perror("Error");
    }

    fclose(fp);
    _exit(EXIT_SUCCESS);
  }

  else {
    if (wait(&status) == -1) {
      perror("Error");
      return;
    }

    if (WIFEXITED(status) == 0) {
      printf("Child process did not exit normally.");
    }
  }
}

void run_program() {
  pid_t pid;
  char *args[BUFFER];
  int arg_num;
  int status;

  status = 0;
  arg_num = 0;
  pid = fork();

  if(pid == -1) {
    perror("Error");
    exit(EXIT_FAILURE);
  }

  else if(pid == 0) {
    args[arg_num] = token;

    while(token != NULL) {
      token = strtok(NULL, " \t\n()<>|&;");
      arg_num++;
      args[arg_num] = token;
    }

    if((execvp(args[0], args) == -1)) {
      perror("Error");
    }
    _exit(EXIT_SUCCESS);
  }
  else {
    if (wait(&status) == -1) {
      perror("Error");
      return;
    }

    if (WIFEXITED(status) == 0) {
      printf("Child process did not exit normally.");
    }
  }
}
