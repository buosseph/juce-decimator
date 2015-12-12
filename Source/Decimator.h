/*
  ==============================================================================

    Decimator.h
    Created: 11 Dec 2015 10:17:35pm
    Author:  Brian Uosseph

  ==============================================================================
*/

#ifndef DECIMATOR_H_INCLUDED
#define DECIMATOR_H_INCLUDED

/**
    Decimator
 
    Handles bit depth and sample rate reduction of an input signal.
 */
class Decimator {
private:
    float output;
    float counter;
    float quantization;
    
public:
    Decimator()
    {
        output = 0.f;
        counter = 0.f;
        quantization = powf(2.f, 32.f);
    }
    
    float decimate (float sample, float bit_depth, float sample_rate)
    {
        output = 0.f;
        quantization = powf(2.f, bit_depth);
        
        counter += sample_rate;
        
        if (counter >= 1.f) {
            counter -= 1.f;
            output = floorf(sample * quantization) / quantization;
        }
        
        return output;
    }
};

#endif  // DECIMATOR_H_INCLUDED
