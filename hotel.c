#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define KNRM  "\x1B[0m"
#define KCYN  "\x1B[36m"
#define KMAG  "\x1B[35m"

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"

//To check password and flow
char password[4],select1_2[1];
//To read file column
char column_1[20],column_2[20],column_3[20],column_4[20],price[20],troom[20],column_5[20],column_6[20],column_7[20],column_8[20];
//To add room
char r_num[5],r_type[5];
//To check packge type in file
char type1[]="A",type2[]="B",type3[]="C";

int select1,select2,select2_2,noofroom,re,count_1=0,count_2,i=3;

//Welcome
void welcome();
//Admin|>>>>>>>>>>>>>>>>>>>>>>>>>
void admin();
//1)_1 View and change packge
void view_change();
//1)_2 Customer details
void record();
//1)_3 Check-out
void check_out();
//1)_4 Add rooms
void addroom();

//User|>>>>>>>>>>>>>>>>>>>>>>>>>
void user();
//2)_1 Print_packges
void print_packages();
//2)_2 Check_room_avaliability
int check_room_avaliability(char type[]);
//2)_3 Check_user_reqest
int check_user_reqest(int count_1,int noofroom,char type[]);
//2)_4 Booking and Generate pay slip
int booking(int count_3,char type[]);

// Count numbers of line in room.txt
int count_file_line_room();
// Count numbers of line in booking_details.txt
int count_file_line_booking_details();


int main(){
    welcome();
    //Admin and User selection
    printf("\n\t---------------------------------------------------\n");
    printf("\t-\tPress No:1 >> Hotel Management            -\n");
    printf("\t-\tPress No:2 >> Guest                        -\n");
    printf("\t---------------------------------------------------\n");

    printf("Enter your selection: ");
    scanf("%d",&select1);

    switch(select1){
        //Admin >>>
        case 1:
            printf("\n%s01) ADMIN",KMAG);
            printf("%s", KNRM);

            lable1:

            printf("\nEnter password: ");
            scanf("%s",&password);

            //Password checking
            if(strcmp(password,"1234")==0){
                admin();
            }
            else{
                if(i>0){
                    printf("\nIncorrect password..You have %d remaining chances\n",i);
                    i--;
                    goto lable1;
                }
            }

            break;
        //User >>>
        case 2:
            user();
    }
}


void welcome(){

    printf("%s\n\t\t\t\t\t +.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.+ \n\t\t\t\t\t+", KCYN);
    printf("                                                                                          +");
    printf("\n\t\t\t\t\t=                                                                                          =");
    printf("\n\t\t\t\t\t=                       >>>||  Welcome to Paramount Hotel  ||<<<                           =");
    printf("\n\t\t\t\t\t=                                                                                          =");
    printf("\n\t\t\t\t\t=                                                                                          =");
    printf("\n\t\t\t\t\t=               Get instant confirmation. Book a Hotel in Paramount online!                =");
    printf("\n\t\t\t\t\t=            Best Price Guarantee . Secure Booking . Hostels . No Booking Fees.            =");
    printf("\n\t\t\t\t\t=           Bed and Breakfasts . Read Real Guest Reviews . 24/7 Customer Service.          =");
    printf("\n\t\t\t\t\t+                                                                                          +");
    printf("\n\t\t\t\t\t +.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.--.*.+ \n  ");
    printf("%s", KNRM);

}


void admin(){

    printf("\t---------------------------------------------------");
    printf("\n\t- Press No:1 >> View and change package price     -\n\t- Press No:2 >> Customer details                  -\n\t- Press No:3 >> Check-out                         -\n\t- Press No:4 >> Add rooms                         -\n\t- Press No:5 >> Exit                              -\n");
    printf("\t---------------------------------------------------\n");
    printf("Enter your selection: ");
    scanf("%s",&select1_2);

    if(strcmp(select1_2,"1")==0){
        printf("%s\n01)_1. VIEW AND CHANGE PACKAGE PRICE.",KMAG);
        printf("%s", KNRM);
        view_change();
    }

    else if(strcmp(select1_2,"2")==0){
        printf("%s\n01)_2.  CUSTOMER DETAILS.",KMAG);
        printf("%s", KNRM);
        record();
    }

    else if(strcmp(select1_2,"3")==0){
        printf("%s\n01)_3. CHECK-OUT.",KMAG);
        printf("%s", KNRM);
        check_out();
    }

    else if(strcmp(select1_2,"4")==0){
        printf("%s\n01)_4. ADD ROOM.\n",KMAG);
        printf("%s", KNRM);
        addroom();
    }

    else{
        exit(0);
    }
}


void view_change(){

    char ch;
    FILE*file1;
    file1=fopen("database_1.txt","r");
    if(file1==NULL){
        printf("Error: view_change");
    }

    printf("\n=========================================\n");
    printf("\n%sPackage\t Facilities\t Price\t    Type\n%s",KBLU,KNRM);
    while(!feof(file1)){
        ch=fgetc(file1);
        printf("%c",ch);
    }
    printf("\n=========================================");
    fclose(file1);

    printf("\n\t---------------------------------------------------");
    printf("\n\t-Press No:1 >> change package                      -\n\t-Press No:2 >> Previous menu                      -\n\t-Press No:3 >> Exit                               -\n");
    printf("\t---------------------------------------------------\n");
    printf("Enter your selection: ");
    scanf("%s",&select1_2);

    if(strcmp(select1_2,"1")==0){
        printf("\nSelect package: ");
        scanf("%s",&select1_2);
        FILE*fPtr;
        FILE*fTemp;
        fPtr=fopen("database_1.txt","r");
        fTemp = fopen("replace.tmp", "w");
        if(fPtr==NULL||fTemp == NULL){
            printf("Error: view_change");
            exit(0);
        }
        re=3;// fix newline error
        while(!feof(fPtr)&&re>0){
            fscanf(fPtr,"%s %s %s %s",column_1,column_2,column_3,column_4);
            if(strcmp(column_1,select1_2)==0){
                printf("\n\tUpdate:RS.%s To Rs.",column_3);
                scanf("%s",&price);
                fprintf(fTemp,"%s\t   %s\t %s\t      %s\n",column_1,column_2,price,column_4);
                re--;
            }
            else{
                fprintf(fTemp,"%s\t   %s\t %s\t      %s\n",column_1,column_2,column_3,column_4);
                re--;
            }
        }
        fclose(fPtr);
        fclose(fTemp);
        remove("database_1.txt");
        rename("replace.tmp","database_1.txt");
        printf("\t%s> Update sucessful !%s\n",KGRN,KNRM);
        
        printf("\t---------------------------------------------------");
        printf("\n\t-Press No:1 >> Previous menu                      -\n\t-Press No:2 >> Exit                               -\n");
        printf("\t---------------------------------------------------\n");
        printf("Enter your selection: ");
        scanf("%s",&select1_2);

        if(strcmp(select1_2,"1")==0){
            admin();
        }
        else{
            exit(0);
        }
    }
    else if(strcmp(select1_2,"2")==0){
        admin();
    }
    else if(strcmp(select1_2,"3")==0){
        exit(0);
    }
}


void record(){

    printf("\n\n");
    FILE*fp;
    fp=fopen("booking_details.txt","r");
    if(fp==NULL){
        printf("Error opening:booking_details.txt");
    }
    re=count_file_line_booking_details();

    printf("================================================================\n\n");
    int t=1;

    while(!feof(fp)&&re>0){
        fscanf(fp,"%s %s %s %s %s %s %s %s",column_1,column_2,column_3,column_4,column_5,column_6,column_7,column_8);
        if(t==1){
            printf("%s%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s%s\n",KBLU,column_1,column_2,column_3,column_4,column_5,column_6,column_7,column_8,KNRM);
            t++;
            continue;
        }
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",column_1,column_2,column_3,column_4,column_5,column_6,column_7,column_8);
        re--;
    }
    printf("\n================================================================\n");
    fclose(fp);

    printf("\n\t---------------------------------------------------");
    printf("\n\t-Press No:1 >> Previous menu                      -\n\t-Press No:2 >> Exit                               -\n");
    printf("\t---------------------------------------------------\n");
    printf("Enter your selection: ");
    scanf("%s",&select1_2);
    if(strcmp(select1_2,"1")==0){
        admin();
    }
    else{
        exit(0);
    }
}


void check_out(){

    //print availability: = "No" rooms
    printf("\n=========================================\n");
    printf("\n%sRoom num\tAvailability%s\n",KBLU,KNRM);
    FILE*fPt;
    fPt=fopen("room.txt","r");
    if(fPt==NULL){
        printf("Error: count_file_line_room");
        exit(0);
    }

    re=count_file_line_room();
    while(!feof(fPt)&&re>0){
        fscanf(fPt,"%s %s %s",column_1,column_2,column_3);
        if(strcmp(column_2,"No")==0){
            printf("%s\t\t%s\n",column_1,column_2);
        }
        re--;
    }
    printf("\n=========================================");
    fclose(fPt);

    printf("\nWhich room number do you want to check-out: ");
    scanf("%s",&troom);

    //update checkout details
    FILE*fPtr;
    FILE*fTemp;
    fPtr=fopen("room.txt","r");
    fTemp = fopen("replace.tmp", "w");
    if(fPtr==NULL||fTemp == NULL){
        printf("Unable to open file:room.txt");
        exit(0);
    }
    re=count_file_line_room();//Fix new line error
    while(!feof(fPtr)&&re>0){
        fscanf(fPtr,"%s %s %s",column_1,column_2,column_3);
        if(strcmp(column_1,troom)==0){
            fprintf(fTemp,"%s\t%s\t%s\n",column_1,"Yes",column_3);
            re--;
        }
        else{
            fprintf(fTemp,"%s\t%s\t%s\n",column_1,column_2,column_3);
            re--;
        }
    }
    fclose(fPtr);
    fclose(fTemp);
    remove("room.txt");
    rename("replace.tmp","room.txt");
    printf("%s> Update sucessful !%s\n",KGRN,KNRM);

    printf("\t---------------------------------------------------");
    printf("\n\t-Press No:1 >> Previous menu                      -\n\t-Press No:2 >> Exit                               -\n");
    printf("\t---------------------------------------------------\n");
    printf("Enter your selection: ");
    scanf("%s",&select1_2);
    if(strcmp(select1_2,"1")==0){
        admin();
    }
    else{
        exit(0);
    }
}


void addroom(){

    FILE*fPtr;
    fPtr=fopen("room.txt","r");
    if(fPtr==NULL){
        printf("Error: count_file_line_room");
        exit(0);
    }
    re=count_file_line_room();//fix new line error
    printf("=========================================\n\n");
    printf("%sRoom No\t\tAvailability\tType%s\n",KBLU,KNRM);
    while(!feof(fPtr)&&re>0){
        fscanf(fPtr,"%s %s %s",column_1,column_2,column_3);
        printf("%s\t\t%s\t\t%s\n",column_1,column_2,column_3);
        re--;
    }
    printf("\n=========================================\n");
    fclose(fPtr);

    printf("Enter room no:");
    scanf("%s",r_num);
    printf("Enter room type:");
    scanf("%s",r_type);

    //update records
    FILE*fp;
    fp=fopen("room.txt","a");
    fprintf(fp,"%s\t%s\t%s\n",r_num,"Yes",r_type);
    fclose(fp);
    printf("%s> Update sucessful !%s\n",KGRN,KNRM);
        
    printf("\t---------------------------------------------------");
    printf("\n\t-Press No:1 >> Previous menu                      -\n\t-Press No:2 >> Exit                               -\n");
    printf("\t---------------------------------------------------\n");
    printf("Enter your selection: ");
    scanf("%s",&select1_2);
    if(strcmp(select1_2,"1")==0){
        admin();
    }
    else{
        exit(0);
    }

}


void user(){

    print_packages();
    //Packge selection
    printf("\nSelect package [ 1 , 2 , 3 ] : ");
    scanf("%d",&select2);
    switch(select2){

        case 1:
            //package 1
            printf("\nHow many rooms do you want: ");
            scanf("%d",&noofroom);
            count_1=0;
            count_1=check_room_avaliability(type1);
            check_user_reqest(count_1,noofroom,type1);
            break;

        case 2:
            //package 2
            printf("\nHow many rooms do you want: ");
            scanf("%d",&noofroom);
            count_1=0;
            count_1=check_room_avaliability(type2);
            check_user_reqest(count_1,noofroom,type2);
            break;

        case 3:
            //package 3
            printf("\nHow many rooms do you want: ");
            scanf("%d",&noofroom);
            count_1=0;
            count_1=check_room_avaliability(type3);
            check_user_reqest(count_1,noofroom,type3);
            break;
    }
}


void print_packages(){

    printf("\n\n%s02) Guest\n",KMAG);
    printf("%s", KNRM);
    FILE*file1;
    file1=fopen("database_1.txt","r");
    if(file1==NULL){
        printf("Unable to open file:database_1.txt");
        exit(0);
    }
    printf("\n      |=========================================|\n      |");
    printf(" %sPackage%s\t  |    %sFacilities%s  |    %sprice%s   |\n",KBLU,KNRM,KBLU,KNRM,KBLU,KNRM);
    re=3;
    while(!feof(file1)&&re>0){
        fscanf(file1,"%s %s %s %s",column_1,column_2,column_3,column_4);
        printf("      |  %s\t..|..\t%s\t ..|.. \t%s    |\n",column_1,column_2,column_3);
        re--;
    }
    printf("      |=========================================|\n");
    fclose(file1);
}


int check_room_avaliability(char type[]){

    FILE*file1;
    file1=fopen("room.txt","r");
    if(file1==NULL){
        printf("Unable to open file:room.txt");
        return 1;
    }
    while(!feof(file1)){
        fscanf(file1,"%s %s %s",column_1,column_2,column_3);
        if(strcmp(column_2,"Yes")==0&&strcmp(column_3,type)==0){
            count_1++;
            }
    }
    fclose(file1);
    return (count_1);
    
}


int check_user_reqest(int count_1,int noofroom,char type[]){

    //If available:
    if(count_1>=noofroom){
        printf("\n\t  Rooms are available ..!\n");
        printf("\t-------------------------------------------------\n");
        printf("\t- Press No:1 >> Continue booking                -\n\t- Press No:2 >> Previous menu                   -\n\t- Press No:3 >> Exit                            -\n");
        printf("\t-------------------------------------------------\n");
        printf("Enter your selection: ");
        scanf("%d",&select2_2);
        if(select2_2==1){
            booking(noofroom,type);
            }
        else if(select2_2==2){
            user();
            }
        else{
            exit(0);
        }
    }

    //If available room < user input:
    else if(count_1!=0){
        printf("\n\t  Sorry..only %d Rooms available .\n",count_1);
        printf("\t-------------------------------------------------\n");
        printf("\t- Press No:1 >> Continue booking                -\n\t- Press No:2 >> Previous menu                   -\n\t- Press No:3 >> Exit                            -\n");
        printf("\t-------------------------------------------------\n");
        printf("Enter your selection: ");
        scanf("%d",&select2_2);
        if(select2_2==1){
            printf("\nHow many rooms do you need out of these %d rooms ?",count_1);
            scanf("%d",&count_2);
            booking(count_2,type);
            }
        else if(select2_2==2){
            user();
            }
        else{
            exit(0);
        }
    }

    //If Rooms are not available:
    else{
        printf("\n\t Sorry..Rooms are not available .\n");
        printf("\t---------------------------------------------------");
        printf("\n\t-Press No:1 >> Previous menu                      -\n\t-Press No:2 >> Exit                               -\n");
        printf("\t---------------------------------------------------\n");
        printf("Enter your selection: ");
        scanf("%d",&select2_2);
        if(select2_2==1){
            user();
            }
        else{
            exit(0);
        }
    }
}


int booking(int count_3,char type[]){

    char name[50],ID[50],checkin[50],checkout[50],mail[50],tnum[50];
    int charge[0];
    int nonight,payselect,cnum,tot;

    printf("\n\n%sClient Details\n\n",KMAG);
    printf("%s", KNRM);
    
    printf("I)   Name                              : ");
    gets(name);
    gets(name);
    printf("II)  NIC / Passport no                 : ");
    gets(ID);
    printf("III) Contact number                    : ");
    gets(tnum);
    printf("IV)  E-mail                            : ");
    gets(mail); 
    printf("V)   Number of nights expected to stay : ");
    scanf("%d",&nonight);
    printf("VI)  Check-in (DD/MM/YY hh:mm AM/PM    :");
    gets(checkin);
    gets(checkin);

    printf("\n\nYour Booking Details:-\n\n");
    printf("    I)   Customer Name             : %s\n",name);
    printf("    II)  Selected packge           : %s\n",type);
    printf("    III) Number of rooms           : %d\n",count_3);
    printf("    IV)  Number of nights expected : %d\n",nonight);

    //find total charge
    FILE*file1;
    file1=fopen("database_1.txt","r");
    if(file1==NULL){
        printf("Error: Booking");
        exit(0);
    }
    while(!feof(file1)){
        fscanf(file1,"%s %s %d %s",column_1,column_2,charge,column_4);
        if(strcmp(column_4,type)==0){
            tot=charge[0]*count_3*nonight;
            break;
            }
    }
    fclose(file1);

    printf("    V)   Total charge              : RS.%d.00\n",tot);
    printf("\n         -----------------------------------------------\n");
    printf("         -Press No:1 >> Pay now                        -\n         -Press No:2 >> Exit                           -");
    printf("\n         -----------------------------------------------\n");
    printf("Enter your selection: ");
    scanf("%d",&payselect);

    if(payselect==1){
        //Payment
        printf("\nEnter Credit / Debit card number: ");
        scanf("%d",&cnum);
        printf("\t%sPayment successful !%s\n\n",KGRN,KNRM);

        //save booking records
        FILE*fp;
        fp=fopen("booking_details.txt","a");
        fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%d\t%s\n",type,count_3,name,ID,tnum,mail,nonight,checkin);
        fclose(fp);

        //Print slip
        printf("\t\t\t\t  %s- Paramount Hotel -\n",KBLU);
        printf(" Location:Badulla   Tel:0552525259   Mail:Paramount@gmail.com   Visit:www.Paramount.com \n");
        printf("---------------------------------------------------------------------------------------\n\n");
        printf("Paid By:%s\t\t\t\t\t\t\t\t\tRECEIPT\n",name);
        printf("%s\n",mail);

        printf("\nBooking Details \n");
        printf("Your Room numbers are:  ");

        //Update availibility and find room numbers in file
        int repeat=count_3;
        FILE*fPtr;
        FILE*fTemp;
        fPtr=fopen("room.txt","r");
        fTemp = fopen("replace.tmp", "w");
        if(fPtr==NULL||fTemp == NULL){
            printf("Error: Booking");
            exit(0);
        }
        re=count_file_line_room();//fix new line error
        while(!feof(fPtr)&&re>0){
            fscanf(file1,"%s %s %s",column_1,column_2,column_3);
            
            if(strcmp(column_2,"Yes")==0&&strcmp(column_3,type)==0&&repeat!=0){
                printf("%s ",column_1);//print room numbers
                fprintf(fTemp,"%s\t%s\t%s\n",column_1,"No",column_3);
                repeat--;
                re--;
            }
            else{
                fprintf(fTemp,"%s\t%s\t%s\n",column_1,column_2,column_3);
                re--;
            }
        }
        fclose(fPtr);
        fclose(fTemp);
        remove("room.txt");
        rename("replace.tmp","room.txt");
        printf("\nCheck-in\t\t%s\n",checkin);
        printf("\nDescription\t\t\t\t\t\t\t\t\t Amount\n");
        printf("Packge  \t\t%s\t\t\t\t\t\t\t   %d\n",column_4,charge[0]);
        printf("Number of room   \t\t\t\t\t\t\t\t      %d\n",count_3);
        printf("Number of nights   \t\t\t\t\t\t\t\t      %d\n",nonight);
        printf("Total   \t\t\t\t\t\t\t\t       RS.%d\n",tot);
        printf("\t\t\t   Thank you for staying with us !\n\n");
        printf("%s",KNRM);
    }

    else{
        exit(0);
    }

}


int count_file_line_room(){

    int c=0;
    FILE*fPtr;
    fPtr=fopen("room.txt","r");
    if(fPtr==NULL){
        printf("Error: count_file_line_room");
        exit(0);
    }
    while(!feof(fPtr)){
        fscanf(fPtr,"%s %s %s",column_1,column_2,column_3);
        c++;
    }
    fclose(fPtr);
    return(c-1);
}

int count_file_line_booking_details(){

    int c=0;
    FILE*fPtr;
    fPtr=fopen("booking_details.txt","r");
    if(fPtr==NULL){
        printf("Error: count_file_line_room");
        exit(0);
    }
    while(!feof(fPtr)){
        fscanf(fPtr,"%s %s %s %s %s %s %s %s",column_1,column_2,column_3,column_4,column_5,column_6,column_7,column_8);
        c++;
    }
    fclose(fPtr);
    return(c-1);
}