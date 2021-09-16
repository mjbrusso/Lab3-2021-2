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

int main() {
    point2D pa(2, 2);
    point2D pb(5, 0);

    float d = pa - pb;
    cout << "A distância entre " << pa
         << " e " << pb
         << " é " << d << endl;

}
