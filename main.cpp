#include <iostream>
#include <string>
using namespace std;
class Validation{
public:
    static bool Name(string name){
    for(int i=0;i<name.size();i++){
        if(!(name[i]>='a'&&name[i]<='z'||name[i]>='A'&&name[i]<='Z'||name[i]==' ')){
           cout<<"Name must be only letters"<<endl;
        return false;
        }
    }
    if(name.size()>4&&name.size()<21){
        return true;
    }

    else{
            cout<<"The name must be more than 4 and less than 21"<<endl;
        return false;
    }

    }
    static bool Password(string password){
    for(int i=0;i<password.size();i++){
        if(password[i]==' '){
            cout<<"Cannot make space in the password"<<endl;
        return false;
        }
    }
    if(password.size()>7&&password.size()<21){
        return true;
    }

     else{
            cout<<"The password must be more than 7 and less than 21"<<endl;
        return false;
    }

       }
    static bool Balance(double balance){
    if(balance>=1500){
        return true;
    }
    else{
        cout<<"The balance must be more than or equal 1500"<<endl;
        return false;
    }
       }
    static bool Salary(double salary){
    if(salary>=5000){
        return true;
    }
    else{
        cout<<"The salary must be more than or equal 5000"<<endl;
        return false;
    }

       }
};
//========================================================================================
class Person{
protected:
    int id;
    string name,password;
public:
    Person(){
     }
    Person(int id,string name,string password){
    this->id=id;
    setName(name);
    setPassword(password);
    }
    void setId(int id){
    this->id=id;
    }
    void setName(string name){
      if(Validation::Name(name)){
         this->name=name;
      }
      else{
        cout<<"Invalid"<<endl;
       }
    }
    void setPassword(string password){
      if(Validation::Password(password)){
        this->password=password;
      }
      else{
        cout<<"Invalid"<<endl;
      }
    }
    int getID(){
    return id;
    }
    string getName(){
    return name;
    }
    string getPassword(){
    return password;
    }
    virtual void DisplayInfo()=0;

};
//=======================================================================================
class Client : public Person{
private:
    double balance;
public:
    Client():Person(){}
    Client(int id,string name,string password,double balance):Person(id,name,password){
      setBalance(balance);
    }
    void setBalance(double balance){
    if(Validation::Balance(balance)){
        this->balance=balance;
      }
      else{
        cout<<"Invalid"<<endl;
      }
    }
    double getBalance(){
    return balance;
    }
    void Deposit(double amount){
    if(amount>0){
        this->balance+=amount;
      }
     }
     void Withdraw(double amount){
     if(amount<=balance&&amount>0){
        this->balance-=amount;
       }

     }
     void TransferTo(double amount,Client& recipient){
       Withdraw(amount);
        recipient.Deposit(amount);
     }
     void CheckBalance(){
          cout<<"Balance:"<<balance<<endl;
 }

     void DisplayInfo(){
      cout<<"Id:"<<id<<endl;
      cout<<"Name:"<<name<<endl;
      cout<<"Balance:"<<balance<<endl;
           }

};
//=========================================================================================
class Employee:public Person{
private:
    double salary;
public:
    Employee():Person(){}
    Employee(int id,string name,string password,double salary):Person(id,name,password){
    setSalary(salary);
    }
    void setSalary(double salary){
    if(Validation::Salary(salary)){
        this->salary=salary;
    }
    else{
        cout<<"Invalid"<<endl;
     }

    }
    double getSalary(){
    return salary;
    }
    void DisplayInfo(){
    
    }
};
//=========================================================================================
class Admin : public Employee{
public:
    Admin():Employee(){}
    Admin(int id,string name,string password,double salary):Employee(id,name,password,salary){

    }
};
int main()
{

    return 0;
}
