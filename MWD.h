/*
 * MWD.h
 *
 *  Created on: Jul 15, 2024
 *      Author: kusha
 */

#ifndef MWD_H_
#define MWD_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class MWD : public NMEASentence {
private:
    string sentenceID;
    double windDirectionTrue;
    double windDirectionMagnetic;
    double windSpeedKnots;
    double windSpeedMetersPerSec;
    string checksum;

public:
    void parse(const string& MWD) override {
    	vector<string> parsedValues ;
    	parsedValues =  subparser (MWD);


        size_t asteriskPos = parsedValues.back().find('*');
        checksum = parsedValues.back().substr(asteriskPos + 1);

        sentenceID = parsedValues[0];
        windDirectionTrue = stod(parsedValues[1]);
        windDirectionMagnetic = stod(parsedValues[3]);
        windSpeedKnots = stod(parsedValues[5]);
        windSpeedMetersPerSec = stod(parsedValues[7]);
    }

    string getSentenceID() const { return sentenceID; }
        double getWindDirectionTrue() const { return windDirectionTrue; }
        double getWindDirectionMagnetic() const { return windDirectionMagnetic; }
        double getWindSpeedKnots() const { return windSpeedKnots; }
        double getWindSpeedMetersPerSec() const { return windSpeedMetersPerSec; }
        string getChecksum() const { return checksum; }

public:
    virtual ~MWD() {}
};




#endif /* MWD_H_ */
