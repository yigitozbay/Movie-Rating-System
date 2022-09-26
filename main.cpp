#include <iostream>
#include "movieRatingSys.h"
#include <fstream>
#include <string>


using namespace std;

int main(void){

    int i=0;
    int x;//movie year
    double y;//movie rating
    string file;
    string filem;
    string z;//Movie name
    string a;
    movieRatingSysList list;

    do{
        cout<<"*****"<<"Welcome to Movie Rating Website"<<"*****"<<endl;
        cout<<"1.Add movie"<<endl;
        cout<<"2.Remove movie"<<endl;
        cout<<"3.Update rating "<<endl;
        cout<<"4.Print by year"<<endl;
        cout<<"5.Print by name(is not working)"<<endl;
        cout<<"6.Print by rating"<<endl;
        cout<<"7.Save to File by Year"<<endl;
        cout<<"8.Save to File by Rating"<<endl;
        cout<<"9.Load File (is not working)"<<endl;
        cout<<"10.Save to File by Name (is not working)"<<endl;
        cout<<"11.Print all"<<endl;
        cout<<"0.Quit"<<endl;
        cin>>i;
        if(i==1){

            cout<<"Name:"<<endl;
            cin.ignore();
            getline(cin,z);
            cout<<"Rating:"<<endl;
            cin>>y;
            cout<<"Year:"<<endl;
            cin>>x;
            list.addmrs(x,y,z);

        }
        if(i==2){
            cout<<"Remove movie:"<<endl;
            cin.ignore();
            getline(cin,a);
            list.removemrs(a);
        }
        if(i==3){
            cout<<"Name of Movie"<<endl;
            cin.ignore();
            getline(cin,a);
            cout<<"New rating"<<endl;
            cin>>y;
            list.updatemrs(y,a);
        }
        if(i==4){
            cout<<"Printting by Year..."<<endl;
            list.printByYear();
        }
        if(i==5){
            cout<<"Printting by Name...(is not working)"<<endl;
        }
        if(i==6){
            cout<<"Printting by Rating..."<<endl;

            list.printByRate();
        }
        if(i==7){
            list.saveToFileByYear();
            cout<<"Check mrsoutput.txt file"<<endl;
        }
        if(i==8){
            list.saveToFileByRate();
            cout<<"Check mrsoutput.txt file"<<endl;

        }
        if(i==11){
             list.printAll();
        }

    }while((i!=0));
}
