/*
 * RMC.h
 *
 *  Created on: Jul 15, 2024
 *      Author: kusha
 */

#ifndef RMC_H_
#define RMC_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
using namespace std;

#include <sstream>
#include <vector>

class RMC : public NMEASentence {
private:
    string sentenceID;
    string time;
    string status;
    double latitude;
    string nsIndicator;
    double longitude;
    string ewIndicator;
    float speed;
    float trackAngle;
    int date;
    float magneticVariation;
    string vs;
    string checksum;
    int hr;
    int mn;
    int sc;

public:
    void parse(const string& RMC) override {

    	vector<string> parsedValues ;
     	parsedValues =  subparser (RMC);

        size_t asteriskPos = parsedValues.back().find('*');
        vs = (parsedValues.back().substr(0, asteriskPos));
        checksum = parsedValues.back().substr(asteriskPos + 1);

        sentenceID = parsedValues[0];
        time = (parsedValues[1]);
        status = parsedValues[2];
        latitude = stod(parsedValues[3]);
        nsIndicator = parsedValues[4][0];
        longitude = stod(parsedValues[5]);
        ewIndicator = parsedValues[6][0];
        speed = stof(parsedValues[7]);
        trackAngle = stof(parsedValues[8]);
        date = stoi(parsedValues[9]);
        magneticVariation = stof(parsedValues[10]);

        hr = stoi(time.substr(0, 2));
        mn = stoi(time.substr(2, 2));
        sc = stoi(time.substr(4, 2));
    }

    string getSentenceID() const { return sentenceID.substr(3,3); }
        string getTime() const { return time; }
        int getHr() const { return hr;}
        int getMn() const { return mn;}
        int getSc() const { return sc;}

        double getLatitude() const { return latitude; }
        string getNSIndicator() const { return nsIndicator; }
        double getLongitude() const { return longitude; }
        string getEWIndicator() const { return ewIndicator; }

        string getStatus() const { return status;}
        float getSpeed() const { return speed; }
        float getTrackAngle() const { return trackAngle; }
        int getDate() const { return date; }
        float getMagneticVariation() const { return magneticVariation; }
        string getVs() const { return vs; }

public:
    virtual ~RMC() {}
};
#endif /* RMC_H_ */
