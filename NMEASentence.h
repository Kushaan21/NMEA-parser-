/*
 * NMEASentence.h
 *
 *  Created on: Jul 16, 2024
 *      Author: kusha
 */

#ifndef NMEASENTENCE_H_
#define NMEASENTENCE_H_


#include <string>
#include <iostream>
using namespace std;
#include <sstream>
#include <vector>

class NMEASentence {
public:
    virtual void parse(const string& sentence) = 0;

    vector<string> subparser (const string& s){
    	stringstream ss(s);
    	string token;
    	vector<string> parsedValues;

    	        while (getline(ss, token, ',')) {
    	            if (token.empty()) {
    	                token = "0";
    	            }
    	            parsedValues.push_back(token);
    	        }
    	 return parsedValues;
    }

    virtual string getSentenceID() const = 0;
    virtual string getChecksum() const { return 0; };


//    virtual string getTime() const { return 0; };
//    virtual double getLatitude() const{ return 0; };
//    virtual string getNSIndicator() const { return 0; };
//    virtual double getLongitude() const { return 0; };
//    virtual string getEWIndicator() const { return 0; };
//    virtual int getQualityIndicator() const { return 0.0; };
//    virtual int getNumberOfSatellites() const { return 0.0; };
//    virtual double getHdop() const { return 0.0; };
//    virtual double getAltitude() const { return 0.0; };
//    virtual string getAltitudeUnits() const { return 0; };
//    virtual double getGeoidSeparation() const { return 0.0; };
//    virtual string getGeoidSeparationUnits() const { return 0; };
//    virtual double getAgeOfDiffCorr() const { return 0.0; };
//    virtual string getDiffRefStationID() const{ return 0; };
//
//
//    virtual string getStatus() const{ return 0; };
//    virtual double getHeading() const { return 0.0; };
//    virtual char getIndicator() const { return 0; };
//
//    virtual string getWindDirection() const{ return 0; };
//    virtual string getWindDirectionReference() const{ return 0; };
//    //virtual float getWindSpeed() const{ return 0; };
//
//    virtual float getSpeed() const { return 0.0; };
//    virtual float getTrackAngle() const { return 0.0; };
//    virtual int getDate() const { return 0; };
//    virtual float getMagneticVariation() const { return 0.0; };
//    virtual string getVS() const { return 0; };
//
//    virtual float getTrueTrack() const { return 0.0; };
//        virtual char getTrueTrackSymbol() const { return 0; };
//        virtual int getMagneticTrack() const { return 0; };
//        virtual char getMagneticTrackSymbol() const { return 0; };
//        virtual float getSpeedKnots() const { return 0.0; };
//        virtual char getSpeedKnotsSymbol() const { return 0; };
//        virtual float getSpeedKmph() const { return 0.0; };
//        virtual char getSpeedKmphSymbol() const { return 0; };
//
//        virtual int getDay() const { return 0; };
//        virtual int getMonth() const { return 0; };
//        virtual int getYear() const { return 0; };
//        virtual int getLocalZoneHours() const { return 0; };
//        virtual int getLocalZoneMinutes() const { return 0; };
//        virtual int getHr() const { return 0; };
//        virtual int getMn() const { return 0; };
//        virtual int getSc() const { return 0; };
//
//        virtual double getCourse() const { return 0.0; };
//        virtual double getDepth() const { return 0.0; };
//        virtual int getTargetID() const { return 0; };
//        virtual double getBatteryVoltage() const { return 0; };
//
//        virtual string getSpeedKmhUnits() const{ return 0; };
//        virtual float getHeadingTrue() const { return 0.0; };
//        virtual float getHeadingMagnetic() const { return 0.0; };
//        virtual float getSpeedKmh() const { return 0.0; };
//        virtual char getHeadingTrueType() const { return 0; };
//        virtual char getHeadingMagneticType() const { return 0; };
//
//        virtual string getDepthUnits() const{ return 0; };
//        virtual string getDepthMode() const{ return 0; };
//        virtual string getDepthUnitsF() const{ return 0; };
//        virtual float getDepthBelowTransducerF() const { return 0.0; };
//        virtual float getDepthBelowTransducerM() const { return 0.0; };
//        virtual float getDepthBelowTransducer() const { return 0.0; };
//
//        virtual double getWindDirectionTrue() const { return 0; };
//        virtual double getWindDirectionMagnetic() const { return 0; };
//        virtual double getWindSpeedKnots() const { return 0; };
//        virtual double getWindSpeedMetersPerSec() const { return 0; };
//
//        virtual vector<string> getData() const {
//
//                return vector<string>();
//            }
public:
    virtual ~NMEASentence() {}
};


#endif /* NMEASENTENCE_H_ */
