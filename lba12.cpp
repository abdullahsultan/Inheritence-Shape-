#include<iostream>
#include<fstream>

class shape
{
protected:
  int width,height;
  int radius;
  int base;
public:
   void get_area()
   {}

};

class circle:public shape
{
public:
  circle(int r)
  {radius=r;}
};

class recitangle:public shape
{
public:
  recitangle(int h,int w)
  {height=h;
    width=w;}
};

class triangle:public shape
{
public:
  triangle(int b,int h)

  {base=b;
  height=h;}
};

int main(int argc, char const *argv[]) {

  return 0;
}
