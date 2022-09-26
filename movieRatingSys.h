#ifndef MOVIERATINGSYS_H_INCLUDED
#define MOVIERATINGSYS_H_INCLUDED

#include <iostream>


using namespace std;
class movieRatingSysNode{
public:
    movieRatingSysNode(){
        next=0;
    }
    movieRatingSysNode(int year,double rating,string movien,movieRatingSysNode*ptr=0){
        m_rating=rating;
        n_movie=movien;
        m_year=year;
        next=ptr;
    }

    int m_year;
    double m_rating;
    string n_movie;
    movieRatingSysNode *next;



};
class movieRatingSysList{
public:
    movieRatingSysList(){
        head=0;
    }
    ~movieRatingSysList();
    int isEmpty(){
        return head==0;
    }
    void addmrs(int,double,string);
    bool removemrs(string);
    void updatemrs(double,string);
    void printByYear();
    void printByName();
    void printByRate();
   // void loadFile(string);
    void saveToFileByYear();
   // void saveToFileByName(string);
    void saveToFileByRate();

    void printAll() const;

private:
    movieRatingSysNode *head;

};


#endif // MOVIERATINGSYS_H_INCLUDED
