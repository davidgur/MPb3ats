# MPBeats / MPB3ats
## Inspiration
Rhythm games dominated our childhood, though they left one thing to be desired. The music selection was often disappointing. By applying modern-day technology to this problem, we are increasing the possibilities of gaming to offer a truly customised experience.

## What it does
MPb3ats takes an MP3 file as input, and creates a customised level for it's accompanying rhythm game. Using various mathematical techniques, accuracy is ensured and leads to an exciting gaming experience.

## How we built it
Given the complex/abstract nature of the problem at hand, Python was the immediate choice for the scientifically complex back end of it. For the front end, we decided to use Ubisoft's game engine. We attempted to fulfilled the requirements for Ubisoft's API challenge.

The back end went though multiple various versions until we finally settled on the current one. We had previously attempted beat detection with machine learning, but found that there was a simpler, more mathematical definition of a "beat" that can be taken advantage of.

## Challenges we ran into
When training a machine learning model, the data would have to be created ourselves. We would take a waveform and write down the timestamp of each and every beat in the song. Of course, we never ended up using this model, but the work was exhausting nonetheless.

One particular challenge that we ran into came from one of our developers working on Linux, and the other working on Windows. Usually, writing C++ code for both these platforms doesn't yield any issues, however when working with sockets and networking, problems can (and will) arise! Definitely a valuable lesson that we won't forget in the future!

## Accomplishments that we're proud of
We're proud of the fact that we were able to get back to basic and solve a problem mathematically rather than using machine learning. Sometimes it seems like throwing machine learning at a problem will solve it, however there may be better solutions that exist and should be used and we feel that we have the better solution for our problem.

## What we learned
We learned many things over these 36 hours, as you should as a hackathon! What first comes to mind is that often, no matter how hard you try, it is extremely tedious to write C++ code that will be compatible between Linux and Windows systems. Another, more philosophical lesson that we came out of this with, is one that allows us to appreciate "low-tech" solutions to modern day problems. Being able to develop a clear algorithm as opposed to using machine learning can help save time, processing power, and accuracy.

## Devpost
[MPBeats](https://devpost.com/software/mpbeats)
