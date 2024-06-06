#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold student data
typedef struct
{
  char name[100];
  int marks;
} Student;

void writeRecords(const char *filename)
{
  FILE *file = fopen(filename, "w");
  if (file == NULL)
  {
    printf("Could not open file %s for writing\n", filename);
    exit(1);
  }

  int n;
  printf("Enter the number of students: ");
  scanf("%d", &n);

  Student student;
  for (int i = 0; i < n; ++i)
  {
    printf("Enter name of student %d: ", i + 1);
    scanf("%s", student.name);
    printf("Enter marks of student %d: ", i + 1);
    scanf("%d", &student.marks);
    fprintf(file, "%s %d\n", student.name, student.marks);
  }

  fclose(file);
  printf("Records written successfully.\n");
}

void readRecords(const char *filename)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Could not open file %s for reading\n", filename);
    exit(1);
  }

  Student student;
  printf("Name\tMarks\n");
  printf("---------------\n");
  while (fscanf(file, "%s %d", student.name, &student.marks) != EOF)
  {
    printf("%s\t%d\n", student.name, student.marks);
  }

  fclose(file);
}

int main()
{
  char filename[100];

  // Get the filename from the user
  printf("Enter the filename: ");
  scanf("%s", filename);

  // Write records to the file
  writeRecords(filename);

  // Read records from the file
  readRecords(filename);

  return 0;
}
