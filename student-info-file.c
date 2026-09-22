
#include <stdio.h>
int main(){
   
    typedef struct{

        char name[50];
        int roll;
        float cgpa;
    }student;

    int n;

    FILE *fp;

    fp = fopen("student-info.txt", "w");

    printf("Enter Number of Student: ");
    scanf("%d", &n);

    student std[n];

    for(int i =0; i<n; i++){

        printf("Enter info of Student: %d\n", i+1);

        printf("Name: ");
        scanf(" %[^\n]", std[i].name);

        printf("Roll: ");
        scanf("%d", &std[i].roll);

        printf("CGPA: ");
        scanf("%f", &std[i].cgpa);
    }

    for(int i=0; i<n; i++){
        fprintf(fp, "\nName: %s \nRoll: %d CGPA: %.2f\n", std[i].name, std[i].roll, std[i].cgpa);
    }

    fclose(fp);

    fp = fopen("student-info.txt", "r");

    char ch;

    while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
    }
    
    fclose(fp);

    return 0;
}