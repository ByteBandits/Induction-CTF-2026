#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // put whatever you want here
    char *name = "";
    char *filename = "intercept.wav";
    
    float beep_dur = 0.3;    
    float bit_gap = 0.05;    
    float letter_gap = 0.7;  
    int step = 1000; 

    char command[16384]; 
    sprintf(command, "sox -n %s ", filename);

    // buffer has to work now
    // theyd need a lil hint cuz 3 bits not enough
    for (int scale = 1; scale <= 8; scale++) {
        char cal[128];
        sprintf(cal, "synth 0.2 sine %d fade q 0.02 0.2 0.02 : ", scale * step);
        strcat(command, cal);
    }
    strcat(command, "synth 0.5 sine 0 : ");

    // whatever bro just complete the code
    printf("Mapping Table\n");
    for (int i = 0; i < strlen(name); i++) {
        char oct[4];
        sprintf(oct, "%03o", (unsigned char)name[i]);
        printf("%c -> %s\n", name[i], oct);
        
        for (int j = 0; j < strlen(oct); j++) {
            int digit = oct[j] - '0';
            int freq = (digit + 1) * step; 
            
            char buffer[256];
            sprintf(buffer, "synth %f sine %d fade q 0.02 %f 0.02 : ", 
                    beep_dur, freq, beep_dur);
            strcat(command, buffer);
            
            sprintf(buffer, "synth %f sine 0 : ", bit_gap);
            strcat(command, buffer);
        }
        strcat(command, "synth 0.6 sine 0 : ");
    }

    int len = strlen(command);
    if (len > 3) { command[len - 3] = '\0'; }
    
    system(command);
    
    printf("\nGenerating Spectrogram.\n");
    // -X 150 makes it a bit wide, mr...
    // say that again....
    // that again...
    system("sox intercept.wav -n spectrogram -y 513 -X 150 -m -o spectrogram.png");
    
    printf("Success! 'intercept.wav' and 'spectrogram.png' created.\n");
    return 0;
}
