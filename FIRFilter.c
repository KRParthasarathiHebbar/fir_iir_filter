#include "FIRFilter.h"

static float FIR_IMPULSE_RESPONSE[FIR_FILTER_LENGTH]={-0.00306200334634002,	-0.00503110836782698,	-0.00677269121762658,	2.87012324819924e-18,	0.0255476989130046	,0.0730833221416457	,0.132472846946078	,0.182615819497229,	0.202292230867672,	0.182615819497229,	0.132472846946078,	0.0730833221416457,	0.0255476989130046,	2.87012324819924e-18,	-0.00677269121762658,	-0.00503110836782698,	-0.00306200334634002};

void FIRFilter_Init (FIRFilter *fir)
{
	for(uint8_t n=0;n<FIR_FILTER_LENGTH;n++)
	{
		fir->buf[n]=0;
	}
	fir->bufIndex=0;

	fir->out=0;
}

float FIRFilter_Update(FIRFilter *fir, float inp)
{
	fir->buf[fir->bufIndex]= inp;

	fir->bufIndex++;

	if(fir->bufIndex == FIR_FILTER_LENGTH)
	{
		fir->bufIndex =0;
	}

	fir->out=0;

	uint8_t sumIndex = fir->bufIndex;

	for(uint8_t n=0;n<FIR_FILTER_LENGTH;n++)
		{
			if (sumIndex > 0)
			{
				sumIndex--;
			}
			else{
				sumIndex = FIR_FILTER_LENGTH - 1;

			}
			fir->out += FIR_IMPULSE_RESPONSE[n] * fir->buf[sumIndex];

		}
	return fir->out;

}



