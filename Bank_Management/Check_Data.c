#include "Bank_structure.h"
#include "Bank_Function.h"
#include <unity.h>
int check_data(char name[],char Acc_no[],long int* ph_no,float* amount){
    while(1){
        if(check_Name(name)==1){
            break;
        }
        else{
            printf("Your name is invalid!!\n\n");
            printf("Enter your name :\t\t\t");
            scanf("%s",name);
            continue;
        }
    }
    while(1){
        if(check_Acc_no(Acc_no)==1){
            break;
        }
        else{
            printf("Invalid Account number!!\n\n");
            printf("Enter your Account number :\t\t\t");
            scanf("%s",Acc_no);
            continue;
        }
    }
    while(1){
        long int dup_no=*ph_no;
        if(check_Ph_no(dup_no)==1){
            break;
        }
        else{
            printf("Invalid phone number!!\n\n");
            printf("Enter your phone number :\t\t\t");
            scanf("%ld",&*ph_no);
            continue;
        }
    }
    while(1){
        float amo=*amount;
        if(check_amount(amo)!=1){
            printf("Minimum Account balance is 1000\n\n");
            printf("Enter your intital amount :\t\t\t");
            scanf("%f",&*amount);
            continue;
        }
        else{
            break;
        }
    }
    return 1;
}
void setUp(void){}
void tearDown(void){}
void bank_function(){
    TEST_ASSERT_EQUAL(1,check_Name("ABC"));
    TEST_ASSERT_EQUAL(0,check_Name("123"));
    TEST_ASSERT_EQUAL(0,check_Name("ABC@"));
    TEST_ASSERT_EQUAL(1,check_Acc_no("123456789010"));
    TEST_ASSERT_EQUAL(0,check_Acc_no("123"));
    TEST_ASSERT_EQUAL(0,check_Acc_no("1234567890101123"));
    TEST_ASSERT_EQUAL(0,check_Acc_no("123Abc"));
    TEST_ASSERT_EQUAL(1,check_Ph_no(1234567890));
    TEST_ASSERT_EQUAL(0,check_Ph_no(12345));
    TEST_ASSERT_EQUAL(0,check_Ph_no(1234567890123));
    TEST_ASSERT_EQUAL(1,check_amount(1000));
    TEST_ASSERT_EQUAL(0,check_amount(500));
    TEST_ASSERT_EQUAL(1,check_amount(2000));
}
int test_code(){
    UnityBegin(NULL);
    RUN_TEST(bank_function);
    return (UnityEnd());
}