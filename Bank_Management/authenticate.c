#include "Bank_structure.h"
extern int check_data(char name[],char Acc_no[12],long int* ph_no,float* amount);
extern int create_acc(struct User usr);
extern void login(char Acc_no[],char pass[]);
void Register_Acc(){
    system("clear");
    User usr;
    printf("Enter your Account number :\t\t");
    scanf("%s",usr.Acc_no);
    printf("Enter your name :\t\t\t");
    scanf("%s",usr.name);
    printf("Enter your password :\t\t\t");
    scanf("%s",usr.pass);
    printf("Enter your phone number :\t\t");
    scanf("%ld",&usr.ph_no);
    printf("Enter your address :\t\t\t");
    scanf("%s",usr.address);
    printf("Enter Account Balance :\t\t\t");
    scanf("%f",&usr.amount);
    check_data(usr.name,usr.Acc_no,&usr.ph_no,&usr.amount);
    if(create_acc(usr)==1){
        printf("Account created succesfully\n\n");
    }
}
void Login_Acc(){
    system("clear");
    char Acc_no[20],pass[20];
    printf("Enter your Account number :\t");
    scanf("%s",Acc_no);
    printf("Enter the Password :\t\t");
    scanf("%s",pass);
    login(Acc_no,pass);
}