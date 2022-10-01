#include <cmath>
#include <vector>

struct Coordination {
	double x, y, z;
	Coordination(double paramx = 0, double paramy = 0, double paramz = 0) : x(paramx), y(paramy), z(paramz){}
};
struct EulerAngle {
	double x, y, z;
	EulerAngle(double paramx = 0, double paramy = 0, double paramz = 0) : x(paramx), y(paramy), z(paramz) {}
};
class Transform
{
public:
	Coordination Position;
	EulerAngle Rotation;


};