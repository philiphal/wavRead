typedef struct {
   
	FILE *fhandle;

	const char * fileName;

	const int size = 4;

	char ChunkID[4];
	char Format[4];
	char Subchunk1ID[4];
	char Subchunk2ID[4];

	int ChunkSize,Subchunk1Size, SampleRate, ByteRate,Subchunk2Size;

	short AudioFormat, NumChannels, BlockAlign, BitsPerSample;

	short *Data;

}wav_struct;


//***************************************************************
//
//***************************************************************
std::vector<int> readFileData(const char*wavFileName)
{
	wav_struct wave, *wave_ptr;
	wave_ptr =  &wave;

	wave_ptr->fileName = wavFileName;
	wave_ptr->fhandle = fopen(wave_ptr->fileName, "rb");



	std::vector<int>audio_data;
	std::vector<char>chunk_ID;
	std::vector<char>_format;
	std::vector<char>sub_chunk1_ID;
	std::vector<char>sub_chunk2_ID;
	
	std::cout<<"\nFILE DETAILS: ";
	std::cout<<"\n^^^^^^^^^^^^ ";
	
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$	
	std::cout<<"\nCHUNK ID: \t ";
	fread(wave_ptr->ChunkID,1,4,wave_ptr->fhandle);
	for(int i=0;i<4;i++)
		{
		chunk_ID.push_back(wave_ptr->ChunkID[i]);
		std::cout<<chunk_ID.at(i);
		}
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	fread(&wave_ptr->ChunkSize,4,1,wave_ptr->fhandle);
	std::cout<<"\nCHUNK SIZE: 	 "<<wave_ptr->ChunkSize;


	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$	
	std::cout<<"\nFORMAT:   \t ";
	fread(wave_ptr->Format,1,4,wave_ptr->fhandle);
	for(int i=0;i<4;i++)
		{
		_format.push_back(wave_ptr->Format[i]);
		std::cout<<_format.at(i);			
		}
	
	
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	fread(wave_ptr->Subchunk1ID,1,4,wave_ptr->fhandle);
	std::cout<<"\nSUB CHUNK1 ID:   ";
	for(int i=0;i<4;i++)
		{
		sub_chunk1_ID.push_back(wave_ptr->Subchunk1ID[i]);
		std::cout<<sub_chunk1_ID.at(i);			
		}
	
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	fread(&wave_ptr->Subchunk2ID,1,4,wave_ptr->fhandle);
	std::cout<<"\nSUB CHUNK2 ID:   ";
	for(int i=0;i<4;i++)
		{
		sub_chunk2_ID.push_back(wave_ptr->Subchunk2ID[i]);
		std::cout<<(int)sub_chunk2_ID.at(i);			
		}

	
	fread(&wave_ptr->AudioFormat,2,1,wave_ptr->fhandle);
	std::cout<<"\nAUDIO FORMAT:    "<<wave_ptr->AudioFormat;
	
	fread(&wave_ptr->NumChannels,2,1,wave_ptr->fhandle);
	std::cout<<"\nNUM CHANNELS:    "<<wave_ptr->NumChannels;
	
	fread(&wave_ptr->SampleRate,4,1,wave_ptr->fhandle);
	std::cout<<"\nSAMPLE RATE:     "<<wave_ptr->SampleRate;
	
	fread(&wave_ptr->ByteRate,4,1,wave_ptr->fhandle);
	std::cout<<"\nBYTE RATE:       "<<wave_ptr->ByteRate;
	
	fread(&wave_ptr->BlockAlign,2,1,wave_ptr->fhandle);
	std::cout<<"\nBLOCK ALIGN:     "<<wave_ptr->BlockAlign;
	
	fread(&wave_ptr->BitsPerSample,2,1,wave_ptr->fhandle);
	std::cout<<"\nBITS PER SAMPLE: "<<wave_ptr->BitsPerSample;
	
	fread(&wave_ptr->Subchunk1Size,4,1,wave_ptr->fhandle);
	std::cout<<"\nSUB CHUNK1 SIZE: "<<wave_ptr->Subchunk1Size;
	
	fread(&wave_ptr->Subchunk2Size,4,1,wave_ptr->fhandle);
	std::cout<<"\nSUB CHUNK2 SIZE: "<<wave_ptr->Subchunk2Size;
	
	std::cout<<"\n\n";
	
	
	// Create an element for every 	sample
	wave_ptr->Data=new short [wave_ptr->Subchunk2Size/(wave_ptr->BitsPerSample/8)]; 
	
	// Reading raw audio data
	fread(wave_ptr->Data,wave_ptr->BitsPerSample/8,wave_ptr->Subchunk2Size/(wave_ptr->BitsPerSample/8),wave_ptr->fhandle); 
	
	// Size of wav file is stored in first index	
	audio_data.push_back(wave_ptr->Subchunk2Size/2);
	
	  for(int i=1 ;i<(wave_ptr->Subchunk2Size/2)+1;++i)
  	{
  		audio_data.push_back(wave_ptr->Data[i]);
  	}
  	fclose(wave_ptr->fhandle);
	return(audio_data);
}
