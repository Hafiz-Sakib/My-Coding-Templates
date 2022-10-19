struct point{
	int x;
	int y;
	
	point() {}
	point(int _x, int _y){
		x = _x;
		y = _y;
	}
};
// Need a anticlockwise sorted vector 
double area(vector<point>& v)
{
	double res = 0;
	
	for(int K=0; K<sz(v); K++){
		point a = (K?v[K-1]:v.back());
		point b = v[K];
		
		res = (a.x-b.x)*(a.y+b.y);
	}
	
	return res/2;
}
