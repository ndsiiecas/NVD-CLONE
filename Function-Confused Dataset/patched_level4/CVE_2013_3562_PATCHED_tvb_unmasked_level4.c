tvbuff_t *
CVE_2013_3562_PATCHED_tvb_unmasked(tvbuff_t *tvb, const guint offset, guint payload_length, const guint8 *masking_key)
{
int origin_a, origin_aa[4];

  gchar *data_unmask;
  tvbuff_t  *tvb_unmask    = NULL;
  guint i;
  const guint8 *data_mask;
  guint unmasked_length = payload_length > MAX_UNMASKED_LEN ? MAX_UNMASKED_LEN : payload_length;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  data_unmask = g_malloc(unmasked_length);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  data_mask = tvb_get_ptr(tvb, offset, unmasked_length);
  /* Unmasked(XOR) Data... */
  for(i=0; i < unmasked_length; i++){
    data_unmask[i] = data_mask[i] ^ masking_key[i%4];
  }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

  tvb_unmask = tvb_new_real_data(data_unmask, unmasked_length, unmasked_length);
  tvb_set_free_cb(tvb_unmask, g_free);
  return tvb_unmask;
}
