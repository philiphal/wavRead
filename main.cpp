#include"wav.h"


int main(int argc, char**argv)
{

   const char* fileName ="8k.wav";
   std::vector<int> WavVect;
   FILE *fp = fopen(fileName, "rb");

   std::cout<<"\n File open...!!!";

   WavVect = readFileData(fp, fileName);






   fclose(fp);



   std::cout<<"\n\nDEBUG\n\n";

return 0;

}
