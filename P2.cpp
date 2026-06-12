//Library management system
//in this we can add new book, check the existing book , also we can search the book which u want
#include<iostream>
#include<fstream>//to read or open the file
using namespace std;

class lib{
    string id,name,author,select;
    fstream file;
    public:
    void add_book();
    void showBooks();
    void extract();



}obj;


int main(){
    while(true){
    cout<<"--------------------------------------"<<endl;
    cout<<"1- Show all book details"<<endl;
    cout<<"2- Select the book"<<endl;
    cout<<"3- Add new book"<<endl;
    cout<<"4- Exit "<<endl;
    cout<<"Enter your choice"<<endl;
    cout<<"--------------------------------------"<<endl;
    char choice;
    cin>>choice;
        cin.ignore(); //to remove the error of the garbage value
    switch (choice)        
    {
    case '1':
          
        obj.showBooks();
        break;
    case '2':
       
        obj.extract();
        break;
    case '3':
   
    
        obj.add_book();                
        break;
    case '4':
        return 0;
        break;    
    default:
    cout<<"Invalid Choice......"<<endl;
        break;
    }
}

    return 0;
} 

void lib :: add_book(){
    cout<<"Enter the id of the book "<<endl;
    getline(cin,id);
    cout<<"Enter the name of the Book "<<endl;
    getline(cin,name);
    cout<<"ENter the author of the book "<<endl;
    getline(cin,author);

    file.open("libData.txt", ios :: out | ios:: app);
    file<<id<<'*'<<name<<'*'<<author<<'\n';
    file.close();
    
}
void lib :: showBooks(){
    file.open("libData.txt",ios::in);
    cout<<"Book details are "<<endl;
    cout<<"Book Id "<<endl;
    cout<<"Book Name "<<endl;
    
    while(getline(file,id,'*')){
        getline(file,name,'*');
        getline(file,author,'\n');
        cout<<"\t\t"<<id<<"\t\t\t"<<name<<"\t\t"<<author<<endl;
    }
    file.close();

}
void lib :: extract(){
    showBooks();
    cout<<"Enter the id of the book "<<endl;
    getline(cin,select);
    bool found=false;
    file.open("libData.txt",ios :: in);
    while(getline(file,id,'*')){
        getline(file,name,'*');
        getline(file,author,'\n');
        if(select==id){
            found=true;
            cout<<id<<'\t\t'<<name<<'\t\t\t'<<author<<endl;
            cout<<"Book Found..."<<endl;
        break;
        }
       
    }
    if(!found){
        cout<<"No book found "<<endl;
    }
    file.close();
}