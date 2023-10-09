#include <iostream>
#include <vector>
#include "func_x.h"
#include <cmath>
#include "dehotomy.h"
using namespace std;

int change_method()
{
    std::setlocale(LC_ALL, "Russian");
    int role = 0;
    std::cout<<"Выберите метод оптимизации: \n [1] - Метод оптимального пассивного поиска [2] - Метод дихитомии"<<std::endl;
    std::cin>>role;

  return role;
}

int main() 
    
    {
        std::setlocale(LC_ALL, "Russian");
        int role = change_method();
        switch (role)
        {
        case 1:{
        struct data data;

        struct data *p_data = &data;
        std::cout<<"Задайте интервал от [a,b]"<<std::endl;
        around_struct(p_data);
        
        calculation_N(p_data);

        delta_N(p_data);

        std::cout<<"Это А "<<data.a<<std::endl;

        std::cout<<"Это Б "<<data.b<<std::endl; 

        std::cout<<"Это Eps "<<data.epsel<<std::endl;

        std::cout<<"Это N "<<data.N<<std::endl;

        std::cout<<"Это Дельта "<<data.delta_N<<std::endl;
        calculation_delta_N(p_data);
        // search_epslent(p_data);
        // std::cout<<"Это Расчётный Epselent "<<data.epsel<<std::endl;
        std::cout<<"Это Расчётная дельта "<<data.calc_delta_N<<std::endl;
        calculation_func_x(p_data);}
            break;
        case 2:
        {
        struct deh_data deh;
        
        struct deh_data *p_data = &deh;
    
        x1_x2(p_data);
        }
        default:1 ;
            break;
        }
        
    
    
        return 0;


    }   