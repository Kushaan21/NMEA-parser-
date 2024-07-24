/*
 * MWV.h
 *
 *  Created on: Jul 15, 2024
 *      Author: kusha
 */

#ifndef MWV_H_
#define MWV_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
using namespace std;

#include <sstream>
#include <vector>

class MWV : public NMEASentence {
private:
    string sentenceID;
    string windDirection;
    string windDirectionReference;
    float windSpeed;
    string windSpeedUnits;
    string status;
    string checksum;

public:
    void parse(const string& MWV) override {
    	vector<string> parsedValues ;
    	parsedValues =  subparser (MWV);

        size_t asteriskPos = parsedValues.back().find('*');
        status = parsedValues.back().substr(0, asteriskPos);
        checksum = parsedValues.back().substr(asteriskPos + 1);

        sentenceID = parsedValues[0];
        windDirection = parsedValues[1];
        windDirectionReference = parsedValues[2];
        windSpeed = stof(parsedValues[3]);
        windSpeedUnits = parsedValues[4];

    }

    	string getSentenceID() const { return sentenceID.substr(3,3); }
        string getWindDirection() const { return windDirection; }
        string getWindDirectionReference() const { return windDirectionReference; }
        float getWindSpeed() const { return windSpeed; }
        string getStatus() const { return status; }
        string getChecksum() const { return checksum; }

        virtual ~MWV() {}

};






#endif /* MWV_H_ */
