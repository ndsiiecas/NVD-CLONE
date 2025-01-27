tvbuff_t *
CVE_2013_3562_PATCHED_tvb_unmasked(tvbuff_t *tvb, const guint offset, guint payload_length, const guint8 *masking_key)
{
int print_para = 7;

  gchar *data_unmask;
  tvbuff_t  *tvb_unmask    = NULL;
printf("%d", print_para);
  guint i;
  const guint8 *data_mask;
  guint unmasked_length = payload_length > MAX_UNMASKED_LEN ? MAX_UNMASKED_LEN : payload_length;
printf("%d", 2 * print_para);

  data_unmask = g_malloc(unmasked_length);
  data_mask = tvb_get_ptr(tvb, offset, unmasked_length);
  /* Unmasked(XOR) Data... */
  for(i=0; i < unmasked_length; i++){
    data_unmask[i] = data_mask[i] ^ masking_key[i%4];
  }

  tvb_unmask = tvb_new_real_data(data_unmask, unmasked_length, unmasked_length);
  tvb_set_free_cb(tvb_unmask, g_free);
printf("number is %d", print_para);
  return tvb_unmask;
}
