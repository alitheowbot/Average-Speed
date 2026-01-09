// keep getting user input until a specific prompt
// divide the users input by colons (:) to determine hh mm ss

// our formula is totaltime / 0.6 * speed
// e.g: to calculate 30 minutes of travel at 100kmph, you get 30 / 0.6 * 100 = 5000 (50km)
// 

// todo: 
// fix colons (works as long as format is STRICTLY followed, no errors/exceptions are thrown) (WIEGAND WOULD BE DISAPPOINTED.)

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Log {
    int hour_;
    int min_;
    int sec_;
    float km_;
};

int main() {
    Log storer;
    vector<Log> distances = {};
    string keepgo = "";
    string q = "";
    char dummy;
    int kmph = 0; int newkmph;
    float totalKM = 0.0; float newKM;
    
    int hour = 00; int tmphour = 00; int newhour;
    int min = 00; int tmpmin = 00; int newmin;
    int sec = 00; int tmpsec = 00; int newsec;

    printf("Format: \nhour:minute:second KM\n");
    
    getline(cin,keepgo);
    while (keepgo != "q") {

        
        if (keepgo == "q") break;


        
        stringstream ss(keepgo);
        while (!ss.eof()) {
            tmphour = hour;
            tmpmin = min;
            tmpsec = sec;
            ss >> hour >> dummy >> min >> dummy >> sec >> newkmph;
        }
        if (kmph == 0) {
            kmph = newkmph;
            storer.hour_ = tmphour;
            storer.min_ = tmpmin;
            storer.sec_ = tmpsec;
            storer.km_ = totalKM;
            distances.push_back(storer);
            getline(cin, keepgo);
        }
        else {
            //cout << tmphour << "::" << tmpmin << "::" << tmpsec << " " << setprecision(2) << fixed << totalKM << " km" << endl;
            
            
            // converting all to min
            newhour = hour - tmphour;
            newhour *= 60;

            newsec = sec - tmpsec;
            newsec *= 0.6;

            newmin = (min - tmpmin) + newhour + newsec;

            newKM = (newmin / 0.6 * kmph) / 100;
            totalKM += newKM;

            storer.hour_ = hour;
            storer.min_ = min;
            storer.sec_ = sec;
            storer.km_ = totalKM;
            distances.push_back(storer);

            //cout << hour << "::" << min << "::" << sec << " " << setprecision(2) << fixed << totalKM << " km" << endl;
            kmph = newkmph;

            getline(cin, keepgo);
        }
    }
    for (Log x: distances) {
        cout 
        << setfill('0') << setw(2) << x.hour_ 
        << "::" 
        << setfill('0') << setw(2) << x.min_ 
        << "::" 
        << setfill('0') << setw(2) << x.sec_ 
        << " " << x.km_ << " km" << endl;
    }

    
    

}
