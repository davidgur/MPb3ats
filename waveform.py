import pydub
import numpy as np
import matplotlib.pyplot as plt

def read(f, normalized=False):
    a = pydub.AudioSegment.from_mp3(f)
    y = np.array(a.get_array_of_samples())
    if a.channels == 2:
        y = y.reshape((-1, 2))

    if normalized:
        return a.frame_rate, np.float32(y) / 2**15
    else:
        return a.frame_rate, y

sr, x = read('train_song.mp3', normalized=True)
x = x.flatten()
plt.plot(x)
plt.gca().ticklabel_format(useOffset=False)
plt.show()
