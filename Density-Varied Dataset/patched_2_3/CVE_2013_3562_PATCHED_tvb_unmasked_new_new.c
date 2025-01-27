tvbuff_t *
CVE_2013_3562_PATCHED_tvb_unmasked(tvbuff_t *tvb, const guint offset, guint payload_length, const guint8 *masking_key)
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;

  gchar *data_unmask;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  tvbuff_t  *tvb_unmask    = NULL;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  guint i;
  const guint8 *data_mask;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  guint unmasked_length = payload_length > MAX_UNMASKED_LEN ? MAX_UNMASKED_LEN : payload_length;

  data_unmask = g_malloc(unmasked_length);
  data_mask = tvb_get_ptr(tvb, offset, unmasked_length);
  /* Unmasked(XOR) Data... */
  for(i=0; i < unmasked_length; i++){
    data_unmask[i] = data_mask[i] ^ masking_key[i%4];
  }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  tvb_unmask = tvb_new_real_data(data_unmask, unmasked_length, unmasked_length);
  tvb_set_free_cb(tvb_unmask, g_free);
  return tvb_unmask;
}
