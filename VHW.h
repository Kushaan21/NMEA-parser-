/*
 * VHW.h
 *
 *  Created on: Jul 15, 2024
 *      Author: kusha
 */

#ifndef VHW_H_
#define VHW_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
using namespace std;

#include <sstream>
#include <vector>

class VHW : public NMEASentence {
private:
    string sentenceID;
    float headingTrue;
    char headingTrueType;
    float headingMagnetic;
    char headingMagneticType;
    float speedKnots;
    string speedKnotsUnits;
    float speedKmh;
    string speedKmhUnits;
    string checksum;

public:
    void parse(const string& vhw) override {
    	vector<string> parsedValues ;
 	   	parsedValues =  subparser (vhw);

        size_t asteriskPos = parsedValues.back().find('*');
        speedKmhUnits = parsedValues.back().substr(0, asteriskPos);
        checksum = parsedValues.back().substr(asteriskPos + 1);

        sentenceID = parsedValues[0];
        headingTrue = stof(parsedValues[1]);
        headingTrueType = parsedValues[2][0];
        headingMagnetic = stof(parsedValues[3]);
        headingMagneticType = parsedValues[4][0];
        speedKnots = stof(parsedValues[5]);
        speedKnotsUnits = parsedValues[6];
        speedKmh = stof(parsedValues[7]);
    }

    string getSentenceID() const { return sentenceID; }
        float getHeadingTrue() const { return headingTrue; }
        char getHeadingTrueType() const { return headingTrueType; }
        float getHeadingMagnetic() const { return headingMagnetic; }
        char getHeadingMagneticType() const { return headingMagneticType; }
        float getSpeedKnots() const { return speedKnots; }
        string getSpeedKnotsUnits() const { return speedKnotsUnits; }
        float getSpeedKmh() const { return speedKmh; }
        string getSpeedKmhUnits() const { return speedKmhUnits; }
        string getChecksum() const { return checksum; }
public:
    virtual ~VHW() {}
};

#endif /* VHW_H_ */
