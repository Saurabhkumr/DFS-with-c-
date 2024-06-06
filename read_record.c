#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold student data
typedef struct
{
  char name[100];
  int marks;
} Student;

int main()
{
  FILE *file;
  char filename[100];
  Student student;

  // Get the file name from the user
  printf("Enter the filename: ");
  scanf("%s", filename);

  // Open the file in read mode
  file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Could not open file %s\n", filename);
    return 1;
  }

  // Read and print the student data
  printf("Name\tMarks\n");
  printf("---------------\n");
  while (fscanf(file, "%s %d", student.name, &student.marks) != EOF)
  {
    printf("%s\t%d\n", student.name, student.marks);
  }

  // Close the file
  fclose(file);

  return 0;
}
