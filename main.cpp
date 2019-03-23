#include"wav.h"
#include"fft.h"
#include<array>


int main(int argc, char**argv)
{

   const char* fileName = "8k.wav";
   const char* opfileName = "cWavData.txt";
   std::vector<int> wavVect;
   std::vector<int> absVect;
   complex<double>wav_vect[32000];
    wavVect = readFileData(fileName);

	for(int i=0; i<wavVect.at(0); i++)
	{
	  std::cout<<wavVect.at(i)<<"\n";
	}

   //writeWavData(opfileName, wavVect, 10);
   std::cout << "\n\nDEBUG\n\n";

return 0;

}
