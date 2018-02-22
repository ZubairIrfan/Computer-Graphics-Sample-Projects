class vector2
{
	public:
		vector2:: vector2() {dx = 0.0; dy = 0.0;}//  constructors
		vector2:: vector2(float x, float y)
		{
			dx = x;
			dy = y;
		}
		
		void setX(float x) { dx = x;}
		void setY(float y) { dy =y;}
		void set (float x, float y)
		{
			dx = x;
			dy = y;
		
		}
		//void draw(void); // draw this vector
		float length(void);
		float deltaX(void);	// return sides
		float deltaY(void);
		void setDiff(Point2& a, Point2& b)	{ dx = b.getX() - a.getX(); dy = b.getY() - a.getY();}
		
	
	private:
		float dx;
		float dy;
};

float vector2:: length(void)
{
	return sqrt(dx * dx + dy * dy);
}

float vector2::  deltaX(void)    // return components
{
	return dx;
}

float vector2::  deltaY(void)
{
	return dy;
}


const vector2 i2(1.0, 0.0);
const vector2 j2(0.0, 1.0);



void putVector(vector2 u);
float cosAngleBetween(vector2 u, vector2 v);  //return cosine of angle between vectors
float angleBetween(vector2 u, vector2 v);  //return angle between vectors
float inner(vector2 u, vector2 v);
float operator* (vector2 u, vector2 v);   // inner product
float directionOf(vector2 v);  // angle in which vector points(radians)
Point2 operator+ (Point2 u, vector2 v); //  overloaded +
vector2 normalize (vector2 u);      //  scale to unit length; if zero, stays zero
vector2 perp(vector2 u );
vector2 operator* (float s, vector2 u);  // scalar product
vector2 operator+ (vector2 u, vector2 v); //  overloaded +
vector2 operator- (vector2 u, vector2 v);  //  overloaded -
vector2 operator- (Point2 q, Point2 p);   // vector from p to q
vector2 operator- (vector2 v);   // unary vector minus
vector2 project(vector2 u, vector2 v);  // projection of u onto v
vector2 reflect(vector2 a, vector2 m);  // reflection of a in m




void putVector(vector2 u)
{
	printf("< %f, %f >", u.deltaX(), u.deltaY());
}

float operator* (vector2 u, vector2 v)
{
	return inner(u,v);
}

float inner(vector2 u , vector2 v)
{
	return u.deltaX() * v.deltaX() + u.deltaY() * v.deltaY();
}

float cosAngleBetween(vector2 u, vector2 v)  //return cosine of angle between vectors
{
	return normalize(u) * normalize(v);
}

float angleBetween(vector2 u, vector2 v)  //return angle between vectors
{
	return acos ( cosAngleBetween(u, v));
}

float directionOf(vector2 v)  // angle in which vector points(radians)
{
	float pi = 3.141592;

	vector2 nv;
	float angle;
	if (v.length() == 0)
		return 0.0;
	else
	{
		nv = normalize (v);
		angle = acos(nv.deltaY());
		if (nv.deltaY() < 0.0)
			return 2*pi - angle;
		else
			return angle;
	}
}


float radian2degree(float rad)   // radian to degree  conversion
{
	float pi = 3.141592;
	float degreesPerRadian = 180/pi;
	return rad * degreesPerRadian;
}

Point2 operator+ (Point2 u, vector2 v)  //  overloaded +
{
	float x; float y;
	x = u.getX() + v.deltaX();
	y = u.getY() + v.deltaY();
	Point2 p(x,y);
	return p;
}

vector2 operator* (float s, vector2 u)  // scalar product
{   
	vector2 temp (s * u.deltaX(), s* u.deltaY());
	return temp;
}


vector2 normalize (vector2 u)  //  scale to unit length; if zero, stays zero
{
	
	float len ;
	len = u.length();
//		printf("U.length:%f \n",len);

	if (len = 0.0)
	{
		vector2 temp(0.0, 0.0);
		return temp;
	}
	else
	{
	len = u.length();
//		printf("u.length:%f \n",len);

//		vector2 temp(u.deltaX()/len, u.deltaY()/len);
		return (1.0 / len) * u;
	}
}

vector2 operator+ (vector2 u, vector2 v)  //  overloaded +
{
	float x; float y;
	vector2 temp;
	x = u.deltaX() + v.deltaX();
	y = u.deltaY() + v.deltaY();
	temp = vector2(x,y);
	return temp;
}



vector2 operator- (vector2 u, vector2 v)  //  overloaded -
{
	float x; float y;
	vector2 temp;
	x = u.deltaX() - v.deltaX();
	y = u.deltaY() - v.deltaY();
	temp = vector2(x,y);
	return temp;
}



vector2 perp(vector2 u )
{
	vector2 temp;
	temp.set(-u.deltaY(), u.deltaX());
	return temp;
}

vector2 project(vector2 u, vector2 v)  // projection of u onto v
{	// v must be nonzero
	return ((v * u)/(v * v))* v;
}

vector2 operator- (Point2 q, Point2 p)   // vector from p to q
{
	vector2 temp;
	temp.set(q.getX() - p.getX(), q.getY() - p.getY());
	return temp;
}

vector2 operator- (vector2 v)   // unary vector minus
{
	vector2 temp;
	temp.set(- v.deltaX() , - v.deltaY());
	return temp;
}

vector2 reflect(vector2 a, vector2 m)  // reflection of a in m
{
	vector2 nm;
	nm = normalize (m);
	return - 1 *(a - (2*(a * nm))* nm);
}

