#include"wav.h"


int main(int argc, char**argv)
{

   const char* fileName ="8k.wav";
   std::vector<int> wavVect;
   FILE *fp = fopen(fileName, "rb");

   std::cout<<"\n File open...!!!";

   wavVect = readFileData(fp, fileName);
   long long sampleCount;

   for(int i = 10;i<wavVect.size(); i++)
   {
      std::cout<<"\n"<<wavVect.at(i);
      sampleCount = i;
   }

   fclose(fp);
   std::cout<<"\n\n Audio file (.wav) contains "<<sampleCount<<" audio samples.\n\n";

   std::cout<<"\n\nDEBUG\n\n";

return 0;

}
