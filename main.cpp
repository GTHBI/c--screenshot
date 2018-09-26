#include "sshotlib.h"
#include <string>
#include <iostream>
#include <direct.h>

int main() {

    time_t thisTime = time(NULL);
    struct tm *aTime = localtime(&thisTime);
    int hour=aTime->tm_hour;
    int min=aTime->tm_min;
    int cur = 1;
    
    POINT p = {0, 0};
    POINT posLast = {LONG_MIN, LONG_MIN};

    while (cur != 0 ) {

            GetCursorPos(&p);

             if ((posLast.x != p.x) || (posLast.y != p.y))
             {   
             string path = "sc-"+std::to_string(cur)+"-"+std::to_string(hour)+".jpg";
             ULONG quality = 100;
             SaveScreenshot(path, quality);
             posLast = p;
           }
        
         cur++;
         Sleep(1000);
    }
    return 0;
}
