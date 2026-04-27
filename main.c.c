#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
  char name[50];
  int id;
  float rent_debt;
  float electric_debt;
};

struct Student students[MAX_STUDENTS];
int num_students = 0;

// ************************ogrenci ekleme fonkisyonu***********************
void add_student()
{
  if (num_students == MAX_STUDENTS)
  {
    printf("Error: Can't add more students (array is full)\n");
    return;
  }

  printf("Enter student name: ");
  scanf("%s", students[num_students].name);

  printf("Enter student ID: ");
  scanf("%d", &students[num_students].id);

  printf("Enter rent debt: ");
  scanf("%f", &students[num_students].rent_debt); //rent-kira __ debt- borc

  printf("Enter electric debt: ");
  scanf("%f", &students[num_students].electric_debt);

  num_students++;
}

//******************ogrenci silme fonkisyonu**********************
void delete_student()
{
  int id;
  printf("Enter student ID: ");
  scanf("%d", &id);

  int i;
  for (i = 0; i < num_students; i++)
  {
    if (students[i].id == id)
    {
      break;
    }
  }

  if (i == num_students)
  {
    printf("Error: Student with ID %d not found\n", id);
    return;
  }

  // Shift all the following students one position to the left
  for (; i < num_students - 1; i++)
  {
    students[i] = students[i + 1];
  }
  num_students--;
}

//****************** ��renci g�ncelleme fonkisyonu ******************
void update_student()
{
  int id;
  printf("Enter student ID: ");
  scanf("%d", &id);

  int i;
  for (i = 0; i < num_students; i++)
  {
    if (students[i].id == id)
    {
      break;
    }
  }

  if (i == num_students)
  {
    printf("Error: Student with ID %d not found\n", id);
    return;
  }

  printf("Enter new student name: ");
  scanf("%s", students[i].name);

  printf("Enter new rent debt: ");
  scanf("%f", &students[i].rent_debt);

  printf("Enter new electric debt: ");
  scanf("%f", &students[i].electric_debt);
}

//********************* ��renci ka��la�t�rma fonkisyonu *****************
int compare_students(const void *a, const void *b)
{
  struct Student *s1 = (struct Student *)a;
  struct Student *s2 = (struct Student *)b;
  return strcmp(s1->name, s2->name);
}

//***************** ��renci listeleme fonkisyonu *****************
void list_students()
{
  qsort(students, num_students, sizeof(struct Student), compare_students);

  for (int i = 0; i < num_students; i++)
  {
    printf("%s (ID: %d) - Rent debt: %.2f, Electric debt: %.2f\n", students[i].name, students[i].id, students[i].rent_debt, students[i].electric_debt);
  }
}

//***************** bor� listesi fonkisyonu *****************
void list_debts()
{
  for (int i = 0; i < num_students; i++)
  {
    printf("%s (ID: %d) - Rent debt: %.2f, Electric debt: %.2f\n", students[i].name, students[i].id, students[i].rent_debt, students[i].electric_debt);
  }
}

//*************** kira borcu �deme fonkisyonu ****************
void pay_rent_debt()
{
  int id;
  printf("Enter student ID: ");
  scanf("%d", &id);

  int i;
  for (i = 0; i < num_students; i++)
  {
    if (students[i].id == id)
    {
      break;
    }
  }

  if (i == num_students)
  {
    printf("Error: Student with ID %d not found\n", id);
    return;
  }

  printf("Enter amount to pay: "); // amount - miktar
  float amount;
  scanf("%f", &amount);

  if (amount > students[i].rent_debt)
  {
    printf("Error: The entered amount is greater than the debt\n");
    return;
  }

  students[i].rent_debt -= amount;
  printf("Rent debt successfully paid. Remaining debt: %.2f\n", students[i].rent_debt); //kira borcu ba�ar�yla �dendi, kalan bor�
}

//*************** Electric borcu �deme fonkisyonu ****************
void pay_electric_debt()
{
  int id;
  printf("Enter student ID: ");
  scanf("%d", &id);

  int i;
  for (i = 0; i < num_students; i++)
  {
    if (students[i].id == id)
    {
      break;
    }
  }

  if (i == num_students)
  {
    printf("Error: Student with ID %d not found\n", id);
    return;
  }

  printf("Enter amount to pay: ");
  float amount;
  scanf("%f", &amount);

  if (amount > students[i].electric_debt)
  {
    printf("Error: The entered amount is greater than the debt\n");
    return;
  }

  students[i].electric_debt -= amount;
  printf("Electric debt successfully paid. Remaining debt: %.2f\n", students[i].electric_debt);
}

//************ main fonkisyonu *******************
int main()
{
  while (1)
  {
    printf("\nMenu:\n");
    printf("1. ��renci ekle (yeni kirac� kayd� i�in)\n");
    printf("2. ��renci kaydini sil\n");
    printf("3. ��renci kaydini g�ncelle\n");
    printf("4. ��renci bilgileri isme g�re s�ralama\n");
    printf("5. ��renci borcu listeleme\n");
    printf("6. Kira borcu �de\n");
    printf("7. Elektir borcu �de\n");
    printf("8. ��k��\n");

    int option; // se�enek
    printf("Enter option: ");
    scanf("%d", &option);

    if (option == 1)
    {
      add_student();
    }
    else if (option == 2)
    {
      delete_student();
    }
    else if (option == 3)
    {
      update_student();
    }
    else if (option == 4)
    {
      list_students();
    }
    else if (option == 5)
    {
      list_debts();
    }
    else if (option == 6)
    {
      pay_rent_debt();
    }
    else if (option == 7)
    {
      pay_electric_debt();
    }
    else if (option == 8)
    {
      printf("Cikis yapildi.");
      break;
    }
  }
  return 0;
}
