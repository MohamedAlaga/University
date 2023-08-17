#include <stdio.h>
#include <stdlib.h>



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

class Prof : public Person{
private:

    string degree;
    double salary;

public:

    Prof(string name,int age,int id,char gender,string degree ,double salary){
        this->name =name;
        this->age =age;
        this->id =id;
        this->gender =gender;
        this->degree = degree;
        this->salary = salary;
    }

    void set_degree(string degree){
        this->degree = degree;
    }
    void set_salary (double salary){
        this->salary = salary;
    }
    string get_degree(){
        return degree;
    }
    int get_salary(){
        return salary;
    }

};
class University{

private:

    static University *unver_ptr;  //create static ptr
    University(){}                 // private conster

    vector<Prof>profs;
    vector<Student>students;
    vector<Departement>departements;
    vector<Course>course;

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

void add_prof(string name,int age,int id,char gender,string degree ,double salary){
        Prof p1(name,age,id,gender,degree,salary);
        profs.push_back(p1);
    }

    bool update_prof(int id ,double salary){
        for(int i=0;i<profs.size();i++){
            if(profs[i].get_id()==id){
                profs[i].set_salary(salary);
                return true;
            }
        }
        return false;
    }

    bool delete_prof(int id ){
        for(int i=0;i<profs.size();i++){
            if(profs[i].get_id()==id){
                profs.erase(profs.begin()+i);
                return true;
            }
        }
        return false;
    }
};
University* University :: unver_ptr=NULL;



int main()
{

}

