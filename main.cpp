#include"wav.h"


int main(int argc, char**argv)
{

   const char* fileName = "8k.wav";
   std::vector<int> wavVect;
   std::vector<int> absVect;

   wavVect = readFileData(fileName);

	for(int i=0; i<100; i++)
	{
	  std::cout<<wavVect.at(i)<<"\n";
	}


   std::cout << "\n\nDEBUG\n\n";

return 0;

}
