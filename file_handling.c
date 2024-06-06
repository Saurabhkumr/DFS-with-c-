#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  fp = fopen("f1.txt", "w");
  char ch;
  char input;
  do
  {
    printf("Enter the data you want to write in file : ");
    scanf(" %c", &ch);
    fputc(ch, fp);
    printf("Want to enter more data : ");
    scanf(" %c", &input);
  } while (input == 'y');
  fclose(fp);
  fp = fopen("f1.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  printf("Content of file is : ");
  while ((ch = fgetc(fp)) != EOF)
  {
    printf(" %c", ch);
  }
  fclose(fp);
}