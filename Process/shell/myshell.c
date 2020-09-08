#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<glob.h>
#define DELIMS " \t\n"


struct cmd_st
{
  glob_t globres;
};



static void promit()
{
  printf("my_shell_0.1\n");
}

static void  parse(char* line,glob_t *res)
{
  char *tok;
  int i = 0;
  while(1)
  {
    tok = strsep(&line,DELIMS);
    if(tok == NULL)
    {
      break;
    }
  if(tok[0] == '\0')
    continue; 
  glob(tok,GLOB_NOCHECK|GLOB_APPEND * i,NULL,res);
  i = 1; 
  }

}



int main()
{
  char *linebuf = NULL;
  size_t linebuf_size = 0;
  glob_t globres;
  struct cmd_st cmd; 
  pid_t pid;
  while(1)
  {
    promit();

    if(getline(&linebuf,&linebuf_size,stdin) < 0)
    {
      break;
    }

    parse(linebuf,&globres);
    if(0)  //内部命令
    {

    }

    else{
     pid =fork();
      if(pid < 0)
      {
        perror("fork() error\n");
        exit(1);
      }
    if(pid == 0)
    {
      execvp(cmd.globres.gl_pathv[0],cmd.globres.gl_pathv);
      perror("execvp()faliure\n");
      exit(1);
    }
    else{
      wait(NULL);
    }
    }

  }

  return 0;
}
