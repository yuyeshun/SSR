#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace std;

int main()
{
	Vector2 v2(2, 4);
	cout << v2 << endl;	
	cout << v2.GetNormal() << endl;

	Vector3 v3(1, 6, 9);
	cout << v3 << endl;	
	cout << v3.GetNormal() << endl;

	Vector4 v4(1, 2, 3);
	cout << v4 << endl;
	cout << v4.GetNormal() << endl;

	char x;
	cin >> x;
	return 0;
}