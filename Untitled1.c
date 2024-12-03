#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct studentcourses{        //Student's Courses Structure

   char course_id[50];
   char grade [10];

};

struct student{        //Student Data Structure

  char name[50];
  char department[50];
  char index_no[50];
  int count;
  struct studentcourses cou[10];     //Structure within Structure

};

struct coursedetails{            //Course Data Structure

  char course_name[50];
  char course_id[50];
  float credit_value;

};

//==========================================================================================================================================================================

void updatestudent(){     //Function For Update Student

   system("cls");
   char CH;
    FILE *studentDetails;
    FILE *temp;

    int found;
   int Subject_count;
   struct student stu;
   char index_no[20];

   studentDetails=fopen("std.txt","r");
   temp=fopen("temp.txt","w");

  printf("\t\t\t\t\t==================================\n");
  printf("\t\t\t\t\t      UPDATE STUDENT DETAILS      \n");
  printf("\t\t\t\t\t==================================\n\n");


  printf("\n\n Enter Student's Index NO You Want To Update :- ");
  scanf("%s",index_no);


  while(fread(&stu,sizeof(struct student),1,studentDetails)){
    if(strcmp(index_no,stu.index_no)==0)
        {
        found=1;

        printf("\n\n\t\t\t\t\t# Enter Student's New Name :- ");
        scanf(" %[^\n]s",stu.name);
        printf("\t\t\t\t\t# Enter Student's New Department :- ");
        scanf(" %[^\n]s",stu.department);
        printf("\t\t\t\t\t# Enter Student's New Index NO :- ");
        scanf(" %[^\n]s",stu.index_no);

        printf("\n\t\t\t\t# How Many Courses are followed by this student :- ");
        scanf("%d",&Subject_count);
        stu.count=Subject_count;
        printf("\n");

        for(int y=0;y<Subject_count;y++){
            printf("\t\t\t\t\t# Enter NO %d Course ID :- ",y+1);
            scanf(" %[^\n]s",stu.cou[y].course_id);
            printf("\t\t\t\t\t# Enter The Grade ('A', 'B', 'C', 'D', 'E' or if absent 'N') :- ");
            scanf("%s",stu.cou[y].grade);
            printf("\n");
        }

  }
    fwrite(&stu,sizeof(struct student),1,temp);

    }
     fclose(studentDetails);
    fclose(temp);

    if(found){
            studentDetails=fopen("std.txt","w");
            temp=fopen("temp.txt","r");
            while(fread(&stu,sizeof(struct student),1,temp)){
                fwrite(&stu,sizeof(struct student),1,studentDetails);
            }
            fclose(studentDetails);
            fclose(temp);
    }
    else{
        printf("\n Student Not Found.....\n\n");}

  printf("Exit To Main Menue Press [y]\nTo Edit Another Student Details Press [E]\nTo View Student Details Press [V]");
  scanf(" %c",&CH);
  if(CH=='Y'||CH=='y')
    main();

  else if(CH=='e'||CH=='E')
    updatestudent();

  else if(CH=='v'||CH=='V')
    viewStudentDetails();

    else{
        main();
    }


    }

//===========================================================================================================================================================================


void updatecourse()      //Function For Updating Course

{

system("cls");
   char CH;
    FILE *coursedetails;
    FILE *temp2;

    int found;

   struct coursedetails cde;

   char courseid[20];

   coursedetails=fopen("coursedetails.txt","r");
   temp2=fopen("temp2.txt","w");

  printf("\t\t\t\t\t===================================\n");
  printf("\t\t\t\t\t       UPDATE COURSE DETAILS       \n");
  printf("\t\t\t\t\t===================================\n\n");


  printf("\n\n Enter Course ID You Want To Update :- ");
  scanf("%s",courseid);


  while(fread(&cde,sizeof(struct coursedetails),1,coursedetails)){
    if(strcmp(courseid,cde.course_id)==0){
        found=1;

     printf("\n\n\t\t\t\t\t # Enter New Course ID :- ");
     scanf(" %[^\n]s",cde.course_id);
     printf("\t\t\t\t\t # Enter New Course Name :- ");
     scanf(" %[^\n]s",cde.course_name);
     printf("\t\t\t\t\t # Enter New Credit Value :- ");
     scanf("%f",&cde.credit_value);

  }
    fwrite(&cde,sizeof(struct coursedetails),1,temp2);

    }
     fclose(coursedetails);
    fclose(temp2);

    if(found){
            coursedetails=fopen("coursedetails.txt","w");
            temp2=fopen("temp2.txt","r");
            while(fread(&cde,sizeof(struct coursedetails),1,temp2)){
                fwrite(&cde,sizeof(struct coursedetails),1,coursedetails);
            }
            fclose(coursedetails);
            fclose(temp2);
    }
    else{
        printf("\n Course Not Found.....\n\n");}

     printf("\n\n Do you want to edit another course [y]/[n]\n To View Course Details Press [V] ");
     scanf(" %c",&CH);
     if(CH=='y'||CH=='Y')
        updatecourse();
     else if(CH=='v'||CH=='V')
        viewcourseDetails();

     else
        main();

}

//============================================================================================================================================================================

int student_check(char studentid[])       //Function For Check Student ID If Already Exist

 {
    FILE *studentDetails;
    struct student stu;
    studentDetails=fopen("std.txt","r");
    if(studentDetails != NULL){
        int found_student=0;
        struct student chk;
        while(fread(&stu,sizeof(struct student),1,studentDetails)){
            int stu_str=strcmp(studentid,stu.index_no);
            if(stu_str==0){
                found_student=1;
            }
        }
        return found_student;
        fclose(studentDetails);
    }else{
        printf("\nError!\nFile can not be opened!\n");
    }
}



//===============================================================================================================================================================================


void enterStudentDetails()          //Function For Getting Student Details

 {

   system("cls");
       printf("\t\t\t\t\t========================\n");
       printf("\t\t\t\t\t  ADD STUDENT DETAILS   \n");
       printf("\t\t\t\t\t========================\n\n\n");
    FILE *studentDetails;
    struct student stu;
    char CH;
    int Sub_count;
    studentDetails=fopen("std.txt","a");

        printf("\t\t\t\t# Enter Student Index NO :- ");
        scanf(" %[^\n]s",stu.index_no);

        int result=student_check(stu.index_no);
        if(result==1){
        printf("\n Record already exist!!\n");
        }else{

        printf("\t\t\t\t# Enter Student Name :- ");
        scanf(" %[^\n]s",stu.name);
        printf("\t\t\t\t# Enter Student Department :- ");
        scanf(" %[^\n]s",stu.department);


        printf("\n\t\t\t\t*How Many Courses are followed by this student :- ");
        scanf("%d",&Sub_count);
        stu.count=Sub_count;
        printf("\n");

        for(int y=0;y<Sub_count;y++){
            printf("\t\t\t\t# Enter NO %d Course ID :- ",y+1);
            scanf(" %[^\n]s",stu.cou[y].course_id);
            printf("\t\t\t\t# Enter The Grade ('A', 'B', 'C', 'D', 'E' or if absent 'N') :- ");
            scanf("%s",stu.cou[y].grade);
            printf("\n");

        }
        fwrite(&stu,sizeof(struct student),1,studentDetails);
        fclose(studentDetails);
        printf(" Detail has been saved!!");
        }

        printf("\n\n Do you want to enter a new student [Y]/[N]\n To Edit Student Details Press [E]\n To View Student Details Press [V] ");
        scanf(" %c",&CH);
        if(CH=='y' || CH=='Y')
            enterStudentDetails();

        else if(CH=='e'||CH=='E')
              updatestudent();

        else if(CH=='v'||CH=='V')
              viewStudentDetails();

        else
            main();

}

//=============================================================================================================================================================================

void viewStudentDetails()                     //Function For Viewing Student Details

 {

  system("cls");
  printf("\t\t\t\t\t=================================\n");
  printf("\t\t\t\t\t   Student Details & GPA VALUE   \n");
  printf("\t\t\t\t\t=================================\n\n\n");
  char CH;
  int found=0;
  FILE *studentDetails,*coursedetails;
  struct student stu;
  struct coursedetails cde;
  char index_no[20];
  studentDetails=fopen("std.txt","r");
  coursedetails=fopen("coursedetails.txt","r");

  printf("\n Enter Student Index NO :- ");
  scanf("%s",index_no);

  while(fread(&stu,sizeof(struct student),1,studentDetails)){
    if(strcmp(index_no,stu.index_no)==0){
        found=1;
        int totalcredit=0;
        float creditGrade=0.0,totalGPA=0.0;

        printf("\t\t\t\t # Name :- %s\n\n",stu.name);
        printf("\t\t\t\t # Index NO :- %s\n\n",stu.index_no);
        printf("\t\t\t\t # Department :- %s\n\n",stu.department);
        printf("\t\t\t\t # Courses & Grades \n\n");

        for(int c=0;c<stu.count;c++){
            while(fread(&cde,sizeof(struct coursedetails),1,coursedetails)){
                if(strcmp(stu.cou[c].course_id,cde.course_id)==0){
                    totalcredit+=cde.credit_value;

                    printf("\t\t\t\t\t\tCourse ID    :- %s \t\n",cde.course_id);
                    //printf("\t\t\t\t\t\tCourse Name  :- %s \t\n",cde.course_name);
                    //printf("\t\t\t\t\t\tCourse Grade :- %s \t\n\n",stu.cou[c].grade);

                    if(strcmp("A",stu.cou[c].grade)==0)
                        creditGrade+=cde.credit_value*4.0;
                    else if(strcmp("B",stu.cou[c].grade)==0)
                        creditGrade+=cde.credit_value*3.0;
                    else if(strcmp("C",stu.cou[c].grade)==0)
                        creditGrade+=cde.credit_value*2.5;
                    else if(strcmp("D",stu.cou[c].grade)==0)
                        creditGrade+=cde.credit_value*1.5;
                    else if(strcmp("E",stu.cou[c].grade)==0)
                        creditGrade+=cde.credit_value*0.0;
                    else if(strcmp("N",stu.cou[c].grade)==0)
                        creditGrade+=cde.credit_value*0.0;

                        break;
                }

            }
                    printf("\t\t\t\t\t\tCourse Name  :- %s \t\n",cde.course_name);
                    printf("\t\t\t\t\t\tCourse Grade :- %s \t\n\n",stu.cou[c].grade);

        }
        printf("\n");
        totalGPA=creditGrade/totalcredit;
        printf("\t\t\t\t # Current GPA :- %.2f\n",totalGPA);
        printf("\n");

    }
  }
  if (found==0)
    printf("\n\t\t\t\t Index NO. Not Found!!\n\n");
  fclose(studentDetails);
  fclose(coursedetails);

  printf("Exit To Main Menue Press [Y]\nTo View Another Student Detail Press [V]\nTo edit Student Details Press [E]");
  scanf(" %c",&CH);
  if(CH=='Y'||CH=='y')
    main();
  else if(CH=='v'||CH=='V')
    viewStudentDetails();
  else if(CH=='e'||CH=='E')
    updatestudent();

        else{
        main();
    }
}


//============================================================================================================================================================================


int course_check(char courseid[])         //Function For Check Course ID If Already Exist

 {
    struct coursedetails cde;
    int found_course=0;
    FILE *coursedetails;
    if((coursedetails=fopen("coursedetails.txt","r"))!=NULL){
        while(fread(&cde,sizeof(struct coursedetails),1,coursedetails)){
            int result=strcmp(courseid,cde.course_id);
            if(result==0){
                found_course=1;
            }
        }
        return found_course;
        fclose(coursedetails);
    }else{
        printf("\nError!\nFile can not be opened!\n");
    }
}


//===============================================================================================================================================================================


  void entercourseDetails()             //Function For Getting Course Details

  {

  system("cls");
  printf("\t\t\t\t\t===========================\n");
  printf("\t\t\t\t\t     Add Course Details     \n");
  printf("\t\t\t\t\t===========================\n\n\n");

  FILE *coursedetails;
  struct coursedetails cde;
  char CH;
  coursedetails=fopen("coursedetails.txt","a");


     printf("\t\t\t\t # Enter Course ID :- ");
     scanf(" %[^\n]s",cde.course_id);
     int found=course_check(cde.course_id);
     if(found==1){
        printf("\n This Course Already Exist!\n");
     }else{

     printf("\t\t\t\t # Enter Course Name :- ");
     scanf(" %[^\n]s",cde.course_name);
     printf("\t\t\t\t # Enter Credit Value :- ");
     scanf("%f",&cde.credit_value);
     printf("\n");

     fwrite(&cde,sizeof(struct coursedetails),1,coursedetails);
     fclose(coursedetails);
     printf(" Details Has Been Saved!! ");

     }

     printf("\n\n Do you want to enter a new course [Y]/[N]\n To Edit Course Details Press [E]\n To View Course Details Press [V] ");
     scanf(" %c",&CH);
     if(CH=='y'||CH=='Y')
        entercourseDetails();

    else if(CH=='e'||CH=='E')
        updatecourse();

    else if(CH=='v'||CH=='V')
        viewcourseDetails();

     else
        main();

  }

//========================================================================================================================================================================

void viewcourseDetails()          //Function For Viewing Course Details

 {

  system("cls");
  printf("\t\t\t\t    =======================\n");
  printf("\t\t\t\t      VIEW Course Details  \n");
  printf("\t\t\t\t    =======================\n\n\n");
  char CH;
  FILE *coursedetails;
  struct coursedetails cde;
  coursedetails=fopen("coursedetails.txt","r");

  while(fread(&cde,sizeof(struct coursedetails),1,coursedetails)){

    printf("\t\t\t\t | Course ID           :- %s\n",cde.course_id);
    printf("\t\t\t\t | Course Name         :- %s\n",cde.course_name);
    printf("\t\t\t\t | Course Credit Value :- %.1f\n",cde.credit_value);
    printf("\n");

  }
  printf("\n");
  printf("Exit To Main Menue Press   [Y]\nTo Edit above detail press [E]\nTo Add More Courses Press  [A]  ");
  scanf(" %c",&CH);
  if(CH=='y'||CH=='Y')
    main();
  else if(CH=='E'||CH=='e')
    updatecourse();
  else if(CH=='a'||CH=='A')
    entercourseDetails();
  else
    main();
}

//==============================================================================================================================================================================

void list_std(){          //Function for listing student


       system("cls");
       printf("\t\t\t\t\t========================\n");
       printf("\t\t\t\t\t      STUDENT LIST      \n");
       printf("\t\t\t\t\t========================\n\n\n");

       char CH;
       FILE *studentDetails;
       struct student stu;
       studentDetails=fopen("std.txt","r");


     while(fread(&stu,sizeof(struct student),1,studentDetails)){


        printf("\t\t\t\t | Index NO   :- %s\n",stu.index_no);
        printf("\t\t\t\t | Name       :- %s\n",stu.name);
        printf("\t\t\t\t | Department :- %s\n\n",stu.department);

        }


  printf("Exit To Main Menue Press       [Y]\nTo Search Student Detail Press [V]\nTo edit Student Details Press  [E]");
  scanf(" %c",&CH);
  if(CH=='Y'||CH=='y')
    main();
  else if(CH=='v'||CH=='V')
    viewStudentDetails();
  else if(CH=='e'||CH=='E')
    updatestudent();

        else{
        main();
    }

}



//==================================================================================================================================================================================

void main()    //The Main Function

  {

  system("cls");
  system("COLOR 0A");

  char CH;

  FILE *studentDetails;
  FILE *coursedetails;

    if (studentDetails=fopen("std.txt","r+")==NULL){

         studentDetails=fopen("std.txt","w");
         fclose(studentDetails);
      }

    if (studentDetails=fopen("coursedetails.txt","r+")==NULL){

        coursedetails=fopen("coursedetails.txt","w");
        fclose(coursedetails);
      }

  printf("\t\t\t\t\t=================================\n");
  printf("\t\t\t\t\t    STUDENT MANAGEMENT SYSTEM    \n");
  printf("\t\t\t\t\t=================================\n\n");


  printf("\t\t\t\t\t 1 - Add Student Details \n");
  printf("\t\t\t\t\t 2 - Add Course Details \n");
  printf("\t\t\t\t\t 3 - View Student Details & GPA \n");
  printf("\t\t\t\t\t 4 - List All Students \n");
  printf("\t\t\t\t\t 5 - View Course Details \n");
  printf("\t\t\t\t\t 6 - Update Student Details \n");
  printf("\t\t\t\t\t 7 - Update Course Details \n");
  printf("\t\t\t\t\t 0 - Exit Programme       \n");


  printf("\n Select Your Choice (1,2,3,4,5,6,0) :- ");
  scanf(" %c",&CH);

  while(CH!='1' && CH!='2' && CH!='3' && CH!='4' && CH!='5' && CH!='6' && CH!='7'&& CH!='0'){

    printf("\n\aWrong Selection, Please Select Your Choice (1,2,3,4,5,6,7,0) :- ");
    scanf(" %c",&CH);
  }



    if (CH=='1'){
        enterStudentDetails();
    }
    else if(CH=='2'){
        entercourseDetails();
    }
    else if(CH=='3'){
        viewStudentDetails();
    }
    else if(CH=='4'){
        list_std();
    }
    else if(CH=='5'){
        viewcourseDetails();
    }
    else if(CH=='6'){
        updatestudent();
    }
    else if(CH=='7'){
        updatecourse();
    }
    else if(CH=='0'){
        printf("\n\n\t\t\t\t~ Thank You For Using Student Management System ~\n\n");
        exit(0);
    }

}

//##############################################################################################################################################################################






