#include"wav.h"


int main(int argc, char**argv)
{

   const char* fileName = "8k.wav";
   std::vector<int> wavVect;
   std::vector<int> absVect;
   FILE *fp = fopen(fileName, "rb");

   wavVect = readFileData(fp, fileName);
   long long sampleCount;
   #ifdef verbose
   for(int i = 10;i < wavVect.size(); i++)
   {
      std::cout<<"\t" << wavVect.at(i)<<", ";
      sampleCount = i;
   }
   #endif
   absVect = get_ABS_sig(wavVect);

   #ifdef verbose
   for(int i = 10;i < absVect.size(); i++)
   {
      std::cout<<"\t" << absVect.at(i)<<", ";
   }
   
   std::cout << "\n\n Audio file (" << fileName << ") contains " << sampleCount << " audio samples.\n\n";
   #endif

   fclose(fp);

   std::cout << "\n\nDEBUG\n\n";

return 0;

}
