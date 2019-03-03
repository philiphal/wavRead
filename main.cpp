#include"wav.h"
#include"fft.h"
#include<array>


int main(int argc, char**argv)
{

   const char* fileName = "8k.wav";
   std::vector<int> wavVect;
   std::vector<int> absVect;
   complex<double>wav_vect[32000];
    wavVect = readFileData(fileName);

	for(int i=0; i<8; i++)
	{
	  std::cout<<wavVect.at(i)<<"\n";
	}
	int radixCheck =  checkRadix2(8);

	std::cout<<"\n Radix Check = "<<radixCheck<<"\n";
	if(checkRadix2(8)!=1)
		return 0;



   std::cout << "\n\nDEBUG\n\n";

return 0;

}
