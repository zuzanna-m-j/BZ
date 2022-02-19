#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Particle {
    
    public:
        virtual double get_area(){
            std::cout << "Not implemented" << std::endl;
        }
};

class Disk: public Particle {
    private:
        double radius;
    public:

        Disk(double r = 1.0){
            radius = r;
        }

        virtual double get_area(){
            return M_PI * radius * radius;
        }
};


// #include <cassert>

// class Something
// {
// public:
// 	// Default constructor
// 	Something(int n = 0, double d = 1.2) // allows us to construct a Something(int, double), Something(int), or Something()
// 	{
// 	}

// 	Something(double d)
// 	{
// 	}
// };

// int main()
// {
// 	Something s1 { 1, 2.4 }; // calls Something(int, double)
// 	Something s2 { 1 }; // calls Something(int, double)
// 	Something s3 {}; // calls Something(int, double)

// 	Something s4 { 2.4 }; // calls Something(double)

// 	return 0;
// }

int main(){

    Disk disk{2.0};
    std::cout << disk.get_area() << std::endl;
    Particle particle;
    std::cout << particle.get_area() << std::endl;

    return 0;
}