#include <iostream>
#include <string>

using namespace std;

class Fueltank{
    private:
        int m_FueltankCapacity;
        int m_Gas_grade;
    public:
        Fueltank(int FueltankCapacity=3000,int Gas=98){
            m_FueltankCapacity=FueltankCapacity;
            m_Gas_grade=Gas;
        }
        int fuel_up(int v,int gas){
            if(v>m_FueltankCapacity){
                cout<<"Error:FueltankCapacity:"<<m_FueltankCapacity<<" but fuel up:"<<v<<endl;
            }
            if(gas!=m_Gas_grade){
                cout<<"Gas_grade:"<<gas<<" Correct Gas_grade "<<m_Gas_grade<<endl;
            }
            else{
                cout<<"fuel_up "<<v<<" Gas_grade: "<<gas<<endl;
            }
            return 1;
            
        };
        int set_Gas_grade(int Gas_grade){
            m_Gas_grade=Gas_grade;
            cout<<"Set_Gas_grade: "<<Gas_grade<<endl;
            return m_Gas_grade;
        }
        int get_Gas_grade(){
            return m_Gas_grade;
        };
};

class Car{
    protected:
    string m_DriveMode;
    
    private:
    int m_MaxSeating;
    Fueltank m_Fueltank;
    int m_price;
    void m_UpdatePrice(int base=500000){
        m_price = m_MaxSeating*base;
    }
    public:
    string m_brand;
    string m_model;
    int m_year;
    
    Car(string x,string y,int z,int s){
        m_brand=x;
        m_model=y;
        m_year=z;
        m_MaxSeating=s;
        m_UpdatePrice();
    }
    int get_MaxSeating(){
        return m_MaxSeating;
    }
    int get_price(){
        return m_price;
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
    int get_Gas_grade(){
        return m_Fueltank.get_Gas_grade();
    }
    int set_Gas_grade(int gas=98){
        return m_Fueltank.set_Gas_grade(gas);
    }
    int fuel_up(int v,int gas=98){
        return m_Fueltank.fuel_up(v,gas);
    }
};

class BMW_Car:public Car{
    public:
    BMW_Car(string y,int z,int s):Car("BMW",y,z,s){
        cout<<"Constructing BMW_Car\n";
        m_DriveMode="Rear-wheel";
    }
    
};

class Audi_Car:public Car{
    public:
    Audi_Car(string y,int z,int s):Car("Audi",y,z,s){
        cout<<"Constructing Audi_Car\n";
        m_DriveMode="Front-wheel";
    }
    
};


class BENZ_Car:public Car{
    public:
    BENZ_Car(string y,int z,int s):Car("BENZ",y,z,s){
        cout<<"Constructing BENZ_Car\n";
        m_DriveMode="Front-wheel";
    }
    
};

int main()
{
    
    
    Audi_Car car_2("A1",2023,5);
    car_2.set_Gas_grade(95);
    cout<<car_2.m_brand<<" : Gas_grade= "<<car_2.get_Gas_grade()<<endl;
    car_2.fuel_up(3000,95);
    
    
}