#include <cmath>
#include <bits/stdc++.h> 
struct data {

float a = -5 , b = 2 ;
int N = 0;
float epsel = 0.0;
float delta_N = 0.0;
float calc_delta_N = 0.0;
int k=1;
void *ptr_table_value;
int result_K = 0.0;
};

void around_struct(struct data *ptr)
{

// ptr->a = -5; ptr->b = 2;
ptr->epsel = 0.1;

};

void calculation_N(struct data *ptr)
{

ptr->N = ((2*(ptr->b-ptr->a))/ptr->epsel)-1;

};

void delta_N(struct data *ptr)
{ 

ptr->delta_N=(ptr->epsel)/2;
};
void search_epslent(struct data *ptr)
{
ptr->epsel = (2*(ptr->b-ptr->a))/(ptr->N+1);
}
void calculation_delta_N(struct data *ptr)
{
ptr->calc_delta_N = (ptr->b-ptr->a)/(ptr->N+1); 
}

void calculation_func_x(struct data *ptr)
{ 
float table_value[ptr->N+1];
float func_x[ptr->N+1];
for (size_t k = 1; k < ptr->N+1; k++)
{
table_value[k]=ptr->a+(k*((ptr->b-ptr->a)/(ptr->N+1)));

}
// for (size_t k = 1; k < ptr->N+1; k++)
// {
// std::cout<<"X от k "<<table_value[k]<<std::endl;
// }
// float result = 0.0;
// float result_fx=0.0;
std::cout<<std::fixed<<"| X от k= "<<std::fixed<<"| funx= "<<std::endl;
for (size_t k = 1; k < ptr->N+1; k++)
{

func_x[k] = (-0.5*cos(0.5*table_value[k])-0.5);


std::cout<<table_value[k]<<" | "<<func_x[k]<<"|"<<std::endl;

}

float X_min=0.0;
float Y_min=0.0;

for (size_t k = 1; k < ptr->N+1; k++){
    if (table_value[k] == 0.0)
    {
        X_min=table_value[k];
        Y_min=func_x[k];
    // std::cout<<"\n F(x)="<<std::endl;
    }

}
std::cout<<"\n X_min = "<<X_min<<" ± "<<X_min+-ptr->delta_N<<std::endl;
std::cout<<std::fixed<<"Y_min = "<<Y_min<<std::endl;
}
