#include <stdio.h>
int main()
{

  FILE *fp;
  char ch[20];
  fp = fopen("f1.txt", "w");
  if (fp == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  printf("enter the data : ");
  gets(ch);
  fputs(ch, fp);

  fclose(fp);
}