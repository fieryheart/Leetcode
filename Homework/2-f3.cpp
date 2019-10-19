#include <iostream>
using namespace std;
class Animal {
    private:
        int _age;
    public:
        Animal(int age) {
            _age = age;
        }
        int getAge() {
            return _age;
        }
};
class Dog: public Animal {
    string _color;
    public:
        Dog(int age, string color) : Animal(age) {
            _color = color;
        }
        void showInfor() {
            cout << "age:" << Animal::getAge() << endl;
            cout << "color:" << _color << endl;
        }
};

int main(){
	Animal ani(5);
	cout<<"age of ani:"<<ani.getAge()<<endl;
	Dog dog(5,"black");
	cout<<"infor of dog:"<<endl;
	dog.showInfor();
}
