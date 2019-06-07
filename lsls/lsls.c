#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>


char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    
    strcpy(result, s1);
    strcat(result, "/");
    strcat(result, s2);
    
    return result;
}

/**
 * Main
 */
int main(int argc, char **argv)
{
 
  DIR *dir;
  struct dirent *ent;
  struct stat buf;

  // // Parse command line
  // printf("%d\n", argc);

  if (argc != 2) {
    fprintf(stderr, "Directory input error\n");
    return 1;
  }

  // // Open directory

  dir = opendir(argv[1]);
  if (dir == NULL) {
    fprintf(stderr, "Can't open directory.");
    exit(1);
  }

  // // Repeatedly read and print entries
  if (dir != NULL) {

    while ((ent = readdir(dir)) != NULL) {

      // printf("%s\n", concat(argv[1], (ent->d_name)));
      stat(concat(argv[1], (ent->d_name)), &buf);

      if ((strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)) {

        printf("%10ld  %s\n", buf.st_size, ent->d_name);
                
      } else {
        
        printf("%10ld  %s\n", buf.st_size, ent->d_name);

      }
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}