#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

int main() {
    srand(time(0));

    int packet[300];
    int fsize;
    cout << "Enter the number of frame: ";
    cin>>fsize;
    cout << "\n\tFrame Size: " << fsize << endl;
    cout << "\n\t------ Data Log --------" << endl;
    cout << "\nFrame\tData\tWaiting\tAcknow\tResend\n" << endl;

    for (int i = 0; i < fsize; i++) {
        packet[i] = rand() % 10000; //
        cout << i + 1 << "\t" << packet[i] << "\t";

        int j = 1;
        bool resent = false;

        ///Simulate waiting/timeout
        while (rand() % 2 == 0) {
            cout << j << " ";
            sleep(1);
            j++;
            if (j > 3) { /// Timeout occurs
                cout << "\tNo\tResending..." << endl;
                cout << i + 1 << "\t" << packet[i] << "\t0\tYES\tNo";
                resent = true;
                break;
            }
        }

        /// Normal ACK received
        if (!resent) {
            if(j==1)
                cout << "0\tYES\tNo";
            else
                cout << "\tYES\tNo";
        }

        cout << endl;
    }

    cout << "\n\n---------- ALL DATA PACKETS SENT ----------\n";

    return 0;
}
