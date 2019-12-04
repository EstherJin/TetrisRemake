//
// Created by Ordencia Wu on 2019-11-28.
//

#include "NonRandom.h"
#include "block1.h"
#include "l.h"
#include "t.h"
#include "i.h"
#include "z.h"
#include "j.h"
#include "s.h"
#include "o.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "coordinates.h"

using namespace std;

NonRandom::NonRandom (string file, int n): Level(n) {
    fileName = file; // add a string here called sequence, load the file into string
    ifstream f {fileName};
	getline(f, sequence);
}

char NonRandom::nextBlock() { //use istringstream to load one char at a time and substr, reload when empty
	char block;
    while (true) {
		istringstream ss{ sequence };
        if (ss >> block) {
            /*switch (block) {
                case 'L':
                    next = new L ();
                    break;
                case 'T':
                    //3,0 3,1 3,2 4,1
                    next = new T ();
                    break;
                case 'I':
                    // 4,0 4,1 4,2 4,3
                    next = new I ();
                    break;
                case 'Z':
                    // 3,0 3,1 4,1 4,2
                    next = new Z ();
                    break;
                case 'J':
                    // 3,0 4,0 4,1 4,2
                    next = new J ();
                    break;
                case 'S':
                    // 3,1 3,2 4,0 4,1
                    next = new S ();
                    break;
                case 'O':
                    // 3,0 3,1 4,0 4,1
                    next = new O ();
                    break;
            }


		}*/

            sequence = sequence.substr(1);
            break;
        } else {
            ifstream f{fileName};
			getline(f, sequence);
            // ss.str(sequence);
        }
    }

    return block;
}
