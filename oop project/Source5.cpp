//#include<iostream>
//using namespace std;
//
//class a {
//protected:
//    int x;
//    int y;  // Declare y in class a
//
//public:
//    void display() {
//        cout << x << endl << y << endl;
//    }
//};
//
//class b : public a {
//public:  // You can access y in class b, and it will be accessible in class a too
//    void display1() {
//        cout << x << endl << y << endl;
//    }
//};
//
//int main() {
//    b objB;
//    objB.display1();  // This will display x and y from class b
//
//    // Accessing y from class a through the display function
//    objB.display();
//
//    return 0;
//}
