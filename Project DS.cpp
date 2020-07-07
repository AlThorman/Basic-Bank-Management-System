#include<iostream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Customer{
string name;
int  id;
double account;
double transactions[3];
string transactionsName[3];
int front = -1, rear = -1, n=3;
Customer *next, *prev ;
};


int front = -1, rear = -1, n=3;

Customer *emp, *cur,*head,*tail;
int i=1;

void InsertCustomer();
void Deposit (int );
void Withdraw (int );
void DisplayList(int );
void Search(string  );
void DisplayTR(int );


int main ()
{
int choose1,choose2,choose3,choose4,num;

string names;

cout<<"\n------ Bank Management System ------";
cout<<"\n[1] Customer.\n[2] Admin.\n[3] Exist. \nChoose Now: ";
cin>>choose1;
while(choose1 != 3)
{
switch (choose1){

case 1:
cout<<"\n[1] Open new account .\n[2] Deposit or Withdraw from your account. ";
cout<<"\n[3] Print your current  balance .\n[4] Last 3 transactions.\n[5] Exist.\nChoose Now: ";
cin>>choose2;
while(choose2 != 5)
{
switch (choose2){
case 1:
InsertCustomer( );
//  Account();
cout<<"\nYour account has been opened\n";
break;\
case 2:
cout<<"\n[1] Deposit.\n[2] Withdraw.\nChoose Now: ";
cin>>choose3;
switch (choose3){
case 1:
cout<<"Enter your ID: ";
cin>>num;
if(num > i-1)
cout<<" The id is not exist"<<endl;
else
{
Deposit( num);
cout<<"Done...\n";
}
break;
case 2:
cout<<"Enter your ID: ";
cin>>num;
if(num > i-1)
cout<<" The id is not exist"<<endl;
else
{
Withdraw ( num);
cout<<"Done...\n";	
}
break;
default:
cout<<"\nWrong input!\n";
}//switch 3 end
break;
case 3:
cout<<"Enter your ID: ";
cin>>num;
DisplayList(num );
break;
case 4:
cout<<"Enter the ID of the customer: ";
cin>>num;
DisplayTR(num);
break;
case 5:
cout<<"\nGoodBye :)\n";
break;
default:
cout<<"\nWrong input!\n";
}//switch 2 end
cout<<"\n[1] Open new account .\n[2] Deposit or Withdraw from your account. ";
cout<<"\n[3] Print your current  balance .\n[4] Last 3 transactions.\n[5] Exist.\nChoose Now: ";
cin>>choose2;
}//case 2 (customer) end
break;
case 2:
cout<<"\n[1] Search by the name of the customer. \n[2] Search by the ID of the customer.\n[3] Exit. \nChoose Now: ";
cin>>choose4;
while(choose4 != 3)
{
switch (choose4){
case 1:
cout<<"Enter the name of the customer: ";
cin>>names;
Search( names );
break;
case 2:
cout<<"Enter the ID of the customer: ";
cin>>num;
DisplayList( num );
break;
case 3:
cout<<"\nGoodBye :)\n";
break;
default:
cout<<"\nWrong input!\n";
}//switch4 end
cout<<"\n[1] Search by the name of the customer. \n[2] Search by the ID of the customer.\n[3] Exit. \nChoose Now: ";
cin>>choose4;
}//while4 end
break;

default:
cout<<"\nWrong input!\n";
}//switch end
cout<<"------ Bank Management System ------";
cout<<"\n[1] Customer.\n[2] Admin.\n[3] Exist. \nChoose Now: ";
cin>>choose1;
}//while end
cout<<"\nThank you for using our app :)\nMade with Love by:\n[1] AbdulRahman Fuad Al-Thorman.\n[2] Ahmad Mohammad Al-Doghan.\n[3] Abdullah Saad Al-Dawsari."<<endl;
}//main end


void InsertCustomer( )
{
int tempMoney;
emp = new Customer;// Create new Customer
fflush(stdin);
cout<<"\nEnter Your Name: " ;
cin>>emp->name ;
emp->id=i ;
cout<<"\nEnter some money to initial your account: ";
cin>>tempMoney;
if(tempMoney >= 0)
emp->account = tempMoney;
else
emp->account = 0;

cout<<"Your ID is ( "<<emp->id<<" )";
i++;
//////// For  last 3 transactions function ///////
double initial;
initial=emp->account;
if ((emp->front == 0 && emp->rear == emp->n-1) || (emp->front == emp->rear+1)) {
if (emp->front == emp->rear) {
emp->front = -1;
emp->rear = -1;
}else {
if (emp->front == emp->n - 1)
emp->front = 0;
else
emp->front = emp->front + 1;
}}



if (emp->front == -1) {
emp->front = 0;
emp->rear = 0;
} else {
if (emp->rear ==emp-> n - 1)
emp->rear = 0;
else
emp->rear = emp->rear + 1;
}
emp->transactions[emp->rear]=initial;
emp->transactionsName[emp->rear]="\nInitial: +$ ";
//////// End of  last 3 transactions function ///////
if (head==NULL)
{
emp->next = NULL ;
emp->prev = NULL ;
head=emp;
tail=emp;
}
else
{
emp->next=head;
emp->prev=NULL;
head->prev = emp;
head=emp;
}
}

void Deposit (int di){
double deposit;
cur = head;

while(cur!=NULL)
{
if (cur->id==di)
{
cout<<"\nHello ( "<<cur->name<<" ) \n"<<"Enter the amount of money that you want to deposit: ";
cin>>deposit;
if (deposit<1)
{
cout<<"\nWrong Input \n( the amount should be greater than Zero ).";
return;
}
else {
cur->account =cur->account +deposit;
//////// For  last 3 transactions function ///////
if ((cur->front == 0 && cur->rear == cur->n-1) || (cur->front == cur->rear+1)) {
if (cur->front == cur->rear) {
cur->front = -1;
cur->rear = -1;
} else {
if (cur->front == emp->n - 1)
cur->front = 0;
else
cur->front = emp->front + 1;
}
}
if (cur->front == -1) {
cur->front = 0;
cur->rear = 0;
} else {
if (cur->rear ==cur->n - 1)
cur->rear = 0;
else
cur->rear = cur->rear + 1;
}
cur->transactions[cur->rear]=deposit;
cur->transactionsName[cur->rear]="\nDeposit: +$ ";
//////// End of  last 3 transactions function ///////
return;
}
}
cur=cur->next ;

}
}
void Withdraw (int di){
double withdraw;
cur = head;

while(cur!=NULL)
{
if (cur->id==di)
{
cout<<"\nHello ( "<<cur->name<<" ) \n"<<"Enter the amount of money that you want to withdraw: ";
cin>>withdraw;
if (withdraw>cur->account)
{
cout<<"\nWrong Input \n( the amount should be less than or equal your balance ).";
return;
}
else {
cur->account =cur->account -withdraw;
//////// For  last 3 transactions function ///////
if ((cur->front == 0 && cur->rear == cur->n-1) || (cur->front == cur->rear+1)) {
if (cur->front == cur->rear) {
cur->front = -1;
cur->rear = -1;
}else {
if (cur->front == emp->n - 1)
cur->front = 0;
else
cur->front = emp->front + 1;
}
}
if (cur->front == -1) {
cur->front = 0;
cur->rear = 0;
} else {
if (cur->rear ==cur-> n - 1)
cur->rear = 0;
else
cur->rear = cur->rear + 1;
}
cur->transactions[cur->rear]=withdraw;
cur->transactionsName[cur->rear]="\nWithdraw: -$ ";
//////// End of  last 3 transactions function ///////
return;
}
}
cur=cur->next ;
}
}

void DisplayList(int di )
{
bool found = 0;
cur = head;
if(cur == NULL)
cout<<"\nThis ID Does not exist!\n" ;
else{
while(cur!=NULL )
{
if (cur->id==di)
{
cout<<"\nName: "<<cur->name <<" ";
cout<<"\nYour Balance: $ "<<fixed<<setprecision(2)<<cur->account<<endl;
found = 1;
break;
}
cur=cur->next ;
}
if(found == 0)
cout<<"\nThis ID Does not exist!\n" ;
}
}

void Search(string names )
{
cur = head;
if(cur == NULL)
cout<<"\nThis Name Does not exist!\n" ;
else
while(cur!=NULL)
{
if (cur->name==names)
{
cout<<"\nName: "<<cur->name ;
cout<<"\nYour Balance: $ "<<fixed<<setprecision(2)<<cur->account<<endl;
}
cur=cur->next ;
}
}


void DisplayTR(int di) {
cur = head;
if(cur == NULL)
cout<<"\nThis ID Does not exist!\n" ;
else{
while(cur!=NULL )
{
if (cur->id==di)
{
int f = cur->front, r =cur->rear;
if (cur->front == -1) {
cout<<"There is no transactions happend !"<<endl;
return;
}
cout<<"\nYour last 3 transactions is :\n";
if (f <= r) {
while (f <= r){
cout<<cur->transactionsName[f];
cout<<fixed<<setprecision(2)<<cur->transactions[f];
f++;
}
} else {
while (f <= n - 1) {
cout<<cur->transactionsName[f]<<" ";
cout<<fixed<<setprecision(2)<<cur->transactions[f];
f++;
}
f = 0;
while (f <= r) {
cout<<cur->transactionsName[f]<<" ";
cout<<fixed<<setprecision(2)<<cur->transactions[f];
f++;
}
}
cout<<endl;
}
cur=cur->next ;
}
}
}



