

#ifndef GLL_H_
#define GLL_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class GLL : public NMEASentence {
private:
    string sentenceID;
    double latitude;
    string nsIndicator;
    double longitude;
    string ewIndicator;
    string time;
    string status;
    string checksum;
    int hr;
    int mn;
    int sc;

public:
    void parse(const string& GLL) override {
    	vector<string> parsedValues ;
     	parsedValues =  subparser (GLL);


        size_t asteriskPos = parsedValues.back().find('*');
        string lastPart = parsedValues.back().substr(0, asteriskPos);
        status = lastPart;
        checksum = parsedValues.back().substr(asteriskPos + 1);

        sentenceID = parsedValues[0];
        latitude = stod(parsedValues[1]);
        nsIndicator = parsedValues[2];
        longitude = stod(parsedValues[3]);
        ewIndicator = parsedValues[4];
        time = parsedValues[5];

        hr = stoi(time.substr(0, 2));
        mn = stoi(time.substr(2, 2));
        sc = stoi(time.substr(4, 2));
    }

    string getSentenceID() const override { return sentenceID.substr(3, 3); }
    double getLatitude() const { return latitude; }
    string getNSIndicator() const { return nsIndicator; }
    double getLongitude() const { return longitude; }
    string getEWIndicator() const { return ewIndicator; }
    string getTime() const { return time; }
    string getStatus() const { return status; }
    string getChecksum() const { return checksum; }
    int getHour() const { return hr; }
    int getMinute() const { return mn; }
    int getSecond() const { return sc; }

    virtual ~GLL() {}
};



#endif /* GLL_H_ */
