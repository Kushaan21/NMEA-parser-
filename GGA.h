/*
 * GGA.h
 *
 *  Created on: Jul 16, 2024
 *      Author: kusha
 */

#ifndef GGA_H_
#define GGA_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
using namespace std;

#include <sstream>
#include <vector>

class GGA : public NMEASentence {
private:
    string sentenceID;
    string time;
    double latitude;
    string nsIndicator;
    double longitude;
    string ewIndicator;
    int qualityIndicator;
    int numberOfSatellites;
    double hdop;
    double altitude;
    string altitudeUnits;
    double geoidSeparation;
    string geoidSeparationUnits;
    double ageOfDiffCorr;
    string diffRefStationID;
    string checksum;
    int hr;
    int mn;
    int sc;

public:
    void parse(const string& GGA) override {
    	vector<string> parsedValues ;
    	parsedValues =  subparser (GGA);


        size_t asteriskPos = parsedValues.back().find('*');
        diffRefStationID = (parsedValues.back().substr(0, asteriskPos));
        checksum = (parsedValues.back().substr(asteriskPos + 1));

        sentenceID = parsedValues[0];
        time = parsedValues[1];
        latitude = stod(parsedValues[2]);
        nsIndicator = parsedValues[3];
        longitude = stod(parsedValues[4]);
        ewIndicator = parsedValues[5];
        qualityIndicator = stoi(parsedValues[6]);
        numberOfSatellites = stoi(parsedValues[7]);
        hdop = stod(parsedValues[8]);
        altitude = stod(parsedValues[9]);
        altitudeUnits = parsedValues[10];
        geoidSeparation = stod(parsedValues[11]);
        geoidSeparationUnits = parsedValues[12];
        ageOfDiffCorr = stod(parsedValues[13]);
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
    int getQualityIndicator() const { return qualityIndicator; }
    int getNumberOfSatellites() const { return numberOfSatellites; }
    double getHdop() const { return hdop; }
    double getAltitude() const { return altitude; }
    string getAltitudeUnits() const { return altitudeUnits; }
    double getGeoidSeparation() const { return geoidSeparation; }
    string getGeoidSeparationUnits() const { return geoidSeparationUnits; }
    double getAgeOfDiffCorr() const { return ageOfDiffCorr; }
    string getDiffRefStationID() const { return diffRefStationID; }
    string getChecksum() const { return checksum; }

    virtual ~GGA() {}
};

#endif /* GGA_H_ */
