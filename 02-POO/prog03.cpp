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

    float operator-(const point2D &other) {
        int cx = (x - other.x) * (x - other.x);
        int cy = (y - other.y) * (y - other.y);

        return sqrt(cx + cy);
    }
};

int main() {
    point2D pa(2, 2);
    pa.print();

    point2D pb(5, 0);
    pb.print();

    float d = pa - pb;
    cout << "Distância " << d << endl;
}
