#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320

extern double input_signal_f32_1kHz_15kHz[SIG_LENGTH];
double calc_mean(double *sig_arr, int sig_length );
double calc_variance(double* sig_src_arr, double sig_mean, int sig_length);
double calc_std(double sig_variance);

double mean_result;
double variance_result;
double STD_result;

int main()
{

    mean_result = calc_mean(&input_signal_f32_1kHz_15kHz[0],SIG_LENGTH);
    variance_result = calc_variance(&input_signal_f32_1kHz_15kHz[0], mean_result, SIG_LENGTH);
    STD_result = calc_std(variance_result);

    printf("\nSignal parameters:\n\nMean = %f\nVariance = %f\nStandard deviation = %f\n\n",mean_result, variance_result, STD_result);

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

double calc_variance(double* sig_src_arr, double sig_mean, int sig_length)
{
    double variance = 0.0;
    for (int i = 0; i < sig_length; i++)
    {
        variance = variance + pow((sig_src_arr[i] - sig_mean), 2);

    }
    variance = variance / ((double)sig_length - 1);
    return variance;

}

double calc_std(double sig_variance)
{

    double std = sqrt(sig_variance);
    return std;
}