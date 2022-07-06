#include <iostream>

using namespace std;

class Camera {
  public:
    int x;

    Camera() :x(0) {}
    Camera(int d){
      cout << "constructor Camera(int d) is invoked" << endl;
      x = d;
    }
};

class Cellphone {
  int d;
  Camera objCamera;

  public:
  Cellphone(int d) 
    : objCamera(d), d(d) {}
  void show() {
    cout << "data of Cellphone object " << d << endl;
    cout << "data of Cellphone'Camera " << objCamera.x << endl;
  }
};

int main() {
  Cellphone objb(25);

  objb.show();
  return 0;
}
