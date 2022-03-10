#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIG_LENGTH 320
#define IMP_RSP_LENGTH 29

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
extern  double  Impulse_response[IMP_RSP_LENGTH];
        double Output_signal[SIG_LENGTH+IMP_RSP_LENGTH];
void convolution( double *sig_src_arr,
                  double *sig_dest_arr,
                  double *imp_response_arr,
                  int sig_src_length,
                  int imp_response_length
                 );


int main()
{
    FILE *fptr_input_sig, *fptr_imp_rsp,*fptr_output_sig;

     convolution( (double*) &InputSignal_f32_1kHz_15kHz[0],
                  (double*) &Output_signal[0],
                  (double*) &Impulse_response[0],
                  (int) SIG_LENGTH,
                  (int) IMP_RSP_LENGTH
                 );

    fptr_input_sig = fopen("input_signal.dat","w");
    fptr_imp_rsp = fopen("impulse_response.dat","w");
    fptr_output_sig = fopen("output_signal.dat","w");

    for(int i=0; i<SIG_LENGTH; i++)
    {
         fprintf(fptr_input_sig,"\n%f",InputSignal_f32_1kHz_15kHz[i]);
    }
    fclose(fptr_input_sig);
    for(int i=0;i<IMP_RSP_LENGTH;i++)
    {
         fprintf(fptr_imp_rsp,"\n%f",Impulse_response[i]);

    }
    fclose(fptr_imp_rsp);

     for(int i=0; i<SIG_LENGTH+IMP_RSP_LENGTH; i++)
     {

         fprintf(fptr_output_sig,"\n%f",Output_signal[i]);
     }
     fclose(fptr_output_sig);

    return 0;
}


void convolution( double *sig_src_arr,
                  double *sig_dest_arr,
                  double *imp_response_arr,
                  int sig_src_length,
                  int imp_response_length
                 )
{
    int i, j;
    for(i=0; i<sig_src_length+imp_response_length; i++)
    {
        sig_dest_arr[i] =0;
    }

      for(i=0; i<sig_src_length; i++)
      {
          for(j=0; j<imp_response_length; j++)
          {
              sig_dest_arr[i+j] = sig_dest_arr[i+j]+ sig_src_arr[i]*imp_response_arr[j];

          }
      }

}


