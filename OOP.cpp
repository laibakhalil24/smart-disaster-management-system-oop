#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>   // rand() aur srand() ke liye
#include <ctime>     // time() ke liye

using namespace std;

// ================= BASE DISASTER CLASS =================
class Disaster {
protected:
    string location;
    int severity;
    int victims;
    int safeCount;       // Shared safe count to prevent random mismatch
    int missingCount;    // Shared missing count to prevent random mismatch

public:
    Disaster(string l = "", int s = 0, int v = 0) {
        location = l;
        severity = s;
        victims = v;
        safeCount = 0;
        missingCount = 0;
    }

    virtual void alert() = 0;
    virtual void showInfo() = 0;

    // Setter to update realistic drone scan values
    void setScanResults(int safe, int missing) {
        safeCount = safe;
        missingCount = missing;
    }

    int getVictims() { return victims; }
    string getLocation() { return location; }
    virtual ~Disaster() {}
};

// ================= EARTHQUAKE CLASS =================
class Earthquake : public Disaster {
private:
    float magnitude;

public:
    Earthquake(string l, int s, int v, float m) : Disaster(l, s, v) { 
        magnitude = m; 
    }

    void alert() {
        cout << "\n=========================================" << endl;
        cout << "            ?? EARTHQUAKE ALERT ??          " << endl;
        cout << "=========================================" << endl;
        cout << "Location Detected: " << location << endl;
        cout << "Recorded Magnitude: " << magnitude << " on Richter Scale" << endl;
        cout << "----------------------------------------" << endl;

        if (magnitude >= 1.0f && magnitude <= 3.9f) {
            cout << "[MESSAGE]: MINOR TREMOR DETECTED." << endl;
            cout << "-> Shaking was very light. No structural damage reported." << endl;
            cout << "-> Status: Keep calm and stay inside." << endl;
        } 
        else if (magnitude >= 4.0f && magnitude <= 5.9f) {
            cout << "[MESSAGE]: MODERATE EARTHQUAKE WARNING!" << endl;
            cout << "-> Ceiling fans and windows are shaking. Minor cracks possible." << endl;
            cout << "-> Status: Move away from glass windows and heavy objects." << endl;
        } 
        else if (magnitude >= 6.0f && magnitude <= 7.9f) {
            cout << "[MESSAGE]: ?? DANGER! MAJOR EARTHQUAKE POP-UP! ??" << endl;
            cout << "-> Severe shaking! Weak buildings may collapse." << endl;
            cout << "-> Status: CRITICAL! Run to open areas immediately!" << endl;
        } 
        else if (magnitude >= 8.0f && magnitude <= 10.0f) {
            cout << "[MESSAGE]: ?? RED ALERT! CATASTROPHIC DISASTER! ??" << endl;
            cout << "-> Total destruction of infrastructure in the area!" << endl;
            cout << "-> Status: EMERGENCY LEVEL 10. Deploy all rescue teams!" << endl;
        }

        if (severity >= 3 || magnitude >= 6.0f) {
            cout << "\n>>> [SYSTEM OVERRIDE]: IMMEDIATE EVACUATION IS MANDATORY! <<<" << endl;
        }
        cout << "=========================================" << endl;
    }

    void showInfo() {
        cout << "=========================================" << endl;
        cout << "        MISSING PERSON STATUS REPORT     " << endl;
        cout << "=========================================" << endl;
        cout << "Location     : " << location << endl;
        cout << "Total Impact : " << victims << " Affected" << endl;
        cout << "-> [TRAPPED / MISSING]: " << missingCount << " Person(s)" << endl;
        cout << "-> [CONFIRMED SAFE]   : " << safeCount << " Person(s) Rescued" << endl;
        cout << "=========================================" << endl;

        cout << "\n-----------------------------------------" << endl;
        cout << "   EARTHQUAKE FINAL DATABASE RECORD      " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Area Name   : " << location << endl;
        cout << "System Level: Severity " << severity << "/3" << endl;
        cout << "Impact Count: " << victims << " Total Victims" << endl;
        cout << "-----------------------------------------" << endl;
    }
};

// ================= FLOOD CLASS =================
class Flood : public Disaster {
private:
    float waterLevel;

public:
    Flood(string l, int s, int v, float w) : Disaster(l, s, v) { waterLevel = w; }

    void alert() {
        cout << "\n=========================================" << endl;
        cout << "              ?? FLOOD ALERT ??            " << endl;
        cout << "=========================================" << endl;
        cout << "Location Detected: " << location << endl;
        cout << "Water Level: " << waterLevel << " ft" << endl;
        cout << "-----------------------------------------" << endl;

        if (waterLevel >= 0.0f && waterLevel <= 2.0f) {
            cout << "[MESSAGE]: MINOR WATER LOGGING." << endl;
            cout << "-> Water accumulation on roads. Slow down vehicles." << endl;
            cout << "-> Status: Avoid underground basements." << endl;
        }
        else if (waterLevel > 2.0f && waterLevel <= 5.0f) {
            cout << "[MESSAGE]: MODERATE FLOOD WARNING!" << endl;
            cout << "-> Water entering low-lying areas. Power cuts expected." << endl;
            cout << "-> Status: Move valuable items and electronics to upper floors." << endl;
        }
        else if (waterLevel > 5.0f && waterLevel <= 10.0f) {
            cout << "[MESSAGE]: ?? DANGER! HIGH FLOOD POP-UP! ??" << endl;
            cout << "-> Strong water currents. Roads submerged entirely." << endl;
            cout << "-> Status: CRITICAL! Do not try to walk or drive through water." << endl;
        }
        else if (waterLevel > 10.0f) {
            cout << "[MESSAGE]: ?? RED ALERT! SEVERE FLASH FLOOD! ??" << endl;
            cout << "-> Submergence of ground floors. Extreme danger." << endl;
            cout << "-> Status: EMERGENCY LEVEL 10. Move to roofs and await rescue!" << endl;
        }

        if (severity >= 3 || waterLevel > 5.0f) {
            cout << "\n>>> [SYSTEM OVERRIDE]: IMMEDIATE EVACUATION IS MANDATORY! <<<" << endl;
        }
        cout << "=========================================" << endl;
    }

    void showInfo() {
        cout << "=========================================" << endl;
        cout << "        MISSING PERSON STATUS REPORT     " << endl;
        cout << "=========================================" << endl;
        cout << "Location     : " << location << endl;
        cout << "Total Impact : " << victims << " Affected" << endl;
        cout << "-> [TRAPPED / MISSING]: " << missingCount << " Person(s)" << endl;
        cout << "-> [CONFIRMED SAFE]   : " << safeCount << " Person(s) Rescued" << endl;
        cout << "=========================================" << endl;

        cout << "\n-----------------------------------------" << endl;
        cout << "        FLOOD FINAL DATABASE RECORD       " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Area Name   : " << location << endl;
        cout << "System Level: Severity " << severity << "/3" << endl;
        cout << "Impact Count: " << victims << " Total Victims" << endl;
        cout << "Water Level : " << waterLevel << " ft" << endl;
        cout << "-----------------------------------------" << endl;
    }
};

// ================= FIRE CLASS =================
class Fire : public Disaster {
private:
    float temperature;

public:
    Fire(string l, int s, int v, float t) : Disaster(l, s, v) { temperature = t; }

    void alert() {
        cout << "\n=========================================" << endl;
        cout << "              ?? FIRE ALERT ??            " << endl;
        cout << "=========================================" << endl;
        cout << "Location Detected: " << location << endl;
        cout << "Temperature: " << temperature << " C" << endl; // Removed problematic character
        cout << "-----------------------------------------" << endl;

        if (temperature >= 15.0f && temperature <= 60.0f) {
            cout << "[MESSAGE]: ABNORMAL HEAT SPARK DETECTED." << endl;
            cout << "-> Smoke or small spark noticed. High thermal reading." << endl;
            cout << "-> Status: Use portable fire extinguishers if safe." << endl;
        }
        else if (temperature > 60.0f && temperature <= 120.0f) {
            cout << "[MESSAGE]: MODERATE FIRE WARNING!" << endl;
            cout << "-> Fire is spreading in localized rooms/zones." << endl;
            cout << "-> Status: Cover mouth with a wet cloth and crawl under smoke." << endl;
        }
        else if (temperature > 120.0f && temperature <= 300.0f) {
            cout << "[MESSAGE]: ?? DANGER! MAJOR WILDFIRE/STRUCTURE FIRE! ??" << endl;
            cout << "-> Structural failure risks. Rapidly engulfing flames." << endl;
            cout << "-> Status: CRITICAL! Do not use elevators. Run via fire exits!" << endl;
        }
        else if (temperature > 300.0f) {
            cout << "[MESSAGE]: ?? RED ALERT! INFERNO/BLAZE STATE! ??" << endl;
            cout << "-> Extreme flashover condition. Inhabitable environment." << endl;
            cout << "-> Status: EMERGENCY LEVEL 10. Call Fire Brigade & Air Support!" << endl;
        }

        if (severity >= 3 || temperature > 60.0f) {
            cout << "\n>>> [SYSTEM OVERRIDE]: IMMEDIATE EVACUATION IS MANDATORY! <<<" << endl;
        }
        cout << "=========================================" << endl;
    }

    void showInfo() {
        cout << "=========================================" << endl;
        cout << "        MISSING PERSON STATUS REPORT     " << endl;
        cout << "=========================================" << endl;
        cout << "Location     : " << location << endl;
        cout << "Total Impact : " << victims << " Affected" << endl;
        cout << "-> [TRAPPED / MISSING]: " << missingCount << " Person(s)" << endl;
        cout << "-> [CONFIRMED SAFE]   : " << safeCount << " Person(s) Rescued" << endl;
        cout << "=========================================" << endl;

        cout << "\n-----------------------------------------" << endl;
        cout << "        FIRE FINAL DATABASE RECORD       " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Area Name   : " << location << endl;
        cout << "System Level: Severity " << severity << "/3" << endl;
        cout << "Impact Count: " << victims << " Total Victims" << endl;
        cout << "Temperature : " << temperature << " C" << endl;
        cout << "-----------------------------------------" << endl;
    }
};

// ================= DRONE CLASS =================
class Drone {
private:
    string droneID;
    int battery;
    string targetArea;
    bool deployed;

public:
    Drone(string id, int b, string a) {
        droneID = id; battery = b; targetArea = a; deployed = false;
    }

    void automaticScan(bool isCritical, int victimCount, int& outSafe, int& outMissing) {
        deployed = true;
        
        if (victimCount == 0) {
            outSafe = 0;
            outMissing = 0;
        } 
        else if (!isCritical) {
            // Non-critical scenario: Missing values kam honi chahiye.
            int maxMissingLimit = (victimCount * 15) / 100;
            if (maxMissingLimit == 0 && victimCount > 0) maxMissingLimit = 1;
            
            outMissing = rand() % (maxMissingLimit + 1);
            if (outMissing >= victimCount) outMissing = victimCount - 1; // Direct edge case check
            if (outMissing < 0) outMissing = 0;
            outSafe = victimCount - outMissing;
        } 
        else {
            // Critical scenario: Missing zyada honge, par total victims ke bilkul barabar nahi honge.
            int minMissing = (victimCount * 60) / 100;
            int maxMissing = (victimCount * 90) / 100;
            
            // Tweak: Ensure maxMissing exact absolute total na banay agar zyada log hon
            if (maxMissing >= victimCount && victimCount > 2) {
                maxMissing = victimCount - 1;
            }
            if (minMissing >= maxMissing) minMissing = maxMissing - 1;
            if (minMissing < 0) minMissing = 0;

            int range = (maxMissing - minMissing + 1);
            outMissing = minMissing + (rand() % range);
            
            if (outMissing >= victimCount && victimCount > 1) outMissing = victimCount - 1;
            outSafe = victimCount - outMissing;
        }

        // --- DRONE SCANNING HEADING ---
        cout << "\n=========================================" << endl;
        cout << "     AERIAL DRONE SCANNING MISSION       " << endl;
        cout << "=========================================" << endl;
        cout << ">>> Automated Drone [" << droneID << "] dispatched to scan " << targetArea << "..." << endl;
        cout << "[Drone Battery Level]: " << battery << "%" << endl;
        
        if (isCritical) {
            cout << "[DRONE LIVE FEED]: Warning! Threat confirmed. Area is INFECTED and risky!" << endl;
            if (outMissing > 0) {
                cout << "[DRONE SCANNER]: Detected " << outMissing << " potential missing/trapped person(s) out of " << victimCount << "!" << endl;
                cout << "                 Scanning for tracking signals..." << endl;
            } else {
                cout << "[DRONE SCANNER]: Area is clear of active missing person signals but structurally unsafe." << endl;
            }
        } else {
            cout << "[DRONE LIVE FEED]: Scan complete. Safe conditions observed. Danger levels are minimal." << endl;
            if (outMissing > 0) {
                cout << "[DRONE SCANNER]: Minor incident impact. Discovered " << outMissing << " isolated/trapped person(s) out of " << victimCount << "." << endl;
            } else {
                cout << "[DRONE SCANNER]: 0 missing signals. All " << outSafe << " individuals are safe." << endl;
            }
        }
        
        battery -= 15; 
        deployed = false;
        cout << "<<< Drone [" << droneID << "] returned to base automatically.\n" << endl;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    srand(time(0)); 
    int choice;
    int totalVictims = 0;
    vector<Disaster*> disasters;

    do {
        cout << "\n====================================";
        cout << "\n DISASTER MANAGEMENT SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Earthquake Alert";
        cout << "\n2. Flood Alert";
        cout << "\n3. Fire Alert";
        cout << "\n4. Show Total Victims";
        cout << "\n0. Exit";
        cout << "\nEnter Choice: ";
        cout.flush();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string loc; int sev, vic, bat; float mag;
            cout << "\n--- Enter Earthquake Data ---" << endl;
            cout << "Location: "; getline(cin, loc); 
            cout << "Severity (1-3): "; cin >> sev;
            while (sev < 1 || sev > 3) {
                cout << "[Error] Invalid range! Enter (1-3): "; cin >> sev;
            }
            cout << "Victims: "; cin >> vic;
            cout << "Magnitude (1.0 - 10.0): "; cin >> mag;
            while (mag < 1.0f || mag > 10.0f) {
                cout << "[Error] Out of Limit! Please enter magnitude between 1.0 and 10.0: "; 
                cin >> mag;
            }
            
            cout << "Enter Drone Battery Level (10 - 100%): "; cin >> bat;
            while (bat < 10 || bat > 100) {
                cout << "[Error] Invalid Battery Range! Enter between 10 and 100: "; cin >> bat;
            }
            cin.ignore();

            Disaster* d = new Earthquake(loc, sev, vic, mag);
            disasters.push_back(d); 
            d->alert();

            Drone autoDrone("EQ-DRN-01", bat, loc);
            bool critical = (mag >= 6.0f || sev == 3);
            int calculatedSafe = 0, calculatedMissing = 0;
            
            autoDrone.automaticScan(critical, vic, calculatedSafe, calculatedMissing);
            d->setScanResults(calculatedSafe, calculatedMissing);
            
            d->showInfo();
            totalVictims += vic;
            break;
        }

        case 2: {
            string loc; int sev, vic, bat; float wl;
            cout << "\n--- Enter Flood Data ---" << endl;
            cout << "Location: "; getline(cin, loc);
            cout << "Severity (1-3): "; cin >> sev;
            while (sev < 1 || sev > 3) {
                cout << "[Error] Invalid range! Enter (1-3): "; cin >> sev;
            }
            cout << "Victims: "; cin >> vic;
            cout << "Water Level(ft): "; cin >> wl;

            cout << "Enter Drone Battery Level (10 - 100%): "; cin >> bat;
            while (bat < 10 || bat > 100) {
                cout << "[Error] Invalid Battery Range! Enter between 10 and 100: "; cin >> bat;
            }
            cin.ignore();

            Disaster* d = new Flood(loc, sev, vic, wl);
            disasters.push_back(d);
            d->alert();

            Drone autoDrone("FL-DRN-02", bat, loc);
            bool critical = (wl > 5.0f || sev == 3);
            int calculatedSafe = 0, calculatedMissing = 0;
            
            autoDrone.automaticScan(critical, vic, calculatedSafe, calculatedMissing);
            d->setScanResults(calculatedSafe, calculatedMissing);

            d->showInfo();
            totalVictims += vic;
            break;
        }

        case 3: {
            string loc; int sev, vic, bat; float temp;
            cout << "\n--- Enter Fire Data ---" << endl;
            cout << "Location: "; getline(cin, loc);
            cout << "Severity (1-3): "; cin >> sev;
            while (sev < 1 || sev > 3) {
                cout << "[Error] Invalid range! Enter (1-3): "; cin >> sev;
            }
            cout << "Victims: "; cin >> vic;
            
            // ADDED: Temperature Validation Loop (15°C to 1000°C)
            cout << "Temperature (15 - 1000 C): "; cin >> temp; 
            while (temp < 15.0f || temp > 1000.0f) {
                cout << "[Error] Out of Realistic Limits! Enter between 15 and 1000 C: ";
                cin >> temp;
            }

            cout << "Enter Drone Battery Level (10 - 100%): "; cin >> bat;
            while (bat < 10 || bat > 100) {
                cout << "[Error] Invalid Battery Range! Enter between 10 and 100: "; cin >> bat;
            }
            cin.ignore();

            Disaster* d = new Fire(loc, sev, vic, temp);
            disasters.push_back(d);
            d->alert();

            Drone autoDrone("FR-DRN-03", bat, loc);
            
            // FIXED: Combined both severe attributes to accurately flag high status
            bool critical = (temp > 120.0f || sev == 3); 
            int calculatedSafe = 0, calculatedMissing = 0;
            
            autoDrone.automaticScan(critical, vic, calculatedSafe, calculatedMissing);
            d->setScanResults(calculatedSafe, calculatedMissing);

            d->showInfo();
            totalVictims += vic;
            break;
        }

        case 4:
            cout << "\nTotal Victims Recorded across all incidents: " << totalVictims << endl;
            break;

        case 0:
            for (size_t i = 0; i < disasters.size(); ++i) { delete disasters[i]; }
            cout << "\nProgram Closed Successfully!" << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
