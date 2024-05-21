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
  std::cout<<std::to_string(k[0])+"\n";
  k[1] = eqn(x.back() +stepSize/2, y.back() + stepSize * (k[0]/2));
  k[2] = eqn(x.back() +stepSize/2, y.back() + stepSize * (k[1]/2));
  k[3] = eqn(x.back() +stepSize, y.back() + stepSize * k[2]);
  y.push_back(y.back() + (stepSize/6) * (k[0] + 2 * k[1] + 2 * k[2] + k[3]));
  x.push_back(x.back() + stepSize);
  std::cout<<"(" + std::to_string(x.back()) + ", " + std::to_string(y.back()) + ")\n";
  if((stepSize < 0 && x.back() <= endPoint) || (stepSize > 0 && x.back() >= endPoint )){
    return y.back();
  }else{
    return thing(x.back(), y.back(), stepSize, endPoint);
  }
}
int main() {
  std::cout<<"4TH ORDER RUNGE KUTTA SOLVER :)\n";
  std::cout<<"enter step size:\n";
  float ss;
  std::cin>> ss;
  std::cout<<"enter starting point:\n";
  std::string sp;
  std::cin>> sp;
  //std::cout<<sp.substr(0, sp.find_first_of(','));
  float xs = std::stof(sp.substr(1, sp.find_first_of(',')));
  float ys = std::stof(sp.substr(sp.find_first_of(',') + 1, sp.length() - 1));
  std::cout<<"enter end x:\n";
  float xf;
  std::cin>> xf;
  x.push_back(xs);
  y.push_back(ys);
  std::cout<<thing(xs,ys, ss, xf);
}




  
