#include <iostream>
#include <math.h>
#define pi 3.141
using namespace std;

//sign function
float sgn(float x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
}

float f_sin(float amplitude, float i) {
    return amplitude*sin(i);
}

float f_sawtooth(float amplitude, float i) {
    return (fmod(i,pi)/pi)*amplitude;
}

//PWM waveform can be made from sign function and sinusoidal function.
//the variable "duty" represents the duty cycle
float f_PWM(float amplitude, float duty, float i){
    return (( sgn(sin(i)+(2*duty)-1)+1 )/2)*amplitude;
}

int main()
{
    float i;
    float amplitude = 5; //maxmimum voltage
    float PWM_duty = 0.8; //PWM duty value between 0 to 1 (0% to 100%)
    for(i=0; i<8*pi;) {
    cout 
    << f_sin(amplitude, i) << " " 
    << f_sawtooth(amplitude, i) << " " 
    << f_PWM(amplitude, PWM_duty, i) << "\n";
    i=i+0.01;
    }
    return 0;
}
