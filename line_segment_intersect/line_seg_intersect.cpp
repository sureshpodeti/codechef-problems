#include<iostream>
using namespace std;

struct Point{
  int x;
  int y;
};

bool OnSegment(struct Point p, struct Point q, struct Point r){

  if(q.x>=min(p.x, r.x) && q.x<=max(p.x, r.x) && q.y>=min(p.y, r.y) && q.y<=max(p.y, r.y)){
    return true;
  }
  return false;
}



int Orientation(struct Point p, struct Point q, struct Point r){
  /*slope of the line through p,q be s1
   
    slope of the line through q,r be s2
  
    if the point r lies right side of line segment joining p,q
    then s1 > s2 else s1 < s2
  */
  
  int value = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
  if(value == 0)
    return 0;

  return (value>0)?1:2;

}

bool Intersect(struct Point p1, struct Point q1, struct Point p2, struct Point q2){
  int o1 = Orientation(p1, q1, p2);
  int o2 = Orientation(p1, q1, q2);
  int o3 = Orientation(p2, q2, p1);
  int o4 = Orientation(p2, q2, q1);

  if(o1!=o2 && o3!=o4){
    return true;
  }

  if(o1 && OnSegment(p1, p2, q1))
    return true;

  if(o2 && OnSegment(p1, q2, q1))
     return true;

  if(o3 && OnSegment(p2, p1, q2))
    return true;

  if(o4 && OnSegment(p2, q1, q2))
    return true;

  return false;
}

int main(){

  struct Point p1 = {1,1}, q1 =  {10,1};
  struct Point p2 = {1,2}, q2 = {10,2};

  cout <<((Intersect(p1, q1, p2, q2))? "Yes": "No") << endl;
  
  return 0;
}
