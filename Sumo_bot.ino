#include <Servo.h>
/* Test it on actual bot **doing
 * Decide walk pattern   **test()
 */
class Sumo_bot
{
  Servo motors[6];                                       // 0- Right foot           1- Left foot
  int offsets[6];                                        // 2- Right leg            3- Left leg
  int pos[6];                                            // 4- Right shoulder       5- Left shoulder

  public:
  Sumo_bot()
  {
    offsets[0]=94;         offsets[1]=84;
    offsets[2]=85;         offsets[3]=90;
    offsets[4]=72;         offsets[5]=150;
  }

  int get_pos(int id)
  {
    return pos[id];
  }
  void connec(int a,int b,int c,int d, int e,int f)                                       //takes pin no as arguments
  {
    motors[0].attach(a);            motors[1].attach(b);
    motors[2].attach(c);            motors[3].attach(d);
    motors[4].attach(e);            motors[5].attach(f);
  }

  void writee(int id,int new_pos)                                                         //sets angle from -90 to 90
  {
    motors[id].write(new_pos+offsets[id]);
    pos[id]=new_pos;
  }
  
  void init_pos()
  {
    set(0,0,0,0,0,0);
  }

  void set(int a,int b,int c,int d, int e,int f)                                          //sets all motors to respective angles
  {
    writee(0,a);            writee(1,b);
    writee(2,c);            writee(3,d);
    writee(4,e);            writee(5,f);
  }

};
Sumo_bot s;


void test(int delayy,int tilt,int twist)
{
  s.set(tilt,s.get_pos(1),s.get_pos(2),s.get_pos(3),s.get_pos(4),s.get_pos(5));
  delay(400);
  s.set(s.get_pos(0),-tilt,s.get_pos(2),s.get_pos(3),s.get_pos(4),s.get_pos(5));
  delay(delayy);
  s.set(s.get_pos(0),s.get_pos(1),twist,twist,s.get_pos(4),s.get_pos(5));
  delay(delayy);
  while(1)
  {
    s.set(s.get_pos(0),tilt,s.get_pos(2),s.get_pos(3),s.get_pos(4),s.get_pos(5));
    delay(delayy);
    s.set(s.get_pos(0),-tilt,-twist,-twist,s.get_pos(4),s.get_pos(5));
    delay(delayy);
    s.set(-tilt,s.get_pos(1),s.get_pos(2),s.get_pos(3),s.get_pos(4),s.get_pos(5));
    delay(delayy);
    s.set(tilt,s.get_pos(1),twist,twist,s.get_pos(4),s.get_pos(5));
    delay(delayy);
  }
}
  /*s.set(s.get_pos[0],s.get_pos[1],s.get_pos[2],s.get_pos[3],s.get_pos[4],s.get_pos[5]);
  delay(2000);*/

void setup()
{
  s.connec(2,3,4,5,6,7);
  s.init_pos();
  delay(3000);
  test(1000,20,30);
  
}

void loop()
{
}
