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

int main()
{

    return 0;
}
