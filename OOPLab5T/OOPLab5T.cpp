#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//  1.15

class Triangle {
public:
    double a;
    double b;
    double c;

    Triangle(double sideA, double sideB, double sideC) {
        a = sideA;
        b = sideB;
        c = sideC;
    }

    void changeSides(double sideA, double sideB, double sideC) {
        a = sideA;
        b = sideB;
        c = sideC;
    }

    double getPerimeter() {
        return a + b + c;
    }

    void printAngles() {
        double pi = 3.14159265;
        double alpha = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / pi;
        double beta = acos((a * a + c * c - b * b) / (2 * a * c)) * 180.0 / pi;
        double gamma = 180.0 - alpha - beta;

        cout << "Angles: " << alpha << ", " << beta << ", " << gamma << endl;
    }
};

class Equilateral : public Triangle {
public:
    double area;

    Equilateral(double side) : Triangle(side, side, side) {
        area = 0;
    }

    void calculateArea() {
        area = (a * a * sqrt(3.0)) / 4.0;
    }
};

void runTask1() {
    cout << "--- Task 1.15 ---" << endl;
    Triangle t(3, 4, 5);
    cout << "Triangle perimeter: " << t.getPerimeter() << endl;
    t.printAngles();

    Equilateral eq(6);
    eq.calculateArea();
    cout << "Equilateral perimeter: " << eq.getPerimeter() << endl;
    cout << "Equilateral area: " << eq.area << endl;
    cout << "-----------------" << endl << endl;
}

//  2.13

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == NULL) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = NULL;

        while (current != NULL) {
            parent = current;
            if (val < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (val < parent->data) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
    }

    void bfs() {
        if (root == NULL) return;

        Node* queue[100];
        int front = 0;
        int rear = 0;

        queue[rear] = root;
        rear++;

        cout << "BFS traversal: ";
        while (front < rear) {
            Node* current = queue[front];
            front++;

            cout << current->data << " ";

            if (current->left != NULL) {
                queue[rear] = current->left;
                rear++;
            }
            if (current->right != NULL) {
                queue[rear] = current->right;
                rear++;
            }
        }
        cout << endl;
    }
};

void runTask2() {
    cout << "--- Task 2.13 ---" << endl;
    BinaryTree tree;
    tree.insert(40);
    tree.insert(20);
    tree.insert(60);
    tree.insert(10);
    tree.insert(30);

    tree.bfs();
    cout << "-----------------" << endl << endl;
}

// ЗАДАЧА 3.13

class Point {
public:
    double x;
    double y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }

    Point(const Point& other) {
        x = other.x;
        y = other.y;
    }

    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "X: " << p.x << ", Y: " << p.y;
        return os;
    }

    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

class ColorPoint : public Point {
public:
    string color;

    ColorPoint() : Point() {
        color = "white";
    }

    ColorPoint(double xVal, double yVal, string col) : Point(xVal, yVal) {
        color = col;
    }

    ColorPoint(const ColorPoint& other) : Point(other) {
        color = other.color;
    }

    ColorPoint& operator=(const ColorPoint& other) {
        if (this != &other) {
            Point::operator=(other);
            color = other.color;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const ColorPoint& cp) {
        os << (Point)cp << ", Color: " << cp.color;
        return os;
    }

    friend istream& operator>>(istream& is, ColorPoint& cp) {
        is >> cp.x >> cp.y >> cp.color;
        return is;
    }
};

void runTask3() {
    cout << "--- Task 3.13 ---" << endl;
    ColorPoint p1(1.1, 2.2, "red");
    cout << "p1 -> " << p1 << endl;

    ColorPoint p2 = p1;
    cout << "p2 -> " << p2 << endl;

    ColorPoint p3;
    p3 = p1;
    cout << "p3 -> " << p3 << endl;

    ColorPoint p4;
    cout << "Enter X, Y and color: ";
    cin >> p4;
    cout << "p4 -> " << p4 << endl;
    cout << "-----------------" << endl << endl;
}

int main() {
    runTask1();
    runTask2();
    runTask3();
    return 0;
}
