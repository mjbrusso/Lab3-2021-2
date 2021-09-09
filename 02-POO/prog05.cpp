#include <cmath>
#include <iostream>

using namespace std;

class point2D {
   protected:
    int x, y;

   public:
    // Construtores
    point2D(int px, int py) : x{px}, y{py} {
    }

    point2D() : point2D(0, 0) {
    }

    // setters
    void setX(int px) {
        x = px;
    }

    void setY(int py) {
        y = py;
    }

    // getters
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    friend float operator-(const point2D &lhs, const point2D &rhs);
    friend ostream &operator<<(ostream &os, const point2D &p);
};

float operator-(const point2D &lhs, const point2D &rhs) {
    int cx = (lhs.x - rhs.x) * (lhs.x - rhs.x);
    int cy = (lhs.y - rhs.y) * (lhs.y - rhs.y);

    return sqrt(cx + cy);
}

ostream &operator<<(ostream &os, const point2D &p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

class point3D : public point2D {
   private:
    int z;

   public:
    point3D(int px, int py, int pz) : point2D(px, py), z{pz} {
        cout << this << endl;
    }

    void foo(){
        cout << "Foo " << x << endl;
    }

    point3D() : point3D(0, 0, 0) {
    }

    void setZ(int pz) {
        z = pz;
    }

    // getters
    int getZ() {
        return z;
    }
    bool operator==(const point3D &rhs) {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    bool operator!=(const point3D &rhs) {
        return !(*this==rhs);
    }

    friend ostream &operator<<(ostream &os, const point3D &p);
};

ostream &operator<<(ostream &os, const point3D &p) {
    return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}

// TODO: operator- 3D

int main() {
    point3D p3(22, 33, 44), pb(55, 22, 0);
    
    p3.foo();
    pb.foo();

    if (p3 != pb)
        cout << p3 << " e " << pb
             << " são iguais" << endl;
    else
        cout << p3 << " e " << pb
             << " são diferentes" << endl;
}
