#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct def_class {
    int pupilCounter;
    char schoolClass;
    int schoolLevel;
    struct def_class *next;
}def_class;

typedef struct def_school {
    def_class *classList;
    int count;
}def_school;

struct def_class *pushFront(char schoolClass, int schoolLevel, int pupilCounter, struct def_school *school) {
    struct def_class *newSchoolClass = (struct def_class*) malloc(sizeof(struct def_class));

    newSchoolClass->schoolClass = schoolClass;
    newSchoolClass->schoolLevel = schoolLevel;
    newSchoolClass->pupilCounter = pupilCounter;

    newSchoolClass->next = school->classList;
    school->classList = newSchoolClass;

    return newSchoolClass;
};

void removeLastYear(struct def_school *school) {
    struct def_class *tmp = school->classList;
    while(tmp != NULL && tmp->next != NULL && tmp->next->schoolLevel != 4) {
        tmp = tmp->next;
    }
    if(tmp == NULL) {
        return;
    }
    struct def_class *yearFour = tmp->next; // 1 Klasse im 4 JG
    if (tmp->schoolLevel == 4){
        yearFour = tmp;
        tmp = NULL;
    }

    struct def_class *next = NULL;
    while(yearFour != NULL) {
        next = yearFour->next;
        yearFour->next = NULL;
        free(yearFour);
        yearFour = next;
    }
    if(tmp == NULL)
        school->classList = NULL;
    else
        tmp->next = NULL;
}

void increment(struct def_school *school) {
    for(struct def_class *p = school->classList; p != NULL; p = p->next) {
        p->schoolLevel++; // Schuljahr um 1 erhöhen
    }
}

char actionMenue() {
    char eingabe;

    printf("Choose action: school (s), year (y), class (c), new (n), exit (x): ");
    scanf(" %c", &eingabe);
    printf("\n");

    if(eingabe == 's' || eingabe == 'y' || eingabe == 'c' || eingabe == 'n' || eingabe == 'x') {
        return eingabe;
    }
    else {
        printf("Invalid selection\n");
        return 0;
    }
}

void newStudent(def_school *info) {
    int eingabe = 0;

    printf("Enter the number of students: ");

    scanf("%d", &eingabe);
    printf("\n");

    removeLastYear(info);
    increment(info);
    info->count++;

    if(eingabe < 15){
        printf("Not enough students\n");
    }
    else if(eingabe > 780) {
        printf("Too much students\n");
    }
    else if(eingabe >= 15 && eingabe <= 30) {
        pushFront('A', 1, eingabe, info);
    }
    else if(eingabe > 30 && eingabe < 40) {
        int pubilB = eingabe / 2;

        pushFront('B', 1, pubilB, info);
        pushFront('A', 1, eingabe - pubilB, info);

    }
    else if(eingabe >= 40) {
        int classCount = eingabe / 20;
        if(classCount > 26) {
            classCount = 26;
        }
        int mod = eingabe % classCount;
        int pubilCount = eingabe / classCount;

        for(int i = classCount - 1; i >= 0; i--) {
            pushFront('A' + i, 1, pubilCount, info);
            if(i == mod) {
                pubilCount++;
            }
        }
    }
}

void printSchool(def_school *info) {
    int totalCount = 0;
    int classCount = 0;

    for(struct def_class *p = info->classList; p != NULL; p = p->next) {
        printf("%d%c - %d\n", p->schoolLevel, p->schoolClass, p->pupilCounter);
        totalCount += p->pupilCounter;
        classCount++;
    }

    if(info->classList != NULL) {
        printf("Total: %d pupils - %d class(es)\n", totalCount, classCount);
        printf("School is operating since %d year(s)\n", info->count); // Really not sure about this one
    }
    else {
        printf("School: no classes\n");
    }
}

void printYear(def_school *info) {
    int eingabe = 0;
    int totalCount = 0;
    int classCount = 0;
    struct def_class *p = NULL;

    if(info->classList == NULL) {
        printf("School: no classes\n");
    } else {
        printf("Enter a year (1-4):");
        scanf("%d", &eingabe);
        printf("\n");

        for(p = info->classList; p != NULL; p = p->next) {
            if(p->schoolLevel == eingabe)
                break;
        }

        for(; p != NULL && p->schoolLevel == eingabe; p = p->next) {
            printf("%d%c - %d\n", p->schoolLevel, p->schoolClass, p->pupilCounter);
            totalCount += p->pupilCounter;
            classCount++;
        }


        if(classCount > 0) {
            printf("Total: %d pupils - %d class(es)\n", totalCount, classCount);
        }
        else {
            printf("No such class\n");
        }
    }
}

void printClass(def_school *info) {
    int eingabe = 0;
    char index;

    if(info->classList == NULL) {
        printf("School: no classes\n");
    } else {
        printf("Enter a class (e.g.: 2B):");
        scanf("%d%c", &eingabe, &index);
        printf("\n");

        if(eingabe >= 1 && eingabe <= 4 && index >= 65 && index <= 90) {
            struct def_class *p;
            for(p = info->classList; p != NULL; p = p->next) {
                if(p->schoolLevel == eingabe && p->schoolClass == index)
                    break;
            }
            if(p != NULL){
                printf("Class %d%c has %d pupils\n", eingabe, index, p->pupilCounter);
            }
            else {
                printf("No such class\n");
            }
        }
        else {
            printf("No such class\n");
        }
    }
}

int main() {
    struct def_school *school= (struct def_school*) malloc(sizeof(struct def_school));
    school->classList = NULL;
    school->count = 0;

    printf("\n");

    while(1){
        char returnValue = actionMenue();
        if(returnValue == 'x')
            break;
        switch(returnValue) {
            case 's':
                printSchool(school);
                break;
            case 'y':
                printYear(school);
                break;
            case 'c':
                printClass(school);
                break;
            case 'n':
                newStudent(school);
                break;
        }
    }
    struct def_class *next = NULL;
    for(struct def_class *p = school->classList; p != NULL;) {
        next = p->next;
        free(p);
        p = next;
    }
    free(school);
    return 0;
}
