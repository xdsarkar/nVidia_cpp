#include<iostream> /* cout */
#include<math.h> /* sqrt(), pow() */
#include<assert.h> /* assert() */

using namespace std;

typedef float f;

/* Vector 3D Class */
class vector3D
{
    public: /* public members */

    f x,y,z;

    vector3D() {x=y=z=0;} /* initialize using a constructor */
    vector3D(f _2Dx, f _2Dy) {x = _2Dx; y = _2Dy; z = 0;} /* For 2D, 2 parameter, assuming component z = 0, there assuming it 2D vector, and equates them to x, y, 0 using constructor */
    vector3D(f _3Dx,f _3Dy,f _3Dz) {x = _3Dx; y = _3Dy; z = _3Dz;} /* For 3D, accepts, 3 parameters, _x, _y, _z, and equates them to x, y, z using constructor */
    
    vector3D(const vector3D &vector); /* intialize using copy constructor */
    
    vector3D operator+(const vector3D &vector);
    vector3D &operator+=(const vector3D &vector);

    vector3D operator-(const vector3D &vector);
    vector3D &operator-=(const vector3D &vector);

    vector3D operator*(f value);
    vector3D &operator*=(f value);

    vector3D operator/(f value);
    vector3D &operator/=(f value);

    vector3D &operator=(const vector3D &vector);

    vector3D cross_product(const vector3D &vector);

    f square();
    f dot_product(const vector3D &vector);
    f magnitude();
    f distance(const vector3D &vector);

    /* Display individual components */
    f disp_x();
    f disp_y();
    f disp_z();

    /* Display all components */
    void displayXYZ();
};

vector3D::vector3D(const vector3D &vector)
{
    x = vector.x;
    y = vector.y;
    z = vector.z;
}

/* Addition of vectors */
vector3D vector3D ::operator+(const vector3D &vector)
{
    return vector3D(x + vector.x, y + vector.y, z + vector.z);
}

/* Addition of vector */
vector3D &vector3D ::operator+=(const vector3D &vector)
{
    return *this += vector;
}

/* Subtraction of vector */
vector3D vector3D ::operator-(const vector3D &vector)
{
    return vector3D(x - vector.x, y - vector.y, z - vector.z);
}

/* Subtraction of vector */
vector3D &vector3D::operator-=(const vector3D &vector)
{
    return *this -= vector;
}

/* Multiplication of vector */
vector3D vector3D ::operator*(f value)
{
    return vector3D(x*value, y*value, z*value);
}

/* Multiplication of vector */
vector3D &vector3D::operator*=(f value)
{
    return *this *= value;
}

/* Division of vector */
vector3D vector3D ::operator/(f value)
{
    assert(value != 0);
    return vector3D(x/value, y/value, z/value);
}

/* Division of vector */
vector3D &vector3D ::operator/=(f value)
{
    assert(value != 0);
    return *this /= value;
}

/* Assignment operator */
vector3D &vector3D::operator=(const vector3D &vector) /* assignment operator */
{
    x = vector.x;
    y = vector.y;
    z = vector.z;
    return *this;
}

/* Dot product of vector */
f vector3D::dot_product(const vector3D &vector)
{
    return x*vector.x + vector.y*y + vector.z*z;
}

/* Cross product of vector */
vector3D vector3D ::cross_product(const vector3D &vector)
{
    f cross_i = y*vector.z - z*vector.y;
    f cross_j = z*vector.x - x*vector.z;
    f cross_k = x*vector.y - y*vector.x;
    return vector3D(cross_i, cross_j, cross_k);
}

/* Magnitude of vector */
f vector3D::magnitude()
{
    return sqrt(square());
}

/* Square of vector */
f vector3D::square()
{
    return pow(x,2) + pow(y,2) + pow(z,2);
}

/* Distance of vector */
f vector3D::distance(const vector3D &vector)
{
    vector3D dist = *this - vector;
    return dist.magnitude();
}

void vector3D::displayXYZ()
{
    cout<<x<<" "<<y<<" "<<z<<endl;
}

f vector3D::disp_x() {return x;}
f vector3D::disp_y() {return y;}
f vector3D::disp_z() {return z;}

int main()
{
    vector3D i=vector3D(5,5,7);
    vector3D j=vector3D(6,3,2);

    vector3D k=i+j; k.displayXYZ();
    vector3D l=i-j; l.displayXYZ();
}