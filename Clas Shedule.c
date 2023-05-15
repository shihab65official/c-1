#include<stdio.h>
struct ClassSchedule
{
    int course;
    float startDateTime;
    float endDateTime;
    //bool isActive;
};

typedef struct ClassSchedule sc;

int listLength = 0;

void displayMenu();
sc inputClassSchedule(sc list[]);
void putAtRightPosition(sc entry, sc list[]);
void displayClassSchedule(sc list[], int length);
void searchClass(sc list[]);

int main()
{
    sc list[100000];

    int menuId = 0;

    while(1)
    {
        displayMenu();
        printf("Enter a menu option: ");
        scanf("%d", &menuId);
        switch(menuId)
        {
            case 0:
            {
                inputClassSchedule(list);
                break;
            }
            case 1:
            {
                displayClassSchedule(list, listLength);
                break;
            }
            case 2:
            {
                searchClass(list);
                break;
            }
            case 3:
            {
                updateClass(list);
                break;
            }
        }
    }

    return 0;
}


void putAtRightPosition(sc entry, sc list[])
{
    if (listLength == 0)
    {
        list[0].course = entry.course;
        list[0].startDateTime = entry.startDateTime;
        list[0].endDateTime = entry.endDateTime;
    }

    for (int i = listLength; i > 0; i--)
    {
        if (entry.startDateTime < list[i-1].startDateTime)
        {
            list[i].course = list[i-1].course;
            list[i].startDateTime = list[i-1].startDateTime;
            list[i].endDateTime = list[i-1].endDateTime;
        }
        else
        {
            list[i].course = entry.course;
            list[i].startDateTime = entry.startDateTime;
            list[i].endDateTime = entry.endDateTime;
            break;
        }
    }

}

sc inputClassSchedule(sc list[])
{
    sc obj;
    printf("Take input for a new class schedule\n");
    printf("Course: ");
    scanf("%d", &obj.course);
    printf("Start date time: ");
    scanf("%f", &obj.startDateTime);
    printf("End date time: ");
    scanf("%f", &obj.endDateTime);
    printf("------------------------\n");

    putAtRightPosition(obj, list);
    listLength++;
    return obj;
}

void displayClassSchedule(sc list[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("course: %d, start: %.2f, end: %.2f\n", list[i].course, list[i].startDateTime, list[i].endDateTime);
    }
}

void displayMenu()
{
    printf("Menu List:\n");
    printf("0: Insert a class\n");
    printf("1: Display class list\n");
    printf("2: Search class\n");
    printf("3: Update class\n");
}

void searchClass(sc list[])
{
    int courceCode;

    printf("Course: ");
    scanf("%d", &courceCode);

    for (int i = 0; i < listLength; i++)
    {
        if (courceCode == list[i].course)
        {
           printf("course: %d, start: %.2f, end: %.2f\n", list[i].course, list[i].startDateTime, list[i].endDateTime);
        }
    }
    printf("CourseCode: %d is not matched\n", courceCode);
}

void updateClass(sc list[])
{
    int courceCode;
    float startTime;
    float endTime;

    printf("Course: ");
    scanf("%d", &courceCode);

    printf("Add Update Information\n");
    printf("Start date time: ");
    scanf("%f", &startTime);
    printf("End date time: ");
    scanf("%f", &endTime);

    for (int i = 0; i < listLength; i++)
    {
        if (courceCode == list[i].course)
        {
           list[i].startDateTime = startTime;
           list[i].endDateTime = endTime;
        }
    }
    printf("CourseCode: %d is not matched\n", courceCode);
}


