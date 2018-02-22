#include "polyLine.h"
const int MAX_PILLARS = 100;

Canvas cvs(640,480,"Test Canvas");

class Chamber
{

	public:
		Chamber();
		Chamber(int p,PolyLine *list);
		
	private:
		int numPillars; 
		PolyLine pillarList[MAX_PILLARS]; 

};

Chamber::Chamber()
{
    numPillars =1;
	
	//Pillar 0 is rectangle with no inside pillars
	
	pillarList[0] = Ngon(Point2(0,0),10,6,0);
	pillarList[0].drawPolyLine(&cvs,pillarList[0].getNumVertices());
		
	}

Chamber::Chamber(int PillarQty,PolyLine *pillarArray)
{
	numPillars = PillarQty;
	
	for(int i=0;i<numPillars;i++)
	{
	      pillarList[i] = pillarArray[i];
		  pillarList[i].drawPolyLine(&cvs,pillarArray[i].getNumVertices());
		
	}


}

