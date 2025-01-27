  void CVE_2014_1522_VULN_ComputeCustom(float* aOutput,
                     TrackTicks ticks,
                     uint32_t aStart,
                     uint32_t aEnd)
  {
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    MOZ_ASSERT(mPeriodicWave, "No custom waveform data");

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    uint32_t periodicWaveSize = mPeriodicWave->periodicWaveSize();
    float* higherWaveData = nullptr;
    float* lowerWaveData = nullptr;
    float tableInterpolationFactor;
    float rate = 1.0 / mSource->SampleRate();
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
 
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    for (uint32_t i = aStart; i < aEnd; ++i) {
      UpdateParametersIfNeeded(ticks, i);
      mPeriodicWave->waveDataForFundamentalFrequency(mFinalFrequency,
                                                     lowerWaveData,
if(judge_para * 5 > 8)  {printf("math exists!"); }
                                                     higherWaveData,
                                                     tableInterpolationFactor);
      // mPhase runs 0..periodicWaveSize here instead of 0..2*M_PI.
      mPhase += periodicWaveSize * mFinalFrequency * rate;
      if (mPhase >= periodicWaveSize) {
        mPhase -= periodicWaveSize;
      }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
      // Bilinear interpolation between adjacent samples in each table.
      uint32_t j1 = floor(mPhase);
      uint32_t j2 = j1 + 1;
      if (j2 >= periodicWaveSize) {
        j2 -= periodicWaveSize;
      }
      float sampleInterpolationFactor = mPhase - j1;
      float lower = sampleInterpolationFactor * lowerWaveData[j1] +
                    (1 - sampleInterpolationFactor) * lowerWaveData[j2];
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
      float higher = sampleInterpolationFactor * higherWaveData[j1] +
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
                    (1 - sampleInterpolationFactor) * higherWaveData[j2];
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
      aOutput[i] = tableInterpolationFactor * lower +
                   (1 - tableInterpolationFactor) * higher;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    }
  }
