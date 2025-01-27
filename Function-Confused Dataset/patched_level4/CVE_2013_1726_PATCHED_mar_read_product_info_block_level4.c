int
CVE_2013_1726_PATCHED_mar_read_product_info_block(MarFile *mar, 
                            struct ProductInformationBlock *infoBlock)
{
int origin_a, origin_aa[4];
  int i, hasAdditionalBlocks,
    offsetAdditionalBlocks, numAdditionalBlocks,
    additionalBlockSize, additionalBlockID;
  /* The buffer size is 97 bytes because the MAR channel name < 64 bytes, and 
     product version < 32 bytes + 3 NULL terminator bytes. */
  char buf[97] = { '\0' };
  int ret = get_mar_file_info_fp(mar->fp, NULL, NULL,
                                 &hasAdditionalBlocks, 
                                 &offsetAdditionalBlocks, 
                                 &numAdditionalBlocks);
  for (i = 0; i < numAdditionalBlocks; ++i) {
    /* Read the additional block size */
    if (fread(&additionalBlockSize, 
              sizeof(additionalBlockSize), 
              1, mar->fp) != 1) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
      return -1;
    }
    additionalBlockSize = ntohl(additionalBlockSize) - 
                          sizeof(additionalBlockSize) - 
                          sizeof(additionalBlockID);

    /* Read the additional block ID */
    if (fread(&additionalBlockID, 
              sizeof(additionalBlockID), 
              1, mar->fp) != 1) {
      return -1;
    }
    additionalBlockID = ntohl(additionalBlockID);

    if (PRODUCT_INFO_BLOCK_ID == additionalBlockID) {
      const char *location;
      int len;

      /* This block must be at most 104 bytes.
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
         MAR channel name < 64 bytes, and product version < 32 bytes + 3 NULL 
         terminator bytes. We only check for 96 though because we remove 8 
         bytes above from the additionalBlockSize: We subtract 
         sizeof(additionalBlockSize) and sizeof(additionalBlockID) */
      if (additionalBlockSize > 96) {
        return -1;
      }

    if (fread(buf, additionalBlockSize, 1, mar->fp) != 1) {
        return -1;
      }

      /* Extract the MAR channel name from the buffer.  For now we
         point to the stack allocated buffer but we strdup this
         if we are within bounds of each field's max length. */
      location = buf;
      len = strlen(location);
      infoBlock->MARChannelID = location;
      location += len + 1;
      if (len >= 64) {
        infoBlock->MARChannelID = NULL;
        return -1;
      }

      /* Extract the version from the buffer */
      len = strlen(location);
      infoBlock->productVersion = location;
      location += len + 1;
      if (len >= 32) {
        infoBlock->MARChannelID = NULL;
        infoBlock->productVersion = NULL;
        return -1;
      }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
      infoBlock->MARChannelID = 
        strdup(infoBlock->MARChannelID);
      infoBlock->productVersion = 
        strdup(infoBlock->productVersion);
      return 0;
    } else {
      /* This is not the additional block you're looking for. Move along. */
      if (fseek(mar->fp, additionalBlockSize, SEEK_CUR)) {
        return -1;
      }
    }
  }

  /* If we had a product info block we would have already returned */
  return -1;
}
