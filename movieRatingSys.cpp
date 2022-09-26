#include "movieRatingSys.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <fstream>

movieRatingSysList::~movieRatingSysList(){
    for(movieRatingSysNode *p; !isEmpty(); ){
        p=head->next;
        delete head;
        head=p;
    }
}
void movieRatingSysList::addmrs(int year,double rating,string movien ){
    if(head!=0)
    {
        movieRatingSysNode *tmp;
        for(tmp=head;tmp->next!=0;tmp=tmp->next);
        if(head!=0){
            tmp->next=new movieRatingSysNode(year,rating,movien);
        }
    }
    else{
        head=new movieRatingSysNode(year,rating,movien,head);
    }
}
bool movieRatingSysList::removemrs(string movien){
    if(head!=0){
        if(head->next==0&&movien==head->n_movie){//tek filim var ise
            delete head;
            head=0;
            cout<<"Deleted !!!"<<endl;
        }
         else if(head->next!=0 && movien==head->n_movie){
            movieRatingSysNode *tmp=head;
            head=head->next;
            delete tmp;
            cout<<"Deleted !!!"<<endl;
        }
        else if(head->next!=0 && movien!=head->n_movie){
            movieRatingSysNode *pred,*tmp;
            for(pred=head,tmp=head->next;tmp!=0&&!(tmp->n_movie==movien);pred=pred->next,tmp=tmp->next);
            if(tmp!=0){
                pred->next=tmp->next;
                delete tmp;
                cout<<"Deleted !!!"<<endl;
            }
        }
        else{
            cout<<"There is no movie in the list."<<endl;
        }
    }
}
void movieRatingSysList::updatemrs(double rating,string movien){
    if(head!=0){
        if(head->next==0&&movien==head->n_movie){//tek filim var ise
            head->m_rating=rating;

        }
        else if(head->next!=0 && movien==head->n_movie){
            head->m_rating=rating;

        }
        else if(head->next!=0 && movien!=head->n_movie){
                movieRatingSysNode *curr=head;
             while(movien!=curr->n_movie){
                curr=curr->next;
                if(movien==curr->n_movie){
                    curr->m_rating=rating;
                }
            }
        }
        else{
            cout<<"Movie not found."<<endl;
        }
    }
}
void movieRatingSysList::printByYear(){
    if(head!=0){
         if(head->next==0){//tek filim var ise
            for(movieRatingSysNode *tmp=head; tmp!=0;tmp=tmp->next){
                cout<<tmp->m_year<<" ";
                cout<<tmp->n_movie<<" ";
                cout<<tmp->m_rating<<" ";
                cout<<endl;
            }
        }
        else if(head->next!=0){
            movieRatingSysNode *curr;
            movieRatingSysNode *tmp;
            int cont;
            int cont2;
            double cont3;
            double cont4;
            string cont5;
            string cont6;

            for(curr=head,tmp=head->next;tmp!=NULL;tmp=tmp->next){

                if(curr->m_year>=tmp->m_year){
                    cont=curr->m_year;
                    cont3=curr->m_rating;
                    cont5=curr->n_movie;

                    cont2=tmp->m_year;
                    cont4=tmp->m_rating;
                    cont6=tmp->n_movie;


                    tmp->m_year=curr->m_year;
                    curr->m_year=cont2;

                    tmp->m_rating=curr->m_rating;
                    curr->m_rating=cont4;

                    tmp->n_movie=curr->n_movie;
                    curr->n_movie=cont6;


                }
                if(tmp->next==NULL){
                    curr=curr->next;
                    tmp=curr;


                }


            }
            for(movieRatingSysNode *tm=head; tm!=0;tm=tm->next){
                        cout<<tm->m_year<<" ";
                        cout<<tm->n_movie<<" ";
                        cout<<tm->m_rating<<" ";
                        cout<<endl;
                    }
        }
    }
}
/*void movieRatingSysList::printByName(){
    if(head!=0){
            if(head->next==0){//tek filim var ise
                for(movieRatingSysNode *tmp=head; tmp!=0;tmp=tmp->next){

                    cout<<tmp->n_movie<<" ";
                    cout<<tmp->m_year<<" ";
                    cout<<tmp->m_rating<<" ";
                    cout<<endl;
                }
            }
            else if(head->next!=0){
                movieRatingSysNode *curr;
                movieRatingSysNode *tmp;
                int cont;
                int cont2;
                double cont3;
                double cont4;
                string cont5;
                string cont6;
                string cont7;


                for(curr=head,tmp=head->next;tmp!=NULL;tmp=tmp->next){
                        cont7=curr->n_movie;
                       /* cont5=curr->n_movie;
                        cont6=tmp->n_movie;

                        int n5=cont5.length();
                        int n6=cont6.length();
                        char char_5[n5+1];
                        char char_6[n6+1];

                        strcpy(char_5,cont5.c_str());
                        strcpy(char_6,cont6.c_str());

                        if(n5<=n6){
                            int m=n6;
                        }
                        else{
                            int m=n5;
                        }





                        for(int i=0;i<2;i++){
                            for(int j=0;j<n6;j++){
                                if(strcmp(char_5[j],char_6[j+1])>0){

                                        cont=curr->m_year;
                                        cont3=curr->m_rating;
                                        cont5=curr->n_movie;

                                        cont2=tmp->m_year;
                                        cont4=tmp->m_rating;
                                        cont6=tmp->n_movie;


                                        tmp->m_year=curr->m_year;
                                        curr->m_year=cont2;

                                        tmp->m_rating=curr->m_rating;
                                        curr->m_rating=cont4;

                                        tmp->n_movie=curr->n_movie;
                                        curr->n_movie=cont6;

                                        tmp=curr->next;
                                }
                                if(tmp->next==NULL){
                                    tmp=curr->next;
                                    tmp=tmp->next;
                                    curr=curr->next;
                                }


                            }

                        }



                       if(cont7>tmp->n_movie){
                            cont=curr->m_year;
                            cont3=curr->m_rating;
                            cont5=curr->n_movie;

                            cont2=tmp->m_year;
                            cont4=tmp->m_rating;
                            cont6=tmp->n_movie;


                            tmp->m_year=curr->m_year;
                            curr->m_year=cont2;

                            tmp->m_rating=curr->m_rating;
                            curr->m_rating=cont4;

                            tmp->n_movie=curr->n_movie;
                            curr->n_movie=cont6;

                            tmp=curr->next;

                        }
                        if(tmp->next==NULL){
                            tmp=curr->next;
                            tmp=tmp->next;
                            curr=curr->next;
                        }

                }
                for(movieRatingSysNode *tm=head; tm!=0;tm=tm->next){

                        cout<<tm->n_movie<<" ";
                        cout<<tm->m_year<<" ";
                        cout<<tm->m_rating<<" ";
                        cout<<" DONE !!!";
                        cout<<endl;
                }


            }




    }


}*/
void movieRatingSysList::printByRate(){
    if(head!=0){

         if(head->next==0){//tek filim var ise
            for(movieRatingSysNode *tmp=head; tmp!=0;tmp=tmp->next){
                cout<<tmp->m_year<<" ";
                cout<<tmp->n_movie<<" ";
                cout<<tmp->m_rating<<" ";
                cout<<endl;
            }
        }
        else if(head->next!=0){
            movieRatingSysNode *curr;
            movieRatingSysNode *tmp;
            int cont;
            int cont2;
            double cont3;
            double cont4;
            string cont5;
            string cont6;

            for(curr=head,tmp=head->next;tmp!=NULL;tmp=tmp->next){

                if(curr->m_rating>=tmp->m_rating){
                    cont=curr->m_year;
                    cont3=curr->m_rating;
                    cont5=curr->n_movie;

                    cont2=tmp->m_year;
                    cont4=tmp->m_rating;
                    cont6=tmp->n_movie;


                    tmp->m_year=curr->m_year;
                    curr->m_year=cont2;

                    tmp->m_rating=curr->m_rating;
                    curr->m_rating=cont4;

                    tmp->n_movie=curr->n_movie;
                    curr->n_movie=cont6;


                }
                if(tmp->next==NULL){
                    curr=curr->next;
                    tmp=curr;
                }



            }
            for(movieRatingSysNode *tm=head; tm!=0;tm=tm->next){
                        cout<<tm->m_rating<<" ";
                        cout<<tm->n_movie<<" ";
                        cout<<tm->m_year<<" ";

                        cout<<endl;
                    }
        }
    }

}

void movieRatingSysList::saveToFileByYear(){
        if(head!=0){
         if(head->next==0){//tek filim var ise
            for(movieRatingSysNode *tmp=head; tmp!=0;tmp=tmp->next){
                cout<<tmp->m_year<<" ";
                cout<<tmp->n_movie<<" ";
                cout<<tmp->m_rating<<" ";
                cout<<endl;
            }
        }
        else if(head->next!=0){
            movieRatingSysNode *curr;
            movieRatingSysNode *tmp;
            int cont;
            int cont2;
            double cont3;
            double cont4;
            string cont5;
            string cont6;

            for(curr=head,tmp=head->next;tmp!=NULL;tmp=tmp->next){

                if(curr->m_year>=tmp->m_year){
                    cont=curr->m_year;
                    cont3=curr->m_rating;
                    cont5=curr->n_movie;

                    cont2=tmp->m_year;
                    cont4=tmp->m_rating;
                    cont6=tmp->n_movie;


                    tmp->m_year=curr->m_year;
                    curr->m_year=cont2;

                    tmp->m_rating=curr->m_rating;
                    curr->m_rating=cont4;

                    tmp->n_movie=curr->n_movie;
                    curr->n_movie=cont6;


                }
                if(tmp->next==NULL){
                    curr=curr->next;
                    tmp=curr;
                }
            }
            ofstream myfile("mrsoutput.txt");
            for(movieRatingSysNode *tm=head; tm!=0;tm=tm->next){
                    myfile<<tm->m_year<<" "<<tm->n_movie<<" "<<tm->m_rating<<" "<<endl;

            }
            myfile.close();
        }
    }
}

void movieRatingSysList::saveToFileByRate(){
      if(head!=0){

         if(head->next==0){//tek filim var ise
            for(movieRatingSysNode *tmp=head; tmp!=0;tmp=tmp->next){
                cout<<tmp->m_year<<" ";
                cout<<tmp->n_movie<<" ";
                cout<<tmp->m_rating<<" ";
                cout<<endl;
            }
        }
        else if(head->next!=0){
            movieRatingSysNode *curr;
            movieRatingSysNode *tmp;
            int cont;
            int cont2;
            double cont3;
            double cont4;
            string cont5;
            string cont6;

            for(curr=head,tmp=head->next;tmp!=NULL;tmp=tmp->next){

                if(curr->m_rating>=tmp->m_rating){
                    cont=curr->m_year;
                    cont3=curr->m_rating;
                    cont5=curr->n_movie;

                    cont2=tmp->m_year;
                    cont4=tmp->m_rating;
                    cont6=tmp->n_movie;


                    tmp->m_year=curr->m_year;
                    curr->m_year=cont2;

                    tmp->m_rating=curr->m_rating;
                    curr->m_rating=cont4;

                    tmp->n_movie=curr->n_movie;
                    curr->n_movie=cont6;
                }
                if(tmp->next==NULL){
                    curr=curr->next;
                    tmp=curr;
                }
            }
            ofstream myfile("mrsoutput.txt");
            for(movieRatingSysNode *tm=head; tm!=0;tm=tm->next){
                    myfile<<tm->m_rating<<" "<<tm->n_movie<<" "<<tm->m_year<<" "<<endl;

            }
            myfile.close();
        }
    }
}
void movieRatingSysList::printAll()const{
    for(movieRatingSysNode *tmp=head; tmp!=0;tmp=tmp->next){
        cout<<tmp->n_movie<<" ";
        cout<<tmp->m_rating<<" ";
        cout<<tmp->m_year<<" ";
        cout<<endl;
    }
}
