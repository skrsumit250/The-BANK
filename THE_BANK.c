/**
 * @file Bank.c
 * @author it's Sumit (you@domain.com)
 * @brief 
 * A programme with following features
 * 1.Create an bank account
 * 2.Deposit Money 
 * 3.Withdrawn Money
 * 4.View Details
 * 5.Transactions History
 * 6.Transfer Money
 * 
 * @version 0.1
 * @date 2022-06-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int uid=0;

struct bank
{
    int id;
    int balance;
    int txn;
    char name[20];
    struct transactions
    {
        int debit;
        int credit;
        int total;
    }
    usertxn[100];
    
}
user[10];

void create()
{
    int temp;
    printf("Enter new account number\n");
    scanf("%d",&temp);
    if(uid==0)
    {
        user[uid].id=temp;
        printf("Enter A/C holder name\n");
        scanf("%s",user[uid].name);
        printf("Account Created\n\n\n");
        uid++;
        
    }
    else
    {
        for(int i=0;i<uid;i++)
        {
            if(temp==user[i].id)
            {
                printf("Account already exits!!!!!\nPLEASE! use another account number\n\n");
                break;
            }
            if(i==(uid-1))
            {
               user[uid].id=temp;
               printf("Enter A/C holder name\n");
               scanf("%s",user[uid].name);
               printf("Account Created\n\n\n");
               uid++;
               break;
            }   
        }
    }   
}
void deposit()
{
    int temp;
    printf("Enter account number\n");
    scanf("%d",&temp);
    for(int i=0;i<uid;i++)
    {
        if(user[i].id==temp)
        {
            int cash;
            printf("Enter amount to be deposited\n");
            scanf("%d",&cash);
            user[i].balance+=cash;
            printf("Amount deposited\n\n\n");
            int j=user[i].txn;
            user[i].usertxn[j].credit=cash;
            user[i].usertxn[j].total=user[i].balance;
            user[i].txn++;
            break;        
        }
        else if(i==(uid-1))
        {
            printf("A/C not exists\n\n\n");
        }
    }
}
void withdrawn()
{
    int temp;
    printf("Enter account number\n");
    scanf("%d",&temp);
    for(int i=0;i<uid;i++)
    {
        if(temp==user[i].id)
        {
            int cash;
            printf("Enter amount to be withdrawned\n");
            scanf("%d",&cash);
            if(user[i].balance==0 || user[i].balance<cash)
            {
                printf("Sorry! you have insufficient Balance\n\n\n");
                break;
            }          
            else
            {
                user[i].balance-=cash;
                printf("Cash Withdrawned\n\n\n");
                int j=user[i].txn;
                user[i].usertxn[j].debit=cash;
                user[i].usertxn[j].total=user[i].balance;
                user[i].txn++;         
            } 
            break;      
        }
        else if(i==(uid-1))
        {
            printf("A/C not exists\n\n\n");
        }
    }
}
void tran()
{
    int temp;
    printf("Enter account number\n");
    scanf("%d",&temp);
    for(int i=0;i<uid;i++)
    {
        if(temp==user[i].id)
        {   int k;
            k=user[i].txn;
            if(k==0)
            {
                printf("No Transactions has done yet!!!\n\n\n");
                break;
            }
            printf("User Account Number : %d\n",user[i].id);
            printf("User Name : %s\n",user[i].name);
            printf("Txn no.\t\t\tDebited\t\t\tCredited\t\t\tBalance\n");
            for(int j=0;j<k;j++)
            {   
                printf("%d\t\t\t",j);
                printf("%d\t\t\t",user[i].usertxn[j].debit);
                printf("%d\t\t\t",user[i].usertxn[j].credit);
                printf("%d\n",user[i].usertxn[j].total);
            }
            printf("\n\n\n");
            break;
        }
        else if(i==(uid-1))
        {
            printf("A/C not exists\n\n\n");
        }
    }
}
void view()
{
    int temp;
    printf("Enter account number\n");
    scanf("%d",&temp);
    for(int i=0;i<uid;i++)
    {
        if(temp==user[i].id)
        {
            printf("A/C number: %d\n",user[i].id);
            printf("A/C Holder name: %s\n",user[i].name);
            printf("Balance: %d\n\n\n",user[i].balance);   
            break;        
        }
        else if(i==(uid-1))
        {
            printf("A/C not exists\n\n\n");
        }
    }
}
void trans()
{
    int temp;
    printf("Enter account number\n");
    scanf("%d",&temp);
    for(int i=0;i<uid;i++)
    {
        if(temp==user[i].id)
        {
            int cash;
            printf("Enter amount to be transfer\n");
            scanf("%d",&cash);
            if(user[i].balance==0 || user[i].balance<cash)
            {
                printf("Sorry! you have insufficient Balance\n\n\n");
                break;
            }          
            else
            {
                user[i].balance-=cash;
                int j=user[i].txn;
                user[i].usertxn[j].debit=cash;
                user[i].usertxn[j].total=user[i].balance;
                user[i].txn++; 
                int tem;
                printf("Enter account number in which money is transfering\n");
                scanf("%d",&tem);
                for(int k=0;k<uid;k++)
                {
                    if(user[k].id==tem)
                    {
                        user[k].balance+=cash;
                        printf("Amount transfered\n\n\n");
                        int m=user[k].txn;
                        user[k].usertxn[m].credit=cash;
                        user[k].usertxn[m].total=user[k].balance;
                        user[k].txn++;
                        break;        
                    }
                    else if(i==(uid-1))
                    {
                        printf("A/C not exists\n\n\n");
                    }
                }      
            } 
            break;      
        }
        else if(i==(uid-1))
        {
            printf("A/C not exists\n\n\n");
        }
    }
}

int main()
{
    int option;
    while(option!=7)
    {
        printf("Menu\n");
        printf("1.Create Account\n");
        printf("2.Cash Deposit\n");
        printf("3.Cash Withdrawn\n");
        printf("4.View A/C details\n");
        printf("5 Transaction History\n");
        printf("6.Transfer Money\n");
        printf("7.Exit\n");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            create();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdrawn();
            break;
        case 4:
            view();
            break;
        case 5:
            tran();
            break;
        case 6:
            trans();
            break;
        case 7:
            return 0;
            break;               
        default:
            printf("Invalid Option......Please try again\n");
            break;
        }
    }
    return 0;    
}
