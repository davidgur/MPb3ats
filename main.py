"""
main.py
David Gurevich
September 14, 2019
"""     

import sys
import json
import numpy as np
import random
from scipy import signal

import librosa
import librosa.display

import matplotlib.pyplot as plt

def get_beat_locs(y, sr):
    _, beats = librosa.beat.beat_track(y=y, sr=sr)

    beat_samples = librosa.frames_to_samples(beats)
    return beat_samples

def get_fq_at_loc(y, sr, loc):
    area_of_interest = np.array( y[loc - 500:loc + 500] )
    area_of_interest = abs(area_of_interest)

    FFT = np.fft.rfft(area_of_interest)[25:]
    fq = np.argmax(FFT)
    print(fq)

y, sr= librosa.load(sys.argv[1])
beat_locs = get_beat_locs(y, sr)

keys = [0] * len(y)
for beat in beat_locs:
    keys[beat] = random.randint(1, 3)

beats_played = {}
for i, key in enumerate(keys):
    if key != 0:
        beats_played[i] = key



with open('output.json', 'w') as f:
    json.dump(beats_played, f, indent=4)

# python main.py [name of mp3 here]