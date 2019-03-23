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


fileName='8k.wav'

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

first_indices[0:10] = rawData[0:10]
last_indices[0:10] = rawData[len(rawData)-10:len(rawData)]

print(first_indices)
print(last_indices)

