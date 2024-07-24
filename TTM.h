/*
 * TTM.h
 *
 *  Created on: Jul 15, 2024
 *      Author: kusha
 */

#ifndef TTM_H_
#define TTM_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
using namespace std;

#include <sstream>
#include <vector>

class TTM : public NMEASentence {
private:
    string sentenceID;
    string time;
    double latitude;
    string nsIndicator;
    double longitude;
    string ewIndicator;
    float speed;
    double course;
    float magneticVariation;
    double depth;
    int targetID;
    double batteryVoltage;
    string checksum;
    int hr;
    int mn;
    int sc;

public:
    void parse(const string& TTM) override {

    	vector<string> parsedValues ;
      	parsedValues =  subparser (TTM);


        size_t asteriskPos = parsedValues.back().find('*');
        batteryVoltage = stod(parsedValues.back().substr(0, asteriskPos));
        checksum = parsedValues.back().substr(asteriskPos + 1);

        sentenceID = parsedValues[0];
        time = parsedValues[1];
        latitude = stod(parsedValues[2]);
        nsIndicator = parsedValues[3];
        longitude = stod(parsedValues[4]);
        ewIndicator = parsedValues[5];
        speed = stof(parsedValues[6]);
        course = stod(parsedValues[7]);
        magneticVariation = stof(parsedValues[8]);
        depth = stod(parsedValues[9]);
        targetID = stoi(parsedValues[10]);
        hr = stoi(time.substr(0, 2));
        mn = stoi(time.substr(2, 2));
        sc = stoi(time.substr(4, 2));
    }

    string getSentenceID() const override { return sentenceID; }
        string getTime()  { return time; }
        double getLatitude()  { return latitude; }
        string getNSIndicator()  { return nsIndicator; }
        double getLongitude()  { return longitude; }
        string getEWIndicator()  { return ewIndicator; }
        float getSpeed()  { return speed; }
        double getCourse()  { return course; }
        float getMagneticVariation()  { return magneticVariation; }
        double getDepth()  { return depth; }
        int getTargetID()  { return targetID; }
        double getBatteryVoltage()  { return batteryVoltage; }
        string getChecksum()  { return checksum; }
        int getHr()  { return hr; }
        int getMn()  { return mn; }
        int getSc()  { return sc; }

public:
    virtual ~TTM() {}
};

#endif /* TTM_H_ */
