#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Course{
private:
string course_name ,course_code;
int course_hours;
vector<string> professors,students;
public:
Course(){course_name = "none";course_code = "000";course_hours=0;}
Course(string name,string code,int hours){
  course_name = name;course_code = code;course_hours=hours;
}
void set_course_name (string name){course_name = name;}
void set_course_code (string code){course_code = code;}
void set_course_hours (int hours){course_hours = hours;}
void add_course_professor (string name){professors.push_back(name);}
void add_course_student (string name){students.push_back(name);}
string get_course_name(){return course_name;}
string get_course_code(){return course_code;}
int get_course_hours(){return course_hours;}
vector<string> get_course_professor(){return professors ;}
vector<string> get_course_students(){return students ;}
};


class universty{
  private:
  static universty* instancePtr ;
vector<Course> courses;
universty(){};
public: universty(universty& obj) = delete;
void addcourse(string name, string code , int hours){
Course co (name,code,hours);
courses.push_back(co);}

bool updatecourse(string code,int hours){
  for(int i = 0 ; i < courses.size();i++){if(!(code.compare(courses[i].get_course_code()))){
    courses[i].set_course_hours(hours);
    return 1;
  }}
  return 0;
}

bool delete_course(string code)
{for(int i = 0 ; i < courses.size();i++){
  if(!(code.compare(courses[i].get_course_code()))){courses.erase(courses.begin()+i);return 1;}}
return 0;
}

static universty* getinstance ()
{

  if(instancePtr == NULL)
  {
    instancePtr = new universty ;
  }
  return instancePtr;
}
};

universty *universty ::instancePtr = NULL;
int main() {

universty *mansoura = universty::getinstance();
  mansoura->addcourse("se", "101", 3);
  cout<<mansoura->delete_course("101");
  mansoura->addcourse("se", "101", 3);
  cout<<mansoura->updatecourse("101", 4);




}
