#include <iostream>
#include <string>
#include <list>


std::list<float> x;
std::list<float> y;

float eqn(float xn, float yn){
  return xn + yn;
}

float thing(float sX, float sY, float stepSize, float endPoint){
  float k[4] = {0.0, 0.0, 0.0, 0.0};
  k[0] = eqn(x.back(), y.back());
  k[1] = eqn(x.back() +stepSize/2, y.back() + stepSize * (k[0]/2));
  k[2] = eqn(x.back() +stepSize/2, y.back() + stepSize * (k[1]/2));
  k[3] = eqn(x.back() +stepSize, y.back() + stepSize * k[2]);
  y.push_back(y.back() + (stepSize/6) * (k[0] + 2 * k[1] + 2 * k[2] + k[3]));
  x.push_back(x.back() + stepSize);
  if((stepSize < 0 && x.back() <= endPoint) || (stepSize > 0 && x.back() >= endPoint )){
    return y.back();
  }else{
    return thing(x.back(), y.back(), stepSize, endPoint);
  }
}
int main() {
  std::cout<<thing(0,0, 1, 3);
}




  
