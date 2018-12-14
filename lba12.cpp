#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
#include<sstream>
#include <bits/stdc++.h>
using namespace std;
void streamer(string line);

class shape
{
protected:
  int width,height;
  int radius;
  int base;
public:
  virtual int get_area()=0;
  virtual int get_perimeter()=0;

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
public:
  int get_perimeter()
  {
    return 2*3.14*radius;
  }
};

class rectangle:public shape
{
public:
  rectangle(int h,int w)
  {height=h;
    width=w;}
  int get_area()
  {
    return width*height;
  }
  int get_perimeter()
  {
    return 2*(width+height);
  }
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
  int get_perimeter()
  {
    return base+height+sqrt((base*base)+(height*height));
  }
};

int main(int argc, char const *argv[]) {

  ifstream in; ofstream out;
  in.open("data.txt");

  string line;

  while(!in.eof())
  {
   (getline(in,line));
//   cout<<line<<endl;
   streamer(line);
  }


  return 0;
}

void streamer(string line)
{


 int pos=line.find(",");
 string sub=line.substr(pos+1);
 cout<<"Sub="<<sub<<endl;
 //cout<<"1st = "<<line.front()<<endl;

switch (line.front()) {
  case 'c':
    {
      circle c(stof(sub));
      cout<<"Area = "<<c.get_area()<<endl;
      cout<<"Perimeter"<<c.get_perimeter()<<endl;
    }
  break;

  case 't':
    {
      
    }
//  case 'r':
}

}
