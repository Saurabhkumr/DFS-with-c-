#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char str[100];

  // Writing a string to a file
  fp = fopen("f1.txt", "w");
  if (fp == NULL)
  {
    printf("Error opening file for writing.\n");
    return 1;
  }

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin); // Read string from user input
  fprintf(fp, "%s", str);         // Write string to file
  fclose(fp);

  // Reading a string from a file
  fp = fopen("f1.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening file for reading.\n");
    return 1;
  }

  printf("Content of file is: ");
  fgets(str, sizeof(str), fp); // Read string from file
  printf("%s", str);           // Print string
  fclose(fp);

  return 0;
}
