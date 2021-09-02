#include <cmath>
#include <iostream>

using namespace std;

class point2D {
   private:
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

    // Others
    void print() {
        cout << "(" << x << ", " << y << ")\n";
    }

    friend float distance(const point2D &p1, const point2D &p2);
};

float distance(const point2D &p1, const point2D &p2) {
    int cx = (p1.x - p2.x) * (p1.x - p2.x);
    int cy = (p1.y - p2.y) * (p1.y - p2.y);

    return sqrt(cx + cy);
}

int main() {
    point2D pa(2, 2);
    pa.print();

    point2D pb(5, 0);
    pb.print();

    float d = distance(pa, pb);
    cout << "Distância " << d << endl;
}
