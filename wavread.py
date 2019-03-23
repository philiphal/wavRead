# -*- coding: utf-8 -*-
"""
Created on Sat Mar 23 15:55:45 2019

@author: mylinux
"""


import numpy as np
import scipy.io as io
import scipy.io.wavfile
import matplotlib.pyplot as plt
import os
#At index 1 in wav array: -63

def writeToFile(fileName, data, numIndices):
    fp = open(fileName, 'w')
    for i in range(numIndices):
        fp.write("At index %d in wav array: %d \n"%(i,int(data[i])))
    fp.close()

fileName='8k.wav'
opFileName='pythonWavData.txt'
Fs,rawData=io.wavfile.read(fileName)
print("")
print(len(rawData/Fs))

rawData=rawData[0:len(rawData)/1]
if(len(rawData)/Fs>60.0):
    print("File Duration = %.2f [mins]"%((float(len(rawData))/Fs)/60))
else:
    print("File Duration = %.2f [secs]"%((float(len(rawData))/Fs)))


Nd=len(rawData); Nfft=2*Nd; T=1.0/Fs; sigTime=Nd*T

first_indices = np.zeros(10)
last_indices = np.zeros(10)

first_indices[0:10] = rawData[1:11]
last_indices[0:10] = rawData[len(rawData)-10:len(rawData)]

writeToFile(opFileName, first_indices, 10)


print(first_indices)
print(last_indices)

