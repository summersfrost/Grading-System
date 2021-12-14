#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int id;
    char name[20];

    char course[20];
    struct subject{
           int sid;
        char scode[20];
        char name[20];
        int mark;
        float sub_ave;
        struct add{
            float foraddwritten;
             float foraddperform;
              float foraddmajor;
        struct calculate{
       float writtencomp;
        float performcomp;
               float majorcomp;
        struct input{
            float writtentotal;
            float writtenperftotal;
            float performtotal;
            float performperftotal;
            float majortotal;
            float majorperftotal;

        struct written{
       float perfscore;
       float studscore;


       }written[5];

         struct performance{
        float perfscore;
       float studscore;


       }perform[5];

       struct majorexam{
      float perfscore;
       float studscore;
       }major[4];

        }input[1];
        }calculate[1];
        }add[1];
    }sub[1];
    int total;
    float per;
}student;

void append(){
        student *s;
        FILE *fp;
        int n,i,j,c,a;
        int b;
        int choice;


        printf("\nEnter how many students : ");
        scanf("%d",&n);
        s = (student*)calloc(n,sizeof(student));
        fp = fopen("mystudents1.txt","a");


        for(i=0;i<n;i++){

            printf("\nSTUDENT DETAILS\n");
              fflush(stdin);
            printf("\nName : ");
            scanf("%[^\n]s",s[i].name);
            printf("ID No : ");
            scanf("%d",&s[i].id);
            fflush(stdin);
            printf("Course : ");
            scanf("%[^\n]s",s[i].course);

            printf("\nENROLLED SUBJECT DETAILS\n");


            for(b=0,j=0,c=0,a=0;j<1;j++,c++,a++,b++){
 printf("Subject ID: ");
            scanf("%d",&s[i].sub[j].sid);
                      fflush(stdin);
                    printf("Subj Name:");
            scanf("%[^\n]s",s[i].sub[j].name);
fflush(stdin);
                    printf("Subj code:");
            scanf("%[^\n]s",s[i].sub[j].scode);

            printf("\nACADEMIC SCORES\n\n");
            printf("Written Quiz");
            for(int no=0;no<10;no++){
                printf("\nScore of Quiz%d : ",no+1);
                scanf("%f",&s[i].sub[j].add[b].calculate[c].input[a].written[no].studscore);
                 printf("No of Items of Quiz%d : ",no+1);
                scanf("%f",&s[i].sub[j].add[b].calculate[c].input[a].written[no].perfscore);

        s[i].sub[j].add[b].calculate[c].input[a].writtentotal+=s[i].sub[j].add[b].calculate[c].input[a].written[no].studscore;
         s[i].sub[j].add[b].calculate[c].input[a].writtenperftotal+=s[i].sub[j].add[b].calculate[c].input[a].written[no].perfscore;
  s[i].sub[j].add[b].calculate[c].writtencomp=(s[i].sub[j].add[b].calculate[c].input[a].writtentotal/s[i].sub[j].add[b].calculate[c].input[a].writtenperftotal)*100;
s[i].sub[j].add[b].foraddwritten=s[i].sub[j].add[b].calculate[c].writtencomp*0.15;

printf("\nDo you want to add Quiz Score? Press 1 for No \n choice: "); scanf("%d",&choice);
if(choice==1){
    break;
}

            }

            printf("\nPerformance Task\n");
              for(int no=0;no<4;no++){
                printf("\nScore of Performance task %d : ",no+1);
              scanf("%f",&s[i].sub[j].add[b].calculate[c].input[a].perform[no].studscore);
                 printf("Overall Score for Performance task %d : ",no+1);
              scanf("%f",&s[i].sub[j].add[b].calculate[c].input[a].perform[no].perfscore);

                        s[i].sub[j].add[b].calculate[c].input[a].performtotal+=s[i].sub[j].add[b].calculate[c].input[a].perform[no].studscore;
         s[i].sub[j].add[b].calculate[c].input[a].performperftotal+=s[i].sub[j].add[b].calculate[c].input[a].perform[no].perfscore;
  s[i].sub[j].add[b].calculate[c].performcomp=(s[i].sub[j].add[b].calculate[c].input[a].performtotal/s[i].sub[j].add[b].calculate[c].input[a].performperftotal)*100;
s[i].sub[j].add[b].foraddperform=s[i].sub[j].add[b].calculate[c].performcomp*0.50;


printf("\nDo you want to add Performance task score? Press 1 for No\n choice: "); scanf("%d",&choice);
if(choice==1){
    break;
}

            }

      printf("\nMAJOR EXAMS\n");
              for(int no=0;no<4;no++){
                printf("\n Score of Exam %d : ",no+1);
              scanf("%f",&s[i].sub[j].add[b].calculate[c].input[a].major[no].studscore);
                 printf(" Overall Score Exam %d : ",no+1);
              scanf("%f",&s[i].sub[j].add[b].calculate[c].input[a].major[no].perfscore);

                        s[i].sub[j].add[b].calculate[c].input[a].majortotal+=s[i].sub[j].add[b].calculate[c].input[a].major[no].studscore;
         s[i].sub[j].add[b].calculate[c].input[a].majorperftotal+=s[i].sub[j].add[b].calculate[c].input[a].major[no].perfscore;
  s[i].sub[j].add[b].calculate[c].majorcomp=(s[i].sub[j].add[b].calculate[c].input[a].majortotal/s[i].sub[j].add[b].calculate[c].input[a].majorperftotal)*100;
s[i].sub[j].add[b].foraddmajor=s[i].sub[j].add[b].calculate[c].majorcomp*0.35;

printf("\nDo you want to add Exam Scores? Press 1 for No \n choice: "); scanf("%d",&choice);
if(choice==1){
        printf("DATA ADDED SUCCESFULLY...\n");
               printf("**********************************************************************************************\n");
    break;
}
            }
s[i].sub[j].sub_ave=s[i].sub[j].add[b].foraddmajor + s[i].sub[j].add[b].foraddwritten + s[i].sub[j].add[b].foraddperform;
  printf("DATA ADDED SUCCESFULLY...\n");
               printf("**********************************************************************************************\n");

    }



            fwrite(s+i,sizeof(student),1,fp);
        }
        fclose(fp);
}


void create(){

        FILE *fp;
        int ch;
printf("Do you want to erase all the data?\n");
printf("Enter 1 for Yes otherwise 2 for No\n");
 printf("choice: ");  scanf("%d",&ch);
switch(ch){
case 1:
    printf("Are You Sure? 1 for yes 2 to cancel\n");
  printf("choice: ");  scanf("%d",&ch);
    switch(ch){
        case 1:
        fp = fopen("mystudents1.txt","w+");
        fclose(fp);
        printf("DATA SUCCESSFULLY DELETED..\n");
        printf("************************************************************************************\n");
        return;

     default:printf("INVALID INPUT..\n");
              printf("****************************************************************************************\n");return;}
        case 2:
            printf("OPERATION CANCELLED..\n");
            printf("****************************************************************************************\n");
            return;
            default:printf("INVALID INPUT..\n");
              printf("****************************************************************************************\n");
            return;
        }



}

void search(){
    int  j, found=0;
    int a,b,c;
    student s1;
    FILE *fp;
    int id;
    int sid;
    int ch;
    printf("What Do You Want To Search?\n");
        printf("Enter 1 for Student 2 for Subject?\n");
        printf("choice: ");scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Student ID:");
            scanf("%d",&id);
            break;
        case 2:
            printf("Subject ID:");
            scanf("%d",&sid);
         break;
        default:
            printf("INVALID INPUT...\n");
            printf("******************************************************************************\n");
           return;
            }



    fp = fopen("mystudents1.txt","r");
    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.id == id || s1.sub[j].sid==sid){
                found=1;
                 printf("\n*******************************************************************************\n");
           printf("Name:");
            printf("%-s\n",s1.name);
            printf("ID NO.:");
              printf("%d\n",s1.id);
                printf("Course:");
            printf("%-s\n\n",s1.course);

            for(b=0,j=0,c=0,a=0;j<1;j++,c++,a++){

                printf("Subject Name:");
            printf("%s\n",s1.sub[j].name);
               printf("Subject Code:");
            printf("%s\t",s1.sub[j].scode);     printf("Subject ID:");
            printf("%d",s1.sub[j].sid);
                      printf("\nWRITTEN QUIZ\n");
                  for(int no=0;no<5;no++){
                printf("Quiz %d : ",no+1);
                printf("%d/%d\t",(int)s1.sub[j].add[b].calculate[c].input[a].written[no].studscore,(int)s1.sub[j].add[b].calculate[c].input[a].written[no].perfscore);

            }
            printf("\n\n");
            printf("PERFORMANCE TASK\n");
                  for(int no=0;no<5;no++){
                printf("Task %d : ",no+1);
                  printf("%d/%d\t",(int)s1.sub[j].add[b].calculate[c].input[a].perform[no].studscore,(int)s1.sub[j].add[b].calculate[c].input[a].perform[no].perfscore);

            }
            printf("\n\n");

            printf("OFFICIAL EXAMS\n");
                  for(int no=0;no<4;no++){
                printf("Periodic Exam %d : ",no+1);
 printf("%d/%d\t",(int)s1.sub[j].add[b].calculate[c].input[a].major[no].studscore,(int)s1.sub[j].add[b].calculate[c].input[a].major[no].perfscore);

            }
printf("\n");
                  grading((int)s1.sub[j].sub_ave);
        }

    }
    }
    if(!found)
        printf("\nDATA NOT FOUND...\n");
         printf("\n********************************************************************************\n");
    fclose(fp);
}

void delete_recstud(){
int  found=0;
int j;
    student s1;
    FILE *fp, *fp1;
    int id,sid;
    int ch;
printf("What Record You Want to Delete:\n");
printf("1.Students 2.Subjects\n");
    scanf("%d",&ch);
   if(ch==1){
      printf("\nEnter ID No to Delete : ");
    scanf("%d",&id);

    }
     else if(ch==2){
       printf("\nEnter Subject ID No to Delete : ");
    scanf("%d",&sid);
   }
   else{
    printf("INVALID INPUT...\n");
    printf("*********************************************************************\n");
    return;
   }

    fp = fopen("mystudents1.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(student),1,fp)){

        if(s1.id == id||s1.sub[j].sid==sid){
            found = 1;

        }
        else
            fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
            fp = fopen("mystudents1.txt","w");
            fp1 = fopen("temp.txt","r");
  printf("RECORD SUCCESSFULLY DELETED..\n");
               printf("*************************************************************\n");
            while(fread(&s1,sizeof(student),1,fp1)){
                fwrite(&s1,sizeof(student),1,fp);
            }
            fclose(fp);
            fclose(fp1);
            return;
    }
    else
        printf("\nDATA NOT FOUND...\n");
         printf("*********************************************************************\n");
}



void display(){
        student s1;
        FILE *fp;
        int j,c,a,b;

        fp = fopen("mystudents1.txt","r");
        printf("********************************************************************************\n");
        while(fread(&s1,sizeof(student),1,fp))

        {   printf("Name:");
            printf("%-s\n",s1.name);
            printf("ID NO.:");
              printf("%d\n",s1.id);
                printf("Course:");
            printf("%-s\n\n",s1.course);

            for(b=0,j=0,c=0,a=0;j<1;j++,c++,a++){

                printf("Subject Name:");
            printf("%s\n",s1.sub[j].name);
               printf("Subject Code:");
            printf("%s\t",s1.sub[j].scode);     printf("Subject ID:");
            printf("%d",s1.sub[j].sid);
                      printf("\nWRITTEN QUIZ\n");
                  for(int no=0;no<5;no++){
                printf("Quiz %d : ",no+1);
                printf("%d/%d\t",(int)s1.sub[j].add[b].calculate[c].input[a].written[no].studscore,(int)s1.sub[j].add[b].calculate[c].input[a].written[no].perfscore);

            }
            printf("\n\n");
            printf("PERFORMANCE TASK\n");
                  for(int no=0;no<5;no++){
                printf("Task %d : ",no+1);
                  printf("%d/%d\t",(int)s1.sub[j].add[b].calculate[c].input[a].perform[no].studscore,(int)s1.sub[j].add[b].calculate[c].input[a].perform[no].perfscore);

            }
            printf("\n\n");

            printf("OFFICIAL EXAMS\n");
                  for(int no=0;no<4;no++){
                printf("Periodic Exam %d : ",no+1);
 printf("%d/%d\t",(int)s1.sub[j].add[b].calculate[c].input[a].major[no].studscore,(int)s1.sub[j].add[b].calculate[c].input[a].major[no].perfscore);

            }
                grading((int)s1.sub[j].sub_ave);


            }

        }
         printf("\n********************************************************************************\n");
        fclose(fp);
}



void update(){
int    found=0;
    student s1;
    FILE *fp, *fp1;
    int j, id,sid;
   int ch;
    printf("*****************************************************************************************************\n");
printf("What Record You Want to Update:\n");
printf("1.Students 2.Subjects\n");
   printf("choice: "); scanf("%d",&ch);
   if(ch==1){
      printf("\nEnter ID No to Update :\n ");
   printf("Student ID: "); scanf("%d",&id);

    }
     else if(ch==2){
       printf("\nEnter Subject ID No to Update : \n");
   printf("Subject ID: "); scanf("%d",&sid);
   }
   else{
    printf("INVALID INPUT...\n");
    printf("*********************************************************************\n");
    return;
   }
    fp = fopen("mystudents1.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.id == id){
            found = 1;
            printf("*****************************************************************************************************\n");
                printf("\nSTUDENT DETAILS\n");
              fflush(stdin);
            printf("\nName : ");
            scanf("%[^\n]s",s1.name);
            printf("ID No : ");
            scanf("%d",&s1.id);
            fflush(stdin);
            printf("Course : ");
            scanf("%[^\n]s",s1.course);

printf("DATA UPDATED SUCCESFULLY..\n");
        }
         if(s1.sub[j].sid == sid){
            found = 1;
            printf("*****************************************************************************************************\n");
               printf("SUBJECT DETAILS\n");
                printf("Subject ID: ");
            scanf("%d",&s1.sub[j].sid);
                      fflush(stdin);
                    printf("Subj Name:");
            scanf("%[^\n]s",s1.sub[j].name);
fflush(stdin);
                    printf("Subj code:");
            scanf("%[^\n]s",s1.sub[j].scode);
printf("DATA UPDATED SUCCESFULLY..\n");


        }
        fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
            fp = fopen("mystudents1.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(student),1,fp1)){
                fwrite(&s1,sizeof(student),1,fp);
            }
            fclose(fp);
            fclose(fp1);
    }
    else
        printf("\nDATA NOT FOUND..\n");
        printf("*************************************************************************************\n");
}


int grading(int gp){




    if (gp >= 95 && gp <= 100) {

         printf("\nSubject Average: 1.0\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 94) {
       printf("\nSubject Average: 1.1\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 93) {
          printf("\nSubject Average: 1.2\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 92) {
          printf("\nSubject Average: 1.3\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 91) {
          printf("\nSubject Average: 1.4\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 90) {
          printf("\nSubject Average: 1.5\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 89) {
         printf("\nSubject Average: 1.6\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 88) {
         printf("\nSubject Average: 1.7\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 87) {
         printf("\nSubject Average: 1.8\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 86) {
           printf("\nSubject Average: 1.9\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 85) {
        printf("\nSubject Average: 2.0\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 84) {
       printf("\nSubject Average: 2.1\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 83) {
      printf("\nSubject Average: 2.2\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 82) {
        printf("\nSubject Average: 2.3\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 81) {
    printf("\nSubject Average: 2.4\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 80) {
           printf("\nSubject Average: 2.5\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 79) {
       printf("\nSubject Average: 2.6\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 78) {
         printf("\nSubject Average: 2.7\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 77) {
           printf("\nSubject Average: 2.8\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 76) {
       printf("\nSubject Average: 2.9\n");
        printf("**********************************************************************************************\n");
    }
    else if (gp == 75) {
        printf("\nSubject Average: 3.0\n");
        printf("**********************************************************************************************\n");
    }

else{
printf("\nSubject Average:5.0\n");
 printf("**********************************************************************************************\n");
}
}

int main(){
    int ch;
    printf("GRADING SYSTEM\n");
    printf("developed by: Benjie S. Juabot BsCpe1\n");
    printf("*************************************************************************************\n");
    do{
        printf("\n1.FORMAT DATA");
        printf("\n2.ADD STUDENT");
        printf("\n3.DISPLAY RECORD");
        printf("\n4.SEARCH RECORD");
        printf("\n5.DELETE STUDENT RECORD");
        printf("\n6.UPDATE RECORD");
        printf("\n7.EXIT");
        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
                create();
            break;
        case 2:
                append();
            break;
        case 3:
                display();
            break;

        case 4:
                search();
        break;


            case 5:
                delete_recstud();
            break;
            case 6:
                update();
                break;

        case 7:
                printf("DATA SUCCESFULLY SAVED....\n");
 printf("**********************************************************************************************\n");
                break;
                default: printf("Invalid Input..\n");
                printf("******************************************************************************************\n");
                break;
        }
        }while(ch!=7);
        }
