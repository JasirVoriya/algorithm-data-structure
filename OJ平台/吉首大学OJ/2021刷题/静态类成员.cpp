#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      static int objectCount;
      // ���캯������
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
         // ÿ�δ�������ʱ���� 1
         objectCount++;
      }
      double Volume()
      {
         return length * breadth * height;
      }
      static int getCount()
      {
         return objectCount;
      }
   private:
      double length;     // ����
      double breadth;    // ���
      double height;     // �߶�
};
 
// ��ʼ���� Box �ľ�̬��Ա
int Box::objectCount = 0;
 
int main(void)
{
  
   string str=("QWERDF");
   cout << "length of size is " << str.length() << endl;
   cout << "size of str is " << str.size() << endl;
   cout << "sizeof str is " << sizeof(str) << endl; 
   // �ڴ�������֮ǰ������������
   cout << "Inital Stage Count: " << Box::getCount() << endl;
 
   Box Box1(3.3, 1.2, 1.5);    // ���� box1
   Box Box2(8.5, 6.0, 2.0);    // ���� box2 
 
   // �ڴ�������֮��������������
   cout << "Final Stage Count: " << Box::getCount() << endl;
   cout << "sizeof Box is " << sizeof(Box1) <<endl;
 
   return 0;
}
