#include <stdio.h>
#include <stdlib.h>

#define SIG_LENGTH 320

extern double input_signal_f32_1kHz_15kHz[SIG_LENGTH];
double calc_mean(double *sig_arr, int sig_length );
double result;

int main()
{

    result = calc_mean(&input_signal_f32_1kHz_15kHz[0],SIG_LENGTH);
    printf("\n\nMean = %f\n\n\n",result);

    return 0;
}



double calc_mean(double *sig_arr, int sig_length )
{
    double mean =0.0;
    for(int i =0;i<sig_length;i++)
    {
        mean = mean + sig_arr[i];
    }

    mean = mean/(double)sig_length;

    return mean;
}
