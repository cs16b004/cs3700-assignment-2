#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<stdio.h>
#include<iterator>
#include<string.h>
#include<stdio.h>
using namespace std;
 struct cartuple{
  string name;
  string price;
};
struct stutuple{
  string rollno;
  string name;
};
void car_print(vector<cartuple*>st){
  cout<<"NAME    PRICE"<<endl;
  for(auto it: st)
    cout<<it->name<<"  "<<it->price<<endl;
}
void stu_print(vector<stutuple*>st){
  cout<<"ROLLNO    NAME"<<endl;
  for(auto it: st)
    cout<<it->rollno<<"  "<<it->name<<endl;
}
bool checktab(string s){
  if (s == "car" || s =="student")
    return true;
  else return false;
}
bool checkcol(string s){
  if (s == "name" || s == "price" || s == "rollno" || s == "*")
    return true;
  else return false;
}
void Tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{

    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}
vector<cartuple*>car;
vector<stutuple*>student;
int fun(string s){
  if(s[s.length()-1] != ';'){
    cout<<"Expected ; In The End\n";
    return 0;
  }
  vector<string> tokens;
  Tokenize(s, tokens);
  vector<string>::iterator it;
  it = tokens.begin();

  if(*it == "select"){
  it =it+1;
  if(it == tokens.end()){
        cout<<"SyNtax Error"<<endl;
        return 0;
      }
    if(!checkcol(*it)){
      cout<<"Coloumn Doesn't Exist"<<endl;
      return 0;
    }
    else{
      if(*it == "*"){
        it = it+1;
        if(it == tokens.end()){
          cout<<"syntax error"<<endl; return 0;
        }
        if(*it != "from"){
          cout<<"Syntax Error\n";
          return 0;
        }
        else {
          it = it + 1;
            if(it == tokens.end()) return 0;
          if(!checktab(*it)){
            cout<<"Table Doesn't Exist"<<endl;
          }
          else{
            if (*it == "car"){
              car_print(car);
              string s ;
              getline(cin,s);

              while(s.length()==0){
                getline(cin,s);
              }
              fun(s);
            }
            if(*it == "student"){
              stu_print(student);
              string s ;
              getline(cin,s);

              while(s.length()==0){
                getline(cin,s);
              }
              fun(s);
            }
          }

        }
      }
    }
  }
  if(it + 1 == tokens.end()) return 0;
  else if (*it  == "insert" && *(it+1) == "into"){
    it = it +2;
    if (it == tokens.end()) return 0;
    if(!checktab(*it)){
      cout<<"Trying to Insert Into Non existent Table"<<endl;
      return 0;
    }
    else {
      if(*it == "car"){
        it = it+1;
        if(it == tokens.end()){
              cout<<"SyNtax Error"<<endl;
              return 0;
            }
        if(*it == "values"){
          if(it+2 == tokens.end()){
            return 0;
          }
          it = it+1;
          cartuple* temp = new cartuple;
          temp->name = *it;
          it = it+1;
          temp->price = *it;
          car.push_back(temp);
        }
        cout<<"Query Ok"<<"  Rows Affected None"<<endl;
        string s ;
        getline(cin,s);

        while(s.length()==0){
          getline(cin,s);
        }
        fun(s);
        /*car_print(car);*/
      }
      if(*it == "student"){
        it = it+1;
        if(it == tokens.end()){
              cout<<"SyNtax Error"<<endl;
              return 0;
            }
        if(*it == "values"){
          if(it+2 == tokens.end()){
            return 0;
          }
          it = it+1;
          stutuple* temp = new stutuple;
          temp->rollno = *it;
          it = it+1;
          temp->name = *it;
          student.push_back(temp);
        }
        cout<<"Query Ok"<<"  Rows Affected None"<<endl;
        string s ;
        getline(cin,s);

        while(s.length()==0){
          getline(cin,s);
        }
        fun(s);
        /*stu_print(student);*/
      }
    }
  }

return 0;
}
int main(){

  stutuple* temp = new stutuple;
  temp->name = "Jaquen H'ghar";
  temp->rollno = "cs16b0034";
  cartuple* temp2 = new cartuple;
  temp2->name = "verna";
  temp2->price = "1000000";
  for(int i=0;i<10;i++)
    student.push_back(temp);
  for(int i=0;i<10;i++)
    car.push_back(temp2);
  string s ;
  getline(cin,s);

  while(s.length()==0){
    getline(cin,s);
  }
  fun(s);

  return 0;
}
