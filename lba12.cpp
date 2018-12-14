#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
#include<sstream>
#include <bits/stdc++.h>
using namespace std;
void streamer(string line);
void save_to_file_cir(float,float,float);
void save(char,float,float,float,float);

class shape
{
protected:
  float width,height;
  float radius;
  float base;
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
      c.get_area();
      c.get_perimeter();
      save_to_file_cir(stof(sub),c.get_area(),c.get_perimeter());
    }
  break;

  case 't':
    {
      string height,base;
      pos=sub.find(",");
      base=sub.substr(pos+1);
      height=sub.substr(pos-3);
      triangle t(stof(height),stof(base));
      save(line.front(),stof(height),stof(base),t.get_area(),t.get_perimeter());
    }
    break;
  case 'r':
  {
    string height,width;
    pos=sub.find(",");
    width=sub.substr(pos+1);
    height=sub.substr(pos-3);
    rectangle r(stof(height),stof(width));
    save(line.front(),stof(height),stof(width),r.get_area(),r.get_perimeter());
  }
}
}

void save_to_file_cir(float radius,float area,float perimeter)
{
  ofstream out("output.txt",ios::app);
  out<<"Circle "<<radius<<" "<<area<<" "<<perimeter<<endl;

}
void save(char type,float width,float height,float area,float perimeter)
{
  ofstream out("output.txt",ios::app);
  switch (type) {
    case 't':
    out<<"Triangle "<<width<<" "<<height<<" "<<area<<" "<<perimeter<<endl;
    case 'r':
    out<<"Rectangle "<<width<<" "<<height<<" "<<area<<" "<<perimeter<<endl;
  }

}
