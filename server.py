import sys
import json
import random
import socket
import multiprocessing

import numpy as np
import librosa
import librosa.display

from scipy import signal

class MP3Processor():
    def __init__(self, f):
        self.f = f
        self.y, self.sr = librosa.load(self.f)
        self.beat_samples = []

    def get_beat_locs(self):
        _, beats = librosa.beat.beat_track(y=self.y, sr=self.sr)

        self.beat_samples = librosa.frames_to_samples(beats)
    
    def export(self):
        beats_played = []
        for ts in self.beat_samples:
            beats_played.append((ts, random.randint(1, 3)))

        beats_played_str = ""
        for beat in beats_played:
            beats_played_str += str(beat[0]) + " " + str(beat[1]) + "\n"

        return beats_played_str


HOST = '127.0.0.1'
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    while True:
        s.listen()
        conn, addr = s.accept()
        with conn:
            print('Connected by', addr)
            while True:
                data = conn.recv(1024)
                if not data:
                    break
                f = data.decode("utf-8")
                my_processor = MP3Processor(f)
                my_processor.get_beat_locs()
                beat_locs = my_processor.export()

                conn.sendall(str.encode(beat_locs))
                print(data.decode("utf-8"))

                del my_processor
                break
