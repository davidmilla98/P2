#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float power, p = 1e-9;
    for(int i=0; i<N; i++)  {
        p = p + pow(x[i],2);
    }
    power = 10 * log10(p/N);
    
    return power;
}

float compute_am(const float *x, unsigned int N) {
    float am, a = 0;
    for(int i=0; i<N; i++)  {
        a = a + fabs(x[i]);
    } 
    am = a/N;   
    return am;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float zcr, z = 0;
    for(int i=1; i<N;i++)   {
        if((x[i]<0 && x[i-1]>0))    {
            z = z + 1;
        }
        else if((x[i]>0 && x[i-1]<0))   {
            z = z + 1;
        }
    }
    zcr = (fm/2) * (1./(N-1.)) * z; 
    return zcr;
}
