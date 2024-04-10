#include "IIRFilter.h"


void IIRFilter_Init (IIRFilter *filt, float alpha)
{
		if( alpha < 0.0f)
		{
			filt->alpha=0.0f;

		}
		else if(alpha > 1.0f)
		{
			filt->alpha=1.0f;
		}
		else
		{
			filt->alpha = alpha;

		}
		filt->out=0.0f;

}

float IIRFilter_Update(IIRFilter *filt, float in)
{

	filt->out=(1.0f - filt->alpha) * in + filt->alpha*filt->out;

	return filt->out;

}





