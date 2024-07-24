/*
 * VTG.h
 *
 *  Created on: Jul 15, 2024
 *      Author: kusha
 */

#ifndef VTG_H_
#define VTG_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
using namespace std;

#include <sstream>
#include <vector>

class VTG : public NMEASentence {
private:
    string sentenceID;
    float trueTrack;
    char trueTrackSymbol;
    int magneticTrack;
    char magneticTrackSymbol;
    float speedKnots;
    char speedKnotsSymbol;
    float speedKmph;
    char speedKmphSymbol;
    string checksum;

public:
    void parse(const string& VTG) override {
    	vector<string> parsedValues ;
  	   	parsedValues =  subparser (VTG);

        size_t asteriskPos = parsedValues.back().find('*');
        speedKmphSymbol = parsedValues.back().substr(0, asteriskPos)[0];
        checksum = parsedValues.back().substr(asteriskPos + 1);

        sentenceID = parsedValues[0];
        trueTrack = stof(parsedValues[1]);
        trueTrackSymbol = parsedValues[2][0];
        magneticTrack = stoi(parsedValues[3]);
        magneticTrackSymbol = parsedValues[4][0];
        speedKnots = stof(parsedValues[5]);
        speedKnotsSymbol = parsedValues[6][0];
        speedKmph = stof(parsedValues[7]);
    }

    string getSentenceID() const { return sentenceID.substr(3,3); }

    float getTrueTrack()  { return trueTrack; }
        char getTrueTrackSymbol()  { return trueTrackSymbol; }
        int getMagneticTrack()  { return magneticTrack; }
        char getMagneticTrackSymbol()  { return magneticTrackSymbol; }
        float getSpeedKnots()  { return speedKnots; }
        char getSpeedKnotsSymbol()  { return speedKnotsSymbol; }
        float getSpeedKmph()  { return speedKmph; }
        char getSpeedKmphSymbol()  { return speedKmphSymbol; }
        string getChecksum() const { return checksum; }


public:
    virtual ~VTG() {}
};

#endif /* VTG_H_ */
