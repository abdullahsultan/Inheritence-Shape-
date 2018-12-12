#include<iostream>
#include<fstream>

class shape
{
protected:
  int width,height;
  int radius;
  int base;
public:
  virtual int get_area()=0;

};

class circle:public shape
{
public:
  circle(int r)
  {radius=r;}
  int get_area()
  {
    return 3.14*radius*radius;
  }
};

class recitangle:public shape
{
public:
  recitangle(int h,int w)
  {height=h;
    width=w;}
  int get_area()
  {return width*height;}
};

class triangle:public shape
{
public:
  triangle(int b,int h)
  {base=b;
  height=h;}

  int get_area()
  {
    return (base*height)/2;
  }
};

int main(int argc, char const *argv[]) {

    





  return 0;
}
