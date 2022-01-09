#include "c4-5.cpp"

int main() {
  Matrix m_1(double(2));
  cout << "m1[] = " << endl;
  m_1.print();
  Matrix m_2 = m_1 + m_1;
  cout << "m2[] = " << endl;
  m_2.print();
  Matrix m_3 = m_2 * m_2;
  cout << "m3[] = " << endl;
  m_3.print();
  return 0;
}
