/*
 * XDR.h
 *
 *  Created on: Jul 15, 2024
 *      Author: kusha
 */

#ifndef XDR_H_
#define XDR_H_

#include "NMEASentence.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class XDR : public NMEASentence {
public:
    string sentenceID;
    struct Transducer {
        char type;
        double value;
        char unit;
        string name;
    };
    vector<Transducer> transducers;
    string checksum;

public:
    void parse(const string& XDR) override {
    	vector<string> parsedValues ;
    	parsedValues =  subparser (XDR);


        size_t asteriskPos = parsedValues.back().find('*');
        checksum = (parsedValues.back().substr(asteriskPos + 1));
        parsedValues.back() = parsedValues.back().substr(0, asteriskPos);

        sentenceID = parsedValues[0];
        for (size_t i = 1; i < parsedValues.size() - 1; i += 4) {
            Transducer t;
            t.type = parsedValues[i][0];
            t.value = stod(parsedValues[i + 1]);
            t.unit = parsedValues[i + 2][0];
            t.name = parsedValues[i + 3];
            transducers.push_back(t);
        }
    }



    string getSentenceID() const {
               return sentenceID.substr(3,3);
           }
    string getChecksum() const {
               return checksum;
           }


    Transducer getTransducer(size_t index) const {
           if (index < transducers.size()) {
               return transducers[index];
           } else {
               throw out_of_range("Index out of range");
           }
       }

    virtual ~XDR() {}
};



#endif /* XDR_H_ */
