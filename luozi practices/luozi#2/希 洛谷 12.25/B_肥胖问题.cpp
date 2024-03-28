#include<iostream>
int main(){
    double m,h;
    scanf("%lf%lf",&m,&h);
    double BMI=m/(h*h);
    if(BMI<18.5)
        std::cout<<"Underweight";             //printf("Underweight");
    else if(BMI>=18.5&&BMI<24)  //* 18.5<=BMI && BMI<24  
	    std::cout<<"Normal";                  //printf("Normal");
    else
        std::cout<<BMI;
	
    
    std::cout<<"\n";
	std::cout<<"Overweight";             // printf("%.4f\n Overweight",BMI);
    return 0;

//! luozi
    if(1){

    }else if(1){

    }else{

    }
}
