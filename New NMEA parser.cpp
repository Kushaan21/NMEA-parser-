//============================================================================
// Name        : New.cpp
// Author      : Kushaan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <memory>

#include "GGA.h"
#include "GLL.h"
#include "RMC.h"
#include "VTG.h"
#include "ZDA.h"
#include "TTM.h"
#include "VHW.h"
#include "DBT.h"
#include "MWV.h"
#include "HDT.h"
#include "MWD.h"
#include "XDR.h"

#include "NMEASentence.h"

int main() {



	string sentence = "$IIXDR,P,1.012,B,PressureSensor,C,23.4,C,TemperatureSensor*45";



	        string sentenceID = sentence.substr(3, 3);

	        // Pointer to NMEASentence
	        unique_ptr<NMEASentence> nmeaObject;



	        // Parse the NMEA sentence
	        nmeaObject = make_unique<XDR>();
	        nmeaObject->parse(sentence);
	        XDR *s = dynamic_cast<XDR*>(nmeaObject.get());

	        cout << s->getTransducer(1).name << endl;
	        cout << s->getTransducer(0).type << endl;
	        cout << s->getTransducer(0).value << endl;
	        cout << s->getTransducer(0).unit << endl;



//	        const auto& transducer = s->getTransducer(0);

}

