#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>


struct VEC3D {
    double x,y,z;
};

struct TYPE_PAIR {
    int type1;
    int type2;
};

const int NUM_TYPES = 2;
int TAG = 0;
bool SET_TYPE [NUM_TYPES] = {false};
Particle* TYPE_PARAMS [NUM_TYPES];
double (*POTENTIALS[NUM_TYPES][NUM_TYPES])(int, int);
 

class ForceField{
    protected:
        struct TYPE_PAIR type_pair;
    public:
        ForceField(int t1, int t2){
            type_pair.type1 = t1;
            type_pair.type2 = t2;
        }
};

class HardHarmonic: public ForceField{
    protected:
        double k_spring;
    public:

        HardHarmonic(int t1, int t2, double k):ForceField(t1,t2){
            k_spring = k;
        }

        struct VEC3D calculate_force(Particle p1, Particle p2){
            struct VEC3D force;
            force.x = 1.0 * k_spring;
            force.y = 1.0;
            force.z = 0.0;
            std::cout<< p1.get_type() <<std::endl;
            std::cout<< p2.get_type() <<std::endl;
            return force;
        }
};


class Integrator{

    private:

        /* ForceFields matrix stores pointers to
        potential functions that operate between specific
        particle types*/

        ForceField* FORCE_FIELDS[NUM_TYPES][NUM_TYPES];

    public:
        Integrator(){
        }
        void set_ForceFields() {}

};




class Particle {

    protected:

        int tag;
        int type;
        double mass;
        VEC3D force;
        VEC3D position;

    public:

        Particle(int t, double x, double y, double z){
            std::cout << "Setting positions" <<std::endl;
            tag = TAG;
            TAG ++;
            type = t;
            set_position(x,y,z);

        }

        void set_position(double x, double y, double z){
            position.x = x;
            position.y = y;
            position.z = z;
        }

        VEC3D get_position(){
            return position;
        }

        int get_tag(){
            return tag;
        }

        int get_type(){
            return type;
        }

        virtual double get_area(){
            std::cout << "Not implemented" << std::endl;
        }

};







class Disc: public Particle {

    private:

        double r_out;
        double r_core;
        
    public:

        Disc(int type, double x = 0.0, double y = 0.0, double z = 0.0, double ro = 1.0, double rc = 1.0):Particle(type, x, y, z){
            r_out = ro;
            r_core = rc;
            if (SET_TYPE[type] == false){
                TYPE_PARAMS[type] = this;
                }
        }

        virtual double get_area(){
            return M_PI * r_out * r_out;
        }
};









int main(){

    Disc disc{2, 2.0, 1.0, 1.0, 1.0};
    VEC3D position = disc.get_position();
    std::cout << position.x << position.y << std::endl;
    std::cout << disc.get_tag() << std::endl;


    return 0;
}