#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Departement{

private:
    string name;
    int capacity;
    float required_gpa;

public:
    Departement(string name, int capacity,float required_gpa){
        this->name = name;
        this->capacity = capacity;
        this->required_gpa = required_gpa;
    }
    void set_name(string name){
        this->name = name;
    }
    void set_capacity (int capacity){
        this->capacity = capacity;
    }
    void set_required_gpa (float required_gpa){
        this->required_gpa = required_gpa;
    }
    string get_name(){
        return name;
    }
    int get_capacity(){
        return capacity;
    }
    float get_required_gpa(){
        return required_gpa;
    }

};

class Person{

protected:
    string name;
    int age;
    int id;
    char gender;

public:

    void set_name(string name){
        this->name =name;
    }
    void set_age(int age){
        this->age =age;
    }
    void set_id (int id){
        this->id =id;
    }
    void set_gender (char gender){
        if(gender=='F'|| gender=='M'){
            this->gender =gender;
        }
    }
    string get_name(){
        return name;
    }
    int get_age(){
        return age;
    }
    int get_id (){
        return id;
    }
    char get_gender (){
        return gender;
    }
};

class Student : public Person{

private:
    int level;
    float gpa;

public:

    Student(string name,int age,int id,char gender,int level ,float gpa){
        this->name =name;
        this->age =age;
        this->id =id;
        this->gender =gender;
        this->level = level;
        this->gpa = gpa;
    }

    void set_level (int level){
        this->level = level;
    }
    void set_gpa (float gpa){
        this->gpa = gpa;
    }
    int get_level(){
        return level;
    }
    float get_gpa(){
        return gpa;
    }
};



class University{

private:

    static University *unver_ptr;  //create static ptr
    University(){}                 // private cons

    //vector<Prof>profs;
    vector<Student>students;
    vector<Departement>departements;
    //vector<Course>course;

public:

    University(const University& obj) = delete;       // delete copy

    static University *get_unver(){
        if(unver_ptr==NULL){
            unver_ptr = new University();
            return unver_ptr;
        }
        else{
            return unver_ptr;
        }
    }

////student functions

    void add_student(string name,int age,int id,char gender,int level ,float gpa){
        Student s1(name,age,id,gender,level,gpa);
        students.push_back(s1);
    }

    bool update_student(int id ,float gpa){
        for(int i=0;i<students.size();i++){
            if(students[i].get_id()==id){
                students[i].set_gpa(gpa);
                return true;
            }
        }
        return false;
    }

    bool delete_student(int id ){
        for(int i=0;i<students.size();i++){
            if(students[i].get_id()==id){
                students.erase(students.begin()+i);
                return true;
            }
        }
        return false;
    }


////departement functions

    void add_departement(string name, int capacity,float required_gpa){
        Departement d1( name, capacity ,required_gpa);
        departements.push_back(d1);

    }

    bool update_departement(string name ,float required_gpa){
        for(int i=0;i<departements.size();i++){
            if(departements[i].get_name()==name){
                departements[i].set_required_gpa(required_gpa);
                return true;
            }
        }
        return false;
    }

    bool delete_departement(string name ){
        for(int i=0;i<departements.size();i++){
            if(departements[i].get_name()==name){
                departements.erase(departements.begin()+i);
                return true;
            }
        }
        return false;
    }
    void data() {
      cout<<students[0].get_id();
    }

// prof functions

//courses functions


};

University* University :: unver_ptr=NULL;



int main()
{
    cout << "Hello world!" << endl;
    University* u1= University ::get_unver();

    u1->add_student("Nafisa",10,1,'F',1,3.2);
    u1->data();

    return 0;
}
