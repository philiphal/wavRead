//wav.h
#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>

	// Buffers etc..
	char ChunkID[4], Format[4], Subchunk1ID[4],Subchunk2ID[4];
	
	int ChunkSize,Subchunk1Size, SampleRate, ByteRate,Subchunk2Size;
	
	short AudioFormat, NumChannels, BlockAlign, BitsPerSample;
	
	short *Data;
//***************************************************************
//
//***************************************************************
std::vector<int> readFileData(FILE*fhandle, const char*fileName)
{
	fhandle=fopen(fileName,"r");

	std::vector<int>audio_data;
	std::vector<char>chunk_ID;
	std::vector<char>_format;
	std::vector<char>sub_chunk1_ID;
	std::vector<char>sub_chunk2_ID;
	
	std::cout<<"\nFILE DETAILS: ";
	std::cout<<"\n^^^^^^^^^^^^ ";
	
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$	
	std::cout<<"\nCHUNK ID: \t ";
	fread(ChunkID,1,4,fhandle);
	for(int i=0;i<4;i++)
		{
		chunk_ID.push_back(ChunkID[i]);
		std::cout<<chunk_ID.at(i);
		}
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	fread(&ChunkSize,4,1,fhandle);
	std::cout<<"\nCHUNK SIZE: 	 "<<ChunkSize;


	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$	
	std::cout<<"\nFORMAT:   \t ";
	fread(Format,1,4,fhandle);
	for(int i=0;i<4;i++)
		{
		_format.push_back(Format[i]);
		std::cout<<_format.at(i);			
		}
	
	
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	fread(Subchunk1ID,1,4,fhandle);
	std::cout<<"\nSUB CHUNK1 ID:   ";
	for(int i=0;i<4;i++)
		{
		sub_chunk1_ID.push_back(Subchunk1ID[i]);
		std::cout<<sub_chunk1_ID.at(i);			
		}
	
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	fread(&Subchunk2ID,1,4,fhandle);
	std::cout<<"\nSUB CHUNK2 ID:   ";
	for(int i=0;i<4;i++)
		{
		sub_chunk2_ID.push_back(Subchunk2ID[i]);
		std::cout<<(int)sub_chunk2_ID.at(i);			
		}

	
	fread(&AudioFormat,2,1,fhandle);
	std::cout<<"\nAUDIO FORMAT:    "<<AudioFormat;
	
	fread(&NumChannels,2,1,fhandle);
	std::cout<<"\nNUM CHANNELS:    "<<NumChannels;
	
	fread(&SampleRate,4,1,fhandle);
	std::cout<<"\nSAMPLE RATE:     "<<SampleRate;
	
	fread(&ByteRate,4,1,fhandle);
	std::cout<<"\nBYTE RATE:       "<<ByteRate;
	
	fread(&BlockAlign,2,1,fhandle);
	std::cout<<"\nBLOCK ALIGN:     "<<BlockAlign;
	
	fread(&BitsPerSample,2,1,fhandle);
	std::cout<<"\nBITS PER SAMPLE: "<<BitsPerSample;
	
	fread(&Subchunk1Size,4,1,fhandle);
	std::cout<<"\nSUB CHUNK1 SIZE: "<<Subchunk1Size;
	
	fread(&Subchunk2Size,4,1,fhandle);
	std::cout<<"\nSUB CHUNK2 SIZE: "<<Subchunk2Size;
	
	std::cout<<"\n\n";
	
	
	// Create an element for every 	sample
	Data=new short [Subchunk2Size/(BitsPerSample/8)]; 
	
	// Reading raw audio data
	fread(Data,BitsPerSample/8,Subchunk2Size/(BitsPerSample/8),fhandle); 
	
	// Size of wav file is stored in first index	
	audio_data.push_back(Subchunk2Size/2);
	
	  for(int i=1 ;i<(Subchunk2Size/2)+1;++i)
  	{
  		audio_data.push_back(Data[i]);
  	}
  	fclose(fhandle);
	return(audio_data);
}

//***************************************************************
//
//***************************************************************
std::vector<int> get_ABS_sig(std::vector<int>audioSignal)
{
		std::vector<int>absSignal;
		
		
		for(int i=1;i<audioSignal.at(0)+1;++i)
			{
			
				absSignal.push_back(std::abs(audioSignal.at(i)));
				
			}
	
	return(absSignal);

}
//***************************************************************
//
//***************************************************************

void writeSignalToFile(std::vector<int>signal,int signalLength,const char*fileName)
{
		std::ofstream myfile;
		myfile.open (fileName,std::ios::out);
		for(int i=0; i<signalLength;++i)
		{
		myfile<<signal.at(i);
		myfile<<"\n";
		}
		myfile.close();
}

//***************************************************************
//
//***************************************************************

float getSignalMean(std::vector<int>signal,int signalLength)
{
			float threshold;
			uint32_t sum=0;
		
		
		for(int i=0;i<signalLength;++i)
			{
			
				sum+=signal.at(i);
				
			}
			threshold=((float)sum)/signalLength;
	
	return(threshold);
}

//***************************************************************
//
//***************************************************************
void writeFileCharacteristics(FILE*fhandle,const char* fileName)
{

	// Write the same file
	fhandle=fopen(fileName,"w");
	fwrite(ChunkID,1,4,fhandle);
	fwrite(&ChunkSize,4,1,fhandle);
	fwrite(Format,1,4,fhandle);
	fwrite(Subchunk1ID,1,4,fhandle);
	fwrite(&Subchunk1Size,4,1,fhandle);
	fwrite(&AudioFormat,2,1,fhandle);
	fwrite(&NumChannels,2,1,fhandle);
	fwrite(&SampleRate,4,1,fhandle);
	fwrite(&ByteRate,4,1,fhandle);
	fwrite(&BlockAlign,2,1,fhandle);
	fwrite(&BitsPerSample,2,1,fhandle);
	fwrite(&Subchunk2ID,1,4,fhandle);
	fwrite(&Subchunk2Size,4,1,fhandle);
	fwrite(Data,BitsPerSample/8,Subchunk2Size/(BitsPerSample/8),fhandle);

	fclose(fhandle);



}
