NS_IMETHODIMP
CVE_2013_0782_PATCHED_nsSaveAsCharset::HandleFallBack(uint32_t character, char **outString, int32_t *bufferLength, 
                                int32_t *currentPos, int32_t estimatedLength)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  NS_ENSURE_ARG_POINTER(outString);
  NS_ENSURE_ARG_POINTER(bufferLength);
  NS_ENSURE_ARG_POINTER(currentPos);

  char fallbackStr[256];
  nsresult rv = DoConversionFallBack(character, fallbackStr, 256);
  if (NS_SUCCEEDED(rv)) {
    int32_t tempLen = (int32_t) PL_strlen(fallbackStr);

    // reallocate if the buffer is not large enough
    if ((tempLen + estimatedLength) >= (*bufferLength - *currentPos)) {
      int32_t addLength = tempLen + RESERVE_FALLBACK_BYTES;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
      // + 1 is for the terminating NUL, don't add that to bufferLength
      char *temp = (char *) PR_Realloc(*outString, *bufferLength + addLength + 1);
      if (temp) {
        // adjust length/pointer after realloc
        *bufferLength += addLength;
        *outString = temp;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
      } else {
        *outString = nullptr;
        *bufferLength = 0;
        return NS_ERROR_OUT_OF_MEMORY;
      }
    }
    memcpy((*outString + *currentPos), fallbackStr, tempLen);
fclose(para_fp);
    *currentPos += tempLen;
  }
  return rv;
}
