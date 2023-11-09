#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CanBo{
protected:
    string name;
    int age;
    string gender;
    string address;
public:
    CanBo(){
        cout<< "\nEnter name: ";
        cin>> name;
        cout << "Enter age: ";
        cin>> age;
        cout << "Enter gender (Male/Fale/Diverse): ";
        cin >> gender;
        cout << "Enter address: ";
        cin.ignore();
        getline(cin, address);
    }

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl; 
    }

    string getName() const {
        return name;
    }
};

//Derived class CongNhan
class CongNhan : public CanBo {
public: 
    CongNhan() : CanBo(){
        cout << "Enter level: ";
        cin >> level;
    }

    //use const keyword: read-only access member function
    void displayInfo() const override{
        CanBo::displayInfo();
        cout << "Level: " << level << endl;
    };
private: 
    int level;
};

//Derived class Kysu
class KySu : public CanBo {
public:
    KySu() : CanBo(){
        cout << "Enter major: ";
        cin >> major;
    }

    void displayInfo() const override{
        CanBo::displayInfo();
        cout << "Major: " << major << endl;
    };
private:
    string major;
};

//Derived class NhanVien
class NhanVien : public CanBo {
public:
    NhanVien() : CanBo(){
        cout<< "Enter job: ";
        cin >> job;
    }

    void displayInfo() const override{
        CanBo::displayInfo();
        cout << "Job: " << job << endl;
    };
private:
    string job;
};

//Class QLCB(Quan ly can bo)
class QLCB {
public:
    void addCanbo(CanBo* cb){
        canBoList.push_back(cb);
    }

    CanBo* findByName(const string& name){
        for(CanBo* cb : canBoList){
            if(cb -> getName() == name){
                return cb;
            }
        }
        return nullptr;
    }
    
    void displayAll(){
        for(CanBo* cb: canBoList){
            cb -> displayInfo();
            cout << "--------------------------" << endl;
        }
    }

    vector<CanBo*> getCanBoList(){
        return canBoList;
    }

    bool isEmpty() const {
        return canBoList.empty();
    }

private:
    vector<CanBo*> canBoList;
};

int main(){
    QLCB qlcb;

    while (true){
        cout<< "Choose type of Can Bo to add: "<< endl;
        cout << "1. Cong nhan.\n";
        cout << "2. Ky su.\n";
        cout << "3. Nhan vien.\n";
        cout << "0. Exit\n";
        cout << "Enter your choice (0, 1, 2, 3): ";
        int choice;
        cin >> choice;
        if(choice == 0){
            break;
        }
        CanBo* newCB = nullptr;
        switch (choice)
        {
        case 1:
            newCB = new CongNhan();
            break;
        case 2:
            newCB = new KySu();
            break;
        case 3:
            newCB = new NhanVien();
            break;
        default:
            cout << "\nInvalid choice. Enter your choice again (0, 1, 2, 3): ";
            continue;
        }

        qlcb.addCanbo(newCB);
    }
    if(!qlcb.isEmpty()){
        cout << "Displaying all CanBo information:\n " << endl;
        qlcb.displayAll();

        string searchName;
        cout << "Enter name you want to search: ";
        cin.ignore();
        getline(cin, searchName);

        CanBo* resultFindCB =  qlcb.findByName(searchName);
        if(resultFindCB != nullptr){
            cout << "Found CanBo " << searchName << ":"<< endl;
            resultFindCB->displayInfo();
        }
        else {
            cout << "CanBo " << searchName << ": Not Found"<< endl;
        }
    }

    //Clean up dynamic memory 
    for(CanBo* cb : qlcb.getCanBoList()){
        delete cb;
    }

    return 0;
}